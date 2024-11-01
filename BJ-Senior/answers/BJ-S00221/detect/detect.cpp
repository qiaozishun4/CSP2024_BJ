//Wrote by Timmy in October 26th
//I wish I could have 100 points in this problem
#include <bits/stdc++.h>
using namespace std;
#define N 100010
int p[N],v[N],a[N],k[N];
pair <int,int> seg[N];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t; cin>>t;
    while (t--){
        int n,m,x,y,ans=0,tot=0;
        cin>>n>>m>>x>>y;
        for (int i=1; i<=n; i++){
            cin>>p[i]>>v[i]>>a[i];
        }for (int i=1; i<=m; i++) cin>>k[i];
        for (int i=1; i<=n; i++){
            if (v[i]<=y){
                if (a[i]<=0) continue;
                int tmp=p[i]+(y*y-v[i]*v[i])/(2*a[i]);
                int l=upper_bound(k+1,k+m+1,tmp)-k,r=m;
                if (l<=r) seg[++tot]={l,r};
            }else{
                if (a[i]>=0){
                    int l=lower_bound(k+1,k+m+1,p[i])-k,r=m;
                    if (l<=r) seg[++tot]={l,r};
                }else{
                    int l=lower_bound(k+1,k+m+1,p[i])-k;
                    int tmp=p[i]+(v[i]*v[i]-y*y+-2*a[i]-1)/(-2*a[i]);
                    int r=lower_bound(k+1,k+m+1,tmp)-k-1;
                    if (l<=r) seg[++tot]={l,r};
                }
            }
        }cout<<tot<<" ";
        sort(seg+1,seg+tot+1);
        for (int i=1; i<=tot;){
            //cout<<seg[i].first<<" "<<seg[i].second<<"\n";
            int R=seg[i].second;
            while (i<=tot&&seg[i].first<=R){
                i++,R=min(R,seg[i].second);
            }ans++;
        }cout<<m-ans<<"\n";
    }return 0;
}
