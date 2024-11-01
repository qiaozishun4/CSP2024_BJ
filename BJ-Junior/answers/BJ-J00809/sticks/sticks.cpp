#include <iostream>
using namespace std;

int t, n;

int main()
{
    freopen("sticks.in", "r", stdin);    
    freopen("sticks.out", "w", stdout);
    cin >> t;
    while (t--) 
    {
        cin >> n;
        int x = n % 7, y = n / 7;
        if (x == 0) for (int i = 1; i <= y; i++) cout << "8";
        else if (x == 1)
        {
            if (y == 0) cout << "-1";
            else {
                cout << "10";
                for (int i = 1; i <= y - 1; i++) cout << "8";
            }
        }
        else if (x == 2){
            cout << "1";
            for (int i = 1; i <= y; i++) cout << "8";
        }
        else if (x == 3){
            if (y == 0) cout << "7";
            else {
                cout << "22";
                for (int i = 1; i <= y - 1; i++) cout << "8";
            }
        }
        else if (x == 4){
            if (y == 0) cout << "4";
            else {
                cout << "20";
                for (int i = 1; i <= y - 1; i++) cout << "8";
            }
        }
        else if (x == 5)
        {
            cout << "2";
            for (int i = 1; i <= y; i++) cout << "8";
        }
        else if (x == 6)
        {
            cout << "6";
            for (int i = 1; i <= y; i++) cout << "8";
        }
        cout << "\n";
    }
    return 0;
}