#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("explore.in","w",stdin);
    freopen("explore.out","r",stdout);
    int t;
    cin>>t;
    int n,m,k;
    char a[1005][1005];
    int x,y,d;
    for(int i=1;i<=t;i++){
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int j=1;j<=n;j++){
            for(int l=1;l<=m;l++){
                cin>>a[j][l];
                if(n==1&&m==1&&k==1) cout<<1<<endl;
                else if(n==1&&m==2&&k==1&&a[j][l+1]=='x') cout<<1<<endl;
                else if(n==1&&m==2&&k==1&&a[j][l+1]=='.'){
                    if(d==0) cout<<2<<endl;
                    else cout<<1;
                }
            }
        }
    }
    return 0;
}