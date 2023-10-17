#ifndef Product_cpp
#define Product_cpp

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include "money.cpp"

using namespace std;

class Product : public Money {
public:
    vector<string> Cars;
    vector<double> Quantity;
    vector<double> Price;
    vector<double> Need_to_refill;

    // void setCars(string cars){
    //     Cars = cars;
    // }
    // string getCars(){
    //     return Cars;
    // }
    // void setCPrice(double price){
    //     Price = price;
    // }
    // double getPrice(){
    //     return Price;
    // }
    Product(double coin_denominations[6], double quantity_of_coins[6], string cars[5], double quantity[5],
            double price[5], double need_to_refill[5])
            : Money(coin_denominations, quantity_of_coins) { // constructor
        for (int i = 0; i < 5; i++) {
            Cars.push_back(cars[i]);
            Quantity.push_back(quantity[i]);
            Price.push_back(price[i]);
            Need_to_refill.push_back(need_to_refill[i]);
        }
    }
};

#endif
