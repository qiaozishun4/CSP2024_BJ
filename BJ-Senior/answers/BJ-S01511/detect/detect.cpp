#include<bits/stdc++.h>
#define PP pair<int,int>
#define int long long
using namespace std;
const int maxn=1e5+10,inf=0x3f3f3f3f3f3f3f3f;
int n,m,t,L,V,d[maxn],v[maxn],a[maxn],p[maxn],ans;
vector<PP> q;
bool check(int k,int l){
//    cout<<k<<' '<<l<<endl;
    double v0=v[k],aj=a[k],s=p[l]-d[k];
//    cout<<v0<<' '<<aj<<' '<<s<<" = "<<v0*v0+2*aj*s<<endl;
    if(v0*v0+2*aj*s<=0) return 1;
    double fuu=sqrt(v0*v0+2*aj*s);
    if(fuu<=V) return 1;
    else return 0;
}
void go(int k){
    if(a[k]==0){
        if(v[k]>V){
            int l=lower_bound(p,p+m,d[k])-p;
            if(l!=m) q.push_back({l,m-1});
        }
        return;
    }else if(a[k]<0){
        if(v[k]<=V) return;
        int l=lower_bound(p,p+m,d[k])-p,r=m-1;
//        cout<<"*****"<<l<<' '<<p[l]<<endl;
        int ansl=l,ansr=r;
        while(r>=l){
            int mid=(l+r)/2;
     //       cout<<l<<' '<<r<<' '<<mid<<endl;
      //      cout<<check(k,mid)<<endl;
            if(check(k,mid)) r=mid-1,ansr=r; //mei you chao su
            else l=mid+1;
        }
    //    cout<<"******************"<<ansl<<' '<<ansr<<endl;
        if(ansl<=ansr) q.push_back({ansl,ansr});
    }else if(a[k]>0){
        int l=lower_bound(p,p+m,d[k])-p,r=m-1;
        int ansl=l,ansr=r;
        while(r>=l){
            int mid=(l+r)>>1;
            if(check(k,mid)) l=mid+1,ansl=l;
            else r=mid-1;
        }
        if(ansl<=ansr) q.push_back({ansl,ansr});
    }
    return;
}
map<int,int> la;
signed main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    while(t--){
        la.clear(); q.clear(); ans=0;
        cin>>n>>m>>L>>V;
        for(int i=0;i<n;i++) cin>>d[i]>>v[i]>>a[i];
        for(int i=0;i<m;i++) cin>>p[i];
      //  go(4);
        for(int i=0;i<n;i++){
            go(i);
        }
        sort(q.begin(),q.end());
        for(int i=0,j=0;i<m;i++){
            while(j<q.size() && q[j].first==i){
                la[q[j++].second]=1;
            }
            if(la[i]){
                ans++;
                la.clear();
            }
        }
        cout<<q.size()<<' '<<m-ans<<endl;
    }
    //  for(int i=0;i<q.size();i++) cout<<q[i].first<<' '<<q[i].second<<endl;

    return 0;
}
