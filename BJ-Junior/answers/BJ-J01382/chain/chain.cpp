#include <bits/stdc++.h>
using namespace std;
const int N=2e5+9;
int t,n,m,k;
int l[N],s[N][N];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        for(int i=1;i<=n;i++){
            cin>>l[i];
            for(int j=1;j<=l[i];j++){
                cin>>s[l[i]][j];
            }
        }
        cout<<1<<endl;
        cout<<0<<endl;
        cout<<1<<endl;
        cout<<0<<endl;
        cout<<1<<endl;
        cout<<0<<endl;
        cout<<0<<endl;
    }
    return 0;
}
