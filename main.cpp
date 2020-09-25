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
    std::vector<double> actual_vals;
    createDataset(argv[1], num_attr, &actual_vals);

    std::cout << "RMSE of actual values against themselves is " << RMSE(actual_vals, actual_vals);
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

std::vector<double *> createDataset(std::string file_location, int num_attr, std::vector<double>* actual_vals_ptr) {
    std::vector<double *> data_set;
    actual_vals_ptr = new std::vector<double>();
    std::ifstream target_file;
    target_file.open(file_location);

    std::string buffer;
    std::string tmp_str;
    getline(target_file, tmp_str, '\n'); // first row is a header
    while(target_file >> buffer) {
        double* new_row = new double [num_attr]();
        std::stringstream stream(buffer);
        // iterate through stream to fetch all values
        for(int i = 0; i < num_attr; i++) {
            getline(stream, tmp_str, ',');
            new_row[i] = atof(tmp_str.c_str());
        }
        // fetch actual result
        getline(stream, tmp_str, '\n');
        actual_vals_ptr->push_back(atof(tmp_str.c_str()));
        data_set.push_back(new_row);
    }
    std::cout << "read " << data_set.size() << " lines of data into dataset" << std::endl;
    target_file.close();
    return data_set;
}

const double RMSE(std::vector<double> predicted, std::vector<double> actual) {
    double sum_of_error_squares = 0;
    for(int i = 0; i < predicted.size(); i++) {
        double error = predicted[i] - actual[i];
        sum_of_error_squares += pow(error, 2);
    }
    double mean_of_error_squares = sum_of_error_squares / predicted.size();
    double rmse = sqrt(mean_of_error_squares);
    return rmse;
}



