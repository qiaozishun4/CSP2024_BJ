#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int n, a[100010], ans = 0;
int one, two;

int main(){

    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];
    sort(a+1, a+1+n);
    //for(int i=1; i<=n; i++) cout<<a[i]<<' ';
    //cout<<endl;
    int lcur = 1, rcur = 1;
    while(lcur <=n && rcur<=n){
        while(a[rcur] <= a[lcur] && rcur<=n) rcur++;
        //cout<<lcur<<' '<<rcur<<endl;
        if(rcur > n) break;
        ans++, lcur++, rcur++;
    }
    cout<<n - ans<<endl;

    return 0;
}
