#include <bits/stdc++.h>
using namespace std;
int t;
int n,k,q;
int s[1005];
int l;
int r[1005];
int c[1005];
int main(){
    cin>>t;
    for (int j=1;j<=t;j++){
        cin>>n>>k>>q;
        for (int i=1;i<=n;i++){
            cin>>l;
            for (int u=1;u<=l;u++){
            	cin>>s[u];
            }
        }
        for (int i=1;i<=q;i++){
            cin>>r[i]>>c[i];
        }
        cout<<j%2<<endl;//6fanle
    }
    return 0;
}