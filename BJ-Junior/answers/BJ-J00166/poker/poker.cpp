#include<bits/stdc++.h>
using namespace std;
int ans[6][20]={0};
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int i,j,n,sum=0;
    char a[2];
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[1]>>a[2];
        if(a[1]=='D')
        {
            if(a[2]>='2' and a[2]<='9')
                ans[1][a[2]-'0']++;
            if(a[2]=='A')
                ans[1][1]++;
            if(a[2]=='T')
                ans[1][10]++;
            if(a[2]=='J')
                ans[1][11]++;
            if(a[2]=='Q')
                ans[1][12]++;
            if(a[2]=='K')
                ans[1][13]++;
        }
        if(a[1]=='C')
        {
            if(a[2]>='2' and a[2]<='9')
                ans[2][a[2]-'0']++;
            if(a[2]=='A')
                ans[2][1]++;
            if(a[2]=='T')
                ans[2][10]++;
            if(a[2]=='J')
                ans[2][11]++;
            if(a[2]=='Q')
                ans[2][12]++;
            if(a[2]=='K')
                ans[2][13]++;
        }
        if(a[1]=='H')
        {
            if(a[2]>='2' and a[2]<='9')
                ans[3][a[2]-'0']++;
            if(a[2]=='A')
                ans[3][1]++;
            if(a[2]=='T')
                ans[3][10]++;
            if(a[2]=='J')
                ans[3][11]++;
            if(a[2]=='Q')
                ans[3][12]++;
            if(a[2]=='K')
                ans[3][13]++;
        }
        if(a[1]=='S')
        {
            if(a[2]>='2' and a[2]<='9')
                ans[4][a[2]-'0']++;
            if(a[2]=='A')
                ans[4][1]++;
            if(a[2]=='T')
                ans[4][10]++;
            if(a[2]=='J')
                ans[4][11]++;
            if(a[2]=='Q')
                ans[4][12]++;
            if(a[2]=='K')
                ans[4][13]++;
        }
    }
    for(i=1;i<=4;i++)
    {
        for(j=1;j<=13;j++)
        {
            if(ans[i][j]==0)
            {
                sum++;
            }
        }
    }
    cout<<sum<<endl;
    return 0;
}
