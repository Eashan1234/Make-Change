#include <iostream>
#include <iomanip>
#include <Windows.h>
using namespace std;

int main()
{
    bool replay = false;
    do{
        system("color F3");
        double price = 0.0;
        double payed = 0.0;
        double change = 0.0;
        double cents = 0.0;
        int cash = 0;
        int dollars = 0;
        int quarters = 0;
        int dimes = 0;
        int nickels = 0;
        int pennies = 0;
        char replayc = 'c';
        char mnu = '1';
        int quantity = 0;
        float total_price = 0.0;

        int fifty = 0;
        int twenty = 0;
        int ten = 0;
        int five = 0;
        int one = 0;

        const float OHIO_TAX_RATE = 0.0575;


        cout << "1 - Apple Airpods Pro - $249.99 \n";
        cout << "2 - Apple Airpods - $159.99 \n";
        cout << "3 - Samsung Galaxy S10+ - $999.99\n";
        cout << "4 - Apple Iphone 11 - 699.99\n";
        cout << "5 - Amazon Alexa Mini - 34.99\n";
        cout << "6 - Macbook Air - 1199.99\n";
        cout << "Enter your selection here: ";
        cin >> mnu;

        if (mnu == '1') {
            price = 249.99;
        }
        else if (mnu == '2') {
            price = 259.99;
        }
        else if (mnu == '3') {
            price = 999.99;
        }
        else if (mnu == '4') {
            price = 699.99;
        }
        else if (mnu == '5') {
            price = 34.99;
        }
        else if (mnu == '6') {
            price = 1199.99;
        }
        else {
            cout << "Enter purchase price:        ";
            cin >> price;
        }

        cout << "Quantity: ";
        cin >> quantity;

        price *= quantity;

        cout << setfill(' ') << setw(26) << " " << endl;
        cout << setfill('-') << setw(26) << " " << endl;
        cout << setfill(' ') << setw(26) << " " << endl;

        cout << "Subtotal: ";
        cout.width(14); cout << right << "$" << fixed << setprecision(2) << price << endl;

        cout << setfill(' ') << setw(26) << " " << endl;

        cout << "Ohio sales tax: " << setprecision(4) << OHIO_TAX_RATE << endl;

        price = price + (price * OHIO_TAX_RATE);

        cout << setfill(' ') << setw(26) << " " << endl;

        cout << "total: ";
        cout.width(17); cout << right << "$" << fixed << setprecision(2) << price << endl;

        cout << setfill(' ') << setw(26) << " " << endl;

        cout << "Date of transaction: ";
        char sdate[9];
        _strdate_s(sdate);
        cout << sdate << endl;

    
        /*time_t now = time(0);
        tm* ltm = localtime(&now);

        cout << "Time of transaction: " << ltm->tm_hour << ":";*/


        cout << "Enter amount recieved:       ";
        cin >> payed;

        if (payed > price) {
            change = abs(payed - price);
        }
        else {
            cout << "User did not pay enough...";
        }

        cout << "Change due: ";
        cout.width(18); cout << right << "$" << fixed << setprecision(2) << change << endl;

        cout << setfill(' ') << setw(26) << " " << endl;
        cout << setfill('-') << setw(26) << " " << endl;
        cout << setfill(' ') << setw(26) << " " << endl;

        cents = change - (int)(change);
        quarters = (int)(cents / 0.25);
        dimes = (int)((cents - (quarters * 0.25)) / 0.1);
        nickels = (int)((cents - (quarters * 0.25) - (dimes * 0.1)) / 0.05);
        pennies = (int)((cents - (quarters * 0.25) - (dimes * 0.1) - (nickels * 0.05)) / 0.01);
        pennies += 1;

        cash = (int)(change);
        fifty = (int)(cash / 50);
        twenty = (int)((cash - (fifty * 50)) /20);
        ten = (int)((cash - (fifty * 50) - (twenty * 20)) / 10);
        five = (int)((cash - (fifty * 50) - (twenty * 20) - (ten * 10)) / 5);
        dollars = (int)((cash - (fifty * 50) - (twenty * 20) - (ten * 10) - (five * 5)));

        /*cout << "Dollors: " << (int)change; cout.width(18); cout << right << fixed << setprecision(2) << (float)((int)change) << endl;
        cout << "Quarters: " << quarters; cout.width(17);  cout << right << fixed << setprecision(2) << quarters * 0.25 << endl;
        cout << "dimes: " << dimes; cout.width(20); cout << right << fixed << setprecision(2) << dimes * 0.1 << endl;
        cout << "nickels: " << nickels; cout.width(18); cout << right << fixed << setprecision(2) << nickels * 0.05 << endl;
        cout << "pennies: " << pennies; cout.width(18); cout << right << fixed << setprecision(2) << pennies * 0.01 << endl;*/

        if ((fifty * 50) > 9 && (float)(fifty * 50) < 100) {
            cout << "$50 bill: " << setw(12) << right << fixed << fifty << setw(17) << right << fixed << setprecision(2) << "$" << (float)(fifty * 50) << endl;
        }
        else if ((fifty * 50) > 99) {
            cout << "$50 bill: " << setw(12) << right << fixed << fifty << setw(16) << right << fixed << setprecision(2) << "$" << (float)(fifty * 50) << endl;
        }else {
            cout << "$50 bill: " << setw(12) << right << fixed << fifty << setw(18) << right << fixed << setprecision(2) << "$" << (float)(fifty * 50) << endl;
        }

        if ((float)(ten * 10) > 9 && (float)(ten * 10) < 100) {
            cout << "$10 bill: " << setw(12) << right << fixed << ten << setw(17) << right << fixed << setprecision(2) << "$" << (float)(ten * 10) << endl;
        }
        else if ((float)(ten * 10) > 99) {
            cout << "$10 bill: " << setw(12) << right << fixed << ten << setw(16) << right << fixed << setprecision(2) << "$" << (float)(ten * 10) << endl;
        }
        else {
            cout << "$10 bill: " << setw(12) << right << fixed << ten << setw(18) << right << fixed << setprecision(2) << "$" << (float)(ten * 10) << endl;
        }

        cout << "$5 bill: " << setw(13) << right << fixed << five << setw(18) << right << fixed << setprecision(2) << "$" << (float)(five * 5) << endl;
        cout << "$1 bill: " << setw(13) << right << fixed << dollars << setw(18) << right << fixed << setprecision(2) << "$" << (float)dollars << endl;
        cout << "Quarters: " << setw(12) << right << fixed << quarters << setw(18) << right << fixed << setprecision(2) << "$" << (float)(quarters * 0.25) << endl;
        cout << "dimes: " << setw(15) << right << fixed << dimes << setw(18) << right << fixed << setprecision(2) << "$" << (float)(dimes * 0.1) << endl;
        cout << "nickels: " << setw(13) << right << fixed << nickels << setw(18) << right << fixed << setprecision(2) << "$" << (float)(nickels * 0.05) << endl;
        cout << "pennies: " << setw(13) << right << fixed << pennies << setw(18) << right << fixed << setprecision(2) << "$" << (float)(pennies * 0.01) << endl;
        

        cout << setfill(' ') << setw(26) << " " << endl;
        cout << setfill('-') << setw(26) << " " << endl;
        cout << setfill(' ') << setw(26) << " " << endl;

        cout << "Change Total: " << change;

        cout << setfill(' ') << setw(26) << " " << endl;
        cout << setfill('-') << setw(26) << " " << endl;
        cout << setfill(' ') << setw(26) << " " << endl;

        cout << "            ***        ***             " << '\n';
        cout << "            ***        ***             " << '\n';
        cout << "    __                          __     " << '\n';
        cout << "      __                      __       " << '\n';
        cout << "         ____________________       " << '\n';

        cout << setfill(' ') << setw(26) << " " << endl;
        cout << setfill(' ') << setw(26) << " " << endl;
        cout << setfill(' ') << setw(26) << " " << endl;
        cout << setfill(' ') << setw(26) << " " << endl;
        cout << setfill(' ') << setw(26) << " " << endl;

        cout << "replay? ";
        cin >> replayc;
        if (replayc == 'r' || replayc == 'R') {
            replay = true;
        }
        else {
            replay = false;
        }
    } while (replay);
    
}
