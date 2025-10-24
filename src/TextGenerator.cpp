#include "TextGenerator.h"

using namespace std;

TextGenerator::TextGenerator(LanguageModel& model) : model(model) {}

string TextGenerator::generate(int length) {
    string output = model.getRandomW();
    while ((int)output.size() < length) {
        string w = output.substr(output.size() - model.k, model.k);
        char next = model.getNextChar(w);
        output.push_back(next);
    }
    return output;
}
