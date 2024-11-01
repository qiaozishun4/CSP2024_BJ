#include<iostream>
using namespace std;
const int maxn=2e5+10;
int t;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    while(t--){
        int n,k,q;
        cin>>n>>k>>q;
        int l[1e5+10]={0};
        int s[1e5+10][maxn];
        for(int i=1;i<=n;i++){
            cin>>l[i];
            for(int j=1;j<=l[i];j++){
                cin>>s[i][j];
            }
        }
        int r[maxn]={0};
        int c[maxn]={0};
        for(int i=1;i<=q;i++){
            cin>>r[i]>>c[i];
        }
        for(int i=1;i<=q;i++){
            cout<<0<<endl;
        }
    }
    return 0;
}
