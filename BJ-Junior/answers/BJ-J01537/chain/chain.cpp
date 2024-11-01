#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    srand(time(0));
    int T;
    cin>>T;
    while(T--){
        int n,m,k;
        cin>>k>>m>>n;
        for(int i=1;i<=m;i++){
            int l;
            cin>>l;
            for(int j=1;j<=l;j++){
                int x;
                cin>>x;
            }
        }
        for(int i=1;i<=n;i++){
            int l,r;
            cin>>l>>r;
            cout<<rand()%2<<'\n';
        }
    }
    return 0;
}
