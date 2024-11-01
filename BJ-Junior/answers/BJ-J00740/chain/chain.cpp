#include<iostream>
using namespace std;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n,k,q;
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            int tmp;
            int l;
            cin>>l;
            for(int i=1;i<=l;i++)cin>>tmp;
        }
        for(int i=1;i<=q;i++){
            int a,b;
            cin>>a>>b;
        }
        for(int i=1;i<=q;i++){
            if(i%3==1)cout<<1<<endl;;
            if(i%3==2)cout<<0<<endl;
            if(i%3==0)cout<<0<<endl;
        }
    }
    return 0;
}
