/*************************************************************************
 * AUTHOR     	 :
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
 * This program will demonstrate the use of pointers and
 * dynamic arrays through the use of the Inventory class.
 *_________________________________________________________
 * INPUT:
 *      none      -   There are no inputs for this program.
 *
 * OUTPUT:
 *      inventory  -   This will display the contents of the
 *                  inventory.
 *      inventory2  -   This will display the contents of the
 ***********************************************************/

int main()
{
    ManageInventory inventory(10);
    inventory.addItem("Nike basketball shoes", 22, 145.99);
    inventory.addItem("Under Armour T-shirt", 33, 29.99);
    inventory.addItem("Brooks running shoes", 11, 111.44);
    inventory.addItem("Asics running shoes", 20, 165.88);
    inventory.addItem("Nike shorts", 77, 45.77);

    ManageInventory inventory2(inventory);

    cout << inventory2 << endl;
    inventory2.printReceipt();

    return 0;
}

/*************************************************************************
 * Method : Class none
 * ----------------------------------------------------------------------
 * This function will
 * ----------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		//
 *
 * POST-CONDITIONS
 *      //
 *************************************************************************/