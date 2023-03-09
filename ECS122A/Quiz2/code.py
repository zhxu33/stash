def quickSort(A, lo, hi):
  if (lo<hi):
    p = partition(A, lo, hi)
    quickSort(A, lo, p-1)
    quickSort(A, p+1, hi)
  return A

def hybridQuickSort(A, lo, hi):
  if (hi-lo) < 10:
    insertionSort(A, lo, hi)
  elif (lo<hi):
    p = partition(A, lo, hi)
    hybridQuickSort(A, lo, p-1)
    hybridQuickSort(A, p+1, hi)
  return A

def partition(A, lo, hi):
  p = A[hi]
  i = (lo-1)
  for j in range(lo, hi): 
      if (A[j] < p):
          i = i + 1
          A[i], A[j] = A[j], A[i]
  A[i+1], A[hi] = A[hi], A[i+1]
  return (i+1)

def insertionSort(A, lo, hi):
  for j in range(lo+1, hi+1):
    i = j 
    while (A[i-1] > A[i] and i > 0 ):
        A[i-1], A[i] = A[i], A[i-1]
        i=i-1
  return A

arr = [20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1]
arr2 = [30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1]
print("20 items: ", hybridQuickSort(arr, 0, len(arr)-1))
print("30 items: ", hybridQuickSort(arr2, 0, len(arr2)-1))