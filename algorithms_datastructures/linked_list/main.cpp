#include <iostream>
#include "linkedlist.h"

int main()
{
  LinkedList mylist;
  mylist.prepend(2);
  mylist.prepend(3);
  mylist.prepend(4);
  mylist.prepend(5);
  mylist.append(100);
  mylist.print();
  mylist.reverse();
  mylist.print();
  mylist.remove(3);
  mylist.print();
  mylist.remove(100);
  mylist.print();
  mylist.remove(5);
  mylist.print();
}