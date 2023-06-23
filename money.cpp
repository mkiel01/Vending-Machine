#ifndef Money_cpp
#define Money_cpp
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
class Money
{
public:
    vector<double> Coin_denominations;
    vector<double> Quantity_of_coins;

    // void setCoin_denominations(){
    //  for (int i = 0; i < 6; i++) {
    //     Coin_denominations.push_back(coin_denominations[i]);
    //  }
    // }
    // void getCoin_denominations(){
    //     // return Coin_denominations;
    // }
    // void setCQuantity_of_coins(double quantity_of_coins[6]){
    //      for (int i = 0; i < 6; i++) {
    //     Quantity_of_coins.push_back(quantity_of_coins[i]);
    //  }
    // }
    // void getQuantity_of_coins(){
    //     // return Quantity_of_coins;
    // }
    Money(double coin_denominations[6], double quantity_of_coins[6])
    { // constructor
        for (int i = 0; i < 6; i++)
        {
            Coin_denominations.push_back(coin_denominations[i]);
            Quantity_of_coins.push_back(quantity_of_coins[i]);
        }
    }
};
#endif
