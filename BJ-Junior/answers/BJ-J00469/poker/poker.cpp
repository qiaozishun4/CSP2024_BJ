#include <iostream>
#include<bits/stdc++.h>
using namespace std;

bool b[100];
int n;
int ans;

int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        char a[5];
        int hs,ds;
        cin>>a;

        if(a[0]=='D')hs=0;
        if(a[0]=='H')hs=1;
        if(a[0]=='C')hs=2;
        if(a[0]=='S')hs=3;
        if(a[1]>='0' && a[1]<='9')
        {
            ds=a[1]-'0';
        }
        else
        {
            if(a[1]=='A')ds=1;
            if(a[1]=='T')ds=10;
            if(a[1]=='J')ds=11;
            if(a[1]=='Q')ds=12;
            if(a[1]=='K')ds=0;
        }
        int id=hs*13+ds;
        b[id]=true;
    }
    for(int i=0;i<52;i++)
    {
        if(!b[i])ans++;
    }
    cout<<ans;
    return 0;
}
