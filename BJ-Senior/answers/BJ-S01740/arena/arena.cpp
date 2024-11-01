#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    srand(time(0));
    cin>>t;
    for(int i=1;i<=t;i++){
        cout<<abs(rand())<<endl;
    }
    return 0;
}
