#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m,l,V,d[100001],v[100001],a[100001],p[100001];
        scanf("%d%d%d%d",&n,&m,&l,&V);
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&d[i],&v[i],&a[i]);
        }
        for(int i=1;i<=m;i++){
            scanf("%d",&p[i]);
        }
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(a[i]==0){
                if(v[i]>V) cnt++;
            }
            else if(a[i]<0){
                int temp;
                for(int j=1;j<=m;j++){
                    if(d[i]<=p[j]){
                        temp=j;
                        break;
                    }
                }
                int v1=(int)ceil(sqrt(2*a[i]*(p[temp]-d[i])+v[i]*v[i]));
                if(v1>V) cnt++;
            }
            else if(a[i]>0){
                int v2=(int)ceil(sqrt(2*a[i]*(p[m]-d[i])+v[i]*v[i]));
                if(v2>V) cnt++;
            }
        }
        for(int i=1;i<=m;i++){
            for(int j=i+1;j<=m;j++){
                if(a[i]>a[j]){
                    swap(a[i],a[j]);
                    swap(d[i],d[j]);
                    swap(v[i],v[j]);
                }
            }
        }
        int pcnt=0,pp[100001]={0};
        for(int i=1;i<=n;i++){
            if(a[i]>0){
                int s=ceil(double((V*V-v[i]*v[i]))/double((2*a[i]))+d[i]);
                for(int j=1;j<=m;j++){
                    if(p[j]>s){
                        if(pp[j]!=1) pcnt++;
                        pp[j]=1;
                        break;
                    }
                }
            }
            if(a[i]<0){
                int s=floor(double((V*V-v[i]*v[i]))/double((2*a[i]))+d[i]);
                int temp,tempcnt=0;
                bool flag=false;
                for(int j=1;j<=m;j++){
                    if(pp[j]==1){
                        if(p[j]<=s&&d[i]<=p[j]) flag=true;
                    }
                    else if(p[j]<=s){
                        if(pp[j]!=1) tempcnt=1;
                        temp=j;
                        break;
                    }
                }
                if(!flag){
                    if(tempcnt==1) pcnt++;
                    pp[temp]=1;
                }
            }
        }
        printf("%d %d\n",cnt,m-pcnt);
    }
    return 0;
}
//非常好题目，使我学会高中物理
