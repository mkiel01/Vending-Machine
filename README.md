# Vending-Machine

C++ vending machine object-oriented programming project.

## About
This project simulates a functioning vending machine with the following features:

- Customers can view and purchase products.
- Technicians can modify product quantities.
- Data is stored in .txt files.
- The machine calculates and dispenses change based on coin quantities.
- The machine handles common user errors, such as attempting to buy out-of-stock products or using invalid coin denominations.

## Technologies

- Object-oriented Programming with Classes (inheritance, accessibility, constructors, etc.).
- File Operations for reading and writing .txt files.
- Bubble Sort Algorithm.
- Functions for various operations.

## Sorting algorithm 
_Below is the most interesting part of the project the sorting algorithm code_

```cpp
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
                            cout << "condition satisfied ";
                            cout << "coin info: " << coin_info[i][0] << " == " << denomination_of_coins[j]
                                 << ": temporary" << endl;
                            while ((coin_info[i][1] >= coin_info[i + 1][1]) && rest_of_money >= coin_info[i][0]) {
                                cout << "picked coin denomination: " << coin_info[i][0] << "zł" << "\n";
                                cout << "corresponding coin quantity: " << coin_info[i][1] << "\n";
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
                                    cout << "rest should equal to 0. rest of money: " << rest_of_money << "\n";
                                }
                            }
                            cout << "quantity priority change and " << rest_of_money << " >= " << coin_info[i][0]
                                 << endl;
                        }
                    }
                }
                if (coinPicked) {
                    i = -1; // Set to -1 so that in the next iteration it becomes 0
                    coinPicked = false; // Reset the flag
                    cout << "flag raised" << endl;
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
            cout << "at the end: " << rest_of_money << endl;
            break; // this is the break that breaks out of the while loop even if the condition is not satisfied
        }
        cout << "after rest: " << rest_of_money << "\n";
        cout << "job done" << endl;
    }
```

### Visualization 

## Getting started 
To get a local copy up and running follow these simple example steps.

### Installation
_Below is an example of how you can install and set up your app._

1. Download and set up a C++ environment. 
2. Clone the repo.
   ```sh
   git clone https://github.com/your_username_/Project-Name.git
    ```
   
### License

This project is licensed under the MIT License - see the [LICENSE](https://github.com/mkiel01/Vending-Machine/blob/main/LICENSE) file for details.


