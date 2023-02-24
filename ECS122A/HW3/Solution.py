# Place your imports here

"""
Write a source code of the implementation of Divide and Conquer method of sorting a set of 20 positive integers in ascending order using (a) merge sort method, (b) quick sort method. There will be 7 test cases for each method and each test case worth 1 point. Please use the template to finish this question or you will get 0 point. 
"""
class Solution:
    def quickSort(self, unsortedArr):
        """
        requirements: Apply quick sort method to the unsorted list.

        input: An unsorted list, for example, [3,5,2,1]

        output: A sorted list in ascending order, for example, [1,2,3,5]
        """
        # insert your codes here
        self.quickSortHelper(unsortedArr, 0, len(unsortedArr)-1)
        # end here
        return unsortedArr

    def quickSortHelper(self, A, lo, hi):
        if (lo<hi):
            p = self.partition(A, lo, hi)
            self.quickSortHelper(A, lo, p-1)
            self.quickSortHelper(A, p+1, hi)

    def partition(self, A, lo, hi):
        p = A[hi]
        i = (lo-1)
        for j in range(lo, hi): 
            if (A[j] < p):
                i = i + 1
                A[i], A[j] = A[j], A[i]
        A[i+1], A[hi] = A[hi], A[i+1]
        return (i+1)

    def mergeSort(self, unsortedArr):
        """
        requirements: Apply quick sort method to the unsorted list.

        input: An unsorted list, for example, [3,5,2,1]

        output: A sorted list in ascending order, for example, [1,2,3,5]
        """
        # insert your codes here
        if (len(unsortedArr) > 1):
            B = unsortedArr[:len(unsortedArr)//2]
            C = unsortedArr[len(unsortedArr)//2:]
            self.mergeSort(B)
            self.mergeSort(C)
            self.merge(B,C,unsortedArr)
        # end here
        return unsortedArr

    def merge(self,B,C,A):
        i = 0
        j = 0
        k = 0
        p = len(B)
        q = len(C)
        while (i < p and j < q):
            if (B[i]<=C[j]):
                A[k] = B[i]
                i = i + 1
            else:
                A[k] = C[j]
                j = j + 1
            k = k + 1
        if (i==p):
            for l in range(q-j):
                A[k+l] = C[j+l]
        else:
            for l in range(p-i):
                A[k+l] = B[i+l]