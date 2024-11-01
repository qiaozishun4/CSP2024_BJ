#include<iostream>
#include<map>
using namespace std;

map<int,int> mp;

int main(){
    ios::sync_with_stdio(0);
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        mp[x]++;
        ans = max(ans,mp[x]);
    }
    cout << ans;
    return 0;
}
