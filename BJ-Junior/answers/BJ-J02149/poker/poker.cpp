#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n; cin>>n;
    int a[5][14];
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=13;j++)
        {
            a[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++)
    {
        string s; cin>>s;
        int t1;
        if(s[0]=='D') t1=1;
        else if(s[0]=='C') t1=2;
        else if(s[0]=='H') t1=3;
        else t1=4;
        if(s[1]>='2'&&s[1]<='9')
        {
            int l=s[1]-'0';
            a[t1][l]=1;
            continue;
        }
        else
        {
            if(s[1]=='A')
            {
                a[t1][1]=1;
                continue;
            }
            else if(s[1]=='T')
            {
                a[t1][10]=1;
                continue;
            }
            else if(s[1]=='J')
            {
                a[t1][11]=1;
                continue;
            }
            else if(s[1]=='Q')
            {
                a[t1][12]=1;
                continue;
            }
            else if(s[1]=='K')
            {
                a[t1][13]=1;
                continue;
            }
        }
    }
    int ans=52;
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=13;j++)
        {
            if(a[i][j]==1) ans--;
        }
    }
    cout<<ans;
    return 0;
}
