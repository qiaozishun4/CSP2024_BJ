#include<iostream>
using namespace std;
long long n,ans;
string h[1000000];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>h[i];
    }
ans=52-n;
    cout<<ans;
return 0;
}
