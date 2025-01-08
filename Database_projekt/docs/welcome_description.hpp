#ifndef WELCOME_HPP
#define WELCOME_HPP




/// @brief  Namespace for the application.
namespace an{

/**! Represents a game.
 *
 * This class provides methods to manage game records, including adding,
 * modyfing, saving and removing game entries.
 * 
 */

class Game{
private:
    std::string m_name; /**< Name of the game.*/
    std::string m_author; /** < Author of the game. */
    int m_year{}; /** < Year of the game's release.*/
public:
    /**
     * @brief Default constructor.
     *
     * Initializes the game with default values: "unknown" for name and author, and 0 for year.
     */
    Game();
    /**
     * @brief Parameterized constructor.
     *
     * @param n Name of the game.
     * @param a Author of the game.
     * @param y Year of the game's release.
     *
     * If the name or author is empty, they default to "unknown". If the year is less than 0, it defaults to 0.
     */
    Game(std::string n, std::string a, int y)  
    
    /**
     * @brief Gets the name of the game.
     * @return The name of the game.
     */
    std::string getN() const;

    /**
     * @brief Gets the author of the game.
     * @return The author of the game.
     */
    std::string getA() const;

    /**
     * @brief Gets the release year of the game.
     * @return The release year of the game.
     */
    int getY() const;
 
    /**
     * @brief Sets the name of the game.
     * @param n New name of the game.
     *
     * If the name is empty, it defaults to "unknown".
     */
    void setN(std::string n);

    /**
     * @brief Sets the author of the game.
     * @param a New author of the game.
     *
     * If the author is empty, it defaults to "unknown".
     */
    void setA(std::string a);

    /**
     * @brief Sets the release year of the game.
     * @param y New release year of the game.
     *
     * If the year is less than or equal to 0, it defaults to 0.
     */
    void setY(int y);

    /**
     * @brief Saves the game record to a file.
     * @param filename Name of the file to save the game record.
     *
     * Appends the game record to the specified file. Displays an error message if the file cannot be opened.
     */
    void save_to_file(const std::string& filename) const;

    /**
     * @brief Displays the game record in the console.
     */
    void display_game() const;

    /**
     * @brief Removes a specific record from a file.
     * @param filename Name of the file containing the records.
     * @param linetoremove Line number of the record to remove.
     *
     * Deletes the specified line from the file. If the file cannot be opened, displays an error message.
     */
    void remove_record(const std::string& filename, int linetoremove);
       
    /**
     * @brief Modifies a specific field in a record within a file.
     * @param filename Name of the file containing the records.
     * @param lineNumber Line number of the record to modify.
     * @param fieldToModify Field to modify: "name", "author", or "year".
     *
     * Updates the specified field of the record at the given line number in the file. If the file cannot
     * be opened or the line number is invalid, displays an error message.
     */
    static void change_record(const std::string& filename, int lineNumber, const std::string& fieldToModify);
    }; 
} // namespace an

#endif // WELCOME_HPP