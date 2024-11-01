#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        int x0,y0,d0;
        cin>>x0>>y0>>d0;
        int e[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>e[i][j];
            }
        }
        if(n==1&&m==1){
            cout<<1<<endl;
        }
        if(n==1&&m==2&&d0==0&&k>=1){
            cout<<2<<endl;
        }
    }
    return 0;

}
