#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb emplace_back
#define pii pair<int,int>
ll n,m,L,V,d[100005],v[100005],a[100005],top;
multiset<int>w;
pii f[100005];
bool cmp(pii &a,pii &b){
    if(a.first==b.first)return a.second>b.second;
    return a.first<b.first;
}
ll su(ll v,ll s,ll a){return v*v+2*a*s;}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        memset(d,0,sizeof d);memset(a,0,sizeof a);memset(v,0,sizeof v);w.clear();top=0;
        cin>>n>>m>>L>>V;
        for(int i=1;i<=n;i++){
            cin>>d[i]>>v[i]>>a[i];
        }
        for(int i=1;i<=m;i++){
            int x;
            cin>>x;
            w.insert(x);
        }
        for(int i=1;i<=n;i++){
            int x=*w.lower_bound(d[i]);
            if(a[i]<=0){
                if(d[i]>(*--w.end()))continue;
                if(su(v[i],x-d[i],a[i])>V*V){
                    d[++top]=d[i],v[top]=v[i],a[top]=a[i];
                }
            }else {
                if((*--w.end())<d[i])continue;
                if(su(v[i],(*--w.end())-d[i],a[i])>V*V){
                    d[++top]=d[i],v[top]=v[i],a[top]=a[i];
                }
            }
        }
        cout<<top<<" ";
        for(int i=1;i<=top;i++){
            if(a[i]<=0){
                int l=*w.lower_bound(d[i]),r=(*--w.end());
                f[i].first=l;
                while(l<r){
                    int mid=(l+r)/2;
                    if(su(v[i],mid-d[i],a[i])>V*V)l=mid+1;
                    else r=mid;
                }
                if(l==(*--w.end()))f[i].second=l;
                else f[i].second=*--w.upper_bound(l-1);
            }else{
                int l=*w.lower_bound(d[i]),r=(*--w.end());
                f[i].second=r;
                while(l<r){
                    int mid=(l+r)/2;
                    if(su(v[i],mid-d[i],a[i])>V*V)r=mid;
                    else l=mid+1;
                }
                f[i].first=*w.lower_bound(l);
            }
        }
        sort(f+1,f+top+1,cmp);
        int l=0,ans=0;
        for(int i=1;i<=top;i++){
            if(f[i].first>l)l=f[i].second,ans++;
            else l=min(l,f[i].second);
        }
        cout<<m-ans<<'\n';
    }
    return 0;
}
