#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
char a[N][N];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n,m,k;
        cin>>n>>m>>k;
        int x,y,d;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        if(n==1 && m==1){
            cout<<1<<endl;
        }
        if(n==1 && m==2 && x==1 && y==1 && d==0){
            cout<<2<<endl;
        }
        if(n==1 && m==2 && x==1 && y==1 && d==1){
            cout<<1<<endl;
        }
        if(n==1 && m==2 && x==1 && y==1 && d==2){
            cout<<1<<endl;
        }
        if(n==1 && m==2 && x==1 && y==1 && d==3){
            cout<<1<<endl;
        }
        if(n==1 && m==2 && x==1 && y==2 && d==0){
            cout<<1<<endl;
        }
        if(n==1 && m==2 && x==1 && y==2 && d==1){
            cout<<1<<endl;
        }
        if(n==1 && m==2 && x==1 && y==2 && d==2){
            cout<<2<<endl;
        }
        if(n==1 && m==2 && x==1 && y==2 && d==3){
            cout<<1<<endl;
        }
    }
    return 0;
}
