#include "Inventory.h"

namespace Inventory
{
    ostream &operator<<(ostream &o, ManageInventory &object)
    {
        for (int i = 0; i < object.count; i++)
        {
            o << "Equipment: " << object.p_pInventoryItems[i]->name
              << " Quantity: " << object.p_pInventoryItems[i]->quantity
              << " Cost: $" << object.p_pInventoryItems[i]->cost
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
    void ManageInventory::printHistory()
    {
        cout << "Transaction History: " << endl;
        for (int i = 0; i < count; i++)
        {
            cout << "Equipment: " << p_pInventoryItems[i]->name
                 << " Quantity: " << p_pInventoryItems[i]->quantity
                 << " Cost: $" << p_pInventoryItems[i]->cost
                 << endl;
        }
    }

    ManageInventory::ManageInventory(const ManageInventory &other) : size{other.size}, count{other.count}, p_pInventoryItems{new Item *[other.size]}
    {
        for (int i = 0; i < other.count; i++)
        {
            p_pInventoryItems[i] = new Item{*other.p_pInventoryItems[i]};
        }
    }
}