#include<bits/stdc++.h>
using namespace std;
struct over
{
    int l,r;
    bool vis;
};
struct car
{
    double d,v,a;
};
int cnt;
car a[100005];
int chk[100005];
int ck[1000005];
over h[100005];
int T,n,m,L,V;
int ans_c,ans_ban;
double dou(double x)
{
    return x*x;
}
void x_init(double x,double y)
{
    h[++cnt].l=int(x);
    h[cnt].r=int(y);
    //printf("%d - %d\n",h[cnt].l,h[cnt].r);
    //chk[h[cnt].l]++,chk[h[cnt].r+1]--;
}
bool cmp(over a,over b)
{
    if(a.l!=b.l)
    {
        return a.l<b.l;
    }
    if(a.r!=b.r)
    {
        return a.r<b.r;
    }
}
void prt_h()
{
    for(int i=1;i<=cnt;i++)
    {
        printf("l=%d r=%d\n",h[i].l,h[i].r);
    }
    printf("\n");
}
void clears()
{
    ans_ban=ans_c=cnt=0;
    memset(ck,0,sizeof(ck));
    memset(chk,0,sizeof(chk));

}
int main()
{
    freopen("detect5.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T;
    while(T--)
    {
        clears();
        scanf("%d%d%d%d",&n,&m,&L,&V);
        for(int i=1;i<=n;i++)
        {
            scanf("%lf%lf%lf",&a[i].d,&a[i].v,&a[i].a);
            if(a[i].a!=0)
            {
                if(a[i].v<=V&&a[i].a<0)
                {
                    continue;
                }
                else if(a[i].v>V&&a[i].a>0)
                {
                    x_init(a[i].d,L);
                }
                else
                {
                    if(a[i].v>V)
                    {
                        double finish=a[i].d+( (dou(double(V))-dou(a[i].v)) / (2*a[i].a));
                        finish=ceil(finish)-1;
                        x_init(a[i].d,min(double(L),finish));
                    }
                    else
                    {
                        double finish=a[i].d+((dou(double(V))-dou(a[i].v)) / (2*a[i].a));
                        finish=ceil(finish)-1;
                        if(int(finish)<=L)
                        {
                            x_init(finish,L);
                        }
                    }
                }
            }
            else
            {
                if(a[i].v>V)
                {
                    x_init(a[i].d,L);
                }
            }
        }
        sort(h+1,h+cnt+1,cmp);
        int x;
        for(int i=1;i<=m;i++)
        {
            scanf("%d",&chk[i]);
            //chk[x]-=low;
            //chk[x+1]+=low;
        }
        for(int j=1;j<=n;j++)
        {
            for(int i=1;i<=m;i++)
            {
                if(h[i].vis==1)
                {
                    if(ck[i]==0)
                    {
                        //cout<<i<<endl;
                        ck[i]=1;

                        ans_ban++;
                    }
                    continue;
                }
                if(chk[j]>=h[i].l&&chk[j]<=h[i].r)
                {
                    h[i].vis=1;
                    ans_c++;
                }
            }
        }
        cout<<ans_c<<" "<<ans_ban<<"\n";
    }
    return 0;
}
