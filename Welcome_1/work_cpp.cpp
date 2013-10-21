#include <iostream>

using namespace std;

void func();

int main()
{
   cout << "Hello!" << endl;

   int  var = 20;   // actual variable declaration.
   int  *ip;        // pointer variable
   int *pb, *pa, *pc;

   ip = &var;       // store address of var in pointer variable
   pa = pb = pc = &var;

   cout << "Value of var variable: ";
   cout << var << endl;

   // print the address stored in ip pointer variable
   cout << "Address stored in ip variable: ";
   cout << ip << endl;

   // access the value at the address available in pointer
   cout << "Value of *ip variable: ";
   cout << *ip << endl;

   for (int i = 0; i <3; i++)
	   func();

   return 0;
}

void func() 
{
   static int x = 0; // x is initialized only once across three calls of func() and x will get incremented three 
                     //times after all the three calls. i.e x will be 2 finally
   printf("%d\n", x); // outputs the value of x
   x = x + 1;
}
