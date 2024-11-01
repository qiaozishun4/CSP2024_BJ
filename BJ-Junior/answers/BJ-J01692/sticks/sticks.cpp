#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n <= 50)
        {
            if (n == 1)
                cout << -1;
            if (n == 2)
                cout << 1;
            if (n == 3)
                cout << 7;
            if (n == 4)
                cout << 4;
            if (n == 5)
                cout << 2;
            if (n == 6)
                cout << 6;
            if (n == 7)
                cout << 8;
            if (n == 8)
                cout << 10;
            if (n == 9)
                cout << 18;
            if (n == 10)
                cout << 23;
            if (n == 11)
                cout << 19;
            if (n == 12)
                cout << 28;
            if (n == 13)
                cout << 68;
            if (n == 14)
                cout << 88;
            if (n == 15)
                cout << 108;
            if (n == 16)
                cout <<188;
            if (n == 17)
                cout <<200;
            if (n == 18)
                cout <<208;
            if (n == 19)
                cout <<288;
            if (n == 20)
                cout <<688;
            if (n == 21)
                cout <<888;
            if (n == 22)
                cout <<1088;
            if (n == 23)
                cout <<1888;
            if (n == 24)
                cout <<2008;
            if (n == 25)
                cout <<2088;
            if (n == 26)
                cout <<2888;
            if (n == 27)
                cout <<6888;
            if (n == 28)
                cout <<8888;
            if (n == 29)
                cout <<10888;
            if (n == 30)
                cout <<18888;
            if (n == 31)
                cout <<20088;
            if (n == 32)
                cout <<20888;
            if (n == 33)
                cout <<28888;
            if (n == 34)
                cout <<68888;
            if (n == 35)
                cout <<88888;
            if (n == 36)
                cout <<108888;
            if (n == 37)
                cout <<188888;
            if (n == 38)
                cout <<200888;
            if (n == 39)
                cout <<208888;
            if (n == 40)
                cout <<288888;
            if (n == 41)
                cout << 688888;
            if (n == 42)
                cout << 888888;
            if (n == 43)
                cout << 1088888;
            if (n == 44)
                cout << 1888888;
            if (n == 45)
                cout << 2008888;
            if (n == 46)
                cout << 2088888;
            if (n == 47)
                cout << 2888888;
            if (n == 48)
                cout << 6888888;
            if (n == 49)
                cout << 8888888;
            if (n == 50)
                cout << 10888888;
            cout << endl;
        }
        else if (n % 7 == 0)
        {
            for (int i = 1; i <= n / 7; ++i)
                cout << 8;
            cout << endl;
        }
        else if (n % 7 == 1)
        {
            cout << 10;
            for (int i = 1; i <= n / 7 - 1; ++i)
                cout << 8;
            cout << endl;
        }
        else
        {
            int m = n - 14;
            int pos8 = 2, cnt8 = 1, fst = 8;
            int len = 2, ct = 15;
            while (m--)
            {
                if (pos8 == 2)
                {
                    if (fst == 1)
                    {
                        fst = 2;
                        cnt8 -= 2;
                        pos8 = len - cnt8 + 1;
                    }
                    else if (fst == 2)
                    {
                        fst = 6;
                    }
                    else if (fst == 6)
                    {
                        fst = 8;
                    }
                    else if (fst == 8)
                    {
                        fst = 1;
                        pos8 = 3;
                        ++len;
                    }
                }
                else
                {
                    pos8--;
                    cnt8++;
                }
            }
            cout << fst;
            for (int i = 2; i < pos8; ++i)
                cout << 0;
            for (int i = pos8; i <= len; ++i)
                cout<< 8;
            cout << endl;
        }
    }
    return 0;
}
