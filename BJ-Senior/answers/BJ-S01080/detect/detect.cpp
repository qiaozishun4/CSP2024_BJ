#include<bits/stdc++.h>
using namespace std;
int t,n,m,l,vmax,d[100010],v[100010],a[100010],p[100010];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>m>>l>>vmax;
        for(int i=1;i<=n;i++){
            cin>>d[i]>>v[i]>>a[i];
        }
        for(int i=1;i<=m;i++){
            cin>>p[i];
        }
        if(n<=20){
            int f[25][25];
            memset(f,0,sizeof(f));
            for(int i=1;i<=n;i++){
                int j;
                for(j=1;j<=m;j++){
                    if(p[j]>=d[i]){
                        break;
                    }
                }
                if(j==m+1){
                    continue;
                }
                for(;j<=m;j++){
                    if(sqrt(1.0*v[i]*v[i]+2.0*a[i]*(p[j]-d[i]))>vmax){
                        f[i][j]=1;
                    }
                }
            }
            int cnt1=0;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    if(f[i][j]){
                        cnt1++;
                        break;
                    }
                }
            }
            int ans=0;
            for(int s=1;s<(1<<m);s++){
                bool b[25];
                memset(b,0,sizeof(b));
                for(int i=1;i<=n;i++){
                    for(int j=1;j<=m;j++){
                        if(((s>>(j-1))&1)&&f[i][j]){
                            b[i]=true;
                        }
                    }
                }
                bool flag1=true;
                for(int i=1;i<=n;i++){
                    bool flag2=true;
                    for(int j=1;j<=m;j++){
                        if(f[i][j]&&(!b[i])){
                            flag2=false;
                            break;
                        }
                    }
                    if(flag2==false){
                        flag1=false;
                        break;
                    }
                }
                if(!flag1){
                    continue;
                }
                int cnt2=0;
                for(int i=1;i<=m;i++){
                    if((s>>(i-1))&1){
                        cnt2++;
                    }
                }
                ans=max(ans,m-cnt2);
            }
            cout<<cnt1<<' '<<ans<<'\n';
        }else{
            int cnt=0;
            for(int i=1;i<=n;i++){
                if(v[i]>vmax&&d[i]<=p[m]){
                    cnt++;
                }
            }
            cout<<cnt<<' ';
            if(cnt==0){
                cout<<m;
            }else{
                cout<<m-1;
            }
            cout<<'\n';
        }
    }
    return 0;
}
