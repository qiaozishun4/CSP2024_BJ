#include<bits/stdc++.h>
using namespace std;
int v[201];
int sum;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        char a[11];
        cin>>a;
        int ls;
        if(a[0]=='D') ls=0;
        else if(a[0]=='C') ls=20;
        else if(a[0]=='H') ls=40;
        else if(a[0]=='S') ls=60;
        if(a[1]=='A') ls+=1;
        else if(a[1]=='T') ls+=10;
        else if(a[1]=='J') ls+=11;
        else if(a[1]=='Q') ls+=12;
        else if(a[1]=='K') ls+=13;
        else ls+=(a[1]-48);
        if(!v[ls])
        {
            sum++;
            v[ls]=1;
        }
    }
    cout<<(52-sum);
}
