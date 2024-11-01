#include<bits/stdc++.h>
using namespace std;
int n;
int p[5][18];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    if(n==52)
    {
        cout<<"0"<<'\n';
        return 0;
    }
    int ans=52;
    for(int i=1;i<=n;i++)
    {
        char a,b;
        cin>>a>>b;
        if(a=='D')
        {
            if(b=='T')
            {
                if(p[1][10]!=0) continue;
                p[1][10]=1;
            }
            if(b>='2'&&b<='9')
            {
                int x=b-'0';
                if(p[1][x]!=0) continue;
                p[1][x]=1;
            }
            else{
                int x=b-'A';
                if(p[1][x]!=0) continue;
                p[1][x]=1;
            }
        }
        if(a=='C')
        {
            if(b=='T')
            {
                if(p[2][10]!=0) continue;
                p[2][10]=1;
            }
            if(b>='2'&&b<='9')
            {
                int x=b-'0';
                if(p[2][x]!=0) continue;
                p[2][x]=1;
            }
            else{
                int x=b-'A';
                if(p[2][x]!=0) continue;
                p[2][x]=1;
            }
        }
        if(a=='H')
        {
            if(b=='T')
            {
                if(p[3][10]!=0) continue;
                p[3][10]=1;
            }
            if(b>='2'&&b<='9')
            {
                int x=b-'0';
                if(p[3][x]!=0) continue;
                p[3][x]=1;
            }
            else{
                int x=b-'A';
                if(p[3][x]!=0) continue;
                p[3][x]=1;
            }
        }
        if(a=='S')
        {
            if(b=='T')
            {
                if(p[4][10]!=0) continue;
                p[4][10]=1;
            }
            if(b>='2'&&b<='9')
            {
                int x=b-'0';
                if(p[4][x]!=0) continue;
                p[4][x]=1;
            }
            else{
                int x=b-'A';
                if(p[4][x]!=0) continue;
                p[4][x]=1;
            }
        }
        ans--;
    }
    cout<<ans<<'\n';
    return 0;
}
