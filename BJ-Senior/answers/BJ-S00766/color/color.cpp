#include<cstdio>
const int N=2e5+5,M=1e6+5;
int a[N],n,maxn=-1;
bool value[N];
inline int max(const int &x,const int &y){return x>=y?x:y;}
void dfs(int x)
{
    if(x==n+1)
    {
        int c=0;
        for(int i=1;i<=n;i++)
            for(int j=i-1;j>=1;j--)
                if(value[i]==value[j]&&a[i]==a[j])
                {
                    c+=a[i];
                    break;
                }
        maxn=max(maxn,c);
        return;
    }
    value[x]=true;
    dfs(x+1);
    value[x]=false;
    dfs(x+1);
}
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int s[M];
        scanf("%d",&n);
        int curmaxn=-1;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            ++s[a[i]];
            curmaxn=max(curmaxn,s[a[i]]);
        }
        if(curmaxn==1)
        {
            printf("0\n");
            continue;
        }
        maxn=-1;
        dfs(1);
        printf("%d\n",maxn);
    }
    return 0;
}