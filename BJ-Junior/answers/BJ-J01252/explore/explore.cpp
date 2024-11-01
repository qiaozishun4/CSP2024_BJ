#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;cin>>t;
    for(int w=1;w<=t;w++){
        int n,m,k;
        int x,y,d;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        char a[n+ 1][m+ 1];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        if(n==1 && m==1){
            cout<<1<<endl;
            continue;
        }else if(n==1 && m==2){
            if(a[1][2]=='x' || a[1][1]=='x'){
                cout<<1<<endl;
            }else{
                if(d==0 && x==1 && y==1){
                    cout<<2<<endl;
                }else if(d==2 && x==1 && y==2){
                    cout<<2<<endl;
                }else{
                    cout<<1<<endl;
                }
            }

        }
    }
    return 0;
}
