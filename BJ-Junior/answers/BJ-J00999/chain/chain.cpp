#include<bits/stdc++.h>
using namespace std;
int a[1001][2001];
struct zf{
    int own[1001];
    int wz[1001];
    int va;
}ha[200050];
bool flag=0;
int n,k,q;
void pd(int n,int le,int lp)
{
    if(flag) return;
    if(n==1)
    {
        if(lp!=0&&ha[le].va>1)
        {
            for(int i=1;i<=ha[le].va;i++)
            {

                for(int j=1;j<=ha[1].va;j++)
                {
                     if(ha[le].own[i]==ha[1].own[j]&&ha[le].wz[i]-ha[1].wz[j]+1<=k&&ha[le].wz[i]-ha[1].wz[j]>0&&ha[1].own[j]!=lp)
                     {
                         flag=1;
                         return;
                     }
                }
            }
        }
        else if(lp==0&&ha[le].va>=1)
        {
            for(int i=1;i<=ha[le].va;i++)
            {

                for(int j=1;j<=ha[1].va;j++)
                {
                     if(ha[le].own[i]==ha[1].own[j]&&abs(ha[le].wz[i]-ha[1].wz[j])+1<=k&&ha[le].wz[i]-ha[1].wz[j]>0)
                     {
                         flag=1;
                         return;
                     }
                }
            }
        }
        return;
    }
    else
    {
        for(int i=1;i<=ha[le].va;i++)
        {
            for(int j=1;j<k;j++)
            {
                if(ha[le].own[i]!=lp)
                {
                    //pd(n-1,a[ha[le].own[i]][ha[le].wz[i]+j],ha[le].own[i]);
                    pd(n-1,a[ha[le].own[i]][ha[le].wz[i]-j],ha[le].own[i]);
                }
            }
        }
        return;
    }
}
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++)
        {
            int l;
            cin>>l;
            for(int j=1;j<=l;j++)
            {
                cin>>a[i][j];
                ha[a[i][j]].va++;
                ha[a[i][j]].own[ha[a[i][j]].va]=i;
                ha[a[i][j]].wz[ha[a[i][j]].va]=j;
            }
        }
        for(int i=1;i<=q;i++)
        {
            int x,y;
            cin>>x>>y;
            flag=0;
            pd(x,y,0);
            cout<<(flag==1? 1:0)<<endl;
        }
    }
    return 0;
}
