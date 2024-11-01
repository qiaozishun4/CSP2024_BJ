#include<iostream>
using namespace std;
bool poker[5][14]={};
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    char c1,c2;
    cin>>n;
    while(n--)
    {
        cin>>c1>>c2;
        int x,y;
        if(c1=='D') x=1;
        else if(c1=='C') x=2;
        else if(c1=='H') x=3;
        else x=4;
        if(c2=='T') y=10;
        else if(c2=='J') y=11;
        else if(c2=='K') y=13;
        else if(c2=='Q') y=12;
        else if(c2=='A') y=1;
        else y=c2-'0';
        poker[x][y]=1;
    }
    int ans=0;
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=13;j++)
        {
            if(poker[i][j]!=1)
            {
                ans++;
            }
        }
    }
    cout<<ans;
}
