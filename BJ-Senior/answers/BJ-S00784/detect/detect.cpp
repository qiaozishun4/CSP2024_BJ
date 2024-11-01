#include<bits/stdc++.h>
using namespace std;
int T;
int n,m,l,v;
struct car{
    int d,v,a;
}c[100005];
struct edge{
    double le,ri;
    bool el,er;
}f[100005];
bool cmp(edge x,edge y){
    if(x.ri!=y.ri) return x.ri<y.ri;
    return x.le>y.le;
}
int p[100005];
bool last[100005];
signed main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>T;
    while(T--){
        cin>>n>>m>>l>>v;
        for(int i=1;i<=n;i++){
            cin>>c[i].d>>c[i].v>>c[i].a;
        }
        for(int i=1;i<=m;i++){
            cin>>p[i];
        }
        for(int i=1;i<=n;i++){
            if(c[i].a==0){
                if(c[i].v>v){
                    f[i].le=c[i].d;
                    f[i].ri=l;
                    f[i].el=true;
                    f[i].er=true;
                }
                else{
                    f[i].le=f[i].ri=-1;
                }
                continue;
            }
            double s=1.0*(v*v-c[i].v*c[i].v)/(2*c[i].a);
            if(c[i].a>0){
                if(c[i].d+s>l){
                    f[i].le=f[i].ri=-1;
                }
                else{
                    f[i].le=c[i].d+s;
                    f[i].ri=l;
                    f[i].el=false;
                    f[i].er=true;
                }
                continue;
            }
            if(c[i].a<0){
                if(s<0){
                    f[i].le=f[i].ri=-1;
                }
                else{
                    f[i].le=c[i].d;
                    f[i].ri=c[i].d+s;
                    f[i].el=true;
                    f[i].er=false;
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            int l=1,r=m;
            int mid;
            //cout<<"HERE?";
            while(l<r){
                mid=(l+r)/2;
                if(p[mid]<f[i].le){
                    l=mid+1;
                }
                else if(p[mid]==f[i].le){
                    break;
                }
                else{
                    r=mid;
                }
            }
            if(p[mid]<f[i].le){
                mid++;
            }
            if(f[i].el&&f[i].er){
                if(p[mid]>=f[i].le&&p[mid]<=f[i].ri){
                    ans++;
                }
                else{
                    f[i].le=f[i].ri=-1;
                }
            }
            else if(!f[i].el&&f[i].er){
                if(p[mid]>f[i].le&&p[mid]<=f[i].ri){
                    ans++;
                    f[i].le=f[i].ri=-1;
                }
            }
            else if(f[i].el&&!f[i].er){
                if(p[mid]>=f[i].le&&p[mid]<f[i].ri){
                    ans++;
                    f[i].le=f[i].ri=-1;
                }
            }
        }
        cout<<ans<<' ';
        sort(f+1,f+n+1,cmp);
        int pos=0;
        for(int i=1;i<=n;i++){
            if(f[i].le!=-1){
                pos=i;
                break;
            }
        }
        for(int i=pos;i<=n;i++){
            for(int j=pos;j<=n;j++){
                if(f[j].le>=f[i].le&&f[j].ri<=f[i].ri){
                    last[i]=true;
                    last[j]=false;
                }
            }
        }
        for(int i=pos;i<=n;i++){
            if(last[i]) ans++;
        }
        cout<<m-ans<<endl;
    }
    return 0;
}
