#include <iostream>
#include "DoublyLinkedList.h"

using namespace std;

int main() {
   // Place your code here to test your solution
   DoublyLinkedList<int> list;
   
   list.Append(1);
   list.Append(3);
   list.Append(5);
   list.Append(7);
   list.Append(9);
   
   list.Print();
   list.PrintReverse();
   
   
   
   return 0;
}
