#include <bits/stdc++.h>

using namespace std;
int main(){
freopen("duel.in","r",stdin);
freopen("duel.out","w",stdout);
int n;
cin >>n;
int a[100010];
for(int i = 1; i <= n; i++)
cin>>a[i];
if(n&1) cout<<n/2+1;
else cout << n/2;
return 0;
}
