#include <bits/stdc++.h>
using namespace std;
struct st{
    int d,v,a;
} b[100005];
struct node{
    int s,t;
    bool operator <(const node &k) const{
        if(t==k.t) return s<k.s;
        return t<k.t;
    }
} d[100005];
int c[100005];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n,m,l,v,ans=0,len=0;cin>>n>>m>>l>>v;
        for(int i=1;i<=n;i++) cin>>b[i].d>>b[i].v>>b[i].a;
        for(int i=1;i<=m;i++) cin>>c[i];
        for(int i=1;i<=n;i++){
            int id=lower_bound(c+1,c+m+1,b[i].d)-c;
            if(!b[i].a){
                if(b[i].v>v&&id<=m) d[++len].s=id,d[len].t=m,ans++;
                continue;
            }
            double x=(double)(v*v-b[i].v*b[i].v)/(2*b[i].a);
            if(x<0){
                if(b[i].a>0&&id<=m) d[++len].s=id,d[len].t=m,ans++;
            }else{
                if(b[i].a>0){
                    int tmp=upper_bound(c+1,c+m+1,b[i].d+x)-c;
                    if(tmp<=m) d[++len].s=tmp,d[len].t=m,ans++;
                }else{
                    int tmp=lower_bound(c+1,c+m+1,b[i].d+x)-c-1;
                    tmp=min(tmp,m);
                    if(tmp>=id) d[++len].s=id,d[len].t=tmp,ans++;
                }
            }
        }
        sort(d+1,d+len+1);
        int last=0,cnt=0;
        for(int i=1;i<=len;i++){
            if(d[i].s>last) cnt++,last=d[i].t;
        }
        cout<<ans<<' '<<m-cnt<<'\n';
    }
    return 0;
}
//CSP-S rp++;
