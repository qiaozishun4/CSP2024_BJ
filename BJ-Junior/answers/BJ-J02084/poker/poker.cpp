#include<bits/stdc++.h>
using namespace std;
long long n,s;
char q,w;
int e,r;
bool g[5][15];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>q>>w;
        if(q=='D')
        {
            e=1;
        }
        else if(q=='C')
        {
            e=2;
        }
        else if(q=='H')
        {
            e=3;
        }
        else if(q=='S')
        {
            e=4;
        }
        if(w<='9'&&w>='2')
        {
            r=w-'0';
        }
        else if(w=='A')
        {
            r=1;
        }
        else if(w=='T')
        {
            r=10;
        }
        else if(w=='J')
        {
            r=11;
        }
        else if(w=='Q')
        {
            r=12;
        }
        else if(w=='K')
        {
            r=13;
        }
        g[e][r]=1;
    }
    for(int i=1;i<=4;i++)
        for(int j=1;j<=13;j++)
            if(g[i][j])
                s++;
    cout<<52-s;
    return 0;
}