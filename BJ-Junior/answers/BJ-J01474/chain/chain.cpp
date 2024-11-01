#include <bits/stdc++.h>
using namespace std;
int t,n,num[10]={6,2,5,5,4,5,6,3,7,6};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        n/=7;
        string a;
        for(int i=1;i<=n;i++) a+='9';
        cout<<a<<endl;
    }
    return 0;
}