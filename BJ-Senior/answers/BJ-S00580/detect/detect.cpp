#include<bits/stdc++.h>
using namespace std;
const int N=1e5+2;
int a[N];
int d[N];
int v[N];
int p[N];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n,m,L,V;
        cin>>n>>m>>L>>V;
        cin>>n;
        int fl=0;
        int ans1=n;
        for(int i=1;i<=n;i++){
            cin>>d[i]>>v[i]>>a[i];
            if(a[i]>0){
                fl=2;
            }
            else if(a[i]==0){
                fl=1;
            }
        }
        for(int i=1;i<=m;i++){
            cin>>p[i];
        }
        for(int i=1;i<=n;i++){
            if(v[i]<=V||d[i]>p[m]){
                ans1--;
            }
        }
        if(fl==0){
            return 0;
            // int sv=V*V;
            // for(int i=1;i<=n;i++){
            //     sv
            // }
            // cout<<ans1<<" "<<m-1;
        }
        else if(fl==1){
            cout<<ans1<<" "<<m-1;
        }
        else{
            return 0;
        }
    }
    return 0;
}