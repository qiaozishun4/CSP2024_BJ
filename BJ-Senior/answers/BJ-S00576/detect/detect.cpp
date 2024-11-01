#include<bits/stdc++.h>
using namespace std;
int t;
int n,m,l,vx;
int ans=0;
int anstwo=0;
struct node{
    int d,a,v;
    float over;
    int ll,rr;
}x[100010];
int check[100010];
int lst[1000010];
void detect(){
    ans=0;
    anstwo=0;
    bool mapp[1000010];
    for(int i=1;i<=l;i++){
        lst[i]=0;
        mapp[i]=0;
    }
    scanf("%d%d%d%d",&n,&m,&l,&vx);
    for(int i=1;i<=n;i++){
        cin>>x[i].d>>x[i].v>>x[i].a;

    }
    for(int i=1;i<=m;i++){
        cin>>check[i];
    }
    for(int i=1;i<=n;i++){
        if(x[i].a>0){
            x[i].over=((vx*vx)-(x[i].v*x[i].v))/(2*x[i].a)+x[i].d;
            if(((vx*vx)-(x[i].v*x[i].v))%(2*x[i].a)!=0){
                    x[i].over+=0.1;
                }
            if(x[i].over<=check[m]){
                ans++;
                for(int j=1;j<=m;j++){
                    if(x[i].over<check[j]){
                        x[i].ll=j;
                        x[i].rr=m;
                        break;
                    }
                }
            }

        }
        else if(x[i].a==0){
            if(x[i].v>vx){
                for(int j=1;j<=m;j++){
                    if(check[j]>=x[i].d){
                        ans++;
                        x[i].ll=j;
                        x[i].rr=m;
                        break;
                    }
                }
            }
        }
        else{
            if(x[i].v>vx){
                x[i].over=((vx*vx)-(x[i].v*x[i].v))/(2*x[i].a)+x[i].d;
                if(((vx*vx)-(x[i].v*x[i].v))%(2*x[i].a)!=0){
                    x[i].over+=0.1;
                }
                bool llss=0;
                for(int j=m;j>=1;j--){
                    if(check[j]>=x[i].d&&check[j]<x[i].over){
                        if(llss==0){
                            ans++;
                            x[i].rr=j;
                            llss=1;
                        }
                        x[i].ll=j;
                    }
                }
            }
        }
        lst[x[i].ll]++;
        lst[x[i].rr+1]--;
    }
    for(int i=1;i<=m;i++){
        if(lst[i]>=0){
            anstwo+=lst[i];
        }
    }
    cout<<ans<<" "<<anstwo<<endl;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        detect();
    }
    return 0;
}
