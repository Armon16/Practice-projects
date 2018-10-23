#pragma once

#include <vector>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "GroceryItem.h"
using namespace std;

class GroceryInventory {
private:
    vector<GroceryItem> _inventory;
    float _taxRate;

public:
    GroceryInventory(){

    }
// grabs information from the txt file to find an item and if the item is not found it will return "Item not found"
    GroceryItem& getEntry(const string& productInfo){
      int i;
      for (i = 0 ; i <  _inventory.size(); i++) {
        if (productInfo == _inventory[i].getName()) {
           return _inventory[i];
        }
      }
      throw std::runtime_error("Item not found");
    }
//pull information linked to a spefic item
    void addEntry(const string& nameOfItem, const int& quantityOfItem, const float& UnitPer, const bool& Taxables){
      GroceryItem unit = GroceryItem(nameOfItem,quantityOfItem,UnitPer,Taxables);
      _inventory.push_back(unit);
    }

    float getTaxRate() const{
      return _taxRate;
    }
    void setTaxRate(const float& TaxRates){
      _taxRate= TaxRates;
    }

    void createListFromFile(const string&);
// pull the price per item and the amount stored and calculates the total price of everything on hand excluding tax
    float calculateUnitRevenue() const{
      float UnitRevenue = 0;
      for (int i = 0; i < _inventory.size(); i++) {
          UnitRevenue += _inventory[i].getUnitPrice() * _inventory[i].getQuantity();
        }
        return UnitRevenue;
      }
// pull all the info for any items that are taxable and calculates the total amount of tax you will recieve from all these items
    float calculateTaxRevenue() const{
      float TaxRevenue = 0;
      for (int i = 0; i < _inventory.size(); i++) {
        if (_inventory[i].isTaxable() == true) {
          TaxRevenue +=_inventory[i].getUnitPrice() * getTaxRate() * _inventory[i].getQuantity() / 100;
        }
      }
      return TaxRevenue;
    }
// calculates the total revenue of all items and tax
    float calculateTotalRevenue() const{
      float TotalRevenue = 0;
      TotalRevenue = calculateTaxRevenue() + calculateUnitRevenue();
      return TotalRevenue;
    }

    GroceryItem& operator[](const int&);
};

void GroceryInventory::createListFromFile(const string& filename) {
    ifstream input_file(filename);

    if (input_file.is_open()) {
        cout << "Successfully opened file " << filename << endl;
        string name;
        int quantity;
        float unit_price;
        bool taxable;
        while (input_file >> name >> quantity >> unit_price >> taxable) {
            addEntry(name, quantity, unit_price, taxable);
        }
        input_file.close();
    } else {
        throw invalid_argument("Could not open file " + filename);
    }
}
