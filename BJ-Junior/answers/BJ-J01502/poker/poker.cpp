#include<iostream>
#include<cstdio>
using namespace std;
bool mp[256][256];
int main()
{
    int n,i,cnt=0;
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(i=1;i<=n;i++)
    {
        char a,b;
        cin>>a>>b;
        if(a=='D'||a=='C'||a=='H'||a=='S')
        {
            if(b=='A'||b=='T'||b=='J'||b=='Q'||b=='K'||(b>='2'&&b<='9'))mp[a][b]=1;
        }
    }
    for(i=1;i<256;i++)
    {
        for(int j=1;j<256;j++)
        {
            if(mp[i][j])cnt++;
        }
    }
    if(cnt<52)cout<<52-cnt;
    else cout<<0;
    return 0;
}
