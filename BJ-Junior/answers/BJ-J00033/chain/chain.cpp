#include<bits/stdc++.h>
using namespace std;
int t,n,k,s,m,o,p,a[1001][1001];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>k>>s;
        for(int i=1;i<=n;i++){
            cin>>m;
            for(int j=1;j<=m;j++) cin>>a[i][j];
        }
        for(int e=1;e<=s;e++){
                int is=0;
        cin>>o>>p;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(a[i][j]==p&&j<=k&&j>=2){
                    is=1;
                    break;
                }
            }
        }
        cout<<is<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}


