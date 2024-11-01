#include <bits/stdc++.h>
using namespace std;
struct Range{
    int lx,rx;
}ra[200005];
int t,n,m,ans1,ans2,lst;
double L,V,d[200005],v[200005],a[200005],p[200005];
int st[200005];
int f_st(int id){
    int l=1,r=m,mid,res=m+1;
    while(l<=r){
        mid=(l+r)/2;
        if(p[mid]<d[id]) l=mid+1;
        else {r=mid-1; res=mid;}
    }
    return res;
}
bool cmp(Range x1,Range x2){
    return x1.rx<x2.rx;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>m>>L>>V;
        ans1=ans2=lst=0;
        for(int i=1;i<=n;i++) cin>>d[i]>>v[i]>>a[i];
        for(int i=1;i<=m;i++) cin>>p[i];
        for(int i=1;i<=n;i++) st[i]=f_st(i);
        for(int i=1;i<=n;i++){
            ra[i].lx=ra[i].rx=0;
            if(a[i]==0&&v[i]>V) ra[i].lx=st[i],ra[i].rx=max(st[i],m);
            if(a[i]>0){
                int l=st[i],r=m,mid,res=m+1; double nowv;
                while(l<=r){
                    mid=(l+r)/2;
                    if(v[i]*v[i]+2*a[i]*(p[mid]-d[i])<0) {l=mid+1; continue;}
                    nowv=sqrt(v[i]*v[i]+2*a[i]*(p[mid]-d[i]));
                    if(nowv<=V) l=mid+1;
                    else {r=mid-1; res=mid;}
                }
                ra[i].lx=res; ra[i].rx=max(res,m);
            }
            if(a[i]<0){
                int l=st[i],r=m,mid,res=0; double nowv;
                while(l<=r){
                    mid=(l+r)/2;
                    if(v[i]*v[i]+2*a[i]*(p[mid]-d[i])<0) {r=mid-1; continue;}
                    nowv=sqrt(v[i]*v[i]+2*a[i]*(p[mid]-d[i]));
                    if(nowv<=V) r=mid-1;
                    else {l=mid+1; res=mid;}
                }
                ra[i].rx=res; ra[i].lx=min(st[i],res);
            }
        }
        sort(ra+1,ra+1+n,cmp);
        for(int i=1;i<=n;i++){
                if(ra[i].lx==0||ra[i].lx==m+1) continue;
                ans1++;
                if(lst<ra[i].lx) {ans2++; lst=ra[i].rx;}
        }
        cout<<ans1<<" "<<m-ans2<<endl;
    }
    return 0;
}
