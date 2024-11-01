#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
#define ll long long
ll poker[5][15];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    ll n,ans=0;
    string a;
    cin>>n;
    for(ll i=1;i<=n;i++)
    {
        cin>>a;
        if(a[0]=='D')
        {
            if(a[1]=='A')poker[1][1]++;
            else if(a[1]=='2')poker[1][2]++;
            else if(a[1]=='3')poker[1][3]++;
            else if(a[1]=='4')poker[1][4]++;
            else if(a[1]=='5')poker[1][5]++;
            else if(a[1]=='6')poker[1][6]++;
            else if(a[1]=='7')poker[1][7]++;
            else if(a[1]=='8')poker[1][8]++;
            else if(a[1]=='9')poker[1][9]++;
            else if(a[1]=='T')poker[1][10]++;
            else if(a[1]=='J')poker[1][11]++;
            else if(a[1]=='Q')poker[1][12]++;
            else if(a[1]=='K')poker[1][13]++;
        }
        else if(a[0]=='C')
        {
            if(a[1]=='A')poker[2][1]++;
            else if(a[1]=='2')poker[2][2]++;
            else if(a[1]=='3')poker[2][3]++;
            else if(a[1]=='4')poker[2][4]++;
            else if(a[1]=='5')poker[2][5]++;
            else if(a[1]=='6')poker[2][6]++;
            else if(a[1]=='7')poker[2][7]++;
            else if(a[1]=='8')poker[2][8]++;
            else if(a[1]=='9')poker[2][9]++;
            else if(a[1]=='T')poker[2][10]++;
            else if(a[1]=='J')poker[2][11]++;
            else if(a[1]=='Q')poker[2][12]++;
            else if(a[1]=='K')poker[2][13]++;
        }
        else if(a[0]=='H')
        {
            if(a[1]=='A')poker[3][1]++;
            else if(a[1]=='2')poker[3][2]++;
            else if(a[1]=='3')poker[3][3]++;
            else if(a[1]=='4')poker[3][4]++;
            else if(a[1]=='5')poker[3][5]++;
            else if(a[1]=='6')poker[3][6]++;
            else if(a[1]=='7')poker[3][7]++;
            else if(a[1]=='8')poker[3][8]++;
            else if(a[1]=='9')poker[3][9]++;
            else if(a[1]=='T')poker[3][10]++;
            else if(a[1]=='J')poker[3][11]++;
            else if(a[1]=='Q')poker[3][12]++;
            else if(a[1]=='K')poker[3][13]++;
        }
        else if(a[0]=='S')
        {
            if(a[1]=='A')poker[4][1]++;
            else if(a[1]=='2')poker[4][2]++;
            else if(a[1]=='3')poker[4][3]++;
            else if(a[1]=='4')poker[4][4]++;
            else if(a[1]=='5')poker[4][5]++;
            else if(a[1]=='6')poker[4][6]++;
            else if(a[1]=='7')poker[4][7]++;
            else if(a[1]=='8')poker[4][8]++;
            else if(a[1]=='9')poker[4][9]++;
            else if(a[1]=='T')poker[4][10]++;
            else if(a[1]=='J')poker[4][11]++;
            else if(a[1]=='Q')poker[4][12]++;
            else if(a[1]=='K')poker[4][13]++;
        }
    }
    for(ll i=1;i<=4;i++)
    {
        for(ll j=1;j<=13;j++)
        {
            if(poker[i][j]==0)
            {
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
