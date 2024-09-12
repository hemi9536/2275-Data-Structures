#include<iostream>
#include<cmath>
#include<iomanip>
#include "../code_1/WordDecoder.hpp"

using namespace std;



int main(int argc, char* argv[])
{
    // DO NOT MODIFY THIS.
    if(argc>1)
    {
         freopen(argv[1],"r",stdin);
    }

    /* TODO- 
              1. cout #>
              2. get the user input
              3. store them in an array
              4. If the array is empty then print "Nothing to evaluate"
                 else call the evaluate function
    */
   string abc;
   cout << "Enter the encoded word separated by '(' and ')'" << endl;
   cout << "#>";
   cin >> abc;
   if (abc == "") {
    cout << "Nothing to evaluate";
    return 0;
   }
   int size = int(abc.size());
   string arr[size];
   for (int i = 0; i < size; i++) {
    arr[i] = abc[i];
   }
   if (arr[0] == "") {
    cout << "Nothing to evaluate";
   } else {
    WordDecoder a;
    a.evaluate(arr, size);
   }
    
    
    return 0;
}