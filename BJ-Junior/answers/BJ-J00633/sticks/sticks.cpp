#include<bits/stdc++.h>
using namespace std;
 long a[10001]={};
 long long z(int n){
    long long i=n/7;
    long long  j=1;
    long long cnt1=1;
    long long cnt2=0;
    while(j<=i){
        j++;
        cnt2+=cnt1*8;
        cnt1*=10;
    }
    return cnt2;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cout<<z(a[i])<<endl;
    }
    return 0;
}

