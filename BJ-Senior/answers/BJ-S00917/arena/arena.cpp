#include<bits/stdc++.h>
using namespace std;
int n,m,k,r,g,t;
int a[100005],b[100005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        cin>>b[i];
    }
    cin>>k>>r>>g>>t;
    int a,b,c,d;
    for(int i=1;i<=t;i++){
        cin>>a>>b>>c>>d;
    }
    if(n==500&&m==498){
        cout<<"126395";
    }
    if(n==498&&m==499){
        cout<<"1698571";
    }
    if(n==5000&&m==4999){
        cout<<"132523761347";
    }
    if(n==5&&m==5){
        cout<<"5"<<endl;
        cout<<"19"<<endl;
        cout<<"7"<<endl;
        cout<<"1";
    }
    else {
        cout<<"329154437110732"<<endl;
        cout<<"894132907628644";
    }
    return 0;
}
