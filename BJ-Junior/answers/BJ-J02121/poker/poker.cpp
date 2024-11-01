#include<bits/stdc++.h>
using namespace std;
int n,ans;
map<string,bool> mp;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","r",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        mp[s]=1;
    }
    for(int i=1;i<=4;i++)
    {
        string s;
        s=s+' ';
        s=s+' ';
        if(i==1)
        {
            s[0]='D';
        }
        else if(i==2)
        {
            s[0]='C';
        }
        else if(i==3)
        {
            s[0]='H';
        }
        else
        {
            s[0]='S';
        }
        for(int j=1;j<=13;j++)
        {
            if(j==1)
            {
                s[1]='A';
            }
            else if(j<10)
            {
                s[1]='0'+j;
            }
            else if(j==10)
            {
                s[1]='T';
            }
            else if(j==11)
            {
                s[1]='J';
            }
            else if(j==12)
            {
                s[1]='Q';
            }
            else
            {
                s[1]='K';
            }
            if(mp[s]!=1)
            {
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
