#include<bits/stdc++.h>
using namespace std;
bool vis[5][14];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,ans=52;
    cin>>n;
    while(n--)
    {
        char x,y;
        int z;
        cin>>x>>y;
        if('2'<=y&&y<='9') z=y-'0';
        else if(y=='A') z=1;
        else if(y=='T') z=10;
        else if(y=='J') z=11;
        else if(y=='Q') z=12;
        else z=13;
        if(x=='S')
        {
            if(!vis[1][z])
            {
                ans--;
                vis[1][z]=1;
            }
        }
        else if(x=='D')
        {
            if(!vis[2][z])
            {
                ans--;
                vis[2][z]=1;
            }
        }
        else if(x=='H')
        {
            if(!vis[3][z])
            {
                ans--;
                vis[3][z]=1;
            }
        }
        else
        {
            if(!vis[4][z])
            {
                ans--;
                vis[4][z]=1;
            }
        }
    }
    cout<<ans;
    return 0;
}
