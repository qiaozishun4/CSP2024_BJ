#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=1e5+10,maxl=1e6+10;
const double eps=1e-7;
int n,m,l,k;
struct CAR
{
    int d,id,v,a;
}a[maxn];
int b[maxn];
int st[maxn],ed[maxn],tot;
vector<int> vec[maxn][2];
int sq(int x)
{
    return x*x;
}
int getpos(double x)
{
    int l=1,r=m,res=1;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(x>=1.0*b[mid]) res=mid,l=mid+1;
        else r=mid-1;
    }
    return res;
}
void sol()
{
    cin>>n>>m>>l>>k;
    for(int i=1;i<=n;i++) cin>>a[i].d>>a[i].v>>a[i].a;
    for(int i=1;i<=m;i++) cin>>b[i];
    tot=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i].d>b[m])
        {
            continue;
        }
        if(a[i].a==0)
        {
            if(a[i].v<=k) continue;
            st[++tot]=lower_bound(b+1,b+1+m,a[i].d)-b;
            ed[tot]=m;
            continue;
        }
        if(a[i].a<0&&a[i].v<=k)
        {
            continue;
        }
        if(a[i].a>0)
        {
            double d=1.0*(sq(k)-sq(a[i].v))/(2.0*a[i].a);
            if(d<0) d=-0.1;
            if((double)a[i].d+d>(double)b[m]+eps)
            {
                continue;
            }
            //cout<<i<<" "<<a[i].d<<" "<<1.0*(a[i].d+d)<<endl;
            //cout<<tot+1<<" "<<i<<endl;
            int tl=getpos(1.0*a[i].d+d);
            if(1.0*b[tl]<=1.0*a[i].d+d+eps) tl++;
            if(tl<=m)
            {
                st[++tot]=tl;
                ed[tot]=m;
            }

        }
        if(a[i].a<0)
        {
            double d=1.0*(sq(k)-sq(a[i].v))/(2.0*a[i].a);
            if(1.0*a[i].d+d<=b[1]+eps) continue;
            int tl=lower_bound(b+1,b+1+m,a[i].d)-b;
            int tr=getpos(d+1.0*a[i].d);
            if(1.0*a[i].d+d>b[m]+eps) tr=m;
            if(1.0*b[tr]+eps>=1.0*a[i].d+d) tr--;
            //cout<<i<<" "<<a[i].d<<" "<<a[i].d+d<<endl;
            if(tl<=tr) st[++tot]=tl,ed[tot]=tr;//,cout<<tot<<" "<<i<<endl;
        }
    }
    /*
    cout<<"seg: "<<endl;
    for(int i=1;i<=tot;i++)
    {
        cout<<st[i]<<" "<<ed[i]<<endl;
    }*/
    for(int i=1;i<=m;i++) vec[i][0].clear(),vec[i][1].clear();
    for(int i=1;i<=tot;i++)
    {
        vec[st[i]][0].push_back(i);
        vec[ed[i]][1].push_back(i);
    }
    int lst=0,cnt=0;
    for(int i=1;i<=m;i++)
    {
        bool flag=0;
        for(int x:vec[i][1])
        {
            if(st[x]<=lst) continue;
            flag=1;
            break;
        }
        if(flag) cnt++,lst=i;
    }
    cout<<tot<<" "<<m-cnt<<endl;
}
signed main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        sol();
    }
	return 0;
}
