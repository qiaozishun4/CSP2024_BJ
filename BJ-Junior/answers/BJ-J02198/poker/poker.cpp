#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    set < string > ans;
    int n;
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        ans.insert(s);
    }
    cout << 52 - ans.size();
    return 0;
}
