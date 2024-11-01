#include <bits/stdc++.h>
using namespace std;
double t,n,m,L,V;
double d[100005],v[100005],a[100005],p[100005];
int check[100005];
int over[100005];
bool dp[10005][10005];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    while(t--){
        int ans=0,cnt=0;
        memset(over,0,sizeof over);
        memset(check,0,sizeof check);
        memset(dp,0,sizeof dp);
        cin>>n>>m>>L>>V;
        for(int i=1;i<=n;i++){
            cin>>d[i]>>v[i]>>a[i];
        }
        for(int i=1;i<=m;i++){
            cin>>p[i];
        }
        for(int i=1;i<=n;i++){
            double l,r;
            if(v[i]>V&&a[i]<0){
                l=d[i];
                r=d[i]+(v[i]*v[i]-V*V)/(2*abs(a[i]));
                for(int j=1;j<=m;j++){
                    if(p[j]>=l&&p[j]<r){
                        check[j]++;
                        if(!over[i])
                            ans++;
                        over[i]++;
                        dp[i][j]=true;
                    }
                }
            }
            if(v[i]>V&&a[i]>=0){
                l=d[i];
                r=L;
                for(int j=1;j<=m;j++){
                    if(p[j]>=l&&p[j]<=r){
                        check[j]++;
                        if(!over[i])
                            ans++;
                        over[i]++;
                        dp[i][j]=true;
                    }
                }

            }
            if(v[i]<=V&&a[i]>0){
                l=d[i]+(V*V-v[i]*v[i])/(2*abs(a[i]));
                r=L;
                for(int j=1;j<=m;j++){
                    if(p[j]>l&&p[j]<=r){
                        check[j]++;
                        if(!over[i])
                            ans++;
                        over[i]++;
                        dp[i][j]=true;
                    }
                }

            }
        }
        cout<<ans<<" ";
        for(int i=1;i<=m;i++){
            if(check[i]==0)
                cnt++;
            if(check[i]==1){
             for(int j=1;j<=n;j++){
                if(dp[j][i]==true){
                    for(int k=1;k<=m;k++){
                        if(dp[j][k]==true){
                            break;
                            cnt++;
                        }
                    }
                }
            }
            }

        }
        cout<<cnt<<endl;
    }
    return 0;
}

