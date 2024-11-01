#include<bits/stdc++.h>
using namespace std;
int n,a[6][15];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    string s;
    cin>>n;
    memset(a,0,sizeof(a));
    for(int i=1;i<=n;i++)
    {
        cin>>s;
        if(s[0]=='D')
        {
            if(s[1]=='A')
            {
                a[1][1]=max(a[1][1],1);
            }
            else if(s[1]=='T')
            {
                a[1][10]=max(a[1][10],1);
            }
            else if(s[1]=='J')
            {
                a[1][11]=max(a[1][11],1);
            }
            else if(s[1]=='Q')
            {
                a[1][12]=max(a[1][12],1);
            }
            else if(s[1]=='K')
            {
                a[1][13]=max(a[1][13],1);
            }
            else
            {
                a[1][int(s[1]-'0')]=max(a[1][int(s[1]-'0')],1);
            }
        }
        else if(s[0]=='C')
        {
            if(s[1]=='A')
            {
                a[2][1]=max(a[2][1],1);
            }
            else if(s[1]=='T')
            {
                a[2][10]=max(a[2][10],1);
            }
            else if(s[1]=='J')
            {
                a[2][11]=max(a[2][11],1);
            }
            else if(s[1]=='Q')
            {
                a[2][12]=max(a[2][12],1);
            }
            else if(s[1]=='K')
            {
                a[2][13]=max(a[2][13],1);
            }
            else
            {
                a[2][int(s[1]-'0')]=max(a[2][int(s[1]-'0')],1);
            }
        }
        else if(s[0]=='H')
        {
            if(s[1]=='A')
            {
                a[3][1]=max(a[3][1],1);
            }
            else if(s[1]=='T')
            {
                a[3][10]=max(a[3][10],1);
            }
            else if(s[1]=='J')
            {
                a[3][11]=max(a[3][11],1);
            }
            else if(s[1]=='Q')
            {
                a[3][12]=max(a[3][12],1);
            }
            else if(s[1]=='K')
            {
                a[3][13]=max(a[3][13],1);
            }
            else
            {
                a[3][int(s[1]-'0')]=max(a[3][int(s[1]-'0')],1);
            }
        }
        else if(s[0]=='S')
        {
            if(s[1]=='A')
            {
                a[4][1]=max(a[4][1],1);
            }
            else if(s[1]=='T')
            {
                a[4][10]=max(a[4][10],1);
            }
            else if(s[1]=='J')
            {
                a[4][11]=max(a[4][11],1);
            }
            else if(s[1]=='Q')
            {
                a[4][12]=max(a[4][12],1);
            }
            else if(s[1]=='K')
            {
                a[4][13]=max(a[4][13],1);
            }
            else
            {
                a[4][int(s[1]-'0')]=max(a[4][int(s[1]-'0')],1);
            }
        }
    }
    int ans=52;
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=13;j++)
        {
            ans-=a[i][j];
        }
    }
    cout<<ans<<endl;
    return 0;
}