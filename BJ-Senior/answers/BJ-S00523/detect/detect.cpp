#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#define clear(x) memset(x,0,sizeof(x))
#define maxn 100005
using namespace std;
double cals(int v0,int a,int t){
    return t*(v0*t+0.5*a*t);
}
double calv(int v0,int a,int s){
    return sqrt(v0*v0+2*a*s);
}
double calms(int v0,int v1,int a){
    if(a==0)return -1;
    return (double)(v1+v0)*(v1-v0)/(2*a);
}
int t,n,m,L,V,d,v,a,p[maxn],j,cnt,ntc,tcn,ans,road[1000005],mx,po,ans2,z,road2[1000005];
double l[maxn],r[maxn];
bool vis[maxn];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    while(t--){
        clear(l);
        clear(r);
        clear(road);
        clear(road2);
        cnt=ntc=tcn=ans=j=mx=z=0;
        cin>>n>>m>>L>>V;
        ans2=m;
        double g,o;
        for(int i = 1;i<=n;i++){
            cin>>d>>v>>a;
            if(a>0){
                g=d+calms(v,V,a);
                o=L;
                cnt++;
            }
            else if(a==0){
                if(v>V)g=d;
                else g=L+1;
                o=L;
                ntc++;
            }
            else{
                if(v>V)g=d;
                else g=L+1;
                o=d+calms(v,V,a);
                if(L-o<0)o=L;
                tcn++;
            }
            if(g-o<=0)l[j]=g,r[j++]=o;
        }
        for(int i = 1;i<=m;i++){
            cin>>p[i];
        }
        if(cnt+ntc==n){
            for(int i = 1;i<=j;i++){
                if(l[i]<=p[m])ans++;
            }
            cout<<ans<<" "<<m-1<<endl;
        }
        else{
            for(int i = 1;i<=j&&tcn!=n;i++){
                road[(int)ceil(l[i])]++;
                road[(int)ceil(r[i])]--;
            }
            while(z<n){
                for(int i = 1;i<=L;i++){
                    road2[i]=road2[i-1]+road[i];
                }
                for(int i = 1;i<=m;i++){
                    if(road[p[i]]==0)ans2++;
                    else if(road[p[i]]>mx)mx=road[p[i]],po=i;
                }
                if(mx==0)break;
                for(int i = 1;i<=n;i++){
                    if(l[i]<=p[po]&&p[po]<=r[i]&&!vis[i]){
                        vis[i]=true;
                        z++;
                        road[(int)ceil(l[i])]--;
                        road[(int)ceil(r[i])]++;
                    }
                }
            }
            cout<<z<<" "<<ans2<<endl;
        }
    }
    return 0;
}
//雅库莫尤卡利
//雅各克洛艾霖
/*
1
5 5 15 3
0 3 0
12 4 0
1 1 4
5 5 ‐2
6 4 ‐4
2 5 8 9 15
*/
