#include<bits/stdc++.h>

using namespace std;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
   int t;
   int n,k,q;
   int l[100010];
   int s[100010][100010];
   cin>>t;
   cin>>n>>k>>q;
   for(int i=0;i<n;i++){
    cin>>l[i];
    for(int j=0;j<l[i];j++){
        cin>>s[i][j];
    }
   }
   for(int i=0;i<q;i++){
    int r,c;
    cin>>r>>c;
    cout<<(c-1)%2<<endl;
   }
    return 0;
}
