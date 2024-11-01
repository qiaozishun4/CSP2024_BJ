#include<bits/stdc++.h>
using namespace std;
int t;
int n,kk,q;
int r,c;
int w[3000][3000];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>kk>>q;
        for(int i=1;i<=n;i++){
            cin>>w[i][0];
            for(int j=1;j<=w[i][0];j++){
                cin>>w[i][j];
            }
        }
        while(q--){
            cin>>r>>c;
            if(r==1){
                int pd=0;
                for(int i=1;i<=n;i++){
                    for(int j=1;j<=w[i][0];j++){
                        for(int k=j;k<=w[i][0];k++){
                            if(pd==0&&w[i][j]==1&&w[i][k]==c&&k-j+1<=kk&&k-j+1>=2){
                                cout<<1<<endl;
                                pd=1;
                            }
                        }
                    }
                }
                if(pd==0) cout<<0<<endl;
            }else{
                int pd=0;
                for(int i=1;i<=n;i++){
                    for(int j=1;j<=w[i][0];j++){
                        if(pd==0&&w[i][j]==kk){
                            cout<<1<<endl;
                            pd=1;
                        }
                    }
                }
                if(pd==0) cout<<0<<endl;
            }
        }
    }
    return 0;
}
