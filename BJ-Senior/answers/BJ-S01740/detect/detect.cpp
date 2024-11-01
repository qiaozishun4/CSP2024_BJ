#include<bits/stdc++.h>
using namespace std;
const int N=2e6;
struct car{
    double d,v,a;
}c[N];
int t,n,M,l;
double V,m[N],nowm[N];
bool f[N];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    srand(time(0));
    cin>>t;
    for(int ii=1;ii<=t;ii++){
        cin>>n>>M>>l>>V;
        for(int i=1;i<=n;i++){
            cin>>c[i].d>>c[i].v>>c[i].a;
        }
        for(int i=1;i<=M;i++){
            cin>>m[i];
        }
        for(int i=1;i<=n;i++){
            f[i]=0;
        }
        int cnt=0,maxr=0;
        for(int i=1;i<=n;i++){
            for(int j=M;j>=1;j--){
                if(c[i].d<=m[j]){
                    if(sqrt(c[i].v*c[i].v+2*c[i].a*(m[j]-c[i].d))>V){
                        cnt++;
                        break;
                    }
                }
                else{
                    break;
                }
            }
        }
        cout<<cnt<<' ';
        for(int i=1;i<=N;i++){
            int rem=0,ans=0;
            for(int j=1;j<=M;j++){
                int r=rand()%2;
                if(r==1){
                    rem++;
                    nowm[j]=-1;
                }
                else{
                    nowm[j]=m[j];
                }

            }
            for(int i=1;i<=n;i++){
                for(int j=M;j>=1;j--){
                    if(c[i].d<=nowm[j]){
                        if(sqrt(c[i].v*c[i].v+2*c[i].a*(nowm[j]-c[i].d))>V){
                            ans++;
                            break;
                        }
                    }
                    else{
                        break;
                    }
                }
            }
            if(ans==cnt)maxr=max(maxr,rem);
        }
        cout<<maxr<<endl;
    }
    return 0;
}
