#include<bits/stdc++.h>
using namespace std;
int h[5][15];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    string s;
    int n,i,j,ans=52;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>s;
        if(s[0]=='D')
        {
            if(s[1]=='A')h[1][1]++;
            else if(s[1]=='T')h[1][10]++;
            else if(s[1]=='J')h[1][11]++;
            else if(s[1]=='Q')h[1][12]++;
            else if(s[1]=='K')h[1][13]++;
            else h[1][s[1]-49]++;
        }
        if(s[0]=='C')
        {
            if(s[1]=='A')h[2][1]++;
            else if(s[1]=='T')h[2][10]++;
            else if(s[1]=='J')h[2][11]++;
            else if(s[1]=='Q')h[2][12]++;
            else if(s[1]=='K')h[2][13]++;
            else h[2][s[1]-49]++;
        }
        if(s[0]=='H')
        {
            if(s[1]=='A')h[3][1]++;
            else if(s[1]=='T')h[3][10]++;
            else if(s[1]=='J')h[3][11]++;
            else if(s[1]=='Q')h[3][12]++;
            else if(s[1]=='K')h[3][13]++;
            else h[3][s[1]-49]++;
        }
        if(s[0]=='S')
        {
            if(s[1]=='A')h[4][1]++;
            else if(s[1]=='T')h[4][10]++;
            else if(s[1]=='J')h[4][11]++;
            else if(s[1]=='Q')h[4][12]++;
            else if(s[1]=='K')h[4][13]++;
            else h[4][s[1]-49]++;
        }
    }
    for(i=1;i<=4;i++)
    {
        for(j=1;j<=13;j++)
        {
            if(h[i][j]!=0)
            {
                ans--;
            }
        }
    }
    cout<<ans;
    return 0;
}