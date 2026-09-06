#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

using namespace std;

class Product {
private:
    int id;
    string name;
    double price;

public:
    Product(int p_id, string p_name, double p_price) 
        : id(p_id), name(p_name), price(p_price) {}

    
    int getProductID() const {
         return id; 
    }

    string getProductName() const {
         return name; 
    }

    double getProductPrice() const {
         return price; 
    }
};

#endif 
