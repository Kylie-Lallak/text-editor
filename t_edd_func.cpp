#include <iostream>
#include <fstream>
using namespace std;
#include "t_edd.hpp"

//prints the contents of the file
void print_file(string filename){
    fstream myFile; 
    myFile.open(filename, ios::in); //open in read mode
    cout << "\nFile: \n";
    if(myFile.is_open()){
        string line;
        while(getline(myFile, line)){
            cout << line << "\n";
        }
    }
    myFile.close();
}

//adds the users input to the file
void write_file(string filename, string add){
    fstream myFile;
    myFile.open(filename, ios::app); // open in append mode

    if(myFile.is_open())
    {
        myFile << add;
        myFile << " "; // adds a space between user entrys
    }
    myFile.close();
}

//removes a word user entered word from the file
void remove_line(std::string filename, std::string remove)
{
    string copy;
    fstream myFile; 
    myFile.open(filename, ios::in); //open in read mode
    cout << "\n File: \n";
    //copys file into string
    if(myFile.is_open()){
        string line;
        while(getline(myFile, line)){
            copy += line;
        }
    }

    int index = copy.find(remove); //gets index of removed word

    //creates string called copy, has removed word taken out
    if(index != string::npos){
        string substr1 = copy.substr(0, index);
        string substr2 = copy.substr(index + remove.length());
        copy = substr1;
        copy.append(substr2);

        restart(filename); // clears file
        write_file(filename, copy); // adds text to file without the revmoed word 
    }
    myFile.close();
}

//overides file with empty string
void restart(std::string filename)
{
    fstream myFile;
    myFile.open(filename, ios::out);
    myFile << "";
    myFile.close();
}