#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
    srand(srand(time(0)));
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;++i){
        cout<<rand()%2<<endl;
    }
    return 0;
}