//ALGORITHMS

FindMax(inputArray) {
   max = inputArray[0]

   for (i = 1; i < inputArray.size; ++i) {
      if (inputArray[i] > max) {
         max = inputArray[i];
      }
   }

   return max
}

//A recursive function is a function that calls itself. Recursive functions are commonly used to implement recursive algorithms.

Factorial(N) {
   if (N == 1)
      return 1
   else
      return N * Factorial(N - 1)
}

CumulativeSum(N) {
   if (N == 0)
      return 0
   else
      return N + CumulativeSum(N - 1)
}

ReverseList(list, startIndex, endIndex) {
   if (startIndex >= endIndex)
      return
   else {
      Swap elements at startIndex and endIndex
      ReverseList(list, startIndex + 1, endIndex - 1)
   }
}

/*-------------------------------------------------------------------------------*/

#include <iostream>

using namespace std;

int Factorial(int N) {
    if (N == 1)
        return 1;
    else
        return N * Factorial(N - 1);
}

int main() {
    int number;
    cout << "Enter a positive integer: ";
    cin >> number;

    if (number < 0) {
        cout << "Factorial of a negative number is not defined." << endl;
    } else {
        cout << "Factorial of " << number << " is " << Factorial(number) << endl;
    }

    return 0;
}

/* This program includes the Factorial function and a main function that takes an integer input from the user, checks if it's positive, and then calculates and prints the factorial using the Factorial function. */

/*-------------------------------------------------------------------------------*/

//FibonacciNumber recursive function.

FibonacciNumber(termIndex) {
   if (termIndex == 0)
      return 0
   else if (termIndex == 1)
      return 1
   else
      return FibonacciNumber(termIndex - 1) + FibonacciNumber(termIndex - 2)
}


/*-------------------------------------------------------------------------------*/

#include<iostream>    
using namespace std;      
void printFibonacci(int n){    
    static int n1=0, n2=1, n3;    
    if(n>0){    
         n3 = n1 + n2;    
         n1 = n2;    
         n2 = n3;    
 cout<<n3<<" ";    
         printFibonacci(n-1);    
    }    
}    
int main(){    
    int n;    
    cout<<"Enter the number of elements: ";    
    cin>>n;    
    cout<<"Fibonacci Series: ";    
    cout<<"0 "<<"1 ";  
    printFibonacci(n-2);  //n-2 because 2 numbers are already printed    
     return 0;  
}  
/* Enter the number of elements: 15 
 Fibonacci Series: 0 1 1 2 3 5 8 13 21 34 55 89 144 233 377 */
 
 /*-------------------------------------------------------------------------------*/
 
//Here's a working C++ program for calculating the Fibonacci number at a given index using the recursive function you provided:

#include <iostream>

using namespace std;

int FibonacciNumber(int termIndex) {
    if (termIndex == 0)
        return 0;
    else if (termIndex == 1)
        return 1;
    else
        return FibonacciNumber(termIndex - 1) + FibonacciNumber(termIndex - 2);
}

int main() {
    int index;
    cout << "Enter the index of the Fibonacci term: ";
    cin >> index;

    if (index < 0) {
        cout << "The index must be a non-negative integer." << endl;
    } else {
        cout << "Fibonacci term at index " << index << " is " << FibonacciNumber(index) << endl;
    }

    return 0;
}

//This program includes the `FibonacciNumber` function and a `main` function that takes an integer input from the user, checks if it's non-negative, and then calculates and prints the Fibonacci number at the given index using the `FibonacciNumber` function.


/*-------------------------------------------------------------------------------*/

//BinarySearch recursive algorithm.
BinarySearch(numbers, low, high, key) {
   if (low > high)
      return -1

   mid = (low + high) / 2
   if (numbers[mid] < key) {
      return BinarySearch(numbers, mid + 1, high, key)
   }
   else if (numbers[mid] > key) {
      return BinarySearch(numbers, low, mid - 1, key)
   }
   return mid
}

//Here's a working C++ program for the recursive Binary Search algorithm you provided:

#include <iostream>
#include <vector>

using namespace std;

int BinarySearch(const vector<int>& numbers, int low, int high, int key) {
    if (low > high)
        return -1;

    int mid = low + (high - low) / 2;  // To avoid potential overflow
    if (numbers[mid] < key) {
        return BinarySearch(numbers, mid + 1, high, key);
    }
    else if (numbers[mid] > key) {
        return BinarySearch(numbers, low, mid - 1, key);
    }
    return mid;
}

int main() {
    vector<int> numbers = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int key;
    cout << "Enter the number to search for: ";
    cin >> key;

    int result = BinarySearch(numbers, 0, numbers.size() - 1, key);
    if (result != -1) {
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found in the array" << endl;
    }

    return 0;
}


/*This program includes the `BinarySearch` function and a `main` function that creates a sorted array of integers, takes an integer input from the user as the key to search for, and then uses the `BinarySearch` function to find the index of the key in the array. If the key is found, it prints the index; otherwise, it prints a message indicating that the element is not in the array. */

/*-------------------------------------------------------------------------------*/

/*To solve the "knapsack problem" as described in the image you provided, you can use a dynamic programming approach. The problem states that we need to choose items to maximize value without exceeding a weight limit of 30 pounds.

Below is a basic C++ program that solves the 0/1 knapsack problem using dynamic programming:*/


#include <iostream>
#include <vector>
#include <algorithm> // for max function

using namespace std;

int knapsack(int weightLimit, const vector<int>& weights, const vector<int>& values, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(weightLimit + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= weightLimit; w++) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][weightLimit];
}

int main() {
    const vector<int> weights = {6, 8, 14, 18, 20}; // Item weights
    const vector<int> values = {25, 42, 65, 95, 100}; // Item values
    int weightLimit = 30; // Knapsack weight limit

    int n = weights.size();
    cout << "Maximum value we can obtain = " << knapsack(weightLimit, weights, values, n) << endl;

    return 0;
}


/*This program defines a `knapsack` function that calculates the maximum value that can be achieved without exceeding the weight limit. The `main` function initializes the weights and values, and then calls the `knapsack` function to solve the problem. The result is then printed to the console.*/


/*-------------------------------------------------------------------------------*/

/*The approach you've shared for the knapsack problem seems to be a greedy one, which does not guarantee an optimal solution for the 0/1 knapsack problem but is more computationally efficient. However, for educational purposes, let's implement it as a C++ program.

Here is a program based on the pseudocode:*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int value;
    int weight;
};

// Comparator to sort items by value in descending order
bool compareByValue(const Item &a, const Item &b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

// The greedy approach for Knapsack problem
int Knapsack01(int maximumWeight, vector<Item> &items) {
    // Sort items descending by value to weight ratio
    sort(items.begin(), items.end(), compareByValue);

    int remaining = maximumWeight;
    int maxValue = 0;
    
    for (int i = 0; i < items.size(); i++) {
        if (items[i].weight <= remaining) {
            // Put item in knapsack
            maxValue += items[i].value;
            remaining -= items[i].weight;
        }
    }

    return maxValue;
}

int main() {
    vector<Item> items = {
        {25, 6}, // Value, Weight
        {42, 8},
        {65, 14},
        {95, 18},
        {100, 20}
    };
    int knapsackMaximumWeight = 30;

    cout << "Maximum value we can obtain = " << Knapsack01(knapsackMaximumWeight, items) << endl;

    return 0;
}


/*This program defines a structure for `Item` that contains `value` and `weight`. The `Knapsack01` function sorts the items by their value-to-weight ratio in descending order and then attempts to add each item to the knapsack if its weight is less than the remaining weight limit. The function returns the maximum value that can be put into the knapsack using this approach. The `main` function tests `Knapsack01` with a given list of items and a knapsack weight limit.*/



/*-------------------------------------------------------------------------------*/

//Longest common substring algorithm

LongestCommonSubstring(str1, str2) {
   matrix = Allocate str1⇢length by str2⇢length matrix

   for (row = 0; row < str1⇢length; row++) {
      for (col = 0; col < str2⇢length; col++) {         
         // Check if the characters match
         if (str1[row] == str2[col]) {
            // Get the value in the cell that's up and to the 
            // left, or 0 if no such cell
            upLeft = 0
            if (row > 0 && col > 0)
               upLeft = matrix[row - 1][col - 1]
                
            // Set the value for this cell
            matrix[row][col] = 1 + upLeft
         }
         else
            matrix[row][col] = 0
      }
   }

   substringLength = Maximum value in matrix
   rowIndex = Row index of maximum value in matrix
   startIndex = rowIndex - substringLength + 1
   return str1⇢substr(startIndex, substringLength)
}

//LongestCommonSubstring("Look", "zyBooks")


/*-------------------------------------------------------------------------------*/

//Dynamic Prog: 
FibonacciNumber(termIndex) {
   if (termIndex == 0)
      return 0

   previous = 0
   current = 1
   i = 1
   while (i < termIndex) {
      next = previous + current
      previous = current
      current = next
      i = i + 1
   }
   return current
}

/*-------------------------------------------------------------------------------*/

/*To modify the previous Fibonacci generator into a dynamic programming version, we will use memoization. This means we will store the results of Fibonacci numbers we have already calculated in an array (or another type of storage) so we don't have to re-calculate them when they are needed again.

Below is the complete C++ program with dynamic programming (using memoization) and with `using namespace std;` as requested:*/


#include <iostream>
#include <vector>

using namespace std;

int FibonacciNumber(int termIndex, vector<int>& memo) {
    if (termIndex == 0) return 0;
    if (termIndex == 1) return 1;

    // If the value is not yet computed, compute it
    if (memo[termIndex] == -1) {
        memo[termIndex] = FibonacciNumber(termIndex - 1, memo) + FibonacciNumber(termIndex - 2, memo);
    }

    // The value is now computed, return it
    return memo[termIndex];
}

int main() {
    int termIndex;
    cout << "Enter the index of the Fibonacci term: ";
    cin >> termIndex;

    if (termIndex < 0) {
        cout << "The index must be a non-negative integer." << endl;
    } else {
        // Create a memoization array initialized with -1
        vector<int> memo(termIndex + 1, -1);
        cout << "Fibonacci term at index " << termIndex << " is " << FibonacciNumber(termIndex, memo) << endl;
    }

    return 0;
}

/*In this program, we have a `memo` array that is passed to the `FibonacciNumber` function. Initially, all elements of `memo` are set to -1 to indicate that the Fibonacci number at that index has not been calculated yet. The `FibonacciNumber` function checks if the number has been computed; if not, it computes and stores the result in `memo`. This way, every Fibonacci number is computed only once, which is the essence of dynamic programming.*/

/*-------------------------------------------------------------------------------*/

