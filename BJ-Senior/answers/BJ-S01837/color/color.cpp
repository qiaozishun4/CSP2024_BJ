#include <bits/stdc++.h>
using namespace std;
const int N=2e5;
int t,n[15],a[15][N],ans;
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","r",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n[i];
        for(int j=1;j<=n[i];j++){
            cin>>a[n[i]][j];
        }
    }
    for(int i=1;i<=t;i++){
        for(int j=1;j<=n[i];j++){
                bool have=false;
            for(int k=j-1;k>0;k++){
                if(a[n[i][j]==a[n[i][k]){
                    have=true;
                    break;
                }
            }
        }
    }
    return 0;
}