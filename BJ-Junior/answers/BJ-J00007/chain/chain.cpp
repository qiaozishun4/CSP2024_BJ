#include<bits/stdc++.h>
using namespace std;
int a[220][220];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n,kk,q;
        bool x=0;
        cin>>n>>kk>>q;
        for(int i=1;i<=n;i++){
            int y;
            cin>>y;
            for(int j=1;j<=y;j++){
                cin>>a[i][j];
                if(a[i][j]==1) x=1;
            }
        }
        if(!x){
            cout<<0;
            continue;
        }
        while(q--){
            int r,c;
            bool fou=0;
            cin>>r>>c;
            if(r==1){
                for(int i=1;i<=n;i++){
                    for(int j=1;a[i][j];j++){
                        if(a[i][j]!=1) continue;
                        for(int k=j+1;k<kk+j;k++){
                            if(a[i][k]==c){
                                if(!fou){
                                    cout<<1<<'\n';
                                fou=1;
                                break;
                                }
                            }
                        }
                    }
                }
            }else if(r==2){
                for(int i=1;i<=n;i++){
                    for(int j=1;a[i][j];j++){
                        if(a[i][j]!=1) continue;
                        for(int k=j+1;k<=kk+j;k++){
                            for(int ii=1;ii<=n;ii++){
                                if(ii==i) continue;
                                for(int jj=1;a[ii][jj];jj++){
                                    for(int kkk=j+1;kkk<=kk+j;kkk++){
                                        if(a[i][k]==a[ii][jj]&&a[ii][kkk]==c){
                                            if(!fou){
                                                cout<<1<<'\n';
                                                fou=1;
                                                break;
                                            }
                                        }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }else{
                    int n;
                    fou=n%2;
                    if(fou) cout<<1<<'\n';
                }
                if(!fou) cout<<0<<'\n';
            }
        }
         return 0;
    }
