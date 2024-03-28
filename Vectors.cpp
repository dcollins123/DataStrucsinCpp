//Complete the code to compute the average of the vector's element values. The result should be 16.


#include <iostream>
#include <vector>
using namespace std;

int main() {
   const int VALS_SIZE = 6;
   vector<int> valsVctr(VALS_SIZE);
   unsigned int i;
   int sumVal;
   int avgVal;

   valsVctr.at(0) = 30;
   valsVctr.at(1) = 20;
   valsVctr.at(2) = 20;
   valsVctr.at(3) = 15;
   valsVctr.at(4) = 5;
   valsVctr.at(5) = 10;

   sumVal = 0;
   avgVal = 0;
   
   for(i = 0; i < valsVctr.size(); ++i){
      sumVal += valsVctr.at(i);
   }
   
   avgVal = sumVal / VALS_SIZE;

   cout << "Avg: " << avgVal << endl;

   return 0;
}


/*-------------------------------------------------------------------------------*/

//The for loop iterates in order, once for each element in the vector. If the value of the current element is less than 0, the element is multiplied by -1. So, the program changes the negative values into positive and outputs them.

#include <iostream>
#include <vector>
using namespace std;

int main() {
   const int NUM_ELEMENTS = 4;
   vector<int> userVals(NUM_ELEMENTS);
   unsigned int i;
   
   userVals.at(0) = -2;
   userVals.at(1) = 3;
   userVals.at(2) = -5;
   userVals.at(3) = 7;
   
   for (i = 0; i < userVals.size(); ++i) {
      if (userVals.at(i) < 0) {
         userVals.at(i) = -1 * userVals.at(i);
      }
      cout << userVals.at(i) << endl;
   }
   
   return 0;
}
/*Printed: 
2
3
5
7

*/ 

 /*-------------------------------------------------------------------------------*/

//Multiple vector example: TV watching time program.

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
   // Source: www.statista.com, 2015
   const int NUM_COUNTRIES = 5;             // Num countries supported
   vector<string> ctryNames(NUM_COUNTRIES); // Country names
   vector<int>    ctryMins(NUM_COUNTRIES);  // Mins TV watched daily
   string userCountry;                      // User defined country
   bool foundCountry = false;               // Match to country supported
   unsigned int i;                          // Loop index
   
   // Fill vector contents
   ctryNames.at(0) = "China";
   ctryMins.at(0) = 155;
   
   ctryNames.at(1) = "Sweden";
   ctryMins.at(1) = 154;
   
   ctryNames.at(2) = "Russia";
   ctryMins.at(2) = 246;
   
   ctryNames.at(3) = "UK";
   ctryMins.at(3) = 216;
   
   ctryNames.at(4) = "USA";
   ctryMins.at(4) = 274;
   
   // Prompt user for country name
   cout << "Enter country name: ";
   cin >> userCountry;
   
   // Find country's index and average TV time
   foundCountry = false;
   for (i = 0; (i < ctryNames.size()) && (!foundCountry); ++i) {
      if (ctryNames.at(i) == userCountry) {
         foundCountry = true;
         cout << "People in " << userCountry << " watch ";
         cout << ctryMins.at(i) << " mins of TV daily." << endl;
      }
   }
   if (!foundCountry) {
      cout << "Country not found; try again." << endl;
   }
   
   return 0;
}

/*
Enter country name: USA
People in USA watch 274 mins of TV daily.

...

Enter country name: Sweden
People in Sweden watch 154 mins of TV daily.

...

Enter country name: Brazil
Country not found; try again.
*/

/*-------------------------------------------------------------------------------*/

/*Add each element in origList with the corresponding value in offsetAmount. Print each sum followed by a space. Ex: If origList = {40, 50, 60, 70} and offsetAmount = {5, 7, 3, 0}, print:
45 57 63 70  */

#include <iostream>
#include <vector>
using namespace std;

int main() {
   const int NUM_VALS = 4;
   vector<int> origList(NUM_VALS);
   vector<int> offsetAmount(NUM_VALS);
   unsigned int i;

   for (i = 0; i < origList.size(); ++i) {
      cin >> origList.at(i);
   }

   for (i = 0; i < offsetAmount.size(); ++i) {
      cin >> offsetAmount.at(i);
   }

   for (i = 0; i < NUM_VALS; ++i) {
      cout << origList.at(i) + offsetAmount.at(i) << " ";
   }

   cout << endl;

   return 0;
}


/*-------------------------------------------------------------------------------*/

/*
For any element in keysList with a value greater than 100, print the corresponding value in itemsList, followed by a space. Ex: If keysList = {42, 105, 101, 100} and itemsList = {10, 20, 30, 40}, print:
20 30 
Since keysList.at(1) and keysList.at(2) have values greater than 100, the value of itemsList.at(1) and itemsList.at(2) are printed.*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
   const int SIZE_LIST = 4;
   vector<int> keysList(SIZE_LIST);
   vector<int> itemsList(SIZE_LIST);
   unsigned int i;

   for (i = 0; i < keysList.size(); ++i) {
      cin >> keysList.at(i);
   }

   for (i = 0; i < itemsList.size(); ++i) {
      cin >> itemsList.at(i);
   }

   /* Your solution goes here  */
   for (i = 0; i < SIZE_LIST; ++i) {
      if (keysList.at(i) > 100) {
         cout << itemsList.at(i) << " ";
      }
   }

   cout << endl;

   return 0;
}

/*-------------------------------------------------------------------------------*/

//Assign currentSize with the size of the sensorReadings vector.

#include <iostream>
#include <vector>
using namespace std;

int main() {
   vector<int> sensorReadings(4); // Initially has 4 elements
   int currentSize;
   int input;
   cin >> input;

   sensorReadings.resize(input); // Resizes the vector to have 'input' number of elements

   /* Your solution goes here  */
   currentSize = sensorReadings.size(); // Assigns the size of the vector to currentSize

   cout << "Number of elements: " << currentSize << endl;

   return 0;
}

/*-------------------------------------------------------------------------------*/ 

/* Resize vector countDown to have newSize elements. Populate the vector with integers {newSize, newSize - 1, …, 1}. Ex: If newSize = 3, then countDown = {3, 2, 1}, and the sample program outputs:
3 2 1 Go! */

#include <iostream>
#include <vector>
using namespace std;

int main() {
   vector<int> countDown(0);
   int newSize;
   unsigned int i;

   cin >> newSize;

   countDown.resize(newSize);
   for (i = 0; i < newSize; ++i) {
      countDown.at(i) = newSize - i;
   }

   for (i = 0; i < countDown.size(); ++i) {
      cout << countDown.at(i) << " ";
   }
   cout << "Go!" << endl;

   return 0;
}

/*-------------------------------------------------------------------------------*/

//Using push_back(), back(), and pop_back(): A grocery list example.
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
   vector<string> groceryList; // Vector storing shopping list
   string groceryItem;         // Individual grocery items
   string userCmd;             // User input
   
   // Prompt user to populate shopping list
   cout << "Enter grocery items or type done." << endl;
   cin >> groceryItem;
   while (groceryItem != "done") {
      groceryList.push_back(groceryItem);
      cin >> groceryItem;
   }
   
   // Display shopping list
   cout << endl << "Enter any key for next item." << endl;
   while (groceryList.size() > 0) {
      groceryItem = groceryList.back();
      groceryList.pop_back();
      cout << groceryItem << "   ";
      cin >> userCmd;
   }
   cout << endl << "Done shopping." << endl;
   
   return 0;
}

/* Enter grocery items or type done.
Oranges
Apples
Bread
Juice
done

Enter any key for next item.
Juice   a
Bread   a
Apples   a
Oranges   a

Done shopping. */

/*-------------------------------------------------------------------------------*/

/* Append newValue to the end of vector tempReadings. Ex: If newValue = 67, then tempReadings = {53, 57, 60} becomes {53, 57, 60, 67}. */

#include <iostream>
#include <vector>
using namespace std;

int main() {
   const int NUM_ELEMENTS = 3;
   vector<int> tempReadings(NUM_ELEMENTS);
   int newValue;
   unsigned int i;

   for (i = 0; i < tempReadings.size(); ++i) {
      cin >> tempReadings.at(i);
   }

   cin >> newValue;

   /* Your solution goes here  */
   tempReadings.push_back(newValue);

   for (i = 0; i < tempReadings.size(); ++i) {
      cout << tempReadings.at(i) << " ";
   }
   cout << endl;

   return 0;
}


/*-------------------------------------------------------------------------------*/

/* Write a statement to print "Last mpg reading: " followed by the value of mpgTracker's last element. End with newline. Ex: If mpgTracker = {17, 19, 20}, print:
Last mpg reading: 20 */


#include <iostream>
#include <vector>
using namespace std;

int main() {
   const int NUM_ELEMENTS = 3;
   vector<int> mpgTracker(NUM_ELEMENTS);
   int i;

   for (i = 0; i < mpgTracker.size(); ++i) {
      cin >> mpgTracker.at(i);
   }

   cout << "Last mpg reading: " << mpgTracker.back() << endl; 

   return 0;
}

/*-------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------*/

//MODIFYING A VECTOR
//Modifying a vector during iteration example: Converting negatives to 0.
#include <iostream>
#include <vector>
using namespace std;

int main() {
   const int NUM_ELEMENTS = 5;         // Number of elements
   vector<int> userVals(NUM_ELEMENTS); // User values
   unsigned int i;                     // Loop index
   
   // Prompt user to populate vector
   cout << "Enter " << NUM_ELEMENTS << " integer values..." << endl;
   for (i = 0; i < userVals.size(); ++i) {
      cout << "Value: ";
      cin >> userVals.at(i);
   }
   
   // Convert negatives to 0
   for (i = 0; i < userVals.size(); ++i) {
      if (userVals.at(i) < 0) {
         userVals.at(i) = 0;
      }
   }
   
   // Print numbers
   cout << "New values:";
   for (i = 0; i < userVals.size(); ++i) {
      cout << " " << userVals.at(i);
   }
   cout << endl;
   
   return 0;
}

/* Enter 5 integer values...
Value: 67
Value: -5
Value: -99
Value: 4
Value: 22
New values: 67 0 0 4 22 */

/*-------------------------------------------------------------------------------*/

//Complete the following program to double each number in the vector.


#include <iostream>
#include <vector>
using namespace std;

int main() {
   const int NUM_ELEMENTS = 5;         // Number of elements
   vector<int> userVals(NUM_ELEMENTS); // User values
   unsigned int i;                     // Loop index
   
   // Prompt user to populate vector
   cout << "Enter " << NUM_ELEMENTS << " integer values..." << endl;
   for (i = 0; i < userVals.size(); ++i) {
      cout << "Value: " << endl;
      cin >> userVals.at(i);
   }
   
   // Double each number
   for (i = 0; i < userVals.size(); ++i) {
      userVals.at(i) *= 2;
   }
   
   // Print doubled numbers
   cout << "Doubled values:";
   for (i = 0; i < userVals.size(); ++i) {
      cout << " " << userVals.at(i);
   }
   cout << endl;
   
   return 0;
}

/*-------------------------------------------------------------------------------*/

//Using = to copy a vector: Original and sale prices.
#include <iostream>
#include <vector>
using namespace std;

int main() {
   const int   NUM_ELEMENTS = 4;         // Number of elements
   vector<int> origPrices(NUM_ELEMENTS); // Original prices
   vector<int> salePrices(NUM_ELEMENTS); // Sale prices
   unsigned int i;                       // Loop index
   
   // Assign original prices
   origPrices.at(0) = 10;
   origPrices.at(1) = 20;
   origPrices.at(2) = 30;
   origPrices.at(3) = 40;
   
   // Copy original prices to sales prices
   salePrices = origPrices;
   
   // Update salePrices. Note: does not affect origPrices
   salePrices.at(2) = 27;
   salePrices.at(3) = 35;
   
   // Output original and sale prices
   cout << "Original prices: ";
   for (i = 0; i < origPrices.size(); ++i) {
      cout << " " << origPrices.at(i);
   }
   cout << endl;
   
   cout << "Sale prices:     ";
   for (i = 0; i < salePrices.size(); ++i) {
      cout << " " << salePrices.at(i);
   }
   cout << endl;
   
   return 0;
}
/* Original prices:  10 20 30 40
Sale prices:      10 20 27 35
 */
 
/*-------------------------------------------------------------------------------*/ 
 
//You can write a loop that checks each element of the `lowerScores` vector, subtracts 1 if the element is greater than 0, and sets the element to 0 if it's not. Here's how you can do that:

#include <iostream>
#include <vector>
using namespace std;

int main() {
   const int SCORES_SIZE = 4;
   vector<int> lowerScores(SCORES_SIZE);
   unsigned int i;

   for (i = 0; i < lowerScores.size(); ++i) {
      cin >> lowerScores.at(i);
   }

   /* Your solution goes here  */
   for (i = 0; i < lowerScores.size(); ++i) {
      if (lowerScores.at(i) > 0) {
         lowerScores.at(i) -= 1;
      } else {
         lowerScores.at(i) = 0;
      }
   }

   for (i = 0; i < lowerScores.size(); ++i) {
      cout << lowerScores.at(i) << " ";
   }
   cout << endl;

   return 0;
}
```

/*This code takes each element in `lowerScores`, checks if it is greater than 0, and then either subtracts 1 or sets it to 0 according to the condition described. Afterward, it prints out the modified `lowerScores` vector.*/
 
/*-------------------------------------------------------------------------------*/

//To shift the elements of `oldScores` to the left and copy the first element to the end of `newScores`, you'll need to loop through `oldScores` and assign each element to the position one less than its current position in `newScores`. The first element of `oldScores` needs to be placed at the end of `newScores`. Here's the code that accomplishes this:

#include <iostream>
#include <vector>
using namespace std;

int main() {
   const int SCORES_SIZE = 4;
   vector<int> oldScores(SCORES_SIZE);
   vector<int> newScores(SCORES_SIZE);
   unsigned int i;

   for (i = 0; i < oldScores.size(); ++i) {
      cin >> oldScores.at(i);
   }

   /* Your solution goes here  */
   for (i = 0; i < oldScores.size() - 1; ++i) {
      newScores.at(i) = oldScores.at(i + 1);
   }
   newScores.at(SCORES_SIZE - 1) = oldScores.at(0);

   for (i = 0; i < newScores.size(); ++i) {
      cout << newScores.at(i) << " ";
   }
   cout << endl;

   return 0;
}
```

/*This code will take the input into `oldScores`, shift the elements to the left in `newScores`, and then place the first element of `oldScores` at the end of `newScores`. Finally, it prints the shifted `newScores`.*/

/*-------------------------------------------------------------------------------*/

//To update each element in the `bonusScores` vector with the sum of itself and the next element, except for the last element, you can use a loop that iterates up to the second-to-last element. Here's how you can do it:

#include <iostream>
#include <vector>
using namespace std;

int main() {
   const int SCORES_SIZE = 4;
   vector<int> bonusScores(SCORES_SIZE);
   unsigned int i;

   for (i = 0; i < bonusScores.size(); ++i) {
      cin >> bonusScores.at(i);
   }

   /* Your solution goes here  */
   for (i = 0; i < bonusScores.size() - 1; ++i) {
      bonusScores.at(i) = bonusScores.at(i) + bonusScores.at(i + 1);
   }

   for (i = 0; i < bonusScores.size(); ++i) {
      cout << bonusScores.at(i) << " ";
   }
   cout << endl;

   return 0;
}
```

/*This code will modify each element of the `bonusScores` vector to be the sum of itself and the next element, leaving the last element unchanged. Then it prints the updated `bonusScores`.*/

/*-------------------------------------------------------------------------------*/

//To subtract 4 from any element's value that is greater than `maxVal`, you can use a loop to iterate through the `dataPoints` vector and apply the condition. Here's how you can do it:

#include <iostream>
#include <vector>
using namespace std;

int main() {
   int maxVal;
   const int NUM_POINTS = 4;
   vector<int> dataPoints(NUM_POINTS);
   unsigned int i;

   cin >> maxVal;

   for (i = 0; i < dataPoints.size(); ++i) {
      cin >> dataPoints.at(i);
   }

   /* Your solution goes here  */
   for (i = 0; i < dataPoints.size(); ++i) {
      if (dataPoints.at(i) > maxVal) {
         dataPoints.at(i) -= 4;
      }
   }

   for (i = 0; i < dataPoints.size(); ++i) {
      cout << dataPoints.at(i) << " " ;
   }
   cout << endl;

   return 0;
}
```

//This code will subtract 4 from any element in the `dataPoints` vector that is greater than `maxVal`, and then it will print the updated `dataPoints`.


/*-------------------------------------------------------------------------------*/

//To check if `oldData` is the same as `newData` and to print "Data matches!" if they are, or to assign `oldData` with `newData` if they are not, you can use the following code:


#include <iostream>
#include <vector>
using namespace std;

int main() {
   const int NUM_POINTS = 4;
   vector<int> oldData(NUM_POINTS);
   vector<int> newData(NUM_POINTS);
   unsigned int i;

   for (i = 0; i < oldData.size(); ++i) {
      cin >> oldData.at(i);
   }

   for (i = 0; i < newData.size(); ++i) {
      cin >> newData.at(i);
   }

   /* Your solution goes here  */
   if (oldData == newData) {
      cout << "Data matches!" << endl;
   } else {
      oldData = newData;
   }

   for (i = 0; i < oldData.size(); ++i) {
      cout << oldData.at(i) << " ";
   }
   cout << endl;

   return 0;
}
```

//This code uses the equality operator `==` to compare `oldData` and `newData`. If they are the same, it prints "Data matches!" followed by a newline. Otherwise, it assigns `newData` to `oldData`. Finally, it prints the (potentially updated) `oldData`.

/*-------------------------------------------------------------------------------*/

//Vector reversal program with correct output.
#include <iostream>
#include <vector>
using namespace std;

int main() {
   const int NUM_ELEMENTS = 8;        // Number of elements
   vector<int> revVctr(NUM_ELEMENTS); // User values
   unsigned int i;                    // Loop index
   int tmpValue;                      // Placeholder
   
   cout << "Enter " << NUM_ELEMENTS << " integer values..." << endl;
   for (i = 0; i < revVctr.size(); ++i) {
      cout << "Value: ";
      cin >> revVctr.at(i);
   }
   
   // Reverse
   for (i = 0; i < (revVctr.size() / 2); ++i) {
      tmpValue = revVctr.at(i);  // These 3 statements swap
      revVctr.at(i) = revVctr.at(revVctr.size() - 1 - i);
      revVctr.at(revVctr.size() - 1 - i) = tmpValue;
   }
   
   // Print values
   cout << endl << "New values: ";
   for (i = 0; i < revVctr.size(); ++i) {
      cout << " " << revVctr.at(i);
   }
   cout << endl;
   
   return 0;
}

/* Enter 8 integer values...
Value: 10
Value: 20
Value: 30
Value: 40
Value: 50
Value: 60
Value: 70
Value: 80

New values:  80 70 60 50 40 30 20 10
 */
 
/*-------------------------------------------------------------------------------*/

//Traversing a C string.
#include <iostream>
using namespace std;

int main() {
   char userStr[20] = "1234567890123456789"; // Input string
   int i; 
   
   // Prompt user for string input
   cout << "Enter string (<20 chars): ";
   cin >> userStr;
   
   // Print string
   cout << endl << userStr << endl;
   
   // Look for '@'
   for (i = 0; userStr[i] != '\0'; ++i) {
      if (userStr[i] == '@') {
         cout << "Found '@'." << endl;
      }
   }
   cout << endl;
   
   
   // The following is an ERROR.
   // May print chars it shouldn't.
   // Problem: doesn't stop at null char.
   cout << "\""; // Print opening "
   for (i = 0; i < 20; ++i) { // Print each char
      cout << userStr[i];
   }
   cout << "\"" << endl;      // Print closing "
   
   
   // The following is an even WORSE ERROR.
   // Accesses beyond valid index range.
   // Program may crash.
   cout << "\""; // Print opening "
   for (i = 0; i < 30; ++i) {
      cout << userStr[i];
   }
   cout << "\"" << endl; // Print closing "
   
   return 0;
}
/* Enter string (<20 chars): test@gmail.com

test@gmail.com
Found '@'.

"test@gmail.com6789"
"test@gmail.com6789P!" */

/*-------------------------------------------------------------------------------*/

//Iterating through a C string using strlen.
#include <iostream>
#include <cstring>
using namespace std;

int main() {
   char userName[15] = "Alan Turing";
   int i;
   
   cout << "Before: " << userName << endl;
   
   for (i = 0; i < strlen(userName); ++i) {
      if (userName[i] == ' ') {
         userName[i] = '_';
      }
   }
   cout << "After:  " << userName << endl;
   
   return 0;
}
/* Before: Alan Turing
After:  Alan_Turing */

/*-------------------------------------------------------------------------------*/

//Use of some functions in cctype.
#include <iostream>
#include <cctype>
using namespace std;

int main() {
   const int MAX_LEN = 30;      // Max string length
   char userStr[MAX_LEN];       // User defined string
   int i;
   
   // Prompt user to enter string
   cout << "Enter string (<"
   << MAX_LEN << " chars): ";
   cin >> userStr;
   
   cout << "Original: " << userStr << endl;
   
   cout << "isalpha:  ";
   for (i = 0; userStr[i] != '\0'; ++i) {
      if (isalpha(userStr[i])) {
         cout << "Y";
      }
      else {
         cout << "N";
      }
   }
   cout << endl;
   
   cout << "isdigit:  ";
   for (i = 0; userStr[i] != '\0'; ++i) {
      if (isdigit(userStr[i])) {
         cout << "Y";
      }
      else {
         cout << "N";
      }
   }
   cout << endl;
   
   cout << "isupper:  ";
   for (i = 0; userStr[i] != '\0'; ++i) {
      if (isupper(userStr[i])) {
         cout << "Y";
      }
      else {
         cout << "N";
      }
   }
   cout << endl;
   
   for (i = 0; userStr[i] != '\0'; ++i) {
      userStr[i] = toupper(userStr[i]);
   }
   cout << "After toupper: " << userStr << endl;
   
   return 0;
}

/* Enter string (<30 chars): ABC123$!def
Original: ABC123$!def
isalpha:  YYYNNNNNYYY
isdigit:  NNNYYYNNNNN
isupper:  YYYNNNNNNNN
After toupper: ABC123$!DEF */

/*-------------------------------------------------------------------------------*/

