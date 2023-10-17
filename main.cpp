#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include "money.cpp"
#include "product.cpp"
#include "vending_machine.cpp"

using namespace std;

string cars[5] = {"Volvo", "BMW", "Ford", "Mazda", "Ferrari"}; // initial values

double quantity[5] = {100, 20, 200, 150, 1}; // initial values

double price[5] = {10, 20, 5, 7, 100}; // initial values

double need_to_refill[5] = {0, 0, 0, 0, 0}; // initial values

double coin_denominations[6] = {5, 2, 1, 0.5, 0.2, 0.1};

double quantity_of_coins[6] = {10, 10, 10, 10, 10, 10};

int main() {

    VendingMachine machine = VendingMachine(coin_denominations, quantity_of_coins, cars, quantity, price,
                                            need_to_refill);

//    while (1==1){



    machine.save_to_file_product("/Users/michalkielkowski/Desktop/infa-all/Vending-Machine/product.txt");
    machine.read_from_file_product("/Users/michalkielkowski/Desktop/infa-all/Vending-Machine/product.txt");
    cout << "\n";
    cout << "Products:\n";
    cout << "\n";
    machine.print_from_file_product();

    machine.save_to_file_money("/Users/michalkielkowski/Desktop/infa-all/Vending-Machine/money.txt");
    machine.read_from_file_money("/Users/michalkielkowski/Desktop/infa-all/Vending-Machine/money.txt");
    cout << "\n";
    cout << "\n";
    cout << "Coins in the machine:\n";
    cout << "\n";
    machine.print_from_file_money();

    machine.secret_code();

    cout << endl
         << "pick your car: ";
    int pick;
    cin >> pick;
    int pickquantity;
    cout << "\n";
    cout << "you choosen: " << cars[pick] << " \n";
    cout << endl
         << "choose quantity: ";
    cin >> pickquantity;

    machine.pick_product_and_quantity(pick, pickquantity);

    machine.cash_pool(" before cash in");

    machine.payment(pick, pickquantity);

    machine.user_payment();

    machine.display_vector();

    machine.adding_to_coins();

    machine.save_to_file_money_updated("/Users/michalkielkowski/Desktop/infa-all/Vending-Machine/money.txt");

    machine.cash_pool(" after inserting money into the machine");

    machine.return_of_money();

    machine.read_from_file_money("/Users/michalkielkowski/Desktop/infa-all/Vending-Machine/money.txt");

    machine.returning_money();

    machine.updatequntity(pick, pickquantity);

    machine.save_to_file_money_updated("/Users/michalkielkowski/Desktop/infa-all/Vending-Machine/money.txt");

    machine.save_to_file_product_updated("/Users/michalkielkowski/Desktop/infa-all/Vending-Machine/product.txt");

    machine.reset_user_money_inserted();


    machine.save_to_file_product("/Users/michalkielkowski/Desktop/infa-all/Vending-Machine/product.txt");
    machine.read_from_file_product("/Users/michalkielkowski/Desktop/infa-all/Vending-Machine/product.txt");
    cout << "\n";
    cout << "Products:\n";
    cout << "\n";
    machine.print_from_file_product();

    machine.save_to_file_money("/Users/michalkielkowski/Desktop/infa-all/Vending-Machine/money.txt");
    machine.read_from_file_money("/Users/michalkielkowski/Desktop/infa-all/Vending-Machine/money.txt");
    cout << "\n";
    cout << "\n";
    cout << "Coins in the machine:\n";
    cout << "\n";
    machine.print_from_file_money();

//    }
}