#include <bits/stdc++.h>
using namespace std;
long long n;
long long b[100][5],cnt=0;
string a;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        if(a[1]>='0'&&a[1]<='9')
        {
            if(a[0]=='C')b[a[1]-'0'][1]++;
            else if(a[0]=='D')b[a[1]-'0'][2]++;
            else if(a[0]=='H')b[a[1]-'0'][3]++;
            else if(a[0]=='S')b[a[1]-'0'][4]++;
        }
        else
        {
            int p;
            if(a[1]=='A')p=1;
            else if(a[1]=='T')p=10;
            else if(a[1]=='J')p=11;
            else if(a[1]=='Q')p=12;
            else if(a[1]=='K')p=13;
            if(a[0]=='C')b[p][1]++;
            else if(a[0]=='D')b[p][2]++;
            else if(a[0]=='H')b[p][3]++;
            else if(a[0]=='S')b[p][4]++;
        }
    }
    for(int i=1;i<=13;i++)
    {
        for(int j=1;j<=4;j++)
        {
            if(b[i][j]==0)cnt++;
        }
    }
    cout<<cnt<<endl;
    //01muban
    /*
        cin>>t>>m;
        for(int i=1;i<=m;i++)
        {
            cin>>w[i]>>v[i];
        }
        for(int i=1;i<=m;i++)
        {
            for(int j=t;j>=0;j--)
            {
                if(j>=w[i])
                {
                    dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+v[i];
                }
            }
        }
        cout<<dp[m][t];
    */
    return 0;
}
