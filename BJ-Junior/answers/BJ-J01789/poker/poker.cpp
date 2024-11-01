#include<bits/stdc++.h>
using namespace std;
int f[10][20],n;
string s1;
int a,b;
int ans;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>s1;
        if(s1[0]=='D')
            a=1;
        if(s1[0]=='C')
            a=2;
        if(s1[0]=='H')
            a=3;
        if(s1[0]=='S')
            a=4;


        if(s1[1]>='2'&&s1[1]<='9')
            b=s1[1]-'0';
        if(s1[1]=='A')
            b=1;
        if(s1[1]=='T')
            b=10;
        if(s1[1]=='J')
            b=11;
        if(s1[1]=='Q')
            b=12;
        if(s1[1]=='K')
            b=13;
        ++f[a][b];
    }
    for(int i=1;i<=4;++i)
        for(int j=1;j<=13;++j)
            if(f[i][j]==0)
                ++ans;
    cout<<ans;
    return 0;
}
