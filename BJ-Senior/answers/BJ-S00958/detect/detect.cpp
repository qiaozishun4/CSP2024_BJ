#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=100005;
int T,n,m,L,V,p[maxn],d[maxn],v[maxn],a[maxn];
pair<int,int> g[maxn];
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n>>m>>L>>V;
        for(int i=1;i<=n;++i)cin>>d[i]>>v[i]>>a[i];
        for(int i=1;i<=m;++i)cin>>p[i];
        int ans1=0,ans2=0,cnt=0;
        for(int i=1;i<=n;++i){
            int tl=1,tr=0;
            if(a[i]<0){
                if(v[i]>V){
                    a[i]=-a[i];
                    tl=lower_bound(p+1,p+m+1,d[i])-p;
                    double tmp=d[i]+(V+v[i])*(v[i]-V)/(double)a[i]/2.0;
                    tr=lower_bound(p+1,p+m+1,ceil(tmp))-p-1;
                }
            }
            else{
                if(a[i]==0&&v[i]<=V)continue;
                tr=m;
                if(v[i]>V){
                    tl=lower_bound(p+1,p+m+1,d[i])-p;
                }
                else{
                    double tmp=d[i]+(V+v[i])*(V-v[i])/(double)a[i]/2.0;
                    tl=upper_bound(p+1,p+m+1,floor(tmp))-p;
                }
            }
            if(tl<=tr){
                //if(T==15)printf("%d %d\n",tl,tr);
                ++ans1;
                g[++cnt]=make_pair(tr,tl);
            }
        }
        sort(g+1,g+cnt+1);
        for(int i=1,j=0;i<=cnt;++i){
            if(j<g[i].second){
                j=g[i].first;
                ++ans2;
            }
        }
        cout<<ans1<<' '<<m-ans2<<'\n';
    }
    return 0;
}