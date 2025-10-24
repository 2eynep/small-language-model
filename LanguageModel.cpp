#include "LanguageModel.h"
#include <fstream>
#include <stdexcept>
#include <random>
#include <iterator>
#include <algorithm>

using namespace std;

LanguageModel::LanguageModel(int k) : k(k), gen(random_device{}()) {}

void LanguageModel::train(const string& filename) {
    ifstream in(filename);
    if (!in) throw runtime_error("Cannot open file");
    text.assign((istreambuf_iterator<char>(in)), istreambuf_iterator<char>());
    buildModel();
}

void LanguageModel::buildModel() {
    for (size_t i = 0; i + k < text.size(); ++i) {
        string w = text.substr(i, k);
        char next = text[i + k];
        freq[w][next]++;
        total[w]++;
    }
}

string LanguageModel::getRandomW() const {
    if (total.empty()) throw runtime_error("Model not trained");
    uniform_int_distribution<size_t> dist(0, total.size() - 1);
    auto c = total.begin();
    advance(c, dist(gen));
    return c->first;
}

char LanguageModel::getNextChar(const string& w) const {
    auto c = freq.find(w);
    if (c == freq.end()) return ' ';

    int sum = total.at(w);
    uniform_int_distribution<int> dist(1, sum);
    int r = dist(gen);

    int cumulative = 0;
    for (auto &p : c->second) {
        cumulative += p.second;
        if (r <= cumulative) return p.first;
    }
    return ' ';
}
