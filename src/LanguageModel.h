#ifndef LANGUAGEMODEL_H
#define LANGUAGEMODEL_H

#include <string>
#include <map>
#include <vector>
#include <random>

using namespace std;

class LanguageModel {
public:
    int k;
    string generate(int length);
    string getRandomW() const;
    void train(const string& filename);
    char getNextChar(const string& w) const;

    LanguageModel(int k);

private:
    string text;
    map<string, map<char, int>> freq;
    map<string, int> total;
    mutable mt19937 gen;

    void buildModel();
};

#endif
