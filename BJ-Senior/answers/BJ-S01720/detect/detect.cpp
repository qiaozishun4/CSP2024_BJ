#include<bits/stdc++.h>
using namespace std;
int p[100005];
struct carr{
    int d,v,a;
    double mo;
}car[100005];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n,m,L,V;
        cin>>n>>m>>L>>V;
        int flagA=0,flagC=0;
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&car[i].d,&car[i].v,&car[i].a);
            if(car[i].a!=0){
                flagA=1;
            }
            if(car[i].a>=0){
                flagC=1;
            }
        }
        for(int i=1;i<=m;i++){
            scanf("%d",&p[i]);
        }
        if(flagA==0){
            int sum=0;
            for(int i=1;i<=n;i++){
                if(car[i].v<=V||car[i].d>p[m]){
                    sum++;
                }
            }
            if(sum==n){
                cout<<sum<<" "<<m<<"\n";
            }else{
                cout<<sum<<" "<<m-1<<"\n";
            }
        }
    }
    return 0;
}
