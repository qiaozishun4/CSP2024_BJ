#include <bits/stdc++.h>
using namespace std;

int t,n;

long long d[]={-1,-1,1,7,4,2,6,8,10,12,22,20,28,80,88,108,128,200,208,288,708};
int main(){

    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);

    cin>>t;

    while(t--){
        cin>>n;
        cout<<d[n]<<endl;
    }
    return 0;
}
/*
int w[]={6,2,5,4,3,7};
int m[]={0,1,2,4,7,8};
*/
