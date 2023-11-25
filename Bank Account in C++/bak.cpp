#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

class Bank
{
private:
    long int account_No;
    string mobile_No;
    string name;
    long int account_Bal;
    int pwd;

public:
    void setdata(long int account_no_a, string mobile_no_a, string name_a, long int account_bal_a, int pwd_a)
    {
        account_No = account_no_a;
        mobile_No = mobile_no_a;
        name = name_a;
        account_Bal = account_bal_a;
        pwd = pwd_a;
    }

    long int getAccount_no()
    {
        return account_No;
    }

    string getMobile_no()
    {
        return mobile_No;
    }
    string getName()
    {
        return name;
    }
    long int getAccount_bal()
    {
        return account_Bal;
    }
    int getPWD()
    {
        return pwd;
    }

    void changemobilno(string oldmobileno, string newmobileno)
    {
        if (oldmobileno == mobile_No)
        {
            mobile_No = newmobileno;
            cout << "Your mobile no. is changed";
            _getch();
        }
        else
        {
            cout << "Enter the Correct old Mobile No.";
            _getch();
        }
    }

    void depmon(int amount)
    {
        account_Bal += amount;
        cout << endl
                 << "\a your Amount is Deposited successfully\n";
            cout << endl
                 << "your available balance is :" << account_Bal;
        _getch();
    }
    void Transaction(int amount)
    {
        if (amount > 0 && amount < account_Bal)
        {
            account_Bal -= amount;
            cout << endl
                 << "\a your Amount is transferred successfully\n";
            cout << endl
                 << "your available balance is :" << account_Bal;
            _getch();
        }
        else
        {
            cout << endl
                 << "Invalid amount or insufficient balance";
            _getch();
        }
    }
};

int main()
{
    system("cls");
    long int enteraccount_no;
    int enterpwd;
    int btn;
    Bank user1;
    user1.setdata(123456789, "1122334455", " Kartik", 300000, 1234);

    do
    {
        system("cls");
        cout << endl
             << "\t Welcome to ATM\n";
        cout << "----------------------------\n";
        cout << "Enter the Account No.\n";
        cin >> enteraccount_no;
        cout << "Enter the account PIN\n";
        cin >> enterpwd;

        if ((enteraccount_no == user1.getAccount_no()) && (enterpwd == user1.getPWD()))
        {
            do
            {
                string oldmobileno, newmobileno;
                long int oth_account_no = 0;
                long int amount = 0;
                system("cls");
                cout << "Welcome" << user1.getName() << endl;
                cout << "----------------------------\n";
                cout << "Choose your Operation\n";
                cout << "----------------------------\n";
                cout << "1.Check account balance\n";
                cout << "2.Change Mobile No.\n";
                cout << "3.User Details\n";
                cout << "4.Deposit money\n";
                cout << "5.Transaction\n";
                cout << "6.exit\n";

                cin >> btn;
                switch (btn)
                {
                case 1: // check balance
                    cout << "Your Current account balance is : " << user1.getAccount_bal();
                    _getch();
                    break;

                case 2: // change mobile no.
                    cout << "Enter the Old mobile No.: ";
                    cin >> oldmobileno;
                    cout << "Enter the New mobile No. :";
                    cin >> newmobileno;
                    user1.changemobilno(oldmobileno, newmobileno);
                    break;
                case 3: // user details
                    cout << "User Details\n";
                    cout << "Name        : " << user1.getName() << endl;
                    cout << "Mobile no   : " << user1.getMobile_no() << endl;
                    cout << "Account no  : " << user1.getAccount_no() << endl;
                    cout << "Account bal : " << user1.getAccount_bal() << endl;
                    _getch();
                    break;
                case 4:
                    cout << "\t Deposit money\n";
                    cout << "---------------------------\n";
                    cin >> amount;
                    user1.depmon(amount);
                    break;
                case 5:
                    cout << "\tTransaction\n";
                    cout << "---------------------------\n";
                    cout << "Enter Account No. which you send money\n";
                    cin >> oth_account_no;
                    cout << "Enter Amount which you transfer \n";
                    cin >> amount;
                    user1.Transaction(amount);

                    break;
                case 6:
                    exit(0);

                default:
                    cout << "Invalid Operation";
                    break;
                }
            } while (1);
        }
    } while (1);
    return 0;
}