#ifndef CS456LAB2_MAIN_H
#define CS456LAB2_MAIN_H

#include <iostream>
#include <fstream>

int checkFileValidity(std::string file_location); // checks if file is in appropriate format, returns number of attributes
double** createDataset(std::string file_location, int num_attr); // creates the dataset from given information

void regression (double ** data_set, int num_attr); // primary output is over text console, no real return
double RMSE(double * predicted, double * actual, int num_vals); // determines general RMSE from a set of given and predicted values of length num_vals

#endif //CS456LAB2_MAIN_H
