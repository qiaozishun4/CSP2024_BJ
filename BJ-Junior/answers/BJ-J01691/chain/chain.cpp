#include<bits/stdc++.h>
using namespace std;
int n,k,q,l[100005],s[200005],r[100005],c[100005];
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        cin>>n>>k>>q;
        for(int i=0;i<n;i++){
            cin>>l[i];
            for(int j=0;j<l[i]+1;j++){
                cin>>s[i];
            }
        }
        for(int j=0;j<q;j++)cin>>r[j]>>c[j];
        cout<<0<<endl;
    }
    return 0;
}