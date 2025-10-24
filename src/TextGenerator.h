#ifndef TEXTGENERATOR_H
#define TEXTGENERATOR_H

#include "LanguageModel.h"
#include <string>

using namespace std;

class TextGenerator {
public:
    TextGenerator(LanguageModel& model);
    string generate(int length);
private:
    LanguageModel& model;
};

#endif
