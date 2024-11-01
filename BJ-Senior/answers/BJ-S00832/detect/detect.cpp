#include<bits/stdc++.h>
using namespace std;

struct poi{
    int b,e;
    int zhp=0;
}a[100086];
bool cmp(poi x,poi y)
{
    return x.b<y.b;
}
int p[100086];
void clean()
{
    for(int i=1;i<=100086;i++)
    {
        a[i].e=0;
        a[i].b=0;
        a[i].zhp=0;
        p[i]=0;
    }
}
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,l,vl,cnt=0,d,v,aj;
        cin>>n>>m>>l>>vl;
        for(int i=1;i<=n;i++)
        {
            cin>>d>>v>>aj;
            if(aj<0)
            {
                if(v<=vl) continue;
                cnt++;
                int m=ceil((vl*vl-v*v)*1.0/2.0/aj);
                a[cnt].b=d;
                a[cnt].e=d+m-1;
            }
            else if(aj==0)
            {
                if(v<=vl) continue;
                a[++cnt].b=d;
                a[cnt].e=l;
            }
            else
            {
                if(v>vl)
                {
                    a[++cnt].b=d;
                    a[cnt].e=l;
                }
                else
                {

                    int m=(vl*vl-v*v)*1.0/2.0/aj;
                    if(m<l)
                    {
                        cnt++;
                        a[cnt].b=d+m+1;
                        a[cnt].e=l;
                    }

                }
            }
        }
        for(int i=1;i<=m;i++)
        {
            cin>>p[i];
        }
        sort(p+1,p+m+1);
        int cnt1=0;
        for(int i=1;i<=cnt;i++)
        {
           int l=1,r=m;
           bool flag=0;
           while(l<=r)
            {
                int mid=(l+r)/2;
                if(p[mid]<a[i].b)
                {
                   l=mid+1;
                }
                else if(p[mid]>a[i].e)
                {
                    r=mid-1;
                }
                else
                {
                    flag=1;
                    //cout<<i<<" ";
                    if(mid>a[i].zhp)
                    {
                        a[i].zhp=mid;
                        l=mid+1;
                    }
                }
            }
            if(flag) cnt1++;
        }
        printf("%d ",cnt1);
       // cout<<cnt1<<" ";
        sort(a+1,a+cnt+1,cmp);
        int cnt2=0;
        int zje=0;
        for(int i=1;i<=cnt;i++)
        {
            if(a[i].zhp==0) continue;
            if(a[i].b>a[zje].e)
            {
                cnt2++;
                zje=i;
                continue;
            }
            if(p[a[zje].zhp]<a[i].b)
            {
                cnt2++;
                zje=i;
                continue;
            }
            if(a[i].e<a[zje].e)
            {
                zje=i;
            }
        }
        printf("%d\n",m-cnt2);
        clean();
    }
    return 0;
}
