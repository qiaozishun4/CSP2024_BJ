#include <bits/stdc++.h>
using namespace std;
long long n,v[5][15],sum;
string a;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a;
        if(a[0]=='C')
        {
            if(a[1]=='A')
            {
                v[1][1]++;
            }
            else if(a[1]=='T')
            {
                v[1][10]++;
            }
            else if(a[1]=='J')
            {
                v[1][11]++;
            }
            else if(a[1]=='Q')
            {
                v[1][12]++;
            }
            else if(a[1]=='K')
            {
                v[1][13]++;
            }
            else
            {
                int b=a[1]-'0';
                v[1][b]++;
            }
        }
        else if(a[0]=='D')
        {
            if(a[1]=='A')
            {
                v[2][1]++;
            }
            else if(a[1]=='T')
            {
                v[2][10]++;
            }
            else if(a[1]=='J')
            {
                v[2][11]++;
            }
            else if(a[1]=='Q')
            {
                v[2][12]++;
            }
            else if(a[1]=='K')
            {
                v[2][13]++;
            }
            else
            {
                int b=a[1]-'0';
                v[2][b]++;
            }
        }
        else if(a[0]=='H')
        {
            if(a[1]=='A')
            {
                v[3][1]++;
            }
            else if(a[1]=='T')
            {
                v[3][10]++;
            }
            else if(a[1]=='J')
            {
                v[3][11]++;
            }
            else if(a[1]=='Q')
            {
                v[3][12]++;
            }
            else if(a[1]=='K')
            {
                v[3][13]++;
            }
            else
            {
                int b=a[1]-'0';
                v[3][b]++;
            }
        }
        else if(a[0]=='S')
        {
            if(a[1]=='A')
            {
                v[4][1]++;
            }
            else if(a[1]=='T')
            {
                v[4][10]++;
            }
            else if(a[1]=='J')
            {
                v[4][11]++;
            }
            else if(a[1]=='Q')
            {
                v[4][12]++;
            }
            else if(a[1]=='K')
            {
                v[4][13]++;
            }
            else
            {
                int b=a[1]-'0';
                v[4][b]++;
            }
        }
    }
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=13;j++)
        {
            cout << v[i][i] << ' ';
            if(v[i][j]==0)
            {
                sum++;
            }
        }
        cout << endl;

    }
    cout << sum;
}