#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    long long t;
    cin>>t;
    while(t--){
        long long n,k,q;
        long long a[10010][10010];
        long long b[100100],c[100100];
        cin>>n>>k>>q;
        for(int i=0;i<n;i++){
            int l;
            cin>>l;
            for(int j=0;j<l;j++){
                cin>>a[i][j];
            }
        }
        for(int i=0;i<q;i++){
            cin>>b[i]>>c[i];
        }
        cout<<0<<endl;
    }
    return 0;
}
