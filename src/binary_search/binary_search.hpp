#ifndef BINARY_SEARCH_HPP
#define BINARY_SEARCH_HPP

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

void printArray(vector <float> arr, int n);
float binarySearch(vector <float> arr, int low, int high, float search);
void insertAndSearchElementsWithBinarySearch(string textFile);

#endif