//
// Created by Dakota on 8/31/2022.
//

#ifndef FILE_STATISTICS_FILEFUNCTION_H
#define FILE_STATISTICS_FILEFUNCTION_H

#include <vector>
#include <map>
#include <string>

using namespace std;

void getWordFrequency(string filePath);
int countWordsInFile(string filePath);
string getFileSize(string filePath);
int countLinesInFile(string filePath);
string getFileExtension(string filePath);

#endif //FILE_STATISTICS_FILEFUNCTION_H
