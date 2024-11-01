#include<bits/stdc++.h>
using namespace std;
struct car{
    long long d,speed,a;
    float chaosud;
};
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    long long p[100005],maxn=-99999;
    long double chaosud[100005];
    bool flag[100005]={false};
    scanf("%d",&T);
    while(T--){
        car a[100005];
        long long ans1=0,ans2=0;
        bool teshuxingzhiA=true;
        long long n,m,l,v;
        scanf("%lld%lld%lld%lld",&n,&m,&l,&v);
        for(int i=1;i<=n;i++){
            scanf("%lld%lld%lld",&a[i].d,&a[i].speed,&a[i].a);
            if(a[i].a!=0){
                teshuxingzhiA=false;
            }
        }
        for(int i=1;i<=m;i++){
            scanf("%lld",&p[i]);
        }
        if(teshuxingzhiA){
            for(int i=1;i<=n;i++){
                if(a[i].speed>v){
                    ans1++;
                }
            }
            cout<<ans1<<' '<<m-1<<endl;
        }
        else{
            for(int i=1;i<=n;i++){
                chaosud[i]=(v-a[i].speed/a[i].a)+a[i].speed*pow((v-a[i].speed/a[i].a),2);
                chaosud[i]/=2;
                if(chaosud[i]<l){
                    ans1++;
                }
            }
            for(int i=1;i<=m;i++){
                if(p[i]<chaosud[i]){
                    flag[i]=true;
                }
            }
            for(int i=1;i<=m;i++){
                if(flag[i]==false){
                    ans2++;
                }
            }
            cout<<ans1<<' '<<ans2<<endl;
        }
    }
    return 0;
}
