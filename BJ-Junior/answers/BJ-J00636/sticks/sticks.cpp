#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int q;
    cin>>q;
    while(q--){
        int n;
        cin>>n;
        for(int i=0;i<n/7;i++) cout<<8;
        cout<<endl;
    }
    return 0;
}