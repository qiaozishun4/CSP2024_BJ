#include <bits/stdc++.h>
using namespace std;

int n;
string s[30] = {"","-1","1","7","4","2","6","8","10","18","22","20","28","68","88","108","188","200","208","288","688"};

void print(int len)
{
    for (int i = 1; i <= len; ++i) cout << "8";
    cout << endl;
}

int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        if (n <= 20) cout << s[n] << endl;
        else
        {
            int len = n / 7;
            if (n % 7 == 0)
            {
                print(len);
            }
            if (n % 7 == 1)
            {
                cout << "10";
                print(len - 1);
            }
            if (n % 7 == 2)
            {
                cout << "1";
                print(len);
            }
            if (n % 7 == 3)
            {
                cout << "200";
                print(len - 2);
            }
            if (n % 7 == 4)
            {
                cout << "20";
                print(len - 1);
            }
            if (n % 7 == 5)
            {
                cout << "2";
                print(len);
            }
            if (n % 7 == 6)
            {
                cout << "6";
                print(len);
            }
        }
    }
    return 0;
}
