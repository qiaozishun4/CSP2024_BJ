#include <bits/stdc++.h>
using namespace std;
string s[105];
int n,vis[105],sum,w;

int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        if(s[i][1]=='A')
        {
            w=1;
        }
        else if(s[i][1]=='2')
        {
            w=2;
        }
        else if(s[i][1]=='3')
        {
            w=3;
        }
        else if(s[i][1]=='4')
        {
            w=4;
        }
        else if(s[i][1]=='5')
        {
            w=5;
        }
        else if(s[i][1]=='6')
        {
            w=6;
        }
        else if(s[i][1]=='7')
        {
            w=7;
        }
        else if(s[i][1]=='8')
        {
            w=8;
        }
        else if(s[i][1]=='9')
        {
            w=9;
        }
        else if(s[i][1]=='T')
        {
            w=10;
        }
        else if(s[i][1]=='J')
        {
            w=11;
        }
        else if(s[i][1]=='Q')
        {
            w=12;
        }
        else
        {
            w=13;
        }
        if(s[i][0]=='D')
        {
            vis[w]=1;
        }
        if(s[i][0]=='C')
        {
            vis[13+w]=1;
        }
        if(s[i][0]=='H')
        {
            vis[26+w]=1;
        }
        if(s[i][0]=='S')
        {
            vis[39+w]=1;
        }
        w=0;
    }
    for(int i=1;i<=52;i++)
    {
        if(vis[i]==0)
        {
            sum++;
        }
    }
    cout<<sum;
    return 0;
}
