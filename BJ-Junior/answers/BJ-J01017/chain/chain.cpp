#include <iostream>
using namespace std;
int t,n,m,k,q,r,c,a[1005][1005];
bool flag;
void xunzhao(int x,int y)
{
    if(r==0)
    {
        if(y==c)
        {
            cout<<"1"<<endl;
            flag=1;
            return;
        }
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(i==x)
        {
            continue;
        }
        for(int j=1;j<=a[i][0];j++)
        {
            if(a[i][j]==y)
            {
                for(int l=j+1;l<=min(j+k-1,a[i][0]);l++)
                {
                    r--;
                    xunzhao(i,a[i][l]);
                    if(flag)
                    {
                        return;
                    }
                    r++;
                }
            }
        }
    }
}
void kaitou()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=a[i][0];j++)
        {
            if(a[i][j]==1)
            {
                for(int l=j+1;l<=min(j+k-1,a[i][0]);l++)
                {
                    r--;
                    xunzhao(i,a[i][l]);
                    if(flag)
                    {
                        return;
                    }
                    r++;
                }
            }
        }
    }
}
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++)
        {
            cin>>m;
            a[i][0]=m;
            for(int j=1;j<=m;j++)
            {
                cin>>a[i][j];
            }
        }
        while(q--)
        {
            cin>>r>>c;
            flag=0;
            kaitou();
            if(flag==0)
            {
                cout<<"0"<<endl;
            }
        }
    }
    return 0;
}
