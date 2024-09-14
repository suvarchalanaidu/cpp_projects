#include <iostream>

using namespace std;

void showmenu()
{
    cout << "****MENU******" << endl;
    cout << "1. Check Balance" << endl;
    cout << "2. Deposit" << endl;
    cout << "3. Withdraw" << endl;
    cout << "4. Exit" << endl;
    cout << "**************" << endl;
}

int main()
{
    //check balance,deposit,withdraw,show menu
    int selectoption;
    double balance = 1000;
    double depositamt;

    do
    {
        showmenu();
        cout << "Please choose your option:" << endl;
        cin >> selectoption;

        system("cls");

        switch (selectoption)
        {
        case 1:
            cout << "Balance is: " << balance << "$" << endl;
            break;

        case 2:
            cout << "Deposit amount: ";
            cin >> depositamt;
            balance = depositamt + balance;
            cout << "Balance is: " << balance << "$" << endl;
            break;

        case 3:
            double withdrawalamout;
            cout << "Withdraw amount: ";
            cin >> withdrawalamout;
            if (withdrawalamout <= balance)
            {
                balance = balance - withdrawalamout;
                cout << "Balance is: " << balance << "$" << endl;
            }
            else
            {
                cout << "No Sufficient Balance" << endl;

            }

            break;
        }

    } while (selectoption != 4);


    return 0;

}