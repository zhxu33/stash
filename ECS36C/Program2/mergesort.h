// Merge Sort
//
// Author: Rob Gysel
// ECS60, UC Davis
// Adapted from: Lysecky & Vahid "Data Structures Essentials", zyBooks

#include <vector>

void MergeSort(std::vector<int>* numbers, int& numComparisons, int& numMemoryAccess, double& mergeSortTime);
void MergeSortRecurse(std::vector<int>* numbers, int i, int k, int& numComparisons, int& numMemoryAccess);
void Merge(std::vector<int>* numbers, int i, int j, int k, int& numComparisons, int& numMemoryAccess);
