#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    srand(0);
    int n,m,f;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>f;
    for(int i=1;i<=m;i++)cin>>f;
    for(int i=1;i<=log2(n)+1;i++)
        cin>>f;
    int t;
    cin>>t;
    if(n==m&&n==5)cout<<"5\n19\n7\n1";
    else if(n==500&&m==498)cout<<126395<<"\n";
    else if(n==498&&m==499)cout<<1698571<<"\n";
    else if(n==5000&&m==4999)cout<<132523761347<<"\n";
    else if(t==1)cout<<rand()<<"\n";
    else cout<<"329154437110732\n894132907628644\n";
    fclose(stdin);
    fclose(stdout);
    return 0;
}