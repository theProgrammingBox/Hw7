#pragma once

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

namespace Inventory
{
    const int MAX_SIZE = 50;

    struct Item
    {
        string name;
        int quantity;
        float cost;
    };

    class ManageInventory
    {
    public:
        ManageInventory() : size(MAX_SIZE), count{0}, p_pInventoryItems{new Item *[MAX_SIZE]} {}
        ManageInventory(int size = MAX_SIZE) : size{size}, count{0}, p_pInventoryItems{new Item *[size]} {}
        ManageInventory(const ManageInventory &other);
        ~ManageInventory();

        void AddItem(string name, int quantity, float cost);
        void TransferTo(ManageInventory &inventory, string name, int quantity);
        void PrintReceipt();
        void Buy(ManageInventory &history);

    private:
        int size;
        int count;
        Item **p_pInventoryItems;

        string CostToString(float cost);
        friend ostream &operator<<(ostream &o, ManageInventory &object);
    };
}
