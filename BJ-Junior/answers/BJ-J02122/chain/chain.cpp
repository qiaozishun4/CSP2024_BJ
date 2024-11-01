#include<bits/stdc++.h>
using namespace std;
int t,n,k,q;
vector<int> s[100005];
int fnd(int z){
    for(int i=1;i<=s[1].size();i++){
        if(s[1][i]==z)return i;
    }
    return -1;
}
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    while(t--){
        cin>>n>>k>>q;
        int r,c,l;
        for(int i=1;i<=n;i++){
            cin>>l;
            for(int j=1;j<=l;j++){
                cin>>s[i][j];
            }
        }
        while(q--){
            cin>>r>>c;
            for(int i=1;i<=n;i++){
                if(fnd(c)-fnd(1)>=k||fnd(c)-fnd(1)<=0)cout<<0<<endl;
                else cout<<1<<endl;
            }
        }
    }
    return 0;
}
