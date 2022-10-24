#include <iostream>  // allows for the use of cout
#include <fstream>  // allows files to be read
#include <string> //allows for the use of string in the program
#include <vector> //allows for the use of vector in the program
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
  nlohmann::json output; //output is the json object that the program will print out at the end
  vector<vector<int>> samples; //samples is a vector of vector of integers used to store all samples in the data
  vector<string> sample_keys; //sample_keys is a vector of strings used to store all the sample keys in the data
  for (auto itr = data.begin(); itr != std::prev(data.end()); ++itr) {  // iterate through all the samples in the json file
    vector<int> a_sample = data[itr.key()].get<vector<int>>();  // store each sample and its elements in a vector
    samples.push_back(a_sample);  // add the sample, consisting of an array of ints, to a vector of samples
    sample_keys.push_back(itr.key());  // save the key of the current sample by saving it to a vector of keys
  } //end of the for loop
  int samplesWithInversions = 0; //sampleWithInversions is the counter that records  the number of samples with inversions in the data
  for (int i = 0; i < samples.size(); i++){  // iterate through each sample
    int num_inversions = 0;  // counts the number of inversions
    for (int j=0; j<samples[i].size()-1; j++) {  // iterate through each element in a sample, until the second last element
      if (samples[i][j] > samples[i][j+1]) {  // compares the current element to the next element to see if there is a consecutive inversion
        num_inversions++;  // increase the counter for the number of inversions
        output[sample_keys[i]]["ConsecutiveInversions"][std::to_string(j)] = {samples[i][j], samples[i][j+1]};  // adds the current case of consecutive inversion to the json
        output[sample_keys[i]]["sample"] = samples[i]; //add the origin sample that has inversions to the json
      }// end of if statement
    }// end of the inner for loop
    if (num_inversions > 0 ) { //if statement to check if the number of inversions is greater than zero
      samplesWithInversions++; //increment sampleWithInversions by one
    } //end of if statement
  } // end of the outer for loop
  output["metadata"]["arraySize"] = samples[0].size();  //record the file size in the output metadata
  output["metadata"]["file"] = argv[1]; //record the file name in the output metadata
  output["metadata"]["numSamples"] = samples.size(); //record the sample size in the output metadata
  output["metadata"]["samplesWithInversions"] = samplesWithInversions; //record the number of samples with inversions in the output metadata
  cout << output.dump(2) << endl; //print out the output json object with dump processed format
}// end of main function
