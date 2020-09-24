#include "main.h"

int main(int argc, char** argv) {
    if(argc != 2) {
        std::cout << "Error: Invalid Argument Count" << std::endl;
        return 1;
    }
    fileData file_data = getFileInfo(argv[1]);
    return 0;
}

fileData getFileInfo(std::string file_location) {
    fileData file_data{};
    // Check if file is a csv
    if(file_location.substr(file_location.length() - 4, file_location.length()) != ".csv"){
        std::cout << "Error: File is not a .csv" << std::endl;
        file_data._is_valid = false;
        return file_data;
    }
    // open file and test
    std::ifstream target_file;
    target_file.open(file_location);
    if (target_file.is_open()) {
        std::cout << "File accepted, reading now" << std::endl ;
    } else {
        std::cout << "Error: invalid file" << std::endl;
        file_data._is_valid = false;
        return file_data;
    }
    file_data._is_valid = true;

    std::string buffer;
    std::string tmp_str;
    file_data._num_rows = 0;
    getline(target_file, tmp_str, '\n'); // first row is a header
    file_data._num_attr = std::count(tmp_str.begin(), tmp_str.end(), ',');
    while(target_file >> buffer) {
        std::getline(target_file, tmp_str, '\n');
        file_data._num_rows++;
    }
    target_file.close();
    std::cout << "This dataset contains " << file_data._num_attr << " attributes and "  << file_data._num_rows<< std::endl;
    return file_data;
}

std::vector<double*> createDataset(std::string file_location, int num_attr, int num_rows) {
    std::vector<double*> data_set;
    std::ifstream target_file;
    target_file.open(file_location);

    for(int i = 0; i < num_attr + 1; i++) {

    }

    target_file.close();
    return data_set;
}


