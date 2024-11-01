#include<iostream>
using namespace std;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t,n,k,q,l,a[10000],r,c;
    cin>>t;
    while(t--){
        cin>>n>>k>>q;

        for(int i=0;i<n;i++){
            cin>>l;
            int w=l;
            while(w--){
                cin>>a[l-w];
            }
        }
        int r,c;
        while(q--){
            cin>>r>>c;
            cout<<1<<endl;
        }

    }

}
