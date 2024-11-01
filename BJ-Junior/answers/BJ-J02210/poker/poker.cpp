#include<bits/stdc++.h>
using namespace std;
long long n,sum=52;
int main(){

    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);

    cin>>n;
    if(sum-n<=0) cout<<"0";
    else cout<<sum-n;

    return 0;
}
