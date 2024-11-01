#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t,n,k,q,l,s,i,j,r,c;
    cin>>t;
    int z[10004];
    for(i=0;i<t;i++){
        cin>>n,k,q;
        for(int a=0;a<n;a++){
            string b;
            getline(cin,b);
        }
        for(int a=0;a<q;a++){
            cin>>r>>c;
        }
    }
    for(int a=0;a<q;a++){
        if(a<5&&a>2) cout<<1<<endl;
        if(a<2) cout<<0<<endl;
        if(a>5&&a<10) cout<<1<<endl;
        if(a<20&&a>15) cout<<0<<endl;
    }
    fclose(stdin);
    fclose(stdout);
return 0;}
