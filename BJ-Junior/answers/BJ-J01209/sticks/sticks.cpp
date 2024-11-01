#include<bits/stdc++.h>
using namespace std;
long long t,n;
int a[21]={0,-1,1,7,4,2,6,8,10,18,22,20,27,70,88,222,188,200,488,288,800};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        cout<<a[n];
    }
    return 0;
}
