#include "main.h"

int main(int argc, char** argv) {
    if(argc != 2) {
        std::cout << "Error: Invalid Argument Count" << std::endl;
        return 1;
    }
    int num_attr = getFileInfo(argv[1]);
    if(num_attr == 0){
        return 0;
    }

    return 0;
}

int getFileInfo(std::string file_location) {
    // Check if file is a csv
    if(file_location.substr(file_location.length() - 4, file_location.length()) != ".csv"){
        std::cout << "Error: File is not a .csv" << std::endl;
        return 0;
    }
    // open file and test
    std::ifstream target_file;
    target_file.open(file_location);
    if (target_file.is_open()) {
        std::cout << "File accepted, reading now" << std::endl ;
    } else {
        std::cout << "Error: invalid file" << std::endl;
        return 0;
    }

    //get info
    std::string tmp_str;
    getline(target_file, tmp_str, '\n'); // first row is a header
    int num_attr = std::count(tmp_str.begin(), tmp_str.end(), ',');
    target_file.close();
    std::cout << "This dataset contains " << num_attr << " attributes" << std::endl;
    return num_attr;
}

std::vector<double *> createDataset(std::string file_location, int num_attr, int num_rows) {
    std::vector<double *> data_set;



    return data_set;
}



