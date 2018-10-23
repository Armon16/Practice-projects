#pragma once

#include <string>
using namespace std;

class GroceryItem {
private:
    string _name;
    int _quantity;
    float _unitPrice;
    bool _taxable;

public:
    GroceryItem();
// stores the items into the the private members
    GroceryItem(const string& productName, const int& quantityOfItem, const float& UnitPer, const bool& Taxables){
      _name = productName;
      _quantity = quantityOfItem;
      _unitPrice = UnitPer;
      _taxable = Taxables;
    }
// recieves the name of the item and then when called returns said name
    string getName() const{
      return _name;
    }
    void setName(const string& productName){
      _name = productName;
    }
    int getQuantity() const{
      return _quantity;
    }
    void setQuantity(const int& quantityOfItem){
      _quantity = quantityOfItem;
    }
    float getUnitPrice() const{
      return _unitPrice;
    }
    void setUnitPrice(const float& UnitPer){
      _unitPrice = UnitPer;
    }
    bool isTaxable() const{
      return _taxable;
    }
    void setTaxable(const bool& Taxables){
      _taxable = Taxables;
    }
};
