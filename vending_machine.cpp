#ifndef Vending_machine_cpp
#define Vending_machine_cpp

#include "product.cpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <cmath>

using namespace std;

class VendingMachine : public Product {
public:
    double denomination_of_coins[6];
    double quantity_of_coins[6];
    string cars[5];
    double price[5];
    double quantity[5];
    double need_to_refill[5];
    int operation_money = 1;
    int operation_product = 1;
    double need_to_pay;
    vector<double> user_denomination;
    vector<double> user_quantity;
    double rest_of_money;

    VendingMachine(double coin_denominations[6], double quantity_of_coins[6], string cars[5], double quantity[5],
                   double price[5], double need_to_refill[5])
            : Product(coin_denominations, quantity_of_coins, cars, quantity, price, need_to_refill) { // constructor
    }

    void save_to_file_product(string name_of_file) {
        if (operation_product == 1) {
            fstream product;
            product.open(name_of_file, ios::in | ios::out);
            if (product.tellg() == 0) {
                cout << "\n";
                cout << "file already has the data" << endl;
            } else {
                cout << "file empty saving data" << endl;
                for (int i = 0; i < 5; i++) {
                    product << Cars[i];
                    product << " ";
                    product << Quantity[i];
                    product << " ";
                    product << Price[i];
                    product << " ";
                    product << Need_to_refill[i] << "\n";
                }
            }
        }

    }


    void read_from_file_product(string name_of_file) {
        operation_product = 2;
        fstream product;
        product.open(name_of_file, ios::in | ios::out);

        if (product.good() == true) {
            for (int i = 0; i < 5; i++) {
                product >> cars[i] >> quantity[i] >> price[i] >> need_to_refill[i];
            }
        }
    }

    void print_from_file_product() {
        for (int i = 0; i < 5; i++) {
            cout << cars[i] << " ";
            cout << "quantity: ";
            cout << quantity[i] << " ";
            cout << "price: ";
            cout << price[i] << "\n";
        }
    }

    void save_to_file_money(string name_of_file) {
        if (operation_money == 1) {
            fstream coins;
            coins.open(name_of_file, ios::in | ios::out);
            if (coins.tellg() == 0) {
                cout << "\n";
                cout << "file already has the data" << endl;
            } else {
                for (int i = 0; i < 6; i++) {
                    coins << Coin_denominations[i];
                    coins << " ";
                    coins << Quantity_of_coins[i] << "\n";
                }
            }
        }

    }

    void read_from_file_money(string name_of_file) {
        operation_money = 2;
        fstream coins;
        coins.open(name_of_file, ios::in | ios::out);

        if (coins.good() == true) {
            for (int i = 0; i < 6; i++) {
                coins >> denomination_of_coins[i] >> quantity_of_coins[i];
            }
        }
    }

    void print_from_file_money() {
        for (int i = 0; i < 6; i++) {
            cout << denomination_of_coins[i] << "zł ";
            cout << "quantity: ";
            cout << quantity_of_coins[i] << "\n";
        }
    }

    void secret_code() {

        int secret_code;
        cout << endl
             << "secret code: ";
        cin >> secret_code;

        if (secret_code == 1101) {
            vector<double> change_quantity;
            int i;
            while (i <= 6) {
                i++;
                double new_quantity;
                cout << "\n";
                cin >> new_quantity;
                cout << "\n";
                change_quantity.push_back(new_quantity);
            }
            fstream coins;
            coins.open("money.txt", ios::in | ios::out);

            for (int i = 0; i < 6; i++) {
                coins << denomination_of_coins[i];
                coins << " ";
                coins << change_quantity[i] << "\n";
            }
            coins.close();
            // exit(0);
        }
    }

    void pick_product_and_quantity(int pick, int pickquantity) {

        if (pickquantity > quantity[pick] && pickquantity != 420) {
            cout << endl
                 << "not enough quantity of product in the machine "
                 << " \n";
        } else if (pickquantity == 420) {
            cout << endl
                 << ": ) "
                 << " \n";
        } else if (pickquantity <= quantity[pick]) {
            string text;
            text = " before cash in";
            cout << endl
                 << "good quantity  "
                 << "\n";
        }
    }

    void cash_pool(string when) {
        double all_money;
        for (int i = 0; i < 6; i++) {
            all_money += denomination_of_coins[i] * quantity_of_coins[i];
        }
        cout << "\n";
        cout << "all money in the machine " << all_money << when << "\n";
    }

    double payment(int price_of_product, double quantity) {

        need_to_pay = quantity * price[price_of_product];
        cout << "\n";
        cout << "pay: " << need_to_pay << " \n";
        return need_to_pay;
    }

    void user_payment() {
        double user_pay;
        user_pay = 0;
        double diffrence;
        while (need_to_pay >= user_pay && diffrence != 0) {
            cout << "how much you paid already " << user_pay << " zł";
            double coin;
            double quantity;
            cout << endl
                 << "choose coin denomination: ";
            cin >> coin;
            user_denomination.push_back(coin);
            cout << endl
                 << "choose quantity: ";
            cin >> quantity;
            user_quantity.push_back(quantity);
            user_pay += coin * quantity;

            cout << "how much you still need to pay " << need_to_pay - user_pay << " zł"
                 << "\n";
            diffrence = need_to_pay - user_pay;
        }

        cout << "price payed"
             << "\n";
    }

    void display_vector() {
        cout << "money which you put in machine"
             << "\n";
        for (int i = 0; i < user_denomination.size(); i++) {
            cout << "coin: ";
            cout << user_denomination[i] << "zł";
            cout << " ";
            cout << "quantity: ";
            cout << user_quantity[i] << "\n";
        }
    }

    void adding_to_coins() {
        for (int i = 0; i < user_denomination.size(); i++) {
            if (user_denomination[i] == 5) {
                quantity_of_coins[0] += user_quantity[i];
            } else if (user_denomination[i] == 2) {
                quantity_of_coins[1] += user_quantity[i];
            } else if (user_denomination[i] == 1) {
                quantity_of_coins[2] += user_quantity[i];
            } else if (user_denomination[i] == 0.5) {
                quantity_of_coins[3] += user_quantity[i];
            } else if (user_denomination[i] == 0.2) {
                quantity_of_coins[4] += user_quantity[i];
            } else if (user_denomination[i] == 0.1) {
                quantity_of_coins[5] += user_quantity[i];
            }
        }
    }

    void save_to_file_money_updated(string name_of_file) {

        fstream coins;
        coins.open(name_of_file, ios::in | ios::out);
        for (int i = 0; i < 6; i++) {
            coins << denomination_of_coins[i];
            coins << " ";
            coins << quantity_of_coins[i] << "\n";
        }
    }
//  HERE THE SORTING ALGORITHM STARTS

    double return_of_money() {
        double user_pay;
        for (int i = 0; i < user_denomination.size(); i++) {
            user_pay += user_denomination[i] * user_quantity[i];
        }
        cout << "price of the product: " << need_to_pay << "\n";
        cout << "money inserted: " << user_pay << "\n";
        rest_of_money = user_pay - need_to_pay;
        cout << "rest: " << rest_of_money << "\n";
        return rest_of_money;
    }

    void sort(double (*coin_info)[2]) {
        // Bubble sort the 2D array in descending order based on quantity
        for (int i = 0; i < 6 - 1; ++i) {
            for (int j = 0; j < 6 - i - 1; ++j) {
                if (coin_info[j][1] < coin_info[j + 1][1]) {
                    // Swap the rows
                    double tempDenomination = coin_info[j][0];
                    double tempQuantity = coin_info[j][1];
                    coin_info[j][0] = coin_info[j + 1][0];
                    coin_info[j][1] = coin_info[j + 1][1];
                    coin_info[j + 1][0] = tempDenomination;
                    coin_info[j + 1][1] = tempQuantity;
                }
            }
        }
    }

    void returning_money() {
        int prior;
        double coin_info[6][2];
        for (int i = 0; i < 6; ++i) {
            coin_info[i][0] = denomination_of_coins[i];
            coin_info[i][1] = quantity_of_coins[i];
        }
        while (rest_of_money >= 0) {
            sort(coin_info);
            // Print the sorted 2D array
            for (int i = 0; i < 6; ++i) {
                cout << "Denomination: " << coin_info[i][0] << ", Quantity: " << coin_info[i][1] << endl;
            }
            for (int i = 0; i < 6; i++) {
                bool coinPicked = false; // Flag to track if a coin was picked in this iteration
                if (rest_of_money >=
                    coin_info[i][0]) {
                    for (int j = 0; j < 6; j++) {
                        if (coin_info[i][0] == denomination_of_coins[j]) {
//                            cout << "condition satisfied ";
//                            cout << "coin info: " << coin_info[i][0] << " == " << denomination_of_coins[j]
//                                 << ": temporary" << endl;
                            while ((coin_info[i][1] >= coin_info[i + 1][1]) && rest_of_money >= coin_info[i][0]) {
                                cout << "icked coin denomination: " << coin_info[i][0] << "zł" << "\n";
//                                cout << "corresponding coin quantity: " << coin_info[i][1] << "\n";
                                rest_of_money -= denomination_of_coins[j];
                                rest_of_money = max(0.0, round(rest_of_money * 100) / 100);
                                quantity_of_coins[j] -= 1;
                                coin_info[i][1] -= 1;
                                if (rest_of_money != 0) {
                                    cout << "still need to return " << rest_of_money << "zł" << "\n";
                                    sort(coin_info);
                                    coinPicked = true; // Set the flag if a coin was picked
                                    break; // Exit the inner loop
                                } else {
//                                    cout << "rest should equal to 0. rest of money: " << rest_of_money << "\n";
                                }
                            }
//                            cout << "quantity priority change and " << rest_of_money << " >= " << coin_info[i][0]
//                                 << endl;
                            cout << "p"; // how does this change the result

                        }
                    }
                }
                if (coinPicked) {
                    i = -1; // Set to -1 so that in the next iteration it becomes 0
                    coinPicked = false; // Reset the flag
//                    cout << "flag raised" << endl;
                }
            }
            fstream coins;
            coins.open("money.txt", ios::in | ios::out);
            for (int i = 0; i < 6; i++) {
                coins << denomination_of_coins[i];
                coins << " ";
                coins << quantity_of_coins[i] << "\n";
            }
            coins.close();
//            cout << "at the end: " << rest_of_money << endl;
            break; // this is the break that breaks out of the while loop even if the condition is not satisfied
        }
        cout << "roceeding with the rest of the money = " << rest_of_money << "\n";
//        cout << "job done" << endl;
    }

    void updatequntity(int choosenproduct, int choosenquantity) {
        quantity[choosenproduct] = quantity[choosenproduct] - choosenquantity;
        cout << "\n";
        cout << "updated quantity of bought product " << quantity[choosenproduct] << " \n";
    }

    void check_need_to_refill() {
        for (int i = 0; i < 5; i++) {
            if (0 == quantity[i]) {
                fstream product;
                product.open("product.txt", std::ios::out | std::ios::app);
                if (product.good() == true) {
                    // string info = "this product need to be refiled ";
                    // string certain_product = cars[i];
                    // file << info;
                    // file << certain_product;
                    need_to_refill[i] = 1;
                    product.close();
                }
            }
        }
    }

    void save_to_file_product_updated(string name_of_file) {

        fstream product;
        product.open(name_of_file, ios::in | ios::out);
        for (int i = 0; i < 5; i++) {
            product << cars[i];
            product << " ";
            product << quantity[i];
            product << " ";
            product << price[i];
            product << " ";
            product << need_to_refill[i] << "\n";
        }
    }

    void reset_user_money_inserted() {
        for (int i = 0; i < user_denomination.size(); i++) {
            user_denomination[i] = 0;
            user_quantity[i] = 0;
        }
    }

};

#endif