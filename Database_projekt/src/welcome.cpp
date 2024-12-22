#include <iostream>
#include <string>
#include <fstream>

using std::cout, std::cin, std::endl;
namespace an{
class Game{
private:
    std::string m_name;
    std::string m_author; // i mean author of the game 
    int m_year{};
public:
    // default constructor
    Game(){
        m_name = "unknown";
        m_author = "unknown";
        m_year = 0;
    }
    // parameterized constructor used to add a new record in add_game function
    Game(std::string n, std::string a, int y) : m_name(n.empty() ? "unknown" : n ), m_author(a.empty() ? "unknown" : a), m_year(y < 0 ? 0 : y){} 
    
    // setting the getters and setters
    std::string getN() const{
        return m_name;
    }
    std::string getA() const{
        return m_author;
    }
    int getY() const{
        return m_year;
    }
    void setN(std::string n){
        if(n.empty()){
            m_name = "unknown";
        }else{
            m_name = n;
        }
    }
    void setA(std::string a){
        if(a.empty()){
            m_author = "unknown";
        }else{
            m_author = a;
        }
    }
    void setY(int y){
        if(y <= 0){ 
            m_year = 0;
        }else{
            m_year = y;
        }
    }

    // method saving an object to file - i have to modify it
    void save_to_file(const std::string& filename) const {
        std::ofstream file(filename, std::ios::app); 
        if (file.is_open()) {
            file << m_name << ", " << m_author << ", " << m_year << "\n"; 
            file.close();
        } else {
            cout << "Could not open the file!" << endl;
        }
    }

    // method to display the created object
    void display_game() const{
        cout<< "Name:"<< m_name << ",Author:" << m_author << ",Year:"<< m_year <<"\n";
    }

    // method to remove a record from a database
    void remove_record(const std::string& filename, int linetoremove){
        std::ifstream inputFile(filename);
        std::ofstream tempFile("temp.txt");
        std::string line;
        int currentLine = 1;
        if(!inputFile.is_open() || !tempFile.is_open()){
            cout << "Could not open the file";
            return;
        }
        //  assign the contence without the line to delete
        while(std::getline(inputFile, line)){
            if(currentLine != linetoremove){
                tempFile << line << "\n";
            }
            currentLine++;
        }
        inputFile.close();
        tempFile.close();
        // overriting the original file with new contence
        std::remove(filename.c_str());
        std::rename("temp.txt", filename.c_str());
    }
    // Method to modify the value in a single record
    static void change_record(const std::string& filename, int lineNumber, const std::string& fieldToModify) {
        std::ifstream fileIn(filename); // opening the file to check
        if (!fileIn.is_open()) {
            cout <<"Could not open the file!" << endl;
            return;
        }

        std::vector<std::string> lines;
        std::string line;
        int currentLine = 1;

        // Reading the file to the vector 'lines' 
        while (std::getline(fileIn, line)) {
            lines.push_back(line);
        }
        fileIn.close();

        // We check if the number of the vector is in the apropriate range
        if (lineNumber <= 0 || lineNumber > static_cast<int>(lines.size())) {
            cout << "Wrong record line value. Exiting..." << endl;
            sleep(4);
            return;
        }

        // We take the line that we want to verify
        std::istringstream lineStream(lines[lineNumber - 1]);
        std::string currentName, currentAuthor;
        int currentYear;

        // Reading each value in the vector
        std::getline(lineStream, currentName, ',');
        std::getline(lineStream, currentAuthor, ',');
        lineStream >> currentYear;

        // Creating the object 'game' with the following values
        Game game;
        game.setN(currentName);
        game.setA(currentAuthor);
        game.setY(currentYear);

        // Collecting new data from the user
        if (fieldToModify == "name") {
            std::string newName;
            std::cout << "Enter the new game name: ";
            std::cin.ignore(); 
            std::getline(std::cin, newName);
            game.setN(newName);
        } else if (fieldToModify == "author") {
            std::string newAuthor;
            std::cout << "Enter the new author: ";
            std::cin.ignore(); 
            std::getline(std::cin, newAuthor);
            game.setA(newAuthor);
        } else if (fieldToModify == "year") {
            int newYear;
            std::cout << "Enter the new year: ";
            std::cin >> newYear;
            game.setY(newYear);
        } else {
            cout << "We don't have such field: " << fieldToModify << "Exiting..." << endl;
            return;
        }

        // Creating a new line with actual data
        std::ostringstream newLineStream;
        newLineStream << game.m_name << ", " << game.m_author << ", " << game.m_year;
        lines[lineNumber - 1] = newLineStream.str();

        // Saving the actualiazed data to the file
        std::ofstream fileOut(filename);
        if (!fileOut.is_open()) {
            cout << "Could not open the file!"<< endl;
            return;
        }
        for (const auto& outputLine : lines) {
            fileOut << outputLine << "\n";
        }
        fileOut.close();
        
        cout << "The record has been modified.Returning..." << endl;
        sleep(3);
    }
    }; 
}
