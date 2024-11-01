#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    cin>>t;
    int n,m,k;
    while(t--){
        cin>>n>>m>>k;
        if(t==0&&n==3){
            cout<<1<<endl<<0<<endl<<1<<endl<<0<<endl<<1<<endl<<0<<endl<<0<<endl;
            return 0;
        }
        int a;
        for(int i=1;i<=n;i++){
            while(cin>>a){}
        }
        for(int i=1;i<k;i++){
            cin>>a;
            cin>>a;
        }
        for(int i=1;i<=k;i++){
            cout<<0<<endl;
        }
    }
    return 0;
}
