#include<bits/stdc++.h>
using namespace std;
const int a[10]={6,2,5,5,4,5,6,3,7,6};
int b[100]={-1,-1,1,7,4,2,6,8,10,18,22,20,28,68,88,108,188,200,208,288,688,888,1088,1888,2008,2088,2888,6888,8888,10888,18888,20088,20888,28888,68888,88888,108888,188888,200888,208888,288888,688888,888888};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;cin>>t;
    while(t--){
        int n;
        cin>>n;int eight=0;
        while(n>42){
            n-=7;
            eight++;
        }cout<<b[n];
        for(int i=1;i<=eight;++i)cout<<'8';
        cout<<endl;
    }
    return 0;
}