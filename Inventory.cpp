#include "Inventory.h"

ostream &operator<<(ostream &o, ManageInventory &object)
{
    for (int i = 0; i < object.count; i++)
    {
        o << "Object: " << object.p_pInventoryItems[i]->name
          << " Quantity: " << object.p_pInventoryItems[i]->quantity
          << " Price: $" << object.p_pInventoryItems[i]->cost
          << endl;
    }

    return o;
}

void ManageInventory::addItem(string name, int quantity, float cost)
{
    // count use post increment
    p_pInventoryItems[count++] = new Item{name, quantity, cost};
}

// Destructor
ManageInventory::~ManageInventory()
{
    // Destroys each ptr obj in p_pInventoryItems array
    for (int i = 0; p_pInventoryItems[i] != nullptr; i++)
    {
        delete p_pInventoryItems[i];
    }
    delete[] p_pInventoryItems;
}

void ManageInventory::printReceipt()
{
    float total = 0;
    for (int i = 0; i < count; i++)
    {
        total += p_pInventoryItems[i]->cost * p_pInventoryItems[i]->quantity;
    }
    cout << "Total (Before tax): $" << total << endl;
    // after 8.25% tax
    cout << "Total (After tax): $" << total * 1.0825 << endl;
}