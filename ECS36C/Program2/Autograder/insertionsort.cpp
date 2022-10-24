// Insertion Sort
//
// Author: Rob Gysel
// ECS60, UC Davis
// Adapted from: Lysecky & Vahid "Data Structures Essentials", zyBooks

#include "insertionsort.h"
#include <ctime>

void InsertionSort(std::vector<int>* numbers, int& numComparisons, int& numMemoryAccess, double& insertionSortTime) {
   int i = 0;
   int j = 0;
   int temp = 0;  // Temporary variable for swap
   clock_t runtime = clock();
   for (i = 1; i < numbers->size(); ++i) {
      j = i;
      // Insert numbers[i] into sorted part
      // stopping once numbers[i] in correct position
      while (j > 0 && (*numbers)[j] < (*numbers)[j - 1]) {
         numComparisons ++;
         // Swap numbers[j] and numbers[j - 1]
         temp = (*numbers)[j];
         (*numbers)[j] = (*numbers)[j - 1];
         (*numbers)[j - 1] = temp;
         --j;
         numMemoryAccess += 6;
      }
      if (j > 0) {
         numMemoryAccess+=2;
         numComparisons++;
      }
   }
   runtime = clock() - runtime;
   insertionSortTime = (double)runtime/CLOCKS_PER_SEC;
   return;
} //./timealgorithms TestCase99.json
