#include <bits/stdc++.h>
using namespace std;
int a[4][13];
int c[90];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    c[int('A')] = 1;
    c[2] = 2;
    c[3] = 3;
    c[4] = 4;
    c[5] = 5;
    c[6] = 6;
    c[7] = 7;
    c[8] = 8;
    c[9] = 9;
    c[int('T')] = 10;
    c[int('J')] = 11;
    c[int('Q')] = 12;
    c[int('K')] = 13;
    int n;
    cin >> n;
    int sum = 52;
    for(int i = 1;i <= n;i++)
    {
        string b;
        cin >> b;
        if(b[0] == 'D')
        {
            if(a[0][c[b[1]]] == 0)
            {

                sum--;
                a[0][c[b[1]]] = 1;
            }
        }
        else if(b[0] == 'C')
        {
            if(a[1][c[b[1]]] == 0)
            {

                sum--;
                a[1][c[b[1]]] = 1;
            }
        }
        else if(b[0] == 'H')
        {
            if(a[2][c[b[1]]] == 0)
            {

                sum--;
                a[2][c[b[1]]] = 1;
            }
        }
        else if(b[0] == 'S')
        {
            if(a[3][c[b[1]]] == 0)
            {

                sum--;
                a[3][c[b[1]]] = 1;
            }
        }
    }
    cout << sum;
    return 0;
}
