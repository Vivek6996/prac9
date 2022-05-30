#include "Polish.h"

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
   string prefix;  

   cout << "Sample input: ";
   getline(cin, prefix);

   Polish polish(prefix);

   string infix = polish.convert();
      
   cout << "Sample output: " << infix;

   if (infix.compare("Error") != 0)
   {
       int ans = polish.calc();

       cout << " = " << ans;
   }
   cout << endl << endl;

   return 0;
}