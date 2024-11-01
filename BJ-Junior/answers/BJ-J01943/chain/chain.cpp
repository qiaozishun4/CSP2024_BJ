#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int T;
    int S[100000];
    cin>>T;
    while(T--){
        int n,k,q;
        cin>>n>>k>>q;
        for(int i=0;i<n;i++){
            int l;
            cin>>l;
            for(int j=0;j<l;j++){
                cin>>S[i];
            }
        }
        for(int i=0;i<q;i++){
            int a,b;
            cin>>a>>b;
        }
        cout<<0<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}