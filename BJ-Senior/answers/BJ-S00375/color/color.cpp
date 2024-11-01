#include<bits/stdc++.h>
using namespace std;
int A[200005],B[200005];
int ans,n,t;

int check()
{
    int sum=0;
    for(int j=1;j<=n;j++)
    {
        t=0;
        for(int k=j-1;k>=1;k--)
        {
            if(B[k]==B[j])
            {
                t=k;
                break;
            }
        }
        if(!t)
        {
            continue;
        }
        if(A[j]==A[t])
        {
            sum+=A[j];
        }
    }
    return sum;
}

int finds(int now,int color)
{
    B[now]=color;
    if(now==n)
    {
        ans=max(ans,check());
        return 0;
    }
    finds(now+1,1);
    finds(now+1,2);
    return 0;
}

int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    cin>>T;
    for(int i=1;i<=T;i++)
    {
        cin>>n;
        for(int j=1;j<=n;j++)
        {
            cin>>A[j];
        }
        finds(1,1);
        finds(1,2);
        cout<<ans<<endl;
        ans=0;
    }
    return 0;
}
