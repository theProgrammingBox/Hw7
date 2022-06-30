#pragma once

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

namespace Inventory
{
    struct Item
    {
        string name;
        int quantity;
        float cost;
    };

    const int MAX_SIZE = 50;

    class ManageInventory
    {
        friend ostream &operator<<(ostream &o, ManageInventory &object);

    public:
        ManageInventory() : count{0}, p_pInventoryItems{new Item *[size]} {}
        ManageInventory(int size) : size{size}, count{0}, p_pInventoryItems{new Item *[size]} {}
        ManageInventory(const ManageInventory &other); // Copy ctor
        ~ManageInventory();
        void addItem(string name, int quantity, float cost);
        void addToCart(ManageInventory &inventory, ManageInventory &cart, string name, int quantity);
        void printReceipt();
        // void printHistory();

    private:
        int size{MAX_SIZE};
        int count;
        Item **p_pInventoryItems;
    };
}
