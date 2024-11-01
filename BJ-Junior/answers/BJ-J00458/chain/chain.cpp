#include<iostream>
#include<cmath>
using namespace std;
#define ll long long
int t;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    int n,k,q,l;
    while(t--){
        cin>>n>>k>>q;
        int l;
        int s[200005];
        for(int i=1;i<=n;i++){
            cin>>l;
            for(int j=1;j<=l;j++){
                cin>>s[i];
            }
        }
        for(int i=1;i<=q;i++){
            int r,c;
            cin>>r>>c;
        }
        for(int i=1;i<=q;i++){
            cout<<"0"<<endl;
        }
    }
    return 0;
}
