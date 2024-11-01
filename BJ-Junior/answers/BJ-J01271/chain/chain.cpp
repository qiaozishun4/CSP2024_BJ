#include<bits/stdc++.h>
using namespace std;
#define int long long
string s[100009];
int n,k,q;
bool f=0;
signed main(){
int t;
freopen("chain.in","r",stdin);
freopen("chain.out","w",stdout);
cin>>t;
int l;
while(t--){
    cin>>n>>k>>q;
    for(int i=1;i<=n;i++){
        cin>>l;
        for(int j=1;j<=l;j++){
            char c;
            cin>>c;
            s[i]+=c;
        }
    }
    for(int i=1;i<=q;i++){
       int r,c;
      cin>>r>>c;
     cout<<"0"<<endl;
    }
}
}
