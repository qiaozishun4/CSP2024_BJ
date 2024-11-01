#include <bits/stdc++.h>
using namespace std;
int n,x,y,ans;
bool pk[4][14];
string s;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    scanf("%d",&n);
    while(n--)
    {
        cin>>s;
        if(s[0]=='C')
            x=0;
        else if(s[0]=='S')
            x=1;
        else if(s[0]=='H')
            x=2;
        else
            x=3;
        if(s[1]<='9'&&s[1]>='2') y=s[1]-'0';
        else if(s[1]=='A') y=1;
        else if(s[1]=='T') y=10;
        else if(s[1]=='J') y=11;
        else if(s[1]=='Q') y=12;
        else y=13;
        pk[x][y]=1;
    }
    for(int i = 0;i < 4;++i)
    {
        for(int j = 1;j <= 13;++j)
        {
            if(!pk[i][j]) ++ans;
        }
    }
    printf("%d",ans);
    return 0;
}
