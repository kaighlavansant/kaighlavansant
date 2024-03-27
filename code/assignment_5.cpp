
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

int main(){

    string filename;
    ifstream iFile;

    while(true){
        cout << "Enter a file name"
        cout << "**";
        getline(cin, filename);

        // error message if the file is an invalid file
       if (iFile.fail()){
        iFile.clear();
        iFile.ignore();
        cout <<"Error: Invalid filename";
       }
    }

}