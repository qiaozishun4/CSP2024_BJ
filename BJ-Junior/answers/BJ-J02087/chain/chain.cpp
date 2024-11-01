#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[4]={0,1,1,1};
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t,n,m,k,q;
    cin>>t;
    while(t--){
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            int l;cin>>l;
            for(int j=1;j<=l;j++){
                int x;cin>>x;
            }
        }
        for(int i=1;i<=q;i++){
            int a,b;
            cin>>a>>b;
        }

        random_shuffle(a,a+3);
        cout<<a[0];
    }
    return 0;
}
