#include<bits/stdc++.h>
using namespace std;
int box[60];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        char x,y;
        cin>>x>>y;
        int a,b;
        if(x=='D') a=0;
        else if(x=='C') a=1;
        else if(x=='H') a=2;
        else a=3;
        if(y=='T') b=10;
        else if(y=='J') b=11;
        else if(y=='Q') b=12;
        else if(y=='K') b=13;
        else if(y=='A') b=1;
        else b=y-48;
        box[a*13+b]=1;
    }
    int sum=0;
    for(int i=1;i<=52;i++)
    {
        if(box[i]==0) sum++;
    }
    cout<<sum;
    return 0;
}
