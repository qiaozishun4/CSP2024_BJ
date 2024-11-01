#include<bits/stdc++.h>
using namespace std;
int n , tong[5][15] , ans;
char a , b;
int makea(char q)
{
    if(q == 'D')
    {
        return 1;
    }
    if(q == 'C')
    {
        return 2;
    }
    if(q == 'H')
    {
        return 3;
    }
    if(q == 'S')
    {
        return 4;
    }
    return 0;
}
int makeb(char q)
{
    if(q == 'A')
    {
        return 1;
    }
    if('2' <= q && q <= '9')
    {
        return int(q - '0');
    }
    if(q == 'T')
    {
        return 10;
    }
    if(q == 'J')
    {
        return 11;
    }
    if(q == 'Q')
    {
        return 12;
    }
    if(q == 'K')
    {
        return 13;
    }
    return 0;
}
int main()
{
    freopen("poker.in" , "r" , stdin);
    freopen("poker.out" , "w" , stdout);
    ios::sync_with_stdio(0);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> a >> b;
        tong[makea(a)][makeb(b)]++;
    }
    for(int i = 1 ; i <= 4 ; i++)
    {
        for(int j = 1 ; j <= 13 ; j++)
        {
            if(tong[i][j] == 0)
            {
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}