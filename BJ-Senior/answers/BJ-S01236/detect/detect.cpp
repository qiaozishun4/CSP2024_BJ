#include<bits/stdc++.h>
#define int long long
using namespace std;
struct cs{
    int l,r;
}s[100009];
int inn;
int sx[1000009];
bool pd(int l,int r){
    l--;
    if(l==-1){
        return sx[r];
    }
    return sx[r]-sx[l];
}
bool cmp(cs a1,cs a2){
    return a1.r==a2.r?a1.l>a2.l:a1.r<a2.r;
}
void _main(){
    inn=0;
    memset(s,0,sizeof(s));
    memset(sx,0,sizeof(sx));
int n,m,l1,v;
    cin>>n>>m>>l1>>v;
    for(int i=1;i<=n;i++){
        int d,vv,a;
        cin>>d>>vv>>a;
        int l,r;
        if(a<0){
            l=d;
            r=d+(vv*vv-v*v-1)/(-2*a);
            r=min(r,l1);
            if(vv<=v||r<l){
                continue;
            }
            s[++inn]={l,r};
        }else if(a==0){
            if(vv>v){
                s[++inn]={d,l1};
            }

        }else{
            l=d+(v*v-vv*vv+2*a)/(2*a);
            r=l1;
            l=max(l,d);
            if(l<=r){
                s[++inn]={l,r};
            }
        }
    }
    for(int i=1;i<=m;i++){
        int d;
        cin>>d;
        sx[d]=1;
    }
    for(int i=1;i<=1000002;i++){
        sx[i]+=sx[i-1];
    }
    int cc;
    cc=0;
    for(int i=1;i<=inn;i++){
        if(pd(s[i].l,s[i].r)){
           s[++cc]=s[i];
        }
    }
    inn=cc;
    sort(s+1,s+1+inn,cmp);
    cc=1;
    cout<<inn<<" ";
    if(inn==0){
        cout<<m<<endl;
        return;
    }
    for(int i=2;i<=inn;i++){
        if(s[i].l>s[cc].l){
           s[++cc]=s[i];
        }
    }
    inn=cc;
    int ans;
    ans=0;
    int ll,r;
    ll=-1,r=1e16;
    for(int i=1;i<=inn;i++){
        ll=max(ll,s[i].l);
        r=min(r,s[i].r);
        if(!pd(ll,r)||r<ll){
            ll=s[i].l,r=s[i].r;
            ans++;
        }
    }
    if(ll!=-1||r!=1e16){
        ans++;
    }
    cout<<m-ans<<endl;
}
signed main(){
    std::ios::sync_with_stdio(0);
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        _main();
    }
    return 0;
}
