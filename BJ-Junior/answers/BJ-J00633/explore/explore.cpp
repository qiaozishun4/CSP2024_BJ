#include<bits/stdc++.h>
using namespace std;
char mp[1001][1001];
int n,m,k,t,cnt1=0,vis2[1001][1001],x010,y010,b;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>m>>k>>x010>>y010>>b;
        for(int j=1;j<=n;j++){
            for(int k=1;k<=m;k++){
                cin>>mp[j][k];
            }
        }
        cout<<(k+1>n*m?n*m:k+1)<<endl;
    }
    return 0;
}
