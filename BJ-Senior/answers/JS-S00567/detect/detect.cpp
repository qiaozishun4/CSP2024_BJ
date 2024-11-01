#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
int t,n,m,ans1,ans2;
ll L,V,d[N],v[N],a[N],p[N];
vector<pair<int,int>> intv;
bool cmp(pair<int,int> x,pair<int,int> y){
    if(x.second!=y.second) return x.second<y.second;
    return x.first<y.first;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n>>m>>L>>V;
        for(int i=1;i<=n;i++) cin>>d[i]>>v[i]>>a[i];
        for(int i=1;i<=m;i++) cin>>p[i];
        ans1=0,ans2=m;
        intv.clear();
        for(int i=1;i<=n;i++){
            if(d[i]>p[m]) continue;
            if(a[i]>0){
                if(d[i]*2*a[i]+(V*V-v[i]*v[i])>=a[i]*2*p[m]) continue;
                int l=lower_bound(p+1,p+m+1,d[i])-p,r=m,mid;
                while(l<r){
                    mid=(l+r)/2;
                    if(d[i]*2*a[i]+(V*V-v[i]*v[i])<a[i]*2*p[mid]) r=mid;
                    else l=mid+1;
                }
                ans1++;
                intv.push_back(make_pair(l,m));
            }
            else if(a[i]==0&&v[i]>V){
                int l=lower_bound(p+1,p+m+1,d[i])-p;
                ans1++;
                intv.push_back(make_pair(l,m));
            }
            else if(a[i]<0){
                if(v[i]<=V) continue;
                int pt=lower_bound(p+1,p+m+1,d[i])-p;
                int l=pt,r=m,mid;
                while(l<r){
                    mid=(l+r+1)/2;
                    if(d[i]*2*a[i]+(V*V-v[i]*v[i])<a[i]*2*p[mid]) l=mid;
                    else r=mid-1;
                }
                if(l==pt&&d[i]*2*a[i]+(V*V-v[i]*v[i])>=a[i]*2*p[l]) continue;
                ans1++;
                intv.push_back(make_pair(pt,l));
            }
        }
        sort(intv.begin(),intv.end(),cmp);
        int pt=0;
        for(int i=0;i<intv.size();i++)
            if(intv[i].first>pt) pt=intv[i].second,ans2--;
        cout<<ans1<<" "<<ans2<<"\n";
    }
    return 0;
}