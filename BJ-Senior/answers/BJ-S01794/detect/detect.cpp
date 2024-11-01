#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
struct node{int l,r;}t[100010];
bool cmp(node a,node b)
{
    return a.r==b.r?a.l>b.l:a.r<b.r;
}
int T,n,m,L,V,cnt,ans1,ans2;
int d[100010],v[100010],a[100010],p[100010];
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T;
    while(T--)
    {
        cin>>n>>m>>L>>V;
        ans1=ans2=cnt=0;
        memset(t,0,sizeof(t));
        for(int i=1;i<=n;i++)
            scanf("%d%d%d",&d[i],&v[i],&a[i]);
        for(int i=1;i<=m;i++)
            cin>>p[i];
        p[m+1]=100000000;
        sort(p+1,p+1+m);
        for(int i=1;i<=n;i++)
        {
            if(v[i]>V&&a[i]>=0)
                cnt++,t[cnt].l=d[i],t[cnt].r=L;
            else if(v[i]<=V&&&a[i]<=0)
                continue;
            else
            {
                long double x=((long double)V*V-v[i]*v[i])*1.0/(2*a[i]);
                if(a[i]>0&&d[i]+x>=L)
                    continue;
                else if(a[i]<0&&d[i]+x>=L)
                    cnt++,t[cnt].l=d[i],t[cnt].r=L;
                else if(a[i]>0)
                    cnt++,t[cnt].l=d[i]+int(x+0.99999999),t[cnt].r=L;
                else if(a[i]<0)
                    cnt++,t[cnt].l=d[i],t[cnt].r=d[i]+int(x);
            }
        }
        sort(t+1,t+1+cnt,cmp);
        int lst=-10001;
        for(int i=1;i<=cnt;i++)
        {
            int l=t[i].l;
            int r=t[i].r;
            if(l<=0&&r<=0)
                continue;
            int x=upper_bound(p+1,p+1+m,r)-p;
            x--;
            if(x==0)
                continue;
            if(p[x]<l)
                continue;
            else
            {
                if(l<=lst)
                    ans1++;
                else
                    lst=p[x],ans1++,ans2++;
            }
        }
        cout<<ans1<<" "<<m-ans2<<endl;
    }
    return 0;
}
