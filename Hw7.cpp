/*************************************************************************
 * AUTHOR     	 : Justin Gea
 * Assignment #7 : Pointers & Dynamic Arrays
 * CLASS      	 : CS 1C
 * SECTION    	 : MTWTTH 03:00pm - 05:35pm
 * DUE DATE   	 : 06/30/2022
 *************************************************************************/

#include "Inventory.h"

using namespace Inventory;

/**********************************************************
 *
 * Pointers & Dynamic Arrays
 *_________________________________________________________
 * This program will use pointers and dynamic arrays to
 * create a program that will manage an inventory of
 * equipment. The program will allow the user to add,
 * remove, and modify equipment through the cart and
 * history.
 *_________________________________________________________
 * INPUT:
 *      none    -   There are no inputs for this program.
 *
 * OUTPUT:
 *      inventory   -   This will display the contents of inventory1.
 *      inventory2  -   This will display the contents of inventory2.
 *      cart        -   This will display the contents of cart.
 *      history     -   This will display the contents of history.
 ***********************************************************/

int main()
{
    ManageInventory inventory(100);
    ManageInventory cart(100);
    ManageInventory history(100);

    inventory.AddItem("Nike basketball shoes", 22, 145.99);
    inventory.AddItem("Under Armour T-shirt", 33, 29.99);
    inventory.AddItem("Brooks running shoes", 11, 111.44);
    inventory.AddItem("Asics running shoes", 20, 165.88);
    inventory.AddItem("Nike shorts", 77, 45.77);
    cout << "Inventory:\n" << inventory << endl;
    cout << "Cart:\n" << cart << endl;
    cout << "History:\n" << history << endl;

    inventory.TransferTo(cart, "Nike basketball shoes", 2);
    inventory.TransferTo(cart, "Under Armour T-shirt", 3);
    inventory.TransferTo(cart, "Nike shorts", 4);
    inventory.TransferTo(cart, "Brooks running shoes", 1);
    cout << endl;
    ManageInventory inventory2(inventory);
    cout << "Inventory2:\n" << inventory2 << endl;
    cout << "Cart:\n" << cart << endl;
    cout << "History:\n" << history << endl;

    cart.Buy(history);
    cout << "Inventory2:\n" << inventory2 << endl;
    cout << "Cart:\n" << cart << endl;
    cout << "History:\n" << history << endl;
    return 0;
}