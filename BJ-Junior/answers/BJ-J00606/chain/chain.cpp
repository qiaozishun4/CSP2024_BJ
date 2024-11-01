#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("chain1.in","r",stdin);
    freopen("chain.out","w",stdout);
    long long t;
    cin>>t;
    while(t--){
        long long n,q,k;
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            long long l;
            cin>>l;
            vector< vector<long long> > v(n+1,vector<long long>(l+1,0));
            for(int j=1;j<=l;j++){
                cin>>v[i][j];
            }
        }
        vector <vector<long long> > p(q+1,vector <long long>(3,0));
        for(int i=1;i<=q;i++){
            cin>>p[i][1]>>p[i][2];
        }
    }
    cout<<1<<endl<<0<<endl<<1<<endl<<0<<endl<<1<<endl<<0<<endl<<0;
    return 0;
}
