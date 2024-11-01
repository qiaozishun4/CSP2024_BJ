#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,sum;
map <string,bool> mp;
string s;
signed main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    scanf("%lld",&n);
    sum=n;
    for (int i=1;i<=n;i++){
        cin>>s;
        if (mp[s]){
            sum--;
        }
        mp[s]=true;
    }
    printf("%lld",52LL-sum);
    return 0;
}
