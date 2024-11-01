#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,a[5][14],cnt;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(ll i=1;i<=n;i++)
    {
        string str;
        cin>>str;
        if(str[0]=='D')
        {
            if(str[1]=='T')
            {
                a[1][10]++;
            }
            else if(str[1]=='A')
            {
                a[1][1]++;
            }
            else if(str[1]=='J')
            {
                a[1][11]++;
            }
            else if(str[1]=='Q')
            {
                a[1][12]++;
            }
            else if(str[1]=='K')
            {
                a[1][13]++;
            }
            else
            {
                a[1][str[1]-'0']++;
            }
        }
        if(str[0]=='C')
        {
            if(str[1]=='T')
            {
                a[2][10]++;
            }
            else if(str[1]=='A')
            {
                a[2][1]++;
            }
            else if(str[1]=='J')
            {
                a[2][11]++;
            }
            else if(str[1]=='Q')
            {
                a[2][12]++;
            }
            else if(str[1]=='K')
            {
                a[2][13]++;
            }
            else
            {
                a[2][str[1]-'0']++;
            }
        }
        if(str[0]=='H')
        {
            if(str[1]=='T')
            {
                a[3][10]++;
            }
            else if(str[1]=='A')
            {
                a[3][1]++;
            }
            else if(str[1]=='J')
            {
                a[3][11]++;
            }
            else if(str[1]=='Q')
            {
                a[3][12]++;
            }
            else if(str[1]=='K')
            {
                a[3][13]++;
            }
            else
            {
                a[3][str[1]-'0']++;
            }
        }
        if(str[0]=='S')
        {
            if(str[1]=='T')
            {
                a[4][10]++;
            }
            else if(str[1]=='A')
            {
                a[4][1]++;
            }
            else if(str[1]=='J')
            {
                a[4][11]++;
            }
            else if(str[1]=='Q')
            {
                a[4][12]++;
            }
            else if(str[1]=='K')
            {
                a[4][13]++;
            }
            else
            {
                a[4][str[1]-'0']++;
            }
        }
    }
    for(ll i=1;i<=4;i++)
    {
        for(ll j=1;j<=13;j++)
        {
            if(a[i][j]!=0)
            {
                cnt++;
            }
        }
    }
    cout<<52-cnt;
    return 0;
}
