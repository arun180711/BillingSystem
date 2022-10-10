#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include<conio.h>
using namespace std;

class billing
{
private:
    string name;
    int phone_number;
    string address3;
    string product;
    int qnty;
    long int amnt;
    unsigned int fileSeq;
    ifstream seqFileIn;
    ofstream seqFileOut;


public:
    void setDetails()
    {
        cout << "ENTER YOUR NAME           : ";
		cin >> name;
		cout << "ENTER YOUR PHONE NUMBER   : ";
		cin >> phone_number;
		int temp = phone_number;
        int len=0;
        while (temp != 0)
        {
            temp /= 10;
            ++len;
        }
		if(len==10)
        {
            cout << "ENTER YOUR ADDRESS        : ";
            cin >> address3;
        }
        else
        {
            cout << "GIVE VALID NUMBER!!";
        }
		_getch();
    }

    void selectProduct()
    {
        cout << "FROM THE ABOVE LIST WHAT PRODUCT YOU WANT : ";
        cin >> product;
        if(product == "phone" || product == "earpod" || product == "laptop")
        {
        cout << endl << "WHATS THE QUANTITY OF " << product << " IS REQUIRED : ";
        cin >> qnty;
        }
        else{cout << "there is no such product..";}
        _getch();
    }

    void billprodct()
    {
        int order;
        cout<<"YOUR PRODUCT'S ROW IN THAT LIST : ";
        cin >> order;
        switch(order)
        {
        case 1:
            amnt = 20000;
            break;
        case 2:
            amnt = 50000;
            break;
        case 3:
            amnt = 2000;
            break;
        }
        amnt *= qnty;
        cout << "THE AMOUNT YOU HAVE TO PAY IS " << amnt;
    }

    void payment()
    {
        string paymentmode;
        long int cash;
        int pin;
        cout << "YOUR BILL FOR THE PRODUCT IS " << amnt;
        cout << endl << "CARD OR CASH\n";
        cin >> paymentmode;
        system("cls");
        if(paymentmode == "cash")
        {
            cout << "PAYMENT BY THE CUSTOMER :";
            cin >> cash;
            cash -= amnt;
            if(cash == 0)
            {
                //empty
            }
            else
            {
                cout << "THE REMAINING AMOUNT : " << cash;
            }

        }
        else
        {
            cout << endl << "PLEASE PLACE YOUR CARD OVER HERE.";
            cout << endl << "PLEASE ENTER YOUR PIN CODE.";
            cin >> pin;
            cout << endl << "THE PAYMENT IS DONE!!";
        }
        _getch();
    }

    void getReceipt()
    {

        seqFileIn.open("sequeceFile.txt", ios::in);
        if (seqFileIn.is_open())
        {
            seqFileIn >> fileSeq;
            fileSeq++;
        }
        else
            fileSeq = 1;
        bool newDataAvailable = true;
        if (newDataAvailable)
            {
            ofstream afile;
            string fileName = name + " details" + to_string(fileSeq) + ".txt";
            afile.open(fileName, ios::app);
            afile << "NAME           : " << name << endl
                  << "PHONE NUMBER   : " << phone_number << endl
                  << "ADDRESS        : " << address3 << endl
                  << "PRODUCT        : " << product << endl
                  << "QUANTITY       : " << qnty << endl
                  << "BILL AMOUNT    : " << amnt << endl
                  << "STATUS         : paid" << fileSeq << "\n";
            afile.close();
            }
    seqFileOut.open("sequeceFile.txt", ios::out);
    seqFileOut << fileSeq;
	    cout << "YOUR RECEIPT IS SENT TO YOU!!";
    }
};

int main()
{
    billing b;
    int choice;
    string ans;
    while(1)
    {
    system("cls");
    cout << endl << "FOLLOWING PRODUCTS ARE AVILABLE IN OUR STORE : \n";
    cout << endl << "---------------------------------------------------";
    cout << endl << "SNO  PRODUCT         PRICE           QUANTITY";
    cout << endl << "---------------------------------------------------";
    cout << endl << "1.    PHONE           20000             350";
    cout << endl << "2.    LAPTOP          50000             360";
    cout << endl << "3.    EARPOD          2000              200";
    cout << endl << "---------------------------------------------------\n\n";

    cout << endl << "1. ENTER YOUR DETAILS";
    cout << endl << "2. SELECT THE PRODUCT";
    cout << endl << "3. BILL THE PRODUCT";
    cout << endl << "4. PAYMENT";
    cout << endl << "5. RECEIPT";
    cout << endl << "6. EXIT\n\n";
    cin >> choice;
    system("cls");
    switch(choice)
    {
    case 1:
        b.setDetails();
        break;
    case 2:
        b.selectProduct();
        break;
    case 3:
        b.billprodct();
        break;
    case 4:
        b.payment();
        break;
    case 5:
        b.getReceipt();
        break;
    case 6:
        exit(1);
    default :
        cout << "THERE IS NO STOCK OF THAT PRODUCT!!!";
    }
    }
    _getch();
    return 0;
}

