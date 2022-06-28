#pragma once
#include <iostream>
#include <string>
using namespace std;

/*
Develop software using dynamic arrays (using the new and
delete operators) that allows a user to enter the names of the
athletic equipment below.

1.  If Mark purchases two pairs of Nike basketball shoes,
three Under Armour T-shirts, four Nike shorts, and one
pair of Brooks running shoes; print a receipt for the
purchase including the total cost before and after tax.
Assume the tax rate is 8.25%
2.  Print an inventory list before and after Mark’s purchase.
3.  Add a copy constructor to your inventory management
class. Test the copy constructor by instantiating a new
inventory management object which is a copy of the
original. Print an inventory list for the new object. This
should match the original inventory.
4.  Your program must use pointer variables for all variables.
5.  Use at least one user defined namespace.
Run valgrind to check for memory leaks

Name of equipment       Cost    Quantity
Nike basketball shoes   $145.99 22
Under Armour T-shirt    $29.99  33
Brooks running shoes    $111.44 11
Asics running shoes     $165.88 20
Nike shorts             $45.77  77

6.  Maintain a transaction history of all items
purchased. Print an audit log of all transactions including cost &
quantity for items. Ensure the copy constructor from step 3 also
makes a copy of the transaction history.
*/