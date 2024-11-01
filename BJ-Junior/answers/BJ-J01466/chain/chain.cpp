#include<bits/stdc++.h>
using namespace std;
int a[1010][2011];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n,kkk,q;
        cin>>n>>kkk>>q;
        for(int i=1;i<=n;i++){
            cin>>a[i][0];
            for(int j=1;j<=a[i][0];j++) cin>>a[i][j];
        }
        while(q--){
            int x,y;
            cin>>x>>y;
            int flag=0;
            for(int i=1;i<=n&&flag==0;i++){
                for(int j=1;j<=a[i][0]&&flag==0;j++){
                    if(a[i][j]==1){
                        for(int k=j+1;k<=a[i][0]&&k-j+1<kkk;k++){
                            if(a[i][k]==y){
                                flag++;
                                cout<<1<<endl;
                                break;
                            }
                        }
                    }
                }
            }
            if(flag==0) cout<<0<<endl;
        }

    }
}
