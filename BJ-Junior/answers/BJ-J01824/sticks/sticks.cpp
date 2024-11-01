#include<bits/stdc++.h>
using namespace std;
int l[55]={0,-1,1,7,4,2,6,8,10,18,22,20,28,68,88,108,188,228,208,288,688};
int sti[7]={6,2,5,4,6,3,7};
int shu[7]={0,1,2,4,6,7,8};
int ans[1000005];
bool f=0;
int iff=-1;
void dfs(int n,int i)
{
    if(n==0)
    {
        if(ans[i]!=0)
        {
            f=1;
            iff=i;
        }
        return;
    }
    if(n<0)return;
    else
    {
        for(int i=0;i<=6;i++)
        {
            ans[i]=shu[i];
            dfs(n-sti[i],i+1);
            ans[i]=0;
        }
    }
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    //da kai wen jian
    int x;
    cin>>x;
    for(int j=1;j<=x;j++)
    {
        int n;
        cin>>n;
        if(n<=20)cout<<l[n];
        else if(n%7==0)
        {
            for(int i=1;i<=n/7;i++)
            cout<<8;
        }
        else
            dfs(n,1);
            for(int m=iff;m>=1;m--)
            {
                cout<<ans[m];
            }
        }
    return 0;
}
