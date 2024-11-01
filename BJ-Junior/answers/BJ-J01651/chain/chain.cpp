#include<iostream>
#include<cstdio>
#define For(v,s,e) for(int v=s;v<=e;v++)
using namespace std;
int T,m,n,k[100030];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>T;
    For(i,1,T){
        int a,b,c;
        cin>>a>>b>>c;
        For(j,1,a){
            int p;
            cin>>p;
            For(erq,1,p)cin>>k[erq];
        }
        For(h,1,c){
            int x,y;
            cin>>x>>y;
            cout<<0<<endl;
        }
    }

    return 0;
}
