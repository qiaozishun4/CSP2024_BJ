#include<bits/stdc++.h>
using namespace std;
int n,k,q;
int t;
int a[1005][1005];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>k>>q;
        for(int j=1;j<=n;j++){
            int x;
            cin>>x;
            for(int y=1;y<=x;y++){
                cin>>a[j][y];
            }
        }
        for(int j=1;j<=q;j++){
            int r,c;
            cin>>r>>c;
            bool f=true;
            for(int x=1;x<=n;x++){
                if(f==false){
                    break;
                }
                for(int y=r;y<=c;y++){
                    if(a[x][y]==y){
                        cout<<1<<endl;
                        f=false;
                        break;
                    }
                }
            }
            if(f==true){
                cout<<0<<endl;
            }
        }
    }
    return 0;
}