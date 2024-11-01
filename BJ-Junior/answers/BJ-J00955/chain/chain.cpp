#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    cin>>t;
    for(int i=0;i<n;i++){
        int n,k,q;
        cin>>n>>k>>q;
        for(int j=0;j<q;j++){
            if(k==q){
                cout<<0<<endl;
            }else{
                cout<<1<<endl;
            }
        }
    }
    return 0;
}
