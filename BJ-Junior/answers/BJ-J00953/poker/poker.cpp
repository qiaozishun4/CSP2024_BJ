#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,a[10][13]={},h,s,ans=0;
char H,S;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(ll i=1;i<=n;i++)
    {
        cin>>H>>S;
        if(H=='D')h=1;
        else if(H=='C')h=2;
        else if(H=='H')h=3;
        else h=4;
        if(S<='9'&&S>='0')s=S-'0';
        else if(S=='A')s=1;
        else if(S=='J')s=11;
        else if(S=='Q')s=12;
        else if(S=='K')s=13;
        else s=10;
        a[h][s]++;
    }
    for(ll i=1;i<=4;i++)
    {
        for(ll j=1;j<=13;j++)
        {
            if(a[i][j]==0)
            {
             //   cout<<i<<" "<<j<<"\n";
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
