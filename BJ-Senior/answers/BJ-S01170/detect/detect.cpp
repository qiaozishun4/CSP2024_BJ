#include <bits/stdc++.h>
using namespace std;

#define N 1000005

double T;
double n,m,L,V,ans1,ans2,b[N];
int cnt=1;
double d[N],v[N],x;
double a[N];
double p[N],pp[N];
int main(){
    //freopen("detect.in","r",stdin);
    //freopen("detect.out","w",stdout);
    cin >> T;
    while(T--){
        cnt=0;
        ans1=0,ans2=0;
        cin >> n >> m >> L >> V;
        for(int i=1;i<=n;i++){
            cin >> d[i] >> v[i] >> a[i];
        }
        for(int i=1;i<=m;i++){
            cin >> p[i];
        }
        for(int i=1;i<=m;i++) pp[i]=0;
        for(int i=1;i<=n;i++){
            if(a[i]==0){
                if(v[i]>V){
                    for(int j=1;j<=m;j++){
                        if(p[j]>=d[i]){
                            ans1++;
                            bool flag=0;
                            for(int y=1;y<cnt;y++){
                                if(pp[y]==p[j]){
                                    flag=1;
                                    break;
                                }
                            }
                            if(!flag) pp[cnt++]=p[j];
                            break;
                        }
                    }
                }

            }else if(a[i]<0){
                double x=(3*3-pow(v[i],2))/(2*a[i]);
                for(int j=1;j<=m;j++){
                    if(p[j]>=d[i]&&p[j]<=d[i]+x){
                        ans1++;
                        bool flag=0;
                        for(int y=1;y<cnt;y++){
                            if(pp[y]==p[j]){
                                flag=1;
                                break;
                            }
                        }
                        if(!flag) pp[cnt++]=p[j];
                        break;
                    }
                }
            }else{
                double x=(3*3-pow(v[i],2))/(2*a[i]);
                if(v[i]+x<=L){
                    for(int j=1;j<=m;j++){
                        if(p[j]>=d[i]+x){
                            ans1++;
                            bool flag=0;
                            for(int y=1;y<cnt;y++){
                                if(pp[y]==p[j]){
                                    flag=1;
                                    break;
                                }
                            }
                            if(!flag) pp[cnt++]=p[j];
                            break;
                        }
                    }
                }
            }
        }
        cout << ans1 << " " << cnt << endl;
    }
    return 0;
}
