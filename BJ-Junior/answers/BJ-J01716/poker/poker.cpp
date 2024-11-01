#include<bits/stdc++.h>
using namespace std;
int n,cnt;
char ch1,ch2;
bool vis[5][20];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a1,a2;
        cin>>ch1>>ch2;
        if(ch1=='D') a1=1;
        else if(ch1=='C') a1=2;
        else if(ch1=='H') a1=3;
        else a1=4;
        if(ch2=='A') a2=1;
        else if(ch2=='T') a2=10;
        else if(ch2=='J') a2=11;
        else if(ch2=='Q') a2=12;
        else if(ch2=='K') a2=13;
        else a2=ch2-48;
        vis[a1][a2]=true;
    }
    for(int i=1;i<=4;i++)
        for(int j=1;j<=13;j++)
            if(!vis[i][j])
                cnt++;
    cout<<cnt;
    return 0;
}
