/* CSCI 261 Assignment 3: Sprockets-R-Us Shopping Cart
 *
 * Author: Eli Billinger
 *
 * Open and get data from product_public file
 * determine all totals needed
 * output data onto receipt file
 */
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main() {
    //variables for data in file
    double sprocketPrice;
    double salesTax;
    double minShippingOne;
    double minShippingTwo;
    double minShippingThree;
    double shippingRateOne;
    double shippingRateTwo;
    double shippingRateThree;
    double minShippingFree;
    int numSprockets;
    double unitSubTotal;
    double subTotal;
    double shippingFee;
    double totalSalesTax;
    double totalWithSales;
    char donation;
    double donationAmount;
    double roundResult;
    double grandTotal;
    // open file
    ifstream sprocketFile("product_public.txt");

    // check for error
    if(sprocketFile.fail()){
        cerr << "Error in opening file";
        return -1;
    }

    // read data from file
    sprocketFile >> sprocketPrice;
    sprocketFile >> salesTax;
    sprocketFile >> minShippingOne;
    sprocketFile >> shippingRateOne;
    sprocketFile >> minShippingTwo;
    sprocketFile >> shippingRateTwo;
    sprocketFile >> minShippingThree;
    sprocketFile >> shippingRateThree;
    sprocketFile >> minShippingFree;

    // close file
    sprocketFile.close();

    cout << "Welcome to SpWelcome to Sprockets-R-Us!" << endl;
    cout << "The cost of a single sprocket is $" << sprocketPrice << endl;
    cout << "How many sprockets do you wish to order" << endl;
    cin >> numSprockets;
    cout << "Thank you for your order of " << numSprockets << " sprockets. One moment while we prepare your recipet..." << endl;

    unitSubTotal = numSprockets * sprocketPrice;
    //determine shipping fee
    if(unitSubTotal >= minShippingOne && unitSubTotal < minShippingTwo){
        shippingFee = shippingRateOne;
    } else if (unitSubTotal >= minShippingTwo && unitSubTotal < minShippingThree){
        shippingFee = shippingRateTwo;
    } else if (unitSubTotal >= minShippingThree && unitSubTotal < minShippingFree){
        shippingFee = shippingRateThree;
    } else {
        shippingFee = 0.00;
        cout << "Thank you for your large purchase. You qualified for free shipping." << endl;
    }
    // determine needed values
    salesTax = salesTax/100;
    subTotal = unitSubTotal + shippingFee;
    totalSalesTax = subTotal * salesTax;
    totalWithSales = subTotal+totalSalesTax;


    roundResult = round(totalWithSales);
    // if not whole number than ask for donation
    if(totalWithSales != roundResult){
        cout << "Do you wish to make a donation to the Human Fund? (Y/N) \n > ";
        cin >> donation;
        if(donationAmount=='Y'){
            donationAmount = ceil(totalWithSales)-totalWithSales;
        }
    } else{
        donation = 'N';
        donationAmount = 0.00;
    }

    // determine grand total
    grandTotal = totalWithSales + donationAmount;
    cout << "Thank you for your order. Your grand total is $" << grandTotal << endl;
    // create receipt file and write in it
    ofstream receipt("receipt.txt");
    if(receipt.fail()){
        cerr << "Error in opening receipt.txt";
        return -1;
    }

    receipt << setfill('-') << setw(29) <<  right << "-" << endl;
    receipt << setfill(' ') << setw(29) << left << "Sprockets-R-Us Order Receipt" << endl;
    receipt << setfill('-') << setw(29) << right << "-" << endl;
    receipt << setfill(' ') << setw(19) << left << "Price per Unit:" <<  '$' << setw(9) << right << sprocketPrice << endl;
    receipt << setw(19) << left << "Quantity Ordered:" <<  setw(10) << right << numSprockets << endl;
    receipt << setw(19) << left << "Unit Subtotal:" << "$" << setw(9)<< right << unitSubTotal << endl;
    receipt << setfill('-') << setw(29) << right << "-" << endl;
    receipt << setfill(' ') << setw(19) << left << "Shipping Fee:" << "$" << setw(9) << right <<setprecision(2)<<fixed<< shippingFee << endl;
    receipt << setfill('-') << setw(29) << right << "-" << endl;
    receipt << setfill(' ') << setw(13) << left << "Sales Tax(" <<setw(3)<<(salesTax*100)<<"):$" << setw(9) << right <<setprecision(2) << fixed << totalSalesTax << endl;
    receipt << setfill('-') << setw(29) << right << "-" << endl;
    receipt << setfill(' ') << setw(19) << left << "Donation?" << setw(10) << right << donation << endl;
    if(donation == 'Y'){
        receipt << setw(19) << left << "Donation Amount:" << "$" << setw(9) << right << setprecision(2) << fixed <<donationAmount << endl;
    }
    receipt << setfill('=') << setw(29) << right << "=" << endl;
    receipt << setfill(' ') << setw(19) << left << "Grand Total:" << "$" << setw(9) << right <<setprecision(2)<< fixed << grandTotal << endl;
    receipt << setfill('=') << setw(29) << right << "=" << endl;

    receipt.close();
    return 0;
}
