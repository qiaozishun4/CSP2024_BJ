#include<bits/stdc++.h>
using namespace std;
int a[5][15];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,ans=52;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        int l;
        if(s[0]=='D')l=1;
        else if(s[0]=='C')l=2;
        else if(s[0]=='H')l=3;
        else if(s[0]=='S')l=4;
        if(s[1]>='2' && s[1]<='9')
        {
            a[l][s[1]-'0']=1;
        }
        else if(s[1]=='A')a[l][1]=1;
        else if(s[1]=='T')a[l][10]=1;
        else if(s[1]=='J')a[l][11]=1;
        else if(s[1]=='Q')a[l][12]=1;
        else if(s[1]=='K')a[l][13]=1;
    }
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=13;j++)
        {
            if(a[i][j]==1)ans--;
        }
    }
    cout<<ans;
    return 0;
}
