#include<bits/stdc++.h>
using namespace std;
int cars[100010][2];
bool cams[1000100];
int ttt;
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n,m,l,k;
        cin>>n>>m>>l>>k;
        int tppppp;
        for(int i=1;i<=n;i++) cin>>cars[i][0]>>cars[i][1]>>tppppp;
        for(int i=1;i<=m;i++){
            cin>>tppppp;
            cams[tppppp]=true;
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(cars[i][1]>k){
                for(int itemp=cars[i][0];itemp<=l;itemp++){
                    if(cams[itemp]){
                        ans++;
                        break;
                    }
                }
            }
        }
        cout<<ans<<" "<<((ans==0)?m:m-1)<<endl;

    }
    return 0;
}

