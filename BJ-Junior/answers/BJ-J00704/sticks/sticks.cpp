#include <bits/stdc++.h>
using namespace std;

#define EOL '\n'

void write_x(long long x)
{
    if (!x)
    {
        return;
    }
    if (x < 0)
    {
        cout << '-';
        x = -x;
    }
    write_x(x / 10);
    cout << x % 10;
}

void write(long long x, char End)
{
    if (!x)
    {
        cout << 0;
    }
    write_x(x);
    cout << End;
}

void put8(long long n)
{
    if (n % 7)
    {
        cerr << "%7 error" << endl;
    }
    while (n)
    {
        cout << 8;
        n -= 7;
    }
    cout << EOL;
}

void calc()
{
    long long n;
    cin >> n;
    if (n <= 1)
    {
        write(-1, EOL);
        return;
    }
    if (n % 7 == 0)
    {
        put8(n);
        return;
    }
    if (n % 7 == 1)
    {
        cout << 10;
        n -= 8;
        put8(n);
        return;
    }
    if (n % 7 == 2)
    {
        cout << 1;
        n -= 2;
        put8(n);
        return;
    }
    if (n % 7 == 3)
    {
        if (n == 3)
        {
            write(7, EOL);
        }
        else if (n == 10)
        {
            write(22, EOL);
        }
        else
        {
            cout << 200;
            n -= 17;
            put8(n);
        }
        return;
    }
    if (n % 7 == 4)
    {
        if (n == 4)
        {
            write(4, EOL);
        }
        else
        {
            cout << 20;
            n -= 11;
            put8(n);
        }
        return;
    }
    if (n % 7 == 5)
    {
        cout << 2;
        n -= 5;
        put8(n);
        return;
    }
    if (n % 7 == 6)
    {
        cout << 6;
        n -= 6;
        put8(n);
        return;
    }
}

int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    long long T;
    cin >> T;
    while (T--)
    {
        calc();
    }
    return 0;
}
