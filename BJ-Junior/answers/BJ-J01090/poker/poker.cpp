#include<bits/stdc++.h>
using namespace std;
bool poker[5][15];
int n;
char flower;
char num;
int ans;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>flower>>num;
        int x,y;
        if(flower=='D') x=0;
        if(flower=='C') x=1;
        if(flower=='H') x=2;
        if(flower=='S') x=3;
        if(num>='2' && num<='9') y=num-'1';
        if(num=='A') y=0;
        if(num=='T') y=9;
        if(num=='J') y=10;
        if(num=='Q') y=11;
        if(num=='K') y=12;
        poker[x][y]=1;
    }
    for(int i=0;i<=3;i++)
    {
        for(int j=0;j<=12;j++)
        {
            if(!poker[i][j]) ans++;
        }
    }
    cout<<ans;
    return 0;
}
