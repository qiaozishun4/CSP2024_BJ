#include<bits/stdc++.h>
using namespace std;
const long long N=100005,M=100005;
long double wy(long long v,long long a,long long V){
    return 1.0*(V+v)*(V-v)/(2*a);
}
long long t,n,m,L,V,d[N],v[N],a[N],p[M],ans,ans2,tot;
struct A{
    long long l,r;
}qj[N];
bool cmp(A a,A b){
    if(a.r!=b.r)return a.r<b.r;
    else return a.l<b.l;
}
void jb(long long l,long long r){
    long long le=lower_bound(p+1,p+m+1,l)-p,ri=upper_bound(p+1,p+m+1,r)-p-1;
    if(le>ri);
    else{
        ans++,tot++;
        qj[tot].l=le,qj[tot].r=ri;
    }
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n>>m>>L>>V;
        for(long long i=1;i<=n;i++)cin>>d[i]>>v[i]>>a[i];
        for(long long i=1;i<=m;i++)cin>>p[i];
        ans=ans2=tot=0;
        for(long long i=1;i<=n;i++){
            if(a[i]<0){
                if(v[i]<=V);
                else{
                    jb(d[i],d[i]+(long long)ceil(wy(v[i],a[i],V))-1);
                }
            }
            else if(a[i]==0){
                if(v[i]<=V);
                else jb(d[i],L);
            }
            else{
                if(v[i]>V)jb(d[i],L);
                else{
                    jb(d[i]+(long long)floor(wy(v[i],a[i],V))+1,L);
                }
            }
        }
        sort(qj+1,qj+tot+1,cmp);
        long long la=-1;
        for(long long i=1;i<=tot;i++){
            if(qj[i].l<=la);
            else la=qj[i].r,ans2++;
        }
        cout<<ans<<" "<<m-ans2<<"\n";
    }
    return 0;
}

