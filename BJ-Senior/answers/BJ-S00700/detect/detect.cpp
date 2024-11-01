#include<bits/stdc++.h>
using namespace std;
struct ts{
    int l,r;
};
const int N=100005;
ts w[N];
int d[N],c[N],a[N],t[N];
bool cmp(ts a,ts b){
    return a.r<b.r;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int _;
    cin>>_;
    while(_--){
        int n,m,z,v,cnt=0,ans=0,tt=-1e9;
        cin>>n>>m>>z>>v;
        for(int i=1;i<=n;++i)
            cin>>d[i]>>c[i]>>a[i];
        for(int i=1;i<=m;++i)cin>>t[i];
        for(int i=1;i<=n;++i){
            if(a[i]>0)w[cnt].r=1e9,w[cnt].l=d[i]+
            max(0,(2*a[i]-c[i]*c[i]+v*v)/2/a[i]);
            if(a[i]<0){
                if(c[i]<=v)w[cnt].l=w[cnt].r=1e9;
                else w[cnt].l=d[i],w[cnt].r=d[i]+
                (c[i]*c[i]-v*v-1)/2/(-a[i])+1;
            }
            if(a[i]==0){
                if(c[i]>v)w[cnt].l=-1e9,w[cnt].r=1e9;
                else w[cnt].l=w[cnt].r=1e9;
            }
            if(lower_bound(t,t+m,w[cnt].l)+1
            <upper_bound(t,t+m,w[cnt].r))++cnt;
        }
        sort(w,w+cnt,cmp);
        cout<<cnt<<" ";
        for(int i=0;i<cnt;++i)
        if(tt<w[i].l){
            tt=*(lower_bound(t,t+m,w[i].r)-1);
            ++ans;
        }
        cout<<ans<<endl;
    }
}
