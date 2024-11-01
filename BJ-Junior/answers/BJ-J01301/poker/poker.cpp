#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,cnt;
ll sum;
string s;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s;
        cnt++;
    }
    sum=52-cnt;
    cout<<sum;
    return 0;
}
