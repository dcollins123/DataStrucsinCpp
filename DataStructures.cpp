//Binary search algorithm.
BinarySearch(numbers, numbersSize, key) {
   mid = 0
   low = 0
   high = numbersSize - 1
   
   while (high >= low) {
      mid = (high + low) / 2
      if (numbers[mid] < key) {
         low = mid + 1
      }
      else if (numbers[mid] > key) {
         high = mid - 1
      }
      else {
         return mid
      }
   }
   
   return -1 // not found
}

main() {
   numbers = { 2, 4, 7, 10, 11, 32, 45, 87 }
   NUMBERS_SIZE = 8
   i = 0
   key = 0
   keyIndex = 0
   
   print("NUMBERS: ")
   for (i = 0; i < NUMBERS_SIZE; ++i) {
      print(numbers[i] + " ")
   }
   printLine()
   
   print("Enter a value: ")
   key = getIntFromUser()
   
   keyIndex = BinarySearch(numbers, NUMBERS_SIZE, key)
   
   if (keyIndex == -1) {
      printLine(key + " was not found.")
   }
   else {
      printLine("Found " + key + " at index " + keyIndex + ".")
   }
}

/* NUMBERS: 2 4 7 10 11 32 45 87 
Enter a value: 10
Found 10 at index 3.
...
NUMBERS: 2 4 7 10 11 32 45 87 
Enter a value: 17
17 was not found. */

/*-------------------------------------------------------------------------------*/

//Runtime complexities for various code examples

// O(1) Constant
FindMin(x, y) {
   if (x < y) {
      return x
   }
   else {
      return y
   }
}

/*-------------------------------------------------------------------------------*/

// O(log N) Logarithmic
BinarySearch(numbers, N, key) {
   mid = 0
   low = 0
   high = N - 1
   
   while (high >= low) {
      mid = (high + low) / 2
      if (numbers[mid] < key) {
         low = mid + 1
      }
      else if (numbers[mid] > key) {
         high = mid - 1
      }
      else {
         return mid
      }
   }
   
   return -1   // not found
}

/*-------------------------------------------------------------------------------*/

// O(N)	Linear	
LinearSearch(numbers, numbersSize, key) {
  for (i = 0; i < numbersSize; ++i) {
      if (numbers[i] == key) {
         return i
      }
   }
   
   return -1 // not found
}

/*-------------------------------------------------------------------------------*/

// O(N log N)	Linearithmic	
MergeSort(numbers, i, k) {
   j = 0
   if (i < k) {
      j = (i + k) / 2              // Find midpoint 
      
      MergeSort(numbers, i, j)     // Sort left part
      MergeSort(numbers, j + 1, k) // Sort right part
      Merge(numbers, i, j, k)      // Merge parts
   }
}

/*-------------------------------------------------------------------------------*/

// O(N)	Quadratic	
SelectionSort(numbers, numbersSize) { 
   for (i = 0; i < numbersSize; ++i) {
      indexSmallest = i
      for (j = i + 1; j < numbersSize; ++j) {
         if (numbers[j] < numbers[indexSmallest]) {
            indexSmallest = j
         }
      }
      
      temp = numbers[i]
      numbers[i] = numbers[indexSmallest]
      numbers[indexSmallest] = temp
   }
}

/*-------------------------------------------------------------------------------*/

// O(c^N)	Exponential	
Fibonacci(N) {
  if ((1 == N) || (2 == N)) {
     return 1
  }
  return Fibonacci(N-1) + Fibonacci(N-2)
}


/*-------------------------------------------------------------------------------*/

// Insertion sort algorithm.
InsertionSort(numbers, numbersSize) {
   i = 0
   j = 0
   temp = 0  // Temporary variable for swap
   
   for (i = 1; i < numbersSize; ++i) {
      j = i
      // Insert numbers[i] into sorted part
      // stopping once numbers[i] in correct position
      while (j > 0 && numbers[j] < numbers[j - 1]) {
         
         // Swap numbers[j] and numbers[j - 1]
         temp = numbers[j]
         numbers[j] = numbers[j - 1]
         numbers[j - 1] = temp
         --j
      }
   }
}

main() {
   numbers = { 10, 2, 78, 4, 45, 32, 7, 11 }
   NUMBERS_SIZE = 8
   i = 0
   
   print("UNSORTED: ")
   for(i = 0; i < NUMBERS_SIZE; ++i) {
      print(numbers[i] + " ")
   }
   printLine()
   
   InsertionSort(numbers, NUMBERS_SIZE)
   
   print("SORTED: ")
   for(i = 0; i < NUMBERS_SIZE; ++i) {
      print(numbers[i] + " ")
   }
   printLine()
}

/* UNSORTED: 10 2 78 4 45 32 7 11 
SORTED: 2 4 7 10 11 32 45 78 */

/*-------------------------------------------------------------------------------*/

//SELECTION SORT SHORT
for (i = 0; i < numbersSize - 1; ++i) {

   // Find index of smallest remaining element
   indexSmallest = i
   for (j = i + 1; j < numbersSize; ++j) {

      if (numbers[j] < numbers[indexSmallest]) {
         indexSmallest = j
      }
   }

   // Swap numbers[i] and numbers[indexSmallest]
   temp = numbers[i]
   numbers[i] = numbers[indexSmallest]
   numbers[indexSmallest] = temp
}

/*-------------------------------------------------------------------------------*/

// Selection sort algorithm.
SelectionSort(numbers, numbersSize) {
   i = 0
   j = 0
   indexSmallest = 0
   temp = 0  // Temporary variable for swap
   
   for (i = 0; i < numbersSize - 1; ++i) {
      
      // Find index of smallest remaining element
      indexSmallest = i
      for (j = i + 1; j < numbersSize; ++j) {
         
         if ( numbers[j] < numbers[indexSmallest] ) {
            indexSmallest = j
         }
      }
      
      // Swap numbers[i] and numbers[indexSmallest]
      temp = numbers[i]
      numbers[i] = numbers[indexSmallest]
      numbers[indexSmallest] = temp
   }
}

main() {
   numbers[] = { 10, 2, 78, 4, 45, 32, 7, 11 }
   NUMBERS_SIZE = 8
   i = 0
   
   print("UNSORTED: ")
   for (i = 0; i < NUMBERS_SIZE; ++i) {
      print(numbers[i] + " ")
   }
   printLine()
   
   SelectionSort(numbers, NUMBERS_SIZE)
   
   print("SORTED: ")
   for (i = 0; i < NUMBERS_SIZE; ++i) {
      print(numbers[i] + " ")
   }
   printLine()   
}

/* UNSORTED: 10 2 78 4 45 32 7 11 
SORTED: 2 4 7 10 11 32 45 78 */

/*-------------------------------------------------------------------------------*/

//Interleaved insertion sort.
InsertionSortInterleaved(numbers, numbersSize, startIndex, gap) {
   i = 0
   j = 0
   temp = 0  // Temporary variable for swap

   for (i = startIndex + gap; i < numbersSize; i = i + gap) {
      j = i
      while (j - gap >= startIndex && numbers[j] < numbers[j - gap]) {
         temp = numbers[j]
         numbers[j] = numbers[j - gap]
         numbers[j - gap] = temp
         j = j - gap
      }
   }
}

/*-------------------------------------------------------------------------------*/

// Quicksort algorithm.
Partition(numbers, lowIndex, highIndex) {
   // Pick middle element as pivot
   midpoint = lowIndex + (highIndex - lowIndex) / 2
   pivot = numbers[midpoint]
   
   done = false
   while (!done) {
      // Increment lowIndex while numbers[lowIndex] < pivot
      while (numbers[lowIndex] < pivot) {
         lowIndex += 1
      }
      
      // Decrement highIndex while pivot < numbers[highIndex]
      while (pivot < numbers[highIndex]) {
         highIndex -= 1
      }
      
      // If zero or one elements remain, then all numbers are 
      // partitioned. Return highIndex.
      if (lowIndex >= highIndex) {
         done = true
      }
      else {
         // Swap numbers[lowIndex] and numbers[highIndex]
         temp = numbers[lowIndex]
         numbers[lowIndex] = numbers[highIndex]
         numbers[highIndex] = temp
         
         // Update lowIndex and highIndex
         lowIndex += 1
         highIndex -= 1
      }
   }
   
   return highIndex
}

Quicksort(numbers, lowIndex, highIndex) {
   // Base case: If the partition size is 1 or zero 
   // elements, then the partition is already sorted
   if (lowIndex >= highIndex) {
      return
   }
   
   // Partition the data within the array. Value lowEndIndex 
   // returned from partitioning is the index of the low 
   // partition's last element.
   lowEndIndex = Partition(numbers, lowIndex, highIndex)
   
   // Recursively sort low partition (lowIndex to lowEndIndex) 
   // and high partition (lowEndIndex + 1 to highIndex)
   Quicksort(numbers, lowIndex, lowEndIndex)
   Quicksort(numbers, lowEndIndex + 1, highIndex)
}

main() {
   numbers[] = { 10, 2, 78, 4, 45, 32, 7, 11 }
   NUMBERS_SIZE = 8
   i = 0
   
   print("UNSORTED: ")
   for(i = 0; i < NUMBERS_SIZE; ++i) {
      print(numbers[i] + " ")
   }
   printLine()
   
   // Initial call to quicksort
   Quicksort(numbers, 0, NUMBERS_SIZE - 1)
   
   print("SORTED: ")
   for(i = 0; i < NUMBERS_SIZE; ++i) {
      print(numbers[i] + " ")
   }
   printLine()
}

/* UNSORTED: 10 2 78 4 45 32 7 11 
SORTED: 2 4 7 10 11 32 45 78 */

/*-------------------------------------------------------------------------------*/

//Merge sort algorithm.
Merge(numbers, i, j, k) {
   mergedSize = k - i + 1                // Size of merged partition
   mergePos = 0                          // Position to insert merged number
   leftPos = 0                           // Position of elements in left partition
   rightPos = 0                          // Position of elements in right partition
   mergedNumbers = new int[mergedSize]   // Dynamically allocates temporary array
                                         // for merged numbers
   
   leftPos = i                           // Initialize left partition position
   rightPos = j + 1                      // Initialize right partition position
   
   // Add smallest element from left or right partition to merged numbers
   while (leftPos <= j && rightPos <= k) {
      if (numbers[leftPos] <= numbers[rightPos]) {
         mergedNumbers[mergePos] = numbers[leftPos]
         ++leftPos
      }
      else {
         mergedNumbers[mergePos] = numbers[rightPos]
         ++rightPos
         
      }
      ++mergePos
   }
   
   // If left partition is not empty, add remaining elements to merged numbers
   while (leftPos <= j) {
      mergedNumbers[mergePos] = numbers[leftPos]
      ++leftPos
      ++mergePos
   }
   
   // If right partition is not empty, add remaining elements to merged numbers
   while (rightPos <= k) {
      mergedNumbers[mergePos] = numbers[rightPos]
      ++rightPos
      ++mergePos
   }
   
   // Copy merge number back to numbers
   for (mergePos = 0; mergePos < mergedSize; ++mergePos) {
      numbers[i + mergePos] = mergedNumbers[mergePos]
   }
}

MergeSort(numbers, i, k) {
   j = 0
   
   if (i < k) {
      j = (i + k) / 2  // Find the midpoint in the partition
      
      // Recursively sort left and right partitions
      MergeSort(numbers, i, j)
      MergeSort(numbers, j + 1, k)
      
      // Merge left and right partition in sorted order
      Merge(numbers, i, j, k)
   }
}

main() {
   numbers = { 10, 2, 78, 4, 45, 32, 7, 11 }
   NUMBERS_SIZE = 8
   i = 0
   
   print("UNSORTED: ")
   for(i = 0; i < NUMBERS_SIZE; ++i) {
      print(numbers[i] + " ")
   }
   printLine()
   
   MergeSort(numbers, 0, NUMBERS_SIZE - 1)
   
   print("SORTED: ")
   for(i = 0; i < NUMBERS_SIZE; ++i) {
      print(numbers[i] + " ")
   }
   printLine()
}

/* UNSORTED: 10 2 78 4 45 32 7 11 
SORTED: 2 4 7 10 11 32 45 78 */

/*-------------------------------------------------------------------------------*/

//RadixGetMaxLength and RadixGetLength functions.
// Returns the maximum length, in number of digits, out of all elements in the array

RadixGetMaxLength(array, arraySize) {
   maxDigits = 0
   for (i = 0; i < arraySize; i++) {
      digitCount = RadixGetLength(array[i])
      if (digitCount > maxDigits)
         maxDigits = digitCount
   }
   return maxDigits
}

// Returns the length, in number of digits, of value
RadixGetLength(value) {
   if (value == 0)
      return 1

   digits = 0
   while (value != 0) {
      digits = digits + 1
      value = value / 10
   }
   return digits
}

/*-------------------------------------------------------------------------------*/

//RadixSort algorithm (for negative and non-negative integers).

RadixSort(array, arraySize) {
   buckets = create array of 10 buckets

   // Find the max length, in number of digits
   maxDigits = RadixGetMaxLength(array, arraySize)
        
   pow10 = 1
   for (digitIndex = 0; digitIndex < maxDigits; digitIndex++) {
      for (i = 0; i < arraySize; i++) {
         bucketIndex = GetLowestDigit(array[i] / pow10)
         Append array[i] to buckets[bucketIndex]
      }
      arrayIndex = 0
      for (i = 0; i < 10; i++) {
         for (j = 0; j < buckets[i].size(); j++) {
            array[arrayIndex] = buckets[i][j]
            arrayIndex = arrayIndex + 1
         }
      }
      pow10 = pow10 * 10
      Clear all buckets
   }

   negatives = all negative values from array
   nonNegatives = all non-negative values from array
   Reverse order of negatives
   Concatenate negatives and nonNegatives into array
}

/*-------------------------------------------------------------------------------*/

