#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct car{
    ll d,sp,a,fd,finish;
}c[1010101];
ll t,n,m,l,v,p[1010101],det[1010110],ans1,ans2,use[1010101];
ll up(ll a,ll b){
    if(a%b==0) return a/b;
    return a/b+1;
}
int main(){
   freopen("detect.in","r",stdin);
   freopen("detect.out","w",stdout);
    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld%lld%lld",&n,&m,&l,&v);
        for(int i=1;i<=n;i++){
            scanf("%lld%lld%lld",&c[i].d,&c[i].sp,&c[i].a);
            if(c[i].a>0){
                c[i].fd=c[i].d+(v*v-c[i].sp*c[i].sp)/(2*c[i].a);
                c[i].finish=l;
                if(c[i].fd>c[i].finish) c[i].fd=0;
            }else if(c[i].a<0){
                c[i].fd=c[i].d+up((v*v-c[i].sp*c[i].sp),(2*c[i].a));
                c[i].finish=c[i].d+(-c[i].sp*c[i].sp)/(2*c[i].a);
                if(c[i].fd>c[i].finish) c[i].fd=0;
            }else{
                if(c[i].sp>v) c[i].fd=c[i].d;
                c[i].finish=l;
            }
        }
        for(int i=1;i<=m;i++){
            scanf("%lld",&p[i]);
            det[p[i]]=1;
            use[p[i]]=1;
        }
        for(int i=1;i<=n;i++){
            if(c[i].fd!=0){
                if(c[i].a>=0){
                    for(int j=c[i].fd+1;j<=c[i].finish;j++){
                        if(det[j]==1){
                            ans1++;
                            use[j]=0;
                            break;
                        }
                    }
                }else{
                    for(int j=c[i].d;j<=c[i].fd-1;j++){
                        if(det[j]==1){
                            ans1++;
                            use[j]=0;
                                break;
                        }
                    }
                }
            }
        }
        for(int i=1;i<=m;i++){
            ans2+=use[p[i]];
        }
        printf("%lld",ans1);
        cout<<" ";
        printf("%lld",ans2);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
