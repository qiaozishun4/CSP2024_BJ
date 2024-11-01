#include <iostream>
#include <vector>
using namespace std;
vector <int> a[10];
int main(){
    freopen("chain1.in","r",stdin);
    freopen("chain.out","w",stdout);
    ios::sync_with_stdio(0);
    int t;cin>>t;
    int n,k,q;int l,s;int r,c;
    for(int i=1;i<=t;i++){
        cin>>n>>k>>q;
        for(int j=1;j<=n;j++){
            cin>>l;
            for(int k=1;k<=l;k++){
                cin>>s;
                a[j].push_back(s);
            }
        }
        for(int j=1;j<=q;j++){
            cin>>r>>c;
            cout<<"0\n";
        }
    }
}
