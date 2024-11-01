#include<bits/stdc++.h>
using namespace std;
int vis[6][15];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        char a,b;
        cin>>a>>b;
        int tmp;
        if(a=='D')
            tmp=1;
        if(a=='C')
            tmp=2;
        if(a=='H')
            tmp=3;
        if(a=='S')
            tmp=4;
        int tmp1;
        if(b>='2'&&b<='9')
            tmp1=b-'0';
        if(b=='A')
            tmp1=1;
        if(b=='T')
            tmp1=10;
        if(b=='J')
            tmp1=11;
        if(b=='Q')
            tmp1=12;
        if(b=='K')
            tmp1=13;
        if(!vis[tmp][tmp1])
        {
            cnt++;
            vis[tmp][tmp1]=true;
        }
    }
    cout<<52-cnt<<endl;
    return 0;
}