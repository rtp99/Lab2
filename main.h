#ifndef CS456LAB2_MAIN_H
#define CS456LAB2_MAIN_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

struct fileData {
    bool _is_valid;
    int _num_attr;
    int _num_rows;
};

fileData getFileInfo(std::string file_location); // checks if file is in appropriate format, returns number of attributes
std::vector<double*> createDataset(std::string file_location, int num_attr, int num_rows); // creates the dataset from given information

void regression (std::vector<double*> data_set, int num_attr, int num_rows); // primary output is over text console, no real return
double RMSE(double * predicted, double * actual, int num_vals); // determines general RMSE from a set of given and predicted values of length num_vals

#endif //CS456LAB2_MAIN_H
