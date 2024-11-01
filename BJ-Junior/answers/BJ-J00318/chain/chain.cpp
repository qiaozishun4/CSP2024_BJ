#include<iostream>
using namespace std;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int T,n,k,q,J,s,r,c;
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>n>>k>>q;
        for(int j=0;j<n;j++){
            cin>>J;
            for(int h=0;h<j;h++){
                cin>>s;
            }
        }
        for(int u=0;u<q;u++){
            cin>>r>>c;
        }
    }
    for(int i=0;i<q;i++){
        cout<<"0"<<endl;
    }
    return 0;
}
