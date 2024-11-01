#include<bits/stdc++.h>
using namespace std;
int n;
bool vis[4][15];
int dx[128],dy[128];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    dx['D']=0;
    dx['C']=1;
    dx['H']=2;
    dx['S']=3;
    for(int i=2;i<=9;i++) dy[i+'0']=i;
    dy['A']=1;
    dy['T']=10;
    dy['J']=11;
    dy['Q']=12;
    dy['K']=13;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        vis[dx[s[0]]][dy[s[1]]]=true;
    }
    int ans=52;
    for(int i=0;i<=3;i++)
    {
        for(int j=1;j<=13;j++)
        {
            if(vis[i][j]) ans--;
        }
    }
    cout<<ans<<endl;
    return 0;
}
