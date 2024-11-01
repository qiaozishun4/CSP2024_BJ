#include <bits/stdc++.h>
using namespace std;
bool check[5][20];
int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n;
    cin >>n;
    int cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        char c1, c2;
        cin >> c1 >> c2;
        int a, b;
        if(c1 == 'D')
        {
            a = 1;
        }
        else if(c1 == 'C')
        {
            a = 2;
        }
        else if(c1 == 'H')
        {
            a = 3;
        }
        else if(c1 == 'S')
        {
            a = 4;
        }
        if(c2 == 'A')
            b = 1;
        else if(c2 == 'T')
            b = 10;
        else if(c2 == 'J')
            b = 11;
        else if(c2 == 'Q')
            b = 12;
        else if(c2 == 'K')
            b = 13;
        if(check[a][b] == 0)
        {
            check[a][b] = 1;
            cnt++;
        }
    }
    cout << 52 - cnt << endl;
	return 0;
}
