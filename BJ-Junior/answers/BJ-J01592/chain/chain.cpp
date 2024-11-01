#include<iostream>
using namespace std;
int n,k,q,l[1005],s[1005][2005];
void doing(){
    cin>>n>>k>>q;
    for(int i=1;i<=n;i++){
        cin>>l[i];
        for(int j=1;j<=l[i];j++){
            cin>>s[i][j];
        }
    }
    while(q--){
        bool ans=0;
        int r,c;
        cin>>r>>c;

        cout<<ans<<'\n';
    }
    return ;
}
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        doing();
    }
    return 0;
}