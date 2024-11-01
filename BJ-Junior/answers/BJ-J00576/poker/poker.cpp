#include<bits/stdc++.h>
using namespace std;
int a[53];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    char x,y;
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++)
    {

        int t=0;
        cin>>x>>y;
        if(x=='C')t+=13;
        if(x=='H')t+=26;
        if(x=='S')t+=39;
        if(y=='A')t+=1;
        if(y=='2')t+=2;
        if(y=='3')t+=3;
        if(y=='4')t+=4;
        if(y=='5')t+=5;
        if(y=='6')t+=6;
        if(y=='7')t+=7;
        if(y=='8')t+=8;
        if(y=='9')t+=9;
        if(y=='T')t+=10;
        if(y=='J')t+=11;
        if(y=='Q')t+=12;
        if(y=='K')t+=13;
        a[t]++;
    }
    for(int i=1;i<=52;i++)
    {
        if(a[i]==0)ans++;
    }
    cout<<ans;
    return 0;
}
