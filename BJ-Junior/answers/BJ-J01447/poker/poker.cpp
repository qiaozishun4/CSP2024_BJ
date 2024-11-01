#include<bits/stdc++.h>
using namespace std;
int ans[100][1000];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        char a,b;
        cin>>a>>b;
        //cout<<a<<" "<<b<<endl;
        int x=0,y=0;

        if(b=='A')x=1;
        else if(b=='T')x=10;
        else if(b=='J')x=11;
        else if(b=='Q')x=12;
        else if(b=='K')x=13;
        else x=int(b-'0');
      //  cout<<x;
        if(a=='D')y=1;
        else if(a=='C')y=2;
        else if(a=='H')y=3;
        else if(a=='S')y=4;
        ans[y][x]++;
    }
    int cnt=0;
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=13;j++)
        {
            if(ans[i][j]==0)cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
