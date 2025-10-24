#include "LanguageModel.h"
#include "TextGenerator.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 4) {
        cerr << "Usage: slm <k> <training_file> <length>\n";
        return 1;
    }

    int k = stoi(argv[1]);
    string filename = argv[2];
    int length = stoi(argv[3]);

    LanguageModel model(k);
    model.train(filename);
    
    TextGenerator generator(model);
    string result = generator.generate(length);
    cout << result << endl;

    return 0;
}
