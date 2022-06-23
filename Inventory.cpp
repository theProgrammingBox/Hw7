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
