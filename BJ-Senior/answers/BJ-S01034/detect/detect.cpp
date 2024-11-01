#include <bits/stdc++.h>
#define maxn 100055
using namespace std;
double t,v,d[maxn],n,m,l,p[maxn],ans,ans1,vis[maxn];
struct cars{
    double x0;
    double v0;
    double a;
    double st;
    double en;
}car[maxn];
inline double maxx(double x,double y){
    return x>y?x:y;
}
inline double minn(double x,double y){
    return x<y?x:y;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin>>t;
    int pan=0;
    for(int i=1;i<=t;i++){
        memset(car,0,sizeof(car));
        memset(d,0,sizeof(d));
        memset(p,0,sizeof(p));
        memset(vis,0,sizeof(vis));
        ans=0;
        ans1=0;
        int wan=0;
        cin>>n>>m>>l>>v;
        wan=l;
        for(int j=1;j<=n;j++){
            cin>>car[j].x0>>car[j].v0>>car[j].a;
            if(car[j].a!=0){
                pan=1;
            }
        }
        int ffar=0;
        int nffar=l;
        for(int j=1;j<=m;j++){
            cin>>p[j];
            ffar=maxx(ffar,p[j]);
        }
        int pan1=0;
        if(!pan){
            for(int j=1;j<=n;j++){
                if(car[j].v0>v){
                    pan1=1;
                    wan=minn(wan,car[j].x0);
                    car[j].st=car[j].x0;
                    car[j].en=l;
                    if(car[j].st<=ffar){
                        ans++;
                    }
                    nffar=minn(nffar,car[j].st);
                }
            }
            for(int j=1;j<=m;j++){
                if(p[j]<ffar){
                    ans1++;
                }
            }
            if(!pan1){
                ans1++;
            }
        }else{
            for(int j=1;j<=n;j++){
                if(car[j].a==0){
                    if(car[j].v0>v){
                        wan=minn(wan,car[j].x0);
                        car[j].st=car[j].x0;
                        car[j].en=l;
                        if(car[j].st<=ffar){
                            pan1=1;
                            ans++;
                        }
                        nffar=minn(nffar,car[j].st);
                    }
                }else if(car[j].a>0){
                    double x1=((v*v)-(car[j].v0*car[j].v0))/(2*car[j].a);
                    car[j].st=car[j].x0+x1;
                    car[j].en=l;
                    if(car[j].st<ffar){
                        pan1=1;
                        ans++;
                    }
                    nffar=minn(nffar,car[j].st);
                }else if(car[j].a<0){
                    if(car[j].v0>v){
                        double x2=((car[j].v0*car[j].v0)-(v*v))/(2*car[j].a);
                        car[j].st=car[j].x0;
                        car[j].en=car[j].x0+x2;
                        int maxxxx=0;
                        for(int k=1;k<=m;k++){
                            if((car[j].st<=p[k])&&(car[j].en>=p[k])){
                                maxxxx=max(maxxxx,k);
                            }
                        }
                        if(maxxxx){
                            pan1=1;
                            vis[maxxxx]=1;
                            ans++;
                        }
                    }
                }

            }
            for(int k=1;k<=m;k++){
                if(vis[k]||p[k]<ffar){
                    ans1++;
                }
            }
            if(!pan1){
                ans1++;
            }
        }
        cout<<ans<<" "<<ans1<<endl;
    }
    return 0;
}

