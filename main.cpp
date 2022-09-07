#include <iostream>
#include "FileFunction.h"

using namespace std;

int main() {

    string filePath;
    cout << "Hello, this function will help provide some insight about a file you put here." << endl;
    cout << "Please enter the path to the file you would like to analyze: ";

    // Get the file path from the user
    // getline(), so we can use spaces in the path
    getline(cin, filePath);
    cout << endl << endl << endl;

    // Print File Information
    cout << "Thank you. Now we will analyze your file." << endl;
    cout << "File Name/Location: " << filePath << endl;
    cout << "File Extension: " << getFileExtension(filePath) << endl;
    cout << "File Size: " << getFileSize(filePath) << endl;
    cout << "Word Count: " << countWordsInFile(filePath) << endl;
    cout << "Line Count: " << countLinesInFile(filePath) << endl;
    getWordFrequency(filePath);

    return 0;
}
