#include <iostream>  // allows for the use of cout
#include <fstream>  // allows files to be read
#include <string> //allows for the use of string in the program
#include <vector> //allows for the use of vector in the program
#include "json.hpp" // allows the accessing of data in json files
using namespace std;  // allows for the use of functions without having to type std::

void openfile(ifstream& file, string filename) { //openfile is a function that opens a file and error checking if it exists
  file.open(filename); //open file
  if (!file) {  // checking if file exists
    std::cerr << "Error: cannot open file " << filename << std::endl;  // print error statement
    exit(1); //exit program due to error
  } //end of if statement
} //end of function

void read_dataset(vector<vector<int>>& samples, vector<string>& sample_keys, nlohmann::json data){ //read_dataset is a function that reads a json dataset and input the samples and keys into vectors
  for (auto itr = data.begin(); itr != std::prev(data.end()); ++itr) {  // iterate through all the samples in the json file
    vector<int> a_sample = data[itr.key()].get<vector<int>>();  // store each sample and its elements in a vector
    samples.push_back(a_sample);  // add the sample, consisting of an array of ints, to a vector of samples
    sample_keys.push_back(itr.key());  // save the key of the current sample by saving it to a vector of keys
  } //end of the for loop
}

int main(int argc, char** argv) { //main function with the parameters argument count and argument vector
  ifstream file1; //declaration of file1 for the first input json file
  ifstream file2; //declaration of file2 for the second input json file
  openfile(file1, argv[1]); //pass through file1 and first file name into openfile function
  openfile(file2, argv[2]); //pass through file2 and second file name into openfile function
  nlohmann::json data1 = nlohmann::json::parse(file1); //data1 is the json object that is converted from file1
  nlohmann::json data2 = nlohmann::json::parse(file2); //data2 is the json object that is converted from file2
  nlohmann::json output; //output is the json object that the program will print out at the end

  vector<vector<int>> samples1; //samples1 is a vector of vector of integers used to store all samples in file1 in the data
  vector<string> sample_keys1; //sample_keys1 is a vector of strings used to store all the sample keys in file1 in the data
  vector<vector<int>> samples2; //samples2 is a vector of vector of integers used to store all samples in file2 in the data
  vector<string> sample_keys2; //sample_keys2 is a vector of strings used to store all the sample keys in file2 in the data
  read_dataset(samples1, sample_keys1, data1);  // stores data1 in json file into vectors
  read_dataset(samples2, sample_keys2, data2); // stores data2 in json file into vectors

  int samplesWithConflictingResults = 0; //declaration of samplesWithConflictingResults that records the number of samples with conflicing results
  for (int i = 0; i < samples1.size(); i++){  // iterate through each sample
    int num_differences = 0;  // records the number of differences in each sample
    for (int j=0; j<samples1[i].size(); j++) {  // iterate through each element in a sample
      if (samples1[i][j] != samples2[i][j]) {  // compares the current element in file1 with file2
        num_differences++;  // increase the counter for the number of inversions
        output[sample_keys1[i]]["Mismatches"][std::to_string(j)] = {samples1[i][j], samples2[i][j]};  // adds the current mismatch case to the json
        output[sample_keys1[i]][argv[1]] = samples1[i];  //add the origin sample that has conflicting results in file1 to the json
        output[sample_keys1[i]][argv[2]] = samples2[i];  //add the origin sample that has conflicting results in file2 to the json
      }// end of if statement
    }// end of the inner for loop
    if (num_differences > 0 ) { //if statement to check if the number of differences is greater than zero
      samplesWithConflictingResults++; //increment samplesWithConflictingResults by one
    } //end of if statement
  } // end of the outer for loop

  output["metadata"]["File1"]["name"] = argv[1]; //record the file name of file1 in the output metadata
  output["metadata"]["File1"]["arraySize"] = samples1[0].size();  //record the file size of file1 in the output metadata
  output["metadata"]["File1"]["numSamples"] = samples1.size(); //record the sample size of file1 in the output metadata
  output["metadata"]["File2"]["name"] = argv[2]; //record the file name of file2 in the output metadata
  output["metadata"]["File2"]["arraySize"] = samples2[0].size();  //record the file size of file2 in the output metadata
  output["metadata"]["File2"]["numSamples"] = samples2.size(); //record the sample size of file2 in the output metadata
  output["metadata"]["samplesWithConflictingResults"] = samplesWithConflictingResults; //record the number of samples with conflicting results in the output metadata
  cout << output.dump(2) << endl; //print out the output json object with dump processed format
}// end of main function
