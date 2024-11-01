#include<bits/stdc++.h>
using namespace std;
const int N=72;
int main(){
    freopen("detect2.in","r",stdin);
    freopen("detect2.out","w",stdout);
    bool flag;
    int t;
    int n,m,l,V;
    double d[N]={},v[N]={},a[N]={};
    double p[N]={};
    cin>>t;
    int cnt=0;
    double s;
    int h[N][N]={},k=1,maxn=-1,sum,maxj,H[N]={};
    for(int g=1;g<=t;g++){
        cin>>n>>m>>l>>V;
        for(int i=1;i<=n;i++)cin>>d[i]>>v[i]>>a[i];
        for(int i=1;i<=m;i++)cin>>p[i];
        for(int i=1;i<=n;i++){
            if(a[i]==0){
                if(d[i]<=p[m]&&v[i]>V){cnt++;H[k++]=i;}
            }else{
                for(int j=1;j<=m;j++){
                    s=p[j]-d[i];
                    if(s>=0){
                        s=sqrt(v[i]*v[i]+2*a[i]*s);
                        if(s>V){cnt++;H[k++]=i;break;}
                    }
                }
            }
        }
        cout<<cnt<<' ';
        cnt=0;
        flag=1;
        maxn=-100;
        for(int j=1;j<=m;j++){
            for(int i=1;i<=n;i++){
                s=p[j]-d[i];
                if(s>=0){
                    s=sqrt(v[i]*v[i]+2*a[i]*s);
                    if(s>V){h[i][j]=1;sum++;}
                }
            }
        }
        while(flag){
            flag=0;
            for(int j=1;j<=m;j++){
                sum=0;
                for(int i=1;i<=n;i++){
                    if(h[i][j])sum++;
                }
                if(maxn<sum){
                    maxn=sum;
                    maxj=j;
                }
            }
            for(int j=1;j<=n;j++){
                if(h[j][maxj]==1){
                    for(int o=1;o<=m;o++)h[j][o]=0;
                }
            }
            cnt++;
            for(int j=1;j<=n;j++)for(int o=1;o<=m;o++)if(h[j][o]==1)flag=0;
        }
        cout<<m-cnt<<endl;
    }
    return 0;
}
