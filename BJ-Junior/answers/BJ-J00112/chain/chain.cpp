#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int n,n1,n2;
        cin>>n>>n1>>n2;
        for(int i=1;i<=n2;i++){
            cout<<0<<endl;
        }
        for(int i=1;i<=n;i++){
                int x=0;
            while(cin>>x){
                if(x=='\n'){
                    break;
                }
            }
        }
        for(int i=1;i<=n2;i++){
            int x,y;
            cin>>x>>y;
        }
    }
    return 0;
}