#include<iostream>
#define ll long long
using namespace std;
ll t,n,m[1000000],p,q,o,x;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>n>>n>>p>>t;
    for(int i=1;i<=p;i++){
    cin>>m[i];
    if(m[i]=='.'){
        o++;
    }else{
    x++;
    }
    }
    if(t==1){
       cout<<t;
    }
    else if(n==1){
            for(int i=1;i<=n;i++){
                if(m[i]!='x'&&t!=0){
                    q++;
    t--;
                }
            }
                cout<<q;
    }else{
    if(o<t){
        cout<<o;
    }
    }

       return 0;
    }


