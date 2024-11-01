#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int TT;
    cin >> TT;
    while(TT--)
    {

        int n;
        cin >> n;
        if(n == 1)cout << "-1\n";
        else if(n == 2)cout << "1\n";
        else if(n == 3)cout << "7\n";
        else if(n == 4)cout << "4\n";
        else if(n == 5)cout << "2\n";
        else if(n == 6)cout << "6\n";
        else
        {
            if(n % 7 == 0)
            {
                string s(n / 7, '8');
                cout << s << "\n";
            }
            else if(n % 7 == 1)
            {
                cout << 10;
                string s(n / 7 - 1, '8');
                cout << s <<"\n";
            }
            else if(n % 7 == 2)
            {
                cout << 1;
                string s(n / 7, '8');
                cout << s << "\n";
            }
            else if(n % 7 == 3)
            {
                cout << 22;
                string s(n / 7 - 1, '8');
                cout << s <<"\n";
            }
            else if(n % 7 == 4)
            {
                cout << 20;
                string s(n / 7 - 1, '8');
                cout << s <<"\n";
            }
            else if(n % 7 == 5)
            {
                cout << 2;
                string s(n / 7, '8');
                cout << s <<"\n";
            }
            else if(n % 7 == 6)
            {
                cout << 6;
                string s(n / 7, '8');
                cout << s <<"\n";
            }
        }
    }
}
