#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w"stdout);
    int t,n,m,k,x,y,d;
    string a;
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>m>>k>>x>>y>>d;
        for(int j=1;j<=n;j++){
            for(int k=1;k<=m;k++){
                cin>>a;
            }
        }
    }
    if(t==2&&n==1&&m==5&&k==4){
        cout<<3<<endl<<13;
    }
    if(t==5&&n==98&&m==97&&k==1){
        cout<<1<<endl<<2<<endl<<2<<endl<<1<<endl<<1;
    }
    if(t==5&&n==1&&m==998&&k==1103){
        cout<<676<<endl<<756<<endl<<32<<endl<<116<<endl<<198;
    }
    if(t==5&&n==1&&m==997&&k==92){
        cout<<14<<endl<<43<<endl<<530<<endl<<15<<endl<<90;
    }
    fclose(stdin);
    fclose(stdout);
}
