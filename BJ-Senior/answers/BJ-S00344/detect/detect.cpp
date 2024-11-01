#include <bits/stdc++.h>
using namespace std;
const int N=100005;
int T,n,m,L,V;
struct node{
    double l,r;
}x[N];
double r[N];
int p[N];
bool f[N],f2[N];
bool cmp(node a,node b){
    if(a.l!=b.l){
        return a.l<b.l;
    }
    return a.r<b.r;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>T;
    while(T--){
        int cnt=0;
        cin>>n>>m>>L>>V;
        for(int i=1;i<=n;i++){
            int d,v,a;
            cin>>d>>v>>a;

            if(v<=V&&a<=0){
                continue;
            }
            cnt++;
            f[cnt]=true;
            if(a>0){
                x[cnt].l=d+1.0*(V*V-v*v)/(2*a);
                x[cnt].r=L;
            }else if(a==0){
                x[cnt].l=d;
                x[cnt].r=L;
            }else{
                x[cnt].l=d;
                x[cnt].r=d+1.0*(V*V-v*v)/(2*a);
            }
        }
        sort(x+1,x+1+cnt,cmp);
        int ans=0;
        for(int i=1;i<=m;i++){
            cin>>p[i];
        }
        for(int i=1;i<=cnt;i++){
            if(x[i].l<=p[m]){
                ans++;
            }
        }
        if(ans==0){
            m++;
        }
        cout<<ans<<' '<<m-1<<'\n';
    }
    return 0;
}
