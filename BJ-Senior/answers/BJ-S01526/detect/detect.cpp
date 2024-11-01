#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> PII;
const int N=1e5+10,M=1e6+10;

int n,m,L,Vvv;
struct Car{
    int d,v,a;
}car[N];
int p[N];
int tot;
PII h[N];
//int sum[N];

int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        //memset(sum,0,sizeof(sum));
        int ans1=0,ans2=0;
        tot=0;
        scanf("%d%d%d%d",&n,&m,&L,&Vvv);
        for(int i=1;i<=n;++i){
            scanf("%d%d%d",&car[i].d,&car[i].v,&car[i].a);
        }
        for(int i=1;i<=m;++i){
            scanf("%d",&p[i]);
        }
        sort(p+1,p+1+m);
        for(int i=1;i<=n;++i){
            int j=lower_bound(p+1,p+1+m,car[i].d)-p;
            if(j>m) continue;
            if(car[i].a<0){
                if(car[i].v<=Vvv) continue;
                double k=(Vvv*Vvv-car[i].v*car[i].v)/2.0/car[i].a;
                int kk=floor(k);
                if(abs(k-kk)<1e-5) kk--;
                kk+=car[i].d;
                int l=upper_bound(p+1,p+1+m,kk)-p-1;
                //sum[j]++;
                //sum[l+1]--;
                if(l>=j){
                    ans1++;
                    h[++tot]={j,l};
                    //printf("%d ",i);
                }
            }
            else if(car[i].a==0){
                if(car[i].v<=Vvv) continue;
                //sum[j]++;
                //sum[m+1]--;
                ans1++;
                h[++tot]={j,m};
                //printf("%d ",i);
            }
            else{
                if(car[i].v>Vvv){
                    //sum[j]++;
                    //sum[m+1]--;
                    ans1++;
                    h[++tot]={j,m};
                    //printf("%d ",i);
                }
                else{
                    double k=(Vvv*Vvv-car[i].v*car[i].v)/2.0/car[i].a;
                    int kk=ceil(k);
                    if(abs(k-kk)<1e-5) kk++;
                    kk+=car[i].d;
                    int l=lower_bound(p+1,p+1+m,kk)-p;
                    //sum[l]++;
                    //sum[m+1]--;
                    if(l<=m){
                        ans1++;
                        h[++tot]={l,m};
                        //printf("%d ",i);
                    }
                }
            }
        }
        //for(int i=1;i<=m;++i) sum[i]+=sum[i-1];
        sort(h+1,h+1+tot);
        int r=h[1].second;
        for(int i=2;i<=tot;++i){
            if(h[i].first<=r){
                r=min(r,h[i].second);
            }
            else{
                //printf("%d ",r);
                ans2++;
                r=h[i].second;
            }
        }
        if(tot>=1){
            ans2++;
            //printf("%d ",r);
        }
        printf("%d %d\n",ans1,m-ans2);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}