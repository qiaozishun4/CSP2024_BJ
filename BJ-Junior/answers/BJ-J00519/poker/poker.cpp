#include <bits/stdc++.h>
using namespace std;
int n,ans;
int tong[53];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        char hua,dian,xb=0;
        cin>>hua>>dian;
        if(hua=='C') xb+=13;
        if(hua=='H') xb+=26;
        if(hua=='S') xb+=39;
        if(dian=='A') xb+=1;
        if(dian<='9'&&dian>='2') xb+=dian-'0';
        if(dian=='T') xb+=10;
        if(dian=='J') xb+=11;
        if(dian=='Q') xb+=12;
        if(dian=='K') xb+=13;
        tong[xb]++;
    }
    for(int i=1;i<53;i++)
    {
        if(tong[i]==0) ans++;
    }
    cout << ans;
    return 0;
}
