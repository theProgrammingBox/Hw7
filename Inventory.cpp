#include "Inventory.h"

namespace Inventory
{
    /*************************************************************************
     * Method ManageInventory: Class Inventory
     * ----------------------------------------------------------------------
     * This function will copy the contents of the other object into this object.
     * ----------------------------------------------------------------------
     * PRE-CONDITIONS
     * 		none
     *
     * POST-CONDITIONS
     *      The contents of the other object will be copied into this object.
     *************************************************************************/

    ManageInventory::ManageInventory(const ManageInventory &other) : size{other.size}, count{other.count}, p_pInventoryItems{new Item *[other.size]}
    {
        for (int i = 0; i < other.count; i++)
        {
            p_pInventoryItems[i] = new Item{*other.p_pInventoryItems[i]};
        }
    }

    /*************************************************************************
     * Method ~ManageInventory: Class Inventory
     * ----------------------------------------------------------------------
     * This function will delete the contents of this object.
     * ----------------------------------------------------------------------
     * PRE-CONDITIONS
     * 		none
     *
     * POST-CONDITIONS
     *      The contents of this object will be deleted.
     *************************************************************************/

    ManageInventory::~ManageInventory()
    {
        for (int i = 0; i < count; i++)
        {
            delete p_pInventoryItems[i];
        }
        delete[] p_pInventoryItems;
    }

    /*************************************************************************
     * Method addItem: Class Inventory
     * ----------------------------------------------------------------------
     * This function will add an item to the inventory.
     * ----------------------------------------------------------------------
     * PRE-CONDITIONS
     * 		string name: The name of the item.
     *      int quantity: The quantity of the item.
     *      float cost: The cost of the item.
     *
     * POST-CONDITIONS
     *      The item will be added to the inventory.
     *************************************************************************/

    void ManageInventory::AddItem(string name, int quantity, float cost)
    {
        if (count == size)
        {
            cout << "This inventory is full.\n";
        }
        else
        {
            p_pInventoryItems[count] = new Item;
            p_pInventoryItems[count]->name = name;
            p_pInventoryItems[count]->quantity = quantity;
            p_pInventoryItems[count]->cost = cost;
            count++;
        }
    }

    /*************************************************************************
     * Method TransferTo: Class Inventory
     * ----------------------------------------------------------------------
     * This function will transfer an item from this object to another object.
     * ----------------------------------------------------------------------
     * PRE-CON
     *     ManageInventory &inventory: The inventory to transfer the item to.
     *     string name: The name of the item.
     *     int quantity: The quantity of the item.
     * 
     * POST-CON
     *     The item will be transferred from this object to the other object.
     *************************************************************************/

    void ManageInventory::TransferTo(ManageInventory &inventory, string name, int quantity)
    {
        for (int i = 0; i < count; i++)
        {
            if (p_pInventoryItems[i]->name == name)
            {
                if (p_pInventoryItems[i]->quantity < quantity)
                {
                    cout << "Not enough of this item in this inventory.\n";
                    return;
                }
                else
                {
                    bool foundTitle = false;
                    for (int j = 0; j < inventory.count; j++)
                    {
                        if (inventory.p_pInventoryItems[j]->name == name)
                        {
                            foundTitle = true;
                            inventory.p_pInventoryItems[j]->quantity += quantity;
                            p_pInventoryItems[i]->quantity -= quantity;
                            break;
                        }
                    }
                    if (!foundTitle)
                    {
                        inventory.AddItem(name, quantity, p_pInventoryItems[i]->cost);
                        p_pInventoryItems[i]->quantity -= quantity;
                    }
                    cout << quantity << " of " << name << " was transferred to the inventory.\n";
                    return;
                }
            }
        }
        cout << "This item is not in this inventory.\n";
    }

    /*************************************************************************
     * Method PrintReceipt: Class Inventory
     * ----------------------------------------------------------------------
     * This function will print the receipt of the transaction.
     * ----------------------------------------------------------------------
     * PRE-CON
     *     none
     *
     * POST-CON
     *     The receipt will be printed.
     *************************************************************************/

    void ManageInventory::PrintReceipt()
    {
        float total = 0;
        for (int i = 0; i < count; i++)
        {
            total += p_pInventoryItems[i]->cost * p_pInventoryItems[i]->quantity;
        }
        cout << "Receipt before tax: " << total << endl;
        cout << "Receipt after tax: " << total * 1.0825 << endl;
    }

    /*************************************************************************
     * Method Buy: Class Inventory
     * ----------------------------------------------------------------------
     * This function will buy all the items in the inventory and add them to the
     * history.
     * ----------------------------------------------------------------------
     * PRE-CON
     *     ManageInventory &history: The inventory to transfer the item to.
     * 
     * POST-CON
     *     The items will be transferred from this object to the other object.
     *************************************************************************/
    
    void ManageInventory::Buy(ManageInventory &history)
    {
        PrintReceipt();
        for (int i = 0; i < count; i++)
        {
            TransferTo(history, p_pInventoryItems[i]->name, p_pInventoryItems[i]->quantity);
        }
    }
    //CostToString
    /*************************************************************************
     * Method CostToString: Class Inventory
     * ----------------------------------------------------------------------
     * This function will convert the cost to a string.
     * ----------------------------------------------------------------------
     * PRE-CON
     *     float cost: The cost of the item.
     *
     * POST-CON
     *     The cost will be converted to a string.
     *************************************************************************/

    string ManageInventory::CostToString(float cost)
    {
        string costStr = to_string(cost);
        string costStrOut = "";
        int index = 0;
        int size = costStr.size();
        while (index < size)
        {
            if ((size - index) % 3 == 0 && index != 0 && index != size - 1)
            {
                costStrOut += ",";
            }
            costStrOut += costStr[index];
            index++;
        }
        return "$" + costStrOut;
    }

    /*************************************************************************
     * Method operator<<: Class Inventory
     * ----------------------------------------------------------------------
     * This function will display the contents of the inventory.
     * ----------------------------------------------------------------------
     * PRE-CONDITIONS
     * 		outstream &o: The output stream.
     *      ManageInventory &object: The object to be displayed.
     *
     * POST-CONDITIONS
     *      The contents of the object will be displayed.
     *************************************************************************/

    ostream &operator<<(ostream &o, ManageInventory &inventory)
    {
        if (inventory.count == 0)
        {
            o << "This inventory is empty." << endl;
        }
        else
        {
            o << setw(20) << "Name" << setw(10) << "Quantity" << setw(10) << "Cost" << endl;
            for (int i = 0; i < inventory.count; i++)
            {
                o << setw(20) << inventory.p_pInventoryItems[i]->name
                  << setw(10) << inventory.p_pInventoryItems[i]->quantity
                  << setw(10) << inventory.CostToString(inventory.p_pInventoryItems[i]->cost) << endl;
            }
        }

        return o;
    }
}