#include<bits/stdc++.h>
using namespace std;
bool p[5][20];
int cnt=52;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        char c,c1;
        cin>>c1;
        cin>>c;
        if(c=='A')c=1;
        if(c>'0'&&c<='9')c-=48;
        if(c=='T')c=10;
        if(c=='J')c=11;
        if(c=='Q')c==12;
        if(c=='K')c==13;
        if(c1=='S')c1=1;
        if(c1=='H')c1=2;
        if(c1=='D')c1=3;
        if(c1=='C')c1=4;
        if(p[c1][c])continue;
        p[c1][c]=1;
        cnt--;
    }
    cout<<cnt;
    return 0;
}
