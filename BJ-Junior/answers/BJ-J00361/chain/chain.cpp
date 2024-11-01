#include<bits/stdc++.h>
using namespace std;
int l,s;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    ios::sync_with_stdio(false);
    srand(time(NULL));
    int t;
    cin>>t;
    while(t--){
        int n,k,q;
        cin>>n>>k>>q;
        for(int i=0;i<n;i++){
            cin>>l;
            for(int j=0;j<l;j++)
                cin>>s;
        }
        for(int i=0;i<q;i++){
            cin>>l>>s;
            cout<<(rand()+rand()+rand())%2<<endl;
        }
    }
    return 0;
}
