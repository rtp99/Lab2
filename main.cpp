#include "main.h"

int main(int argc, char** argv) {
    if(argc != 2) {
        std::cout << "Error: Invalid Argument Count" << std::endl;
        return 1;
    }
    int num_attr = checkFileValidity(argv[1]);
    return 0;
}

int checkFileValidity(std::string file_location) {
    // Check if file is a csv
    if(file_location.substr(file_location.length() - 4, file_location.length()) != ".csv"){
        std::cout << "Error: File is not a .csv" << std::endl;
        return 1;
    }
    // open file and test
    std::ifstream target_file;
    target_file.open(file_location);
    if (target_file.is_open()) {
        std::cout << "File accepted, reading now" << std::endl ;
    } else {
        std::cout << "Error: invalid file" << std::endl;
        return 1;
    }

    std::string tmp_str;
    getline(target_file, tmp_str, '\n'); // first row is a header
    getline(target_file, tmp_str, '\n');
    int num_attr = std::count(tmp_str.begin(), tmp_str.end(), ',');
    target_file.close();
    std::cout << "This dataset contains " << num_attr << " attributes" << std::endl;
    return num_attr;
}

double **createDataset(std::string file_location, int num_attr) {
    std::ifstream target_file;
    target_file.open(file_location);



    return nullptr;
}

