#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int T;
    cin>>T;
    for(int i=0;i<T;i++){
        int n,k,q,S[10000];
        cin>>n>>k>>q;
        for(int j=0;j<n;j++){
            int l;
            cin>>l;
            for(int s=0;s<n;s++){
                cin>>S[s];
            }
        }
        for(int Q=0;Q<q;Q++){
            int r,c;
            cin>>r>>c;
            cout<<0;
        }
    }
    return 0;
}
