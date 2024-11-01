#include <bits/stdc++.h>
using namespace std;
int f(int n){
    if(n<2)
    {
        return-1;
    }
    if(n==2) return 1;
    if(n==3) return 7;
    if(n==4) return 4;
    if(n==5) return 2;
    if(n==6) return 0;
    if(n==7) return 8;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t; cin>>t;
    for(int i=1;i<=t;i++)
    {
        int n; cin>>n;
        cout<<f(n);
    }
    return 0;
}
