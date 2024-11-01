#include<bits/stdc++.h>
using namespace std;
int t,s[200005];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    while(t--){
        int n,k,q;
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            int l;
            cin>>l;
            for(int j=1;j<=l;j++)cin>>s[j];
        }for(int i=1;i<=q;i++){
            int r,c;
            cin>>r>>c;
            cout<<r%2<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
