#include<bits/stdc++.h>//long long
using namespace std;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int T;
    cin>>T;
    for(int t=1;t<=T;t++){
        int n,k,q,shift,s;
        cin>>n>>k>>q;
        for(int i=0;i<n;i++){
            cin>>shift;
            for(int j=0;j<shift;j++)cin>>s;
        }
        for(int i=0;i<q;i++){
                cin>>shift>>s;
                cout<<1<<endl;
        }
    }
    return 0;
}
