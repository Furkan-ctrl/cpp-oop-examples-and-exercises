#ifndef ORDER_H
#define ORDER_H

#include <string>
#include <vector>
#include "Product.h"

using namespace std;

class Order {
private:
    int orderId;
    string customerName;
    vector<Product> orderedProducts;

public:
    
    Order(int o_id, string c_name) 
        : orderId(o_id), customerName(c_name) {}

   
    void addProduct(const Product& product) {
        orderedProducts.push_back(product);
    }

    
    double calculateOrderTotal() const {
        double total = 0.0;
        for (const auto& product : orderedProducts) {
            total += product.getProductPrice();
        }
        return total;
    }

    
    int getOrderID() const {
         return orderId;
    }

     string getCustomerName() const {
         return customerName; 
    }
    
    const vector<Product>& getOrderedProducts() const {
         return orderedProducts; 
    }
};

#endif 
