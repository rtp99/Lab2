#include "main.h"

int main(int argc, char** argv) {
    srand((unsigned) time(0));
    if(argc != 2) {
        std::cout << "Error: Invalid Argument Count" << std::endl;
        return 1;
    }
    int num_attr = getFileInfo(argv[1]);
    if(num_attr == 0){
        return 0;
    }
    std::vector<double> actual_vals;
    std::vector<double*> data_set = createDataset(argv[1], num_attr, &actual_vals);
    regression(data_set, actual_vals, num_attr);
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

void regression(std::vector<double *> data_set, std::vector<double> actual_vals, int num_attr) {
    // generate coefficient sets (array of 14 values from 0 to 1)
    std::vector<double *> coefficients = gen_coefficients(num_attr);
    // iterate through all the data with each coefficient set
    double best_rsme = DBL_MAX;
    double* best_co = nullptr;
    std::vector<double> best_predicted_vals;
    for(double* curr_co : coefficients) {
        std::vector<double> curr_predicted_vals;
        for(double* row : data_set) {
            double row_total = 0;
            for(int i = 0; i < num_attr; i++){
                // multiply each attribute in the row by its corresponding coefficient
                row_total += row[i] * curr_co[i];
            }
            // add them all together to get the predicted result, store in vector of predicted_vals
            curr_predicted_vals.push_back(row_total);
        }
            // calculate RMSE for current prediction set
        double curr_rmse = RMSE(curr_predicted_vals, actual_vals);
            // compare to previous highest RMSE
        if(curr_rmse < best_rsme) {
            // if smaller, set highest RMSE and save coefficients and predictions
            best_rsme = curr_rmse;
            best_co = curr_co;
            best_predicted_vals = curr_predicted_vals;
        }
            // if larger, trash the values
    }
    // print final coefficient set and its RMSE

    std::cout << "Final coefficient set is: " << std::endl;
    for(int i = 0; i < num_attr; i++) {
        std::cout << best_co[i] << ", ";
    }
    std::cout << std::endl;
    std::cout << "Which produced an RMSE of: " << best_rsme << std::endl;
}

std::vector<double *> gen_coefficients(int num_attr) {
    std::vector<double *> coefficients;
    for(int i = 0; i < 100 ; i ++) {
        double* new_row = new double [num_attr]();
        for(int j = 0; j < num_attr; j++) {
            new_row[j] = 2 + (rand() / (double)RAND_MAX) * (-2);
        }
        coefficients.push_back(new_row);
    }
    return coefficients;
}



