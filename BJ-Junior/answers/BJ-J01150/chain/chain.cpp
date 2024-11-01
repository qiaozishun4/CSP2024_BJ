#include<bits/stdc++.h>
using namespace std;
bool tong[100001];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n,m,q;
        cin>>n>>m>>q;
        for(int i=1;i<=n;i++){
            int f;
            cin>>f;
            for(int j=1;j<=f;j++){
                int s;
                cin>>s;
                tong[s]=true;
            }
        }
        for(int i=1;i<=q;i++){
            int r,c;
            cin>>r>>c;
            if(!tong[c]){
                cout<<"0\n";
            }
            else{
                cout<<"1\n";
            }
        }
    }
    return 0;
}
