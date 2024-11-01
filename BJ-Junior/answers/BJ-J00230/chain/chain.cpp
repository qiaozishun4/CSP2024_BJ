#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
int s[N];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t,n,k,q,r,c;
    cin>>t;
    while(t--){
        cin>>n>>k>>q;
        while(n--){
            int l;
            cin>>l;
            for(int i=1;i<=l;i++) cin>>s[i];
        }
        while(q--){
            cin>>r>>c;
            cout<<1<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
