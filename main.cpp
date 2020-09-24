#include "main.h"

int main(int argc, char** argv) {
    std::ifstream target_file;
    // check argument count
    if(argc != 2) {
        std::cout << "Error: Invalid Argument Count" << std::endl;
        return 1;
    }
    // Check if file is a csv
    std::string to_process = argv[1];
    if(to_process.substr(to_process.length() - 4, to_process.length()) != ".csv"){
        std::cout << "Error: File is not a .csv" << std::endl;
        return 1;
    }
    // open file and test
    target_file.open(argv[1]);
    if (target_file.is_open()) {
        std::cout << "File accepted, reading now" << std::endl ;
    } else {
        std::cout << "Error: invalid file" << std::endl;
        return 1;
    }
    return 0;
}
