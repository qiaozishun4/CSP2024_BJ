#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+1;
int t,n,m,L,V,d[N],v[N],a[N],p[N],l[N],r[N],pre[N],ans=0;
int abs(int a){
    return max(a,-a);
}
int ceil(int x,int y){
    return x/y+(x%y!=0);
}
int exfloor(int x,int y){
    return x/y-(x%y==0);
}
int exceil(int x,int y){
    return x/y+1;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>m>>L>>V;
        for(int i=1;i<=n;i++){
            cin>>d[i]>>v[i]>>a[i];
            if(a[i]==0){
                if(v[i]>V){
                    l[i]=d[i],r[i]=L;
                }
            }else if(a[i]>V){
                int s=V*V-v[i]*v[i];
                int st=exceil(s,2*a[i]);
                if(st<=L){
                    l[i]=st,r[i]=L;
                }
            }else{
                if(v[i]>V){
                    l[i]=d[i],r[i]=min(L,exfloor(v[i]*v[i]-V*V,-2*a[i]));
                }
            }
        }
        for(int i=1;i<=m;i++){
            cin>>p[i];
        }
        for(int i=1;i<=n;i++){
            int g=lower_bound(p+1,p+m+1,l[i])-p;
            int h=upper_bound(p+1,p+m+1,r[i])-p-1;
            if(h-g+1>0){
                ans++;
            }
        }
        cout<<ans<<' '<<m-1<<'\n';
    }
    return 0;
}

