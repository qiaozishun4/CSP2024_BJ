#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
ll T,n,m,L,V,d[100010],v[100010],a[100010],p[100010];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n>>m>>L>>V;
        for(int i=1;i<=n;i++){
            cin>>d[i]>>v[i]>>a[i];
        }
        for(int i=1;i<=m;i++){
            cin>>p[i];
        }
        int ans1=0;
        vector<pii> vec;
        for(int i=1;i<=n;i++){
            if(a[i]>=0){
                ll l=lower_bound(p+1,p+1+m,d[i])-p;
                if(l==m+1)  continue;
                l--;
                ll r=m+1;
                while(r-l>1){
                    ll mid=(l+r)/2ll;
                    if(v[i]*v[i]+2ll*a[i]*(p[mid]-d[i])>V*V){
                        r=mid;
                    }
                    else{
                        l=mid;
                    }
                }
                //cout<<i<<" a>=0 "<<r<<endl;
                if(r<=m){
                    ans1++;
                    vec.push_back({m,r});
                }
            }
            else{
                if(v[i]<=V) continue;
                ll l=lower_bound(p+1,p+1+m,d[i])-p;
                if(l==m+1)  continue;
                int sv=l;
                l--;
                ll r=m+1;
                while(r-l>1){
                    ll mid=(l+r)/2ll;
                    if(2ll*abs(a[i])*(p[mid]-d[i])>=v[i]*v[i]-V*V){
                        r=mid;
                    }
                    else{
                        l=mid;
                    }
                }
                //cout<<i<<" a<0 "<<sv<<" "<<r<<endl;
                if(r>sv){
                    ans1++;
                    vec.push_back({r-1,sv});
                }
            }
        }
        int ans2=0;
        sort(vec.begin(),vec.end());
        for(int i=0;i<(int)vec.size();i++){
            int j=i;
            while(j<(int)vec.size()&&vec[j].second<=vec[i].first&&vec[i].first<=vec[j].first) j++;
            j--;
            i=j;
            ans2++;
        }
        ans2=m-ans2;
        cout<<ans1<<" "<<ans2<<endl;
    }
    return 0;
}