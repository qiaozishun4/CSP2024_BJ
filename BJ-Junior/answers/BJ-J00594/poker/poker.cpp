#include<bits/stdc++.h>
using namespace std;
int cnt[5][15];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    int i;
    for(i=1;i<=n;i++)
    {
        char c1,c2;
        cin>>c1>>c2;
        int type,num;
        if(c1=='D')
        {
            type=1;
        }
        if(c1=='C')
        {
            type=2;
        }
        if(c1=='H')
        {
            type=3;
        }
        if(c1=='S')
        {
            type=4;
        }
        if(c2>='2'&&c2<='9')
        {
            num=c2-'0';
        }
        if(c2=='A')
        {
            num=1;
        }
        if(c2=='T')
        {
            num=10;
        }
        if(c2=='J')
        {
            num=11;
        }
        if(c2=='Q')
        {
            num=12;
        }
        if(c2=='K')
        {
            num=13;
        }
        cnt[type][num]=1;
    }
    int j;
    int ans=0;
    for(i=1;i<=4;i++)
    {
        for(j=1;j<=13;j++)
        {
            if(!cnt[i][j])
            {
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
