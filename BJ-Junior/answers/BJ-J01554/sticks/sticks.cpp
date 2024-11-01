#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--){
        int x;
        cin>>x;
        for(int i=1;i<=x/7;i++) cout<<8;
        cout<<endl;
    }
    return 0;
}
