#include <iostream>

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: slm <k> <training_file> <length>\n";
        return 1;
    }

    return 0;
}