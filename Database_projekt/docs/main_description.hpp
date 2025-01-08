#ifndef MAIN_HPP
#define MAIN_HPP

/**
 *  Declarations for the main program functions.
 *  
 */

/**
 * Funtion used to show MariaDB-like view.
 * It is asking to choose user options. 
 */
void choose_user();

/**
 * Funtion used to create MariaDB-like view.
 * It is asking for activities which user can do with his database.
 */
void welcome(); 

/// Function is used to check if the user nickname already exists
bool contains();

/// Function is used to append the vector with the nicknames
void check();

/// Function is used to create a new user account in "All_users.txt"
void create_account();

/// Function is used to create a text file for a new user
void create_file();

/// Function showing the contence of a vector handling the users nicknames
void show_users();

/**
 * Function is used to check if the user's txt file is not empty.
 * The file is checked by reading the first char without skipping white spaces.
 * If the file is at the char is at the end the file is empty.
 */
bool is_empty();

/**
 * Funtion used to depict all games in the user's database.
 * It is simply reading out the contence of the user's text file.
 * It return also the number of the records inside the text file.
 * This functionality is used to keep on track of the file's size.
 */
int read_objects();

/**
 * Funtion used to add a new game into the user's database.
 * It asks the user if his sure that he wants to add a new game.
 * Next it adds a new game by collecting three values from the user.
 * The data is then used in parametrized constructor within the fucntion.
 * After that there are methods which are used to save the file into the file,
 * and display the contence.  
 */
void add_game();

int main();

#endif //MAIN_HPP