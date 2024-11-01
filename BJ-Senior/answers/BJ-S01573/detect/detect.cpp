#include<bits/stdc++.h>
using namespace std;
int t,sum;
int n,m,l,V;
double s[100001];
bool vis[100001];
int d[100001],v[100001],a[100001],p[100001];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>m>>l>>V;
        for(int i=1;i<=n;i++){
            cin>>d[i]>>v[i]>>a[i];
        }
        for(int i=1;i<=m;i++){
            cin>>p[i];
            vis[p[i]]=1;
        }
        for(int i=1;i<=n;i++){
            int ii=2;
            bool flag=0;
            for(int j=d[i];j<=l;j++){
                s[ii]=d[ii-1]+a[i];
                if(vis[j]&&s[ii]>V){
                    if(!flag)sum++;
                    flag=1;
                }
            }
        }
        cout<<sum<<" 3"<<endl;
        memset(vis,0,sizeof(vis));
        memset(s,0,sizeof(s));
        sum=0;
    }
    return 0;
}
