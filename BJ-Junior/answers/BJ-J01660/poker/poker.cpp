#include<bits/stdc++.h>
using namespace std;
char s[2][52];
int vis[4][13];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    memset(vis,0,sizeof(vis));
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>s[0][i]>>s[1][i];
    }
    for(int i=0;i<n;i++)
    {
        if(s[0][i]=='D')
        {
            if(s[1][i]=='A') vis[0][0]++;
            if(s[1][i]=='2') vis[0][1]++;
            if(s[1][i]=='3') vis[0][2]++;
            if(s[1][i]=='4') vis[0][3]++;
            if(s[1][i]=='5') vis[0][4]++;
            if(s[1][i]=='6') vis[0][5]++;
            if(s[1][i]=='7') vis[0][6]++;
            if(s[1][i]=='8') vis[0][7]++;
            if(s[1][i]=='9') vis[0][8]++;
            if(s[1][i]=='T') vis[0][9]++;
            if(s[1][i]=='J') vis[0][10]++;
            if(s[1][i]=='Q') vis[0][11]++;
            if(s[1][i]=='K') vis[0][12]++;
        }
        else if(s[0][i]=='C')
        {
            if(s[1][i]=='A') vis[1][0]++;
            if(s[1][i]=='2') vis[1][1]++;
            if(s[1][i]=='3') vis[1][2]++;
            if(s[1][i]=='4') vis[1][3]++;
            if(s[1][i]=='5') vis[1][4]++;
            if(s[1][i]=='6') vis[1][5]++;
            if(s[1][i]=='7') vis[1][6]++;
            if(s[1][i]=='8') vis[1][7]++;
            if(s[1][i]=='9') vis[1][8]++;
            if(s[1][i]=='T') vis[1][9]++;
            if(s[1][i]=='J') vis[1][10]++;
            if(s[1][i]=='Q') vis[1][11]++;
            if(s[1][i]=='K') vis[1][12]++;
        }
        else if(s[0][i]=='H')
        {
            if(s[1][i]=='A') vis[2][0]++;
            if(s[1][i]=='2') vis[2][1]++;
            if(s[1][i]=='3') vis[2][2]++;
            if(s[1][i]=='4') vis[2][3]++;
            if(s[1][i]=='5') vis[2][4]++;
            if(s[1][i]=='6') vis[2][5]++;
            if(s[1][i]=='7') vis[2][6]++;
            if(s[1][i]=='8') vis[2][7]++;
            if(s[1][i]=='9') vis[2][8]++;
            if(s[1][i]=='T') vis[2][9]++;
            if(s[1][i]=='J') vis[2][10]++;
            if(s[1][i]=='Q') vis[2][11]++;
            if(s[1][i]=='K') vis[2][12]++;
        }
        else if(s[0][i]=='S')
        {
            if(s[1][i]=='A') vis[3][0]++;
            if(s[1][i]=='2') vis[3][1]++;
            if(s[1][i]=='3') vis[3][2]++;
            if(s[1][i]=='4') vis[3][3]++;
            if(s[1][i]=='5') vis[3][4]++;
            if(s[1][i]=='6') vis[3][5]++;
            if(s[1][i]=='7') vis[3][6]++;
            if(s[1][i]=='8') vis[3][7]++;
            if(s[1][i]=='9') vis[3][8]++;
            if(s[1][i]=='T') vis[3][9]++;
            if(s[1][i]=='J') vis[3][10]++;
            if(s[1][i]=='Q') vis[3][11]++;
            if(s[1][i]=='K') vis[3][12]++;
        }
    }
    int ans=0;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<13;j++)
        {
            if(vis[i][j]==0) ans++;
        }
    }
    cout<<ans;
    return 0;
}
