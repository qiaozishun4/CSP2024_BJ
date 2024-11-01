#include<bits/stdc++.h>
using namespace std;
int d[100001];
int u[100001];
int g[100001];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n,m,l,v;
        cin>>n>>m>>l>>v;
        for(int i=1;i<=n;i++){
            int t;
            cin>>d[i]>>u[i]>>t;
        }
        for(int i=1;i<=m;i++){
            cin>>g[i];
        }
        int sum=0;
        for(int i=1;i<=n;i++){
            bool f=false;
            for(int j=1;j<=m;j++){
                if(g[j]>d[i]&&u[i]>v&&!f){
                    sum++;
                    f=true;
                }
            }
        }
        cout<<sum<<" "<<m-1;
    }
    return 0;
}