#include <iostream>
#include <fstream>
#include <string>
#include "t_edd.hpp"
using namespace std;

int main(){

string filename; // name of file (can be created or opened)
fstream myFile; // file
bool contuine = true; // tells wether or not to contuine loop
string add; // string of what user wants to add to file
string remove; // string of what user wants removed from file

// intro/ get file name
cout << "\nWelcome to My Text Editor!\n";
cout << "\nYou will enter the name of the file you wish to open or create (if the file exsits it will be opened if not it will be created.\n";
cout << "Remeber to add .txt to the end of the file name!\n\nPlease enter file name: ";
cin >> filename; 
cout << "\n";

//checking if file can be opened
myFile.open(filename, ios::app); 
if(!myFile){
    cout << "Failed to open file, be sure the file name has .txt at the end.\n Closing program.\n";
    return 1; // exting if file can not be opened

}
myFile.close();

getline(cin, add);
// keep taking user commands until they type EXIT
while(contuine)
{ 
    print_file(filename);

    // // get user input , command or text to add to file
    cout << "\nPlease enter what you would like to add to the file (HELP for Help): \n";
    getline(cin, add);

    if(add == "HELP")
    {
        cout << "\nType EXIT to leave program\nType REMOVE to remove a word from a file\nType RESTART to clear file\n";
    }
    else if(add == "REMOVE")
    {
        cout << "Please enter the text you would like removed from the file: ";
        cin >> remove;
        remove_line(filename, remove);
    }
    else if(add == "RESTART")
    {
        cout << "Your file has been cleared.";
        restart(filename);
    }
    else if(add == "EXIT")
    {
        contuine = false;
    }
    else
    {
        write_file(filename, add);

    }

}

cout << "\nExiting Program\nGoodbye\n";
 return 0;

}
