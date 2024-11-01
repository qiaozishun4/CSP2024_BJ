#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        long long n;
        cin>>n;
        for(int i=1;i<=n/7;i++){
            cout<<8;
        }
        cout<<endl;
    }
    return 0;
}