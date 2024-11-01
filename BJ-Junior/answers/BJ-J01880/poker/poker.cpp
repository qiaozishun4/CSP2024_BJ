#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("poker.in",r,stdin);
    freopen("poker.out",w,stdout);
    int n,p[5][14];
    cin>>n;
    string s;
    for(int i=1;i<=n;i++)
    {
        cin>>s;
        if(s[0]=='D')
        {
            if(s[1]<='9'&&s[1]>='2')
            {
                p[1][s[1]-'0']++
            }
            else if(s[1]=='A')p[1][1]++;
            else if(s[1]=='J')p[1][11]++;
            else if(s[1]=='K')p[1][13]++;
            else if(s[1]=='T')p[1][10]++;
            else p[1][12]++;
        }
        else
        {
            if(s[0]=='C')
            {
                if(s[1]<='9'&&s[1]>='2')
                {
                    p[2][s[1]-'0']++
                }
                else if(s[1]=='A')p[2][1]++;
                else if(s[1]=='J')p[2][11]++;
                else if(s[1]=='K')p[2][13]++;
                else if(s[1]=='T')p[2][10]++;
                else p[2][12]++;
            }
            else
            {
                if(s[0]=='H')
                {
                    if(s[1]<='9'&&s[1]>='2')
                    {
                        p[3][s[1]-'0']++
                    }
                    else if(s[1]=='A')p[3][1]++;
                    else if(s[1]=='J')p[3][11]++;
                    else if(s[1]=='K')p[3][13]++;
                    else if(s[1]=='T')p[3][10]++;
                    else p[3][12]++;
                }
                else
                {
                    if(s[1]<='9'&&s[1]>='2')
                    {
                        p[4][s[1]-'0']++
                    }
                    else if(s[1]=='A')p[4][1]++;
                    else if(s[1]=='J')p[4][11]++;
                    else if(s[1]=='K')p[4][13]++;
                    else if(s[1]=='T')p[4[10]++;
                    else p[4][12]++;
                }
            }
        }
    }
    int ans=0;
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=13;j++)
        {
            if(p[i][j]==0)ans++;
        }
    }
    cout<<ans;
    return 0;
}