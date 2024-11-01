#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
map<string, bool> mp;
int main(){
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n;
    cin >> n;
    int cnt = 52;
    for (int i = 1; i <= n; i++){
        string s;
        cin >> s;
        if (mp[s] == false){
            mp[s] = true;
            cnt--;
        }
    }
    cout << cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
