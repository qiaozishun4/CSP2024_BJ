#include <bits/stdc++.h>

using namespace std;
char m[14]={0,65,2,3,4,5,6,7,8,9,84,74,81,75};
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,ans=0,poker[4][14]={0};
    string a;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        if(a[0]=='D')
        {
            if(a[1]-'0'>=2&&a[1]-'0'<=9)
            {
                poker[0][a[1]]++;
            }
            else
            {
                for(int j=1;j<=13;j++)
                {
                    if(a[1]==m[j])
                        poker[0][j]++;
                }
            }

        }
        else if(a[0]=='C')
        {
            if(a[1]>=2&&a[1]<=9)
                {
                    poker[1][a[1]]++;
                }
            else
            {
                for(int j=1;j<=13;j++)
                {
                    if(a[1]==m[j])
                        poker[1][j]++;
                }
            }
        }
        else if(a[0]=='H')
        {
            if(a[1]>=2&&a[1]<=9)
                {
                    poker[2][a[1]]++;
                }
            else
            {
                for(int j=1;j<=13;j++)
                {
                    if(a[1]==m[j])
                        poker[2][j]++;
                }
            }
        }
        else
        {
            if(a[1]>=2&&a[1]<=9)
            {
                poker[0][a[1]]++;
            }
            else
            {
                for(int j=1;j<=13;j++)
                {
                    if(a[1]==m[j])
                        poker[0][j]++;
                }
            }
        }
    }
    for(int i=0;i<=3;i++)
    {
        for(int j=1;j<=13;j++)
        {
            if(poker[i][j]==0)
                ans++;
        }
    }
    cout<<ans;
    return 0;
}