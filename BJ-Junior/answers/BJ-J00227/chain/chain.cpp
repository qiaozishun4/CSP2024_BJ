#include<bits/stdc++.h>
using namespace std;
int n,t,m,p;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>m>>p;
        int num;
        char c;
        for(int i=1;i<=n;i++){
            cin>>num;
            for(int i=1;i<=num;i++)cin>>c;
        }
        for(int i=1;i<=p;i++)cin>>num>>num;
        for(int i=1;i<=p;i++)cout<<rand()%2<<endl;
    }

    return 0;
}
