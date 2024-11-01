#include <iostream>
#include <algorithm>
#include <cstring>
#define int long long
using namespace std;
const int N=1e5+7;
const int M=1e6+7;
struct car{
    int d,v0,a;
}c[N];
struct node{
    int l,r;
}b[N];
bool cmp(node x, node y)
{
    if(x.r==y.r) return x.l<y.l;
    return x.r<y.r;
}
int p[N],over[N];
int n,m,L,V,cnt[M],t,vis[N];
int pos(int i)
{
    return (V*V-c[i].v0*c[i].v0)/2/c[i].a+c[i].d+1;
}
int lowbit(int x)
{
    return x & -x;
}
void modify(int x)
{
    for(int i=x; i<=L; i+=lowbit(i))
        cnt[i]++;
}
int query(int x)
{
    int sum=0;
    for(int i=x; i>=1; i-=lowbit(i))
        sum+=cnt[i];
    return sum;
}
int check()
{
    int tmp=0,sum=0,j=1;
    for(int i=1; i<=t; i++)
    {
        if(b[i].l<=tmp) continue;
//        cout<<i<<" ";
        while(j<m)
        {
            if(p[j+1]>b[i].r) break;
            j++;
        }
//        cout<<j<<" ";
        tmp=p[j];
//        cout<<tmp<<endl;
        sum++;
    }
    return sum;
}
signed main(){
    ios::sync_with_stdio(false);
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        t=0;
        memset(cnt,0,sizeof(cnt));
        memset(over,0,sizeof(over));
        cin>>n>>m>>L>>V;
        for(int i=1; i<=n; i++)
            cin>>c[i].d>>c[i].v0>>c[i].a,c[i].d++;
        for(int i=1; i<=m; i++)
            cin>>p[i],p[i]++;
        L++;
        for(int i=1; i<=n; i++)
        {
            if(c[i].a>0)
            {
                if(c[i].v0>V) over[i]=c[i].d;
                else over[i]=pos(i);
            }
            if(c[i].a<0)
            {
                if(c[i].v0<=V) continue;
                if((V*V-c[i].v0*c[i].v0)%(2*c[i].a)==0) over[i]=pos(i)-2;
                else over[i]=pos(i)-1;
            }
            if(c[i].a==0)
            {
                if(c[i].v0<=V) continue;
                else over[i]=c[i].d;
            }
        }
        int ans=0;
        for(int i=1; i<=m; i++)
            modify(p[i]);
        for(int i=1; i<=n; i++)
        {
            if(c[i].a>0 && over[i]>L) over[i]=0;
            if(c[i].a<0 && over[i]>L) over[i]=L;
        }
//        for(int i=1; i<=L; i++) cout<<query(i)<<" ";
//        cout<<endl;
        for(int i=1; i<=n; i++)
        {
            if(!over[i]) continue;
            if(c[i].a>=0 && query(L)-query(over[i]-1)>0)
                b[++t]=(node){over[i],L};
            if(c[i].a<0 && query(over[i])-query(c[i].d-1)>0)
                b[++t]=(node){c[i].d,over[i]};
        }
//        for(int i=1; i<=n; i++)
//            cout<<over[i]<<" ";
//        cout<<endl;
        cout<<t<<" ";
//        for(int i=1; i<=t; i++)
//            cout<<b[i].l<<" "<<b[i].r<<endl;
        sort(p+1,p+m+1);
        sort(b+1,b+t+1,cmp);
        int le=1,ri=m;
//        while(le<ri)
//        {
//            int mid=(le+ri)/2;
//            if(check(mid)) ri=mid;
//            else le=mid+1;
//        }
        ans=m-check();
        cout<<ans<<endl;
    }
    return 0;
}
