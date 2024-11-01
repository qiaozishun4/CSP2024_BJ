#include <bits/stdc++.h>

using namespace std;

int n;
string s;
int m[5][15];
int ans;

int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s;
        if(s[0]=='D')
        {
            if(s[1]=='A')
                m[1][1]=1;
            else if(s[1]=='T')
                m[1][10]=1;
            else if(s[1]=='J')
                m[1][11]=1;
            else if(s[1]=='Q')
                m[1][12]=1;
            else if(s[1]=='K')
                m[1][13]=1;
            else
                m[1][s[1]-'0']=1;
        }
        else if(s[0]=='C')
        {
            if(s[1]=='A')
                m[2][1]=1;
            else if(s[1]=='T')
                m[2][10]=1;
            else if(s[1]=='J')
                m[2][11]=1;
            else if(s[1]=='Q')
                m[2][12]=1;
            else if(s[1]=='K')
                m[2][13]=1;
            else
                m[2][s[1]-'0']=1;
        }
        else if(s[0]=='H')
        {
            if(s[1]=='A')
                m[3][1]=1;
            else if(s[1]=='T')
                m[3][10]=1;
            else if(s[1]=='J')
                m[3][11]=1;
            else if(s[1]=='Q')
                m[3][12]=1;
            else if(s[1]=='K')
                m[3][13]=1;
            else
                m[3][s[1]-'0']=1;
        }
        else if(s[0]=='S')
        {
            if(s[1]=='A')
                m[4][1]=1;
            else if(s[1]=='T')
                m[4][10]=1;
            else if(s[1]=='J')
                m[4][11]=1;
            else if(s[1]=='Q')
                m[4][12]=1;
            else if(s[1]=='K')
                m[4][13]=1;
            else
                m[4][s[1]-'0']=1;
        }
    }
    for(int i=1;i<=4;i++)
        for(int j=1;j<=13;j++)
            if(m[i][j]==0)
                ans++;
    cout<<ans;
    return 0;
}
