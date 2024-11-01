#include <iostream>
using namespace std;
int a[200005],n,m;
bool b[15];
void dfs(int x)
{
    if(x>n)
    {
        int i,c1,d1,c2=-1,d2=-1,s=0;
        for(i=1;i<=n;i++)
        {
            if(b[i]&&a[i]==c2)
                s+=a[i];
            if(!b[i]&&a[i]==d2)
                s+=a[i];
            if(b[i])
                c1=i,c2=a[i];
            else
                d1=i,d2=a[i];
        }
        m=max(m,s);
        return;
    }
    b[x]=0;
    dfs(x+1);
    b[x]=1;
    dfs(x+1);
}
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%d",a+i);
        if(n<=15)
        {
            m=0;
            dfs(1);
            cout<<m<<endl;
        }
    }
    return 0;
}