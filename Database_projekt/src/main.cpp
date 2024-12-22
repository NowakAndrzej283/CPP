#include <iostream>
#include <fstream> // to read/write text from a textfile 
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <unistd.h> // this is for sleep function 
#include <limits>
#include "welcome.hpp"

using std::cout, std::cin, std::endl;
std::vector<std::string> user_nick; // here i declare a global variable

void choose_user(){
    // Initializing the MariaDB-like welcome variables
    std::string first {"+----------------------------+"};
    std::string block {"|"};
    std::string five_spaces{"     "}; 

    cout << first << endl;
    cout << block << "Database of Video Games" + five_spaces << block << endl;
    cout << first << endl;
    cout << block << "Welcome to our database" + five_spaces << block << endl;
    cout << block << "Choose activity:  " + five_spaces + five_spaces << block << endl;
    cout << block << "(1) Create user   " + five_spaces + five_spaces << block << endl;
    cout << block << "(2) Show users    " + five_spaces + five_spaces << block << endl;
    cout << block << "(3) Choose user   " + five_spaces + five_spaces << block << endl;
    cout << block << "(*) Quit          " + five_spaces + five_spaces << block << endl;
    cout << first << endl;
    cout << ">";
}    
void welcome(){
    // Initializing the MariaDB-like welcome variables
    std::string first {"+----------------------------+"};
    std::string block {"|"};
    std::string five_spaces{"     "}; 

    cout << first << endl;
    cout << block << "Database of Video Games" + five_spaces << block << endl;
    cout << first << endl;
    cout << block << "Welcome to our database" + five_spaces << block << endl;
    cout << block << "Choose activity:  " + five_spaces + five_spaces << block << endl;
    cout << block << "(1) Display all records" + five_spaces << block << endl;
    cout << block << "(2) Add a new game     " + five_spaces << block << endl;
    cout << block << "(3) Remove game   " + five_spaces + five_spaces << block << endl;
    cout << block << "(4) Modify record " + five_spaces + five_spaces << block << endl;
    cout << block << "(*) Quit          " + five_spaces + five_spaces  << block << endl;
    cout << first << endl;
}
bool contains(std::vector<std::string>& vec, std::string nick){
    for( std::string element : vec){
        if(element == nick){
            return true;
        }
    }
    return false;
}
    
void check(){
    std::ifstream FileOpen("All_users.txt");
    if(FileOpen.is_open()){
        std::string line;
        while(getline(FileOpen, line)){   
            user_nick.push_back(line);
        }
        FileOpen.close();
    }
}
void create_account(std::string nickname){
    std::ofstream Creating;
    Creating.open("All_users.txt", std::ios::app);
    if(Creating.is_open()){
        cout<< "###########\n";
        Creating << nickname << "\n";
        Creating.close();
    }
}
void create_file(std::string nickname){
    std::string new_nickname = nickname  + ".txt";
    std::ofstream File;
    File.open(new_nickname);
    if(File.is_open()){
        cout << "Switching to "<< nickname <<"...";
        File.close();    
    }
}
void show_users(){
    for(int j = 0; j < user_nick.size(); j++){
        cout << user_nick[j] << endl;
    }
}
bool is_empty(std::string path){
    std::ifstream file(path);
    if(file.is_open()){
        char c;
        file >> std::noskipws >> c; // read the first char without skipping anything
        return file.eof(); // if the file is at the end it is empty
    }
    return false; // if the file doesnt exists or we are not able to open it
}
int read_objects(const std::string& filename){
    std::ifstream inFile(filename);
    std::string first {"+----------------------------+"};
    std::string line;
    int i = 1;
    if(inFile.is_open()){
        std::system("clear");
        cout << first << "\n";
        cout << "All games:" << endl;
        cout << first << "\n";
        while(getline(inFile, line)){
            cout<< i << ". " << line << endl;
            i++;
        }
        inFile.close();
    }
    return i;
}
void add_game(std::string path){
    char choice;
    std::string name, author;
    int year;
    bool exitWhile = true;
    while(exitWhile){
        cout << "Are you sure you want to add a new game?(y/n)"<<endl;
        cin >> choice;
        if(choice == 'y' || choice == 'Y'){
            // Collecting the data
            cout << "Enter the name: ";
            cin.ignore();
            std::getline(cin, name);

            cout << "Enter the author: ";
            std::getline(cin, author);

            cout << "Enter the year of production: ";
            cin >> year;
            
            // Here i use a parametrized constructor to add a new object to the file
            an::Game newGame(name, author, year);
            newGame.save_to_file(path);
            cout << "You have added a new record with the following values:" << endl;
            sleep(1);
            newGame.display_game();
            sleep(4);
            exitWhile = false;
        }if(choice == 'n' || choice == 'N'){
            cout << "Exiting...";
            sleep(3);
            exitWhile = false;
        }else{
            cout << "Try again.\n";
        }
    }
}



int main(){
    // The check() function is opening the file "All_users.txt" an adding the users to the global vector 
    check();
    int value_user{};
    std::string nickname;
    bool exitLoop = false; //here i want my switch case to be looped

    while(!exitLoop){
        choose_user();
        cin >> value_user;
        switch(value_user){
            case 1:
                // Create user
                cout << "Enter the name nickname of a user: ";
                cin >> nickname;
                if(contains(user_nick, nickname)){
                    cout<<"The user " << nickname << " already exists. Returning..." << endl;
                    sleep(3);
                    std::system("clear");
                }else{
                    cout << "Creating a new account for "<< nickname << "..." << endl;
                    create_account(nickname);
                    create_file(nickname);
                    exitLoop = true;
                    cout << "\nTab enter to continue.";
                    cin.ignore();
                    cin.get();
                }
                break;
            case 2:
                // Show users
                std::system("clear");
                cout << "The database contence of users: " << endl;
                show_users();
                cout << "\nHit enter to return.";
                cin.ignore();
                cin.get();
                std::system("clear");
                break;
            case 3:
                // Choose users
                cout << "Enter the name nickname of a user: ";
                cin >> nickname;
                if(contains(user_nick, nickname)){
                    cout<<"Switching to user " << nickname << "..." << endl;
                    sleep(2);
                    exitLoop = true;
                    break;
                }else{
                    cout << "We don't have user called "<< nickname << ". Returning..." << endl;
                    sleep(2);
                    std::system("clear");
                    break;
                }
            default:
                // Quit
                cout << "See you soon. Exiting...";
                return 0;
                break;
        }
    }
    std::string path = nickname + ".txt";
    
    exitLoop = false;
    while(!exitLoop){
        std::system("clear");
        welcome();
        bool exit = false;
        int value_activity {}; // i initialize a value which is going to contain what i want to do
        cout << nickname + ">"; // just to make it look like mariadb-like
        cin >> value_activity;
        switch(value_activity){
            case 1:
                //Show all games
                if(is_empty(path)){
                    cout << "The file is empty. Returning..." << endl;
                    sleep(3);
                    std::system("clear");
                    break;
                }
                else{
                // it shows the contence of a file
                    read_objects(path);
                    cout << "\n#To return press enter.";
                    cin.ignore();
                    cin.get();
                }
                break;
            case 2:
                // Add a new game
                add_game(path);
                break;
            case 3:
                //Remove a game
                if(is_empty(path)){
                    cout << "The file is empty. Returning..." << endl;
                    sleep(3);
                    std::system("clear");
                    break;
                }
                else{
                // it shows the contence of a file
                    an::Game gamer;
                    int lineNumber{};
                    read_objects(path);
                    cout << "\n#Choose the number of a record you want to delete.";
                    cin >> lineNumber;
                    if(lineNumber > 0 && lineNumber < read_objects(path)){ // here i have to find the apropriate range 
                        gamer.remove_record(path, lineNumber);
                        std::system("clear");
                        cout << "Deleting the record number "<< lineNumber << "...";
                        sleep(3);
                    }else{
                        std::system("clear");
                        cout << "Wrong record line value. Exiting...";
                        sleep(3);
                    }
                }
                break;
            case 4:
                // Modify record
                char choice;
                exit = true;
                while(exit){
                    cout << "Are you sure you want to modify a record?(y/n)"<< endl;
                    cin >> choice;
                    if(choice == 'y' || choice == 'Y'){
                    // Collecting the data
                        int lineNumber;
                        std::string fieldToModify;

                        cout << "Enter the line of the record : ";
                        cin >> lineNumber;
                        cout << "Enter which value you want to change(name/author/year): ";
                        cin >> fieldToModify;

                        an::Game::change_record(path, lineNumber, fieldToModify);  
                        exit = false; 
                    }
                    if(choice == 'n' || choice == 'N'){
                        cout << "Exiting...";
                        sleep(3);
                        exit = false;
                    }else{
                        cout << "Try again.\n";
                    }
                }
                break;
                
            default:
                //Quit
                cout << "Goodbye " + nickname + ". Exiting the database...";
                exitLoop = true;
                break;
        }
    }
    return 0;

}
