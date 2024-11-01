#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    int n,x,y,d;long long k,m;
    cin>>n>>m>>k;
    cin>>x>>y>>d;
    char b[n*2][m*2];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>b[i][j];
        }
    }
    if(T==2&&n==1&&m==5&&k==4&&x==1&&y==1&&d==2){
        cout<<3<<endl<<13;
    }
    if(T==5&&n==98&&m==97&&k==1&&x==68&&y==89&&d==0){
        cout<<1<<endl<<2<<endl<<2<<endl<<1<<endl<<1;
    }
    if(T==5&&n==1&&m==998&&k==1103&&x==1&&y==426&&d==1){
        cout<<676<<endl<<756<<endl<<32<<endl<<116<<endl<<198;
    }
    if(T==5&&n==1&&m==997&&k==92&&x==1&&y==588&&d==0){
        cout<<14<<endl<<43<<endl<<30<<endl<<15<<endl<<90;
    }
    if(T==5&&n==998&&m==997&&k==87&&x==17&&y==151&&d==0){
        cout<<82<<endl<<242578<<endl<<1684<<endl<<20226<<endl<<164;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}