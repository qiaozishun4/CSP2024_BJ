#include<bits/stdc++.h>
using namespace std;

int t;
int n,m,len,V;
int pos[1000010];
int l[100010],r[100010];
int sum[1000010];

struct node
{
    int l,r;
}s[100010];

bool cmp(node x,node y)
{
    return x.l<y.l;
}

int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        int num=0;
        scanf("%d%d%d%d",&n,&m,&len,&V);
        for(int i=1;i<=n;i++)
        {
            int d,v,a;
            scanf("%d%d%d",&d,&v,&a);
            if(a==0&&v>V)
            {
                l[i]=d;
                r[i]=len;
            }
            if(a>0)
            {
                l[i]=(int)(d+(double)(V*V-v*v)/(double)(2*a)+1.0);
                r[i]=len;
            }
            if(a<0)
            {
                l[i]=d;
                r[i]=(int)(d+(double)(V*V-v*v)/(double)(2*a)-0.0000001);
            }
            if(l[i]<d)l[i]=d;
            if(r[i]>len)r[i]=len;
            if(l[i]>r[i])l[i]=r[i]=0;
        }
        for(int i=1;i<=m;i++)
        {
            int p;
            scanf("%d",&p);
            pos[p]=1;
        }
        sum[0]=0;
        for(int i=1;i<=len;i++)
            sum[i]=sum[i-1]+pos[i];
        for(int i=1;i<=n;i++)
        {
            if(sum[r[i]]-sum[l[i]-1]>0)
            {
                num++;
                s[num].l=l[i],s[num].r=r[i];
            }
        }
        printf("%d ",num);
        int ans=1;
        sort(s+1,s+num+1,cmp);
        int left,right=1e9;
        for(int i=1;i<=num;i++)
        {
            left=s[i].l;
            right=min(right,s[i].r);
            if(left>right||sum[right]-sum[left-1]<=0)
            {
                ans++;
                right=s[i].r;
            }
        }
        printf("%d\n",m-ans);
    }
    return 0 ;
}