#include<bits/stdc++.h>
# define eps 1e-6
using namespace std;
int com(long double a,long double b)
{

    if(b-a<eps)
        return 1;
    else if(fabs(b-a)<=eps) return 0;
    return -1;

}
struct node {
    long double l,r;
}segements[100100];
struct node1 {
    long long l,r;
    bool operator<(const node &T) const {
        if(l-T.l==0)
            return r<T.r;
        else return l<T.l;
    }
}t[100100];
long long n,m,L,vmax,tot,cnt,ans;
long long pos[100100];

void bs(long long d,long long v,long long a)
{
    if(a>0)
    {
        long double l=(vmax*vmax-v*v)*1.0/2*a+d;
        if(com(l,L)<=0)
        {
            segements[++cnt]=(l+eps*10,L);
        //    printf("%.3Lf %.3Lf\n",segements[cnt].l,segements[cnt].r);


        }
       // else puts("sb");
    }
    else if(a<0){
        if(v>vmax)
        {
            int k=min(((vmax*vmax-v*v)*1.0/2*a+d-eps),L*1.0-eps);
            segements[++cnt]=(d,k);
        }
      //  else puts("sb");
    }
    else{
        if(v>vmax)
            segements[++cnt]=(d,L);
    //printf("%.3Lf %.3Lf\n",segements[cnt].l,segements[cnt].r);
    }
   // else puts("sb");
}
void check(long long i)
{
    long double l=segements[i].l,r=segements[i].r;
    ll L1=1,R1=m,L2=1,R2=m;
    while(L1<R1)
    {

        ll mid=ceil((L1+R1)/2.0)
        if(com(pos[mid],r)<=0)
            R1=mid;
        else L1=mid+1
    }
    if(L2<R2){
        ll mid=ceil((L2+R2)/2.0);
        if(com(pos[mid],r)<=0)
            l2=mid;
        else R2=mid-1
    }
    if(pos[L2]>r||pos[L1]<l||L1>L2)
        return;
    t[++tot]=(L1,L2);
}
void solve()
{
    cin>>n>>m>>L>>vmax;
    tot=ans=0;

    for(int i=1;i<=n;i++)
    {
        long long d,v,a;
        cin>>d>>v>>a;
        bs(d,v,a);
    }
    for(int i=1;i<=m;i++)
    {
        cin>>pos[i];

    }
    for(int i=1;i<=cnt;i++)
    {
        cin>>check(i);

    }
    sort(t+1,t+tot+1)
    ll minend=segements[l].r;
    for(int i=2;i<=tot;i+_+)
    {

        if(t[i].l>minend)
        {

            ans++;
            ll L1=1,R1=m
            while(L1<R1)
            {

                ll mid=ceil((L1+R1)/2.0)
                if(com(pos[mid],r)<=0)
                    R1=mid;
                else L1=mid+1
            }
            minend=t[L1].r;
            i=L1;
        }
        else minend=min(minend,t[i].r);
    }
    cout<<tot<<" "<<m-ans-1;
}
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin>>T;
    while(T--)
        solve();
    return 0;
}
