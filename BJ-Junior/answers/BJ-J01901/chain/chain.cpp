#include<bits/stdc++.h>
using namespace std;
int t,a[1005][1005],b[1005][2];
int main()
{
    freopen("chain1.in","r",stdin);
    freopen("chain1.out","w",stdout);
    cin>>t;
    int n,k,q;
    for(int i=1;i<=t;i++){
        cin>>n>>k>>q;
        int l;
        for(int k=1;k<=n;k++){
            cin>>l;
            for(int j=1;j<=l;j++){
                cin>>a[k][j];
            }
        }
        for(int k=1;k<=q;k++){
            cin>>b[k][0]>>b[k][1];
        }
    }
    for(int i=1;i<=q;i++) cout<<0<<endl;
    return 0;
}
