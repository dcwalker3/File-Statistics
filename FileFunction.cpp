//
// Created by dakot on 8/31/2022.
//

#include "FileFunction.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

void printVector(vector<string> words) {
    for (int i = 0; i < words.size(); i++) {
        cout << words[i] << endl;
    }
}

// Function to get the file extension
string getFileExtension(string filePath) {
    string extension;
    int filePathLength = filePath.length();
    int extensionLength = 0;

    // Start at the end of the file path and work backwards
    // Stop once we reach a period.
    // Store that as the extensionLength
    for (int i = filePathLength - 1; i >= 0; i--) {
        if (filePath[i] == '.') {
            extensionLength = filePathLength - i;
            break;
        }
    }

    // Go from filePathLength to (filePathLength - fileExtensionLength)
    // and store each character in the extension string
    for (int i = 0; i < extensionLength; i++) {
        extension += filePath[filePathLength - extensionLength + i];
    }

    return extension;
}

// This function will figure out how many bytes are in a file
string getFileSize(string filePath){
    // Get the file size
    ifstream file(filePath);
    file.seekg(0, ios::end);
    int size = file.tellg();
    file.close();

    // Convert the size to human-readable format
    if(size < 1024){
        return to_string(size) + " bytes";
    } else if(size < 1048576){
        return to_string(size/1024) + "KB";
    } else if(size < 1073741824){
        return to_string(size/1048576) + "MB";
    } else {
        return to_string(size/1073741824) + "GB";
    }

}

// This function will count the number of lines in a file
int countLinesInFile(string filePath){
    ifstream file(filePath);
    string line;
    int count = 0;
    while (getline(file, line)) {
        count++;
    }
    file.close();
    return count;
}

// This function will count the number of words in a file
int countWordsInFile(string filePath){
    ifstream file(filePath);
    string line;

    int wordCount = 0;
    while (getline(file, line)) {
        istringstream iss(line);
        string word;
        while (iss >> word) {
            wordCount++;
        }
    }

    return wordCount;
}


// Find the highest frequency of a word in a file
map<string, int> findMostCommonWord(map<string, int> wordFrequency) {
    // Variable Initialization
    map<string, int> mostCommonWord;
    int highestFrequency = 0;

    // Create an iterator for the map
    map<string, int>::iterator iterate;

    // Loop through the map and find the highest frequency
    for (iterate = wordFrequency.begin(); iterate != wordFrequency.end(); iterate++) {
        // If value is the new highest value
        if (iterate->second > highestFrequency) {
            // Set the new highest value by clearing the map and adding the new value
            highestFrequency = iterate->second;
            mostCommonWord.clear();
            mostCommonWord.insert({iterate->first, iterate->second});
        }
        // If the values are the same
        else if (iterate->second == highestFrequency) {
            // Add the value to the map
            mostCommonWord.insert({iterate->first, iterate->second});
        }
    }

    return mostCommonWord;

}



// Find the lowest frequency of a word in a file
map<string, int> findLeastCommonWord(map<string, int> wordFrequency) {
    // Variable initialization
    map<string, int> leastCommonWord;
    int lowestFrequency = 0;

    // Create an iterator for the map
    map<string, int>::iterator iterate;

    // Set the lowest frequency to the first word in the map
    for (iterate = wordFrequency.begin(); iterate != wordFrequency.end(); iterate++) {
        lowestFrequency = iterate->second;
        leastCommonWord.insert({iterate->first, iterate->second});
        break;
    }

    // Iterate through the map and find the lowest frequency
    for (iterate = wordFrequency.begin(); iterate != wordFrequency.end(); iterate++) {
        // If the current word has a lower frequency than the lowest frequency, set the lowest frequency to the current word
        if (iterate->second < lowestFrequency) {
            // Reset the leastCommonWord map and make it
            // only the current least common word
            lowestFrequency = iterate->second;
            leastCommonWord.clear();
            leastCommonWord.insert({iterate->first, iterate->second});
        } else if (iterate->second == lowestFrequency) {
            // The values are equal, so add the current word
            leastCommonWord.insert({iterate->first, iterate->second});
        }
    }
    // Return the map of the least common words/word
    return leastCommonWord;

}

// Function to return all contents of a file
void getWordFrequency(string filePath){

    // Create file stream and open the file
    ifstream file(filePath);
    string line;

    map<string, int> wordFrequency;
    map<string, int> mostCommonWord;
    map<string, int> leastCommonWord;

    // Loop through the file and words
    while (getline(file, line)) {
        istringstream iss(line);
        string word;
        while (iss >> word) {
            // Add all words to the map
            // Increment its value by 1 so if
            // the word is just added, it will be 1
            wordFrequency[word]++;


        }
    }

    // Get the most common word
    mostCommonWord = findMostCommonWord(wordFrequency);
    // Get the least common word
    leastCommonWord = findLeastCommonWord(wordFrequency);

    // Print the most common word and the least common word
    cout << "Most common word: \'" << mostCommonWord.begin()->first << "\' with frequency: " << mostCommonWord.begin()->second << endl;
    cout << "Least common word: \'" << leastCommonWord.begin()->first << "\' with frequency: " << leastCommonWord.begin()->second << endl;
}