#include<bits/stdc++.h>
using namespace std;
int t,n,m,l,v,p[100010],vis[100010];
int d[100010],v1[100010],a[100010];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    while(t--){
        memset(vis,0,sizeof(vis));
        cin>>n>>m>>l>>v;
        for(int i=1;i<=n;i++){
            cin>>d[i]>>v1[i]>>a[i];
        }
        for(int i=1;i<=m;i++){
            cin>>p[i];
        }
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(a[i]==0){
                int x=lower_bound(p+1,p+m+1,d[i])-p;
                if(x!=m+1){
                    if(v1[i]>v){
                        vis[x]=1;
                        cnt++;
                    }
                }
            }
            if(a[i]<0){
                int x=lower_bound(p+1,p+m+1,d[i])-p;
                if(x!=m+1){
                    if(v1[i]*v1[i]+2*a[i]*(p[x]-d[i])>v*v){
                        vis[x]=1;
                        cnt++;
                    }
                }
            }
            if(a[i]>0){
                if(p[m]>=d[i]){
                    if(v1[i]*v1[i]+2*a[i]*(p[m]-d[i])>v*v){
                        vis[m]=1;
                        cnt++;
                    }
                }
            }
        }
        int sum=0;
        for(int i=1;i<=m;i++){
            if(vis[i]==0){
                sum++;
            }
        }
        cout<<cnt<<" "<<sum<<endl;
    }
    return 0;
}
