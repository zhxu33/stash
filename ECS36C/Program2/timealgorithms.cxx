#include <iostream>  // allows for the use of cout
#include <fstream>  // allows files to be read and written
#include <string> //allows for the use of string in the program
#include <vector> //allows for the use of vector in the program
#include <ctime>  // allows runtime to be calculated
#include "quicksort.h" //allows quicksort functions to be used
#include "mergesort.h" //allows mergesort functions to be used
#include "insertionsort.h" //allows insertionsort functions to be used
#include "json.hpp" // allows the accessing of data in json files
using namespace std;  // allows for the use of functions without having to type std::

int main(int argc, char** argv) { //main function with the parameters argument count and argument vector
  ifstream file; //declaration of file for the input json file
  file.open(argv[1]); //open the file that was given in the first command line argument
  if (!file) {  // checking if file exists
    std::cerr << "Error: cannot open file " << argv[1] << std::endl;  // print error statement
    exit(1); //exit program due to error
  } //end of if statement
  nlohmann::json data = nlohmann::json::parse(file); //data is the json object that is converted from file
  vector<vector<int>> samples; //samples is a vector of vector of integers used to store all samples in the data
  vector<string> sample_keys; //sample_keys is a vector of strings used to store all the sample keys in the data
  for (auto itr = data.begin(); itr != std::prev(data.end()); ++itr) {  // iterate through all the samples in the json file
    vector<int> a_sample = data[itr.key()].get<vector<int>>();  // store each sample and its elements in a vector
    samples.push_back(a_sample);  // add the sample, consisting of an array of ints, to a vector of samples
    sample_keys.push_back(itr.key());  // save the key of the current sample by saving it to a vector of keys
  } //end of the for loop
  //calculate numComparisons/ numMemoryAccess for each sample
  ofstream output; //declare output for data to be written to
  output.open("output.csv");  // create csv file
  output << "Sample,InsertionSortTime,InsertionSortCompares,InsertionSortMemaccess,MergeSortTime,MergeSortCompares,MergeSortMemaccess,QuickSortTime,QuickSortCompares,QuickSortMemaccess" << endl;  // write line to output.csv
  for (int i = 0; i < samples.size(); i++){  // iterate through each sample
    int insertionSortComparisons = 0, insertionSortMemoryAccess = 0, mergeSortComparisons = 0, mergeSortMemoryAccess = 0, quickSortComparisons = 0, quickSortMemoryAccess = 0;  // declare variables to count numComparisons/ numMemoryAccess for each type of sort
    double insertionSortTime = 0, mergeSortTime = 0, quickSortTime = 0;  // declare variables to store runtime for different sorting algorithms
    vector<int> sample_copy1 = samples[i]; //create a copy of the vector that is being sorted for insertionsort
    vector<int> sample_copy2 = samples[i]; //create a copy of the vector that is being sorted for mergesort
    vector<int> sample_copy3 = samples[i]; //create a copy of the vector that is being sorted for quicksort
    InsertionSort(&sample_copy1, insertionSortComparisons, insertionSortMemoryAccess, insertionSortTime);  // sort vector with insertionsort
    MergeSort(&sample_copy2, mergeSortComparisons, mergeSortMemoryAccess, mergeSortTime); //sort vector with mergesort
    QuickSort(&sample_copy3, quickSortComparisons, quickSortMemoryAccess, quickSortTime); // sort vector with quicksort
    output << sample_keys[i] << "," << insertionSortTime << "," << insertionSortComparisons << "," << insertionSortMemoryAccess << "," << mergeSortTime << "," << mergeSortComparisons << "," << mergeSortMemoryAccess << "," << quickSortTime << "," << quickSortComparisons << "," << quickSortMemoryAccess << endl;
    //write numComparisons, numMemoryAccess and runtime for each type of sort to output.csv
  }
  //printing csv files
  output.close();  // close output.csv
  ifstream output_file; //declare output_file to be printed to the console
  output_file.open("output.csv");  // open output.csv
  string line;  // stores a single line of output.csv at a time
  while (getline(output_file, line)) {  // get a line from output.csv and store it in variable line
    cout << line << endl; //print line to the console
  } //end of while loop
}// end of main function
