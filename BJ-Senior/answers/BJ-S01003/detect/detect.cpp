#include<bits/stdc++.h>
using namespace std;
int t;
int n,m,L,V;
int d[100001],a[100001],v[100001];
int p[100001],c[100001];
struct node{
    int l,r;
}x[100001];
bool cmp(node x,node y){
    return x.l<y.l;
}
node bj(node a,node b){
    return {max(a.l,b.l),min(a.r,b.r)};
}
void solve(){
    cin>>n>>m>>L>>V;
    for(int i=1;i<=n;++i){
        cin>>d[i]>>v[i]>>a[i];
    }
    for(int i=1;i<=m;++i){
        cin>>p[i];
    }
    sort(p+1,p+m+1);
    int ans=0;
    for(int i=1;i<=n;++i){
        if(a[i]==0&&v[i]>V&&d[i]<=p[m]){
            x[++ans].l=lower_bound(p+1,p+m+1,d[i])-p;
            x[ans].r=m;
        }
        if(a[i]>0&&2*d[i]*a[i]+max(V*V-v[i]*v[i],0)<2*a[i]*p[m]){
            x[++ans].l=lower_bound(p+1,p+m+1,d[i]+max(V*V-v[i]*v[i],0)/(2*a[i])+1)-p;
            x[ans].r=m;
        }
        if(a[i]<0&&v[i]>V){
            int l=lower_bound(p+1,p+m+1,d[i])-p;
            int r=lower_bound(p+1,p+m+1,d[i]+(v[i]*v[i]-V*V-1)/(-2*a[i])+1)-p-1;
            if(l<=r){
                x[++ans].l=l;
                x[ans].r=r;
            }
        }
    }
    sort(x+1,x+ans+1,cmp);
    cout<<ans<<" ";
    if(ans==0){
        cout<<m<<endl;
        return ;
    }
    int sum=1;
    node id=x[1];
    for(int i=2;i<=ans;++i){
        node res=bj(id,x[i]);
        if(res.l<=res.r){
            id=res;
        }else{
            id=x[i];
            sum++;
        }
    }
    cout<<m-sum<<endl;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
