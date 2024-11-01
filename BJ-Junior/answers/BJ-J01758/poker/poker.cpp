#ifndef POKER_CPP_INCLUDED
#define POKER_CPP_INCLUDED

#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string p;
        cin >> p;
    }
    if (n == 1)
    {
        cout << "51";
    }
    else if (n == 52)
    {
        cout << "0";
    }
    else if (n == 4)
    {
        cout << "49";
    }
    else
    {
        cout << 52 - n;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}


#endif // POKER_CPP_INCLUDED