#include<bits/stdc++.h>
using namespace std;
int n, cnt;
map<string, int> mp;
int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);

    cin >> n;
    for(int i = 1; i <= n; i++){
        string tmp;
        cin >> tmp;
        if(!mp[tmp]){
            cnt++;
            mp[tmp] = 1;
        }
    }
    cout << 52 - cnt;
    return 0;
}