#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int num[100010];

int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    for (int i = 1;i <= n;i++){
        int x;
        cin>>x;
        num[x]++;
    }
    int ans = 0;
    for (int i = 1;i <= 100005;i++){
        ans = max(ans - num[i],0);
        ans += num[i];
    }
    cout<<ans<<endl;
    return 0;
}
