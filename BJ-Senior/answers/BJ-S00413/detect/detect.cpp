#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n,m,L,V,p[maxn],ans1=0,ans2=0,q,l[maxn],visl[1000005];
double t,s;
struct st{
    int d,v,a;
}c[maxn];
int main(int argc,char** argv){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    memset(l,0,sizeof(l));
    memset(visl,0,sizeof(visl));
    cin>>q;
    while(q--){
        int location;
        cin>>n>>m>>L>>V;
        for(int i=1;i<=n;i++) cin>>c[i].d>>c[i].v>>c[i].a;
        for(int i=1;i<=m;i++) cin>>l[i];
        for(int i=1;i<=n;i++){
            location=maxn;
            if(c[i].a==0){
                if(c[i].v<=V||c[i].d>l[m]){
                    continue;
                }
                for(int j=1;j<=m;j++){
                    if(l[j]>=c[i].d){
                        location=j;
                        break;
                    }
                }
                visl[location]=1;
                ans1++;
            }else if(c[i].a>0){
                t=(V-c[i].v*1.0)/(c[i].a*1.0);
                s=c[i].v*t+(1.0*c[i].a*t*t)/2.0;
                if(1.0*c[i].d+s>=l[m]*1.0){
                    continue;
                }
                for(int j=1;j<=m;j++){
                    if(l[j]>c[i].d+s){
                        location=j;
                        break;
                    }
                }
                if(location!=maxn){
                    visl[location]=1;
                    ans1++;
                }
            }else{
                double des=0;
                if(c[i].v<=V){
                    continue;
                }
                t=(V-c[i].v*1.0)/(c[i].a*1.0);
                s=c[i].v*t+(1.0*c[i].a*t*t)/2.0;
                for(int j=1;j<=m;j++){
                    if(1.0*c[i].d+s>l[j]*1.0&&c[i].d<=l[j]){
                        location=j;
                        break;
                    }
                }
                if(location!=maxn){
                    visl[location]=1;
                    ans1++;
                }
            }
        }
        for(int i=1;i<=m;i++){
            if(visl[i]==0){
                ans2++;
            }
        }
        cout<<ans1<<" "<<ans2<<endl;
        ans1=0;ans2=0;
        memset(l,0,sizeof(l));
        memset(visl,0,sizeof(visl));
    }
    return 0;
}
