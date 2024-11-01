#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int t,n,m,l,v,p[100005],ans1,ans2;
struct car{int d,v,a;}a[100005];
bool f[100005],suba=true,subb=true;
void dfs(int x,int sum){
    if(x>m){
        int ans=0;
        for(int j=1;j<=n;j++) for(int i=1;i<=m;i++) if(a[j].d<=p[i] and f[i]){
            int s=p[i]-a[j].d;
            double v1=sqrt(a[j].v*a[j].v+2*a[j].a*s);
            if(v1>v){ans++;break;}
        }
        if(ans==ans1) ans2=max(ans2,sum);
        return;
    }
    f[x]=true;
    dfs(x+1,sum);
    f[x]=false;
    dfs(x+1,sum+1);
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    while(t--){
        ans1=0,ans2=0;
        cin>>n>>m>>l>>v;
        for(int i=1;i<=n;i++){
            cin>>a[i].d>>a[i].v>>a[i].a;
            if(a[i].a!=0) suba=false;
            if(a[i].a<=0) subb=false;
        }
        for(int i=1;i<=m;i++) cin>>p[i];
        if(n<=20 and m<=20){
            for(int j=1;j<=n;j++) for(int i=1;i<=m;i++) if(a[j].d<=p[i]){
                int s=p[i]-a[j].d;
                double v1=sqrt(a[j].v*a[j].v+2*a[j].a*s);
                if(v1>v){ans1++;break;}
            }
            if(ans1!=0) dfs(1,0);
            else ans2=m;
        }else if(suba){
            for(int i=1;i<=n;i++) if(a[i].d<=p[m] and a[i].v>v) ans1++;
            if(ans1!=0) ans2=m-1;
            else ans2=m;
        }else if(subb){
            for(int i=1;i<=n;i++) if(a[i].d<=p[m]){
                int s=p[m]-a[i].d;
                double v1=sqrt(a[i].v*a[i].v+2*a[i].a*s);
                if(v1>v) ans1++;
            }
            if(ans1!=0) ans2=m-1;
            else ans2=m;
        }
        cout<<ans1<<' '<<ans2<<endl;
    }
    return 0;
}