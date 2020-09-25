#ifndef CS456LAB2_MAIN_H
#define CS456LAB2_MAIN_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>


int getFileInfo(std::string file_location); // checks if file is in appropriate format, returns number of attributes
std::vector<double*> createDataset(std::string file_location, int num_attr, std::vector<double>* actual_vals_ptr); // creates the dataset from given information

void regression (std::vector<double*> data_set, int num_attr); // primary output is over text console, no real return
const double RMSE(std::vector<double> predicted, std::vector<double> actual); // determines general RMSE from a set of given and predicted values of length num_vals

#endif //CS456LAB2_MAIN_H
