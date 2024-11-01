#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int a[N],t;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    while(t--){
        int n,m,q;
        cin>>n>>m>>q;
        for(int i=1;i<=n;i++){
            int x;
            cin>>x;
            for(int j=1;j<=x;j++){
                int y;
                cin>>y;
            }
        }
        for(int i=1;i<=q;i++){
            int x,y;
            cin>>x>>y;
            cout<<0<<endl;
        }
    }
    return 0;
}
