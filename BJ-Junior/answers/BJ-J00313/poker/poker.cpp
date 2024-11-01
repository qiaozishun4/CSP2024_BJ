#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
map<string, bool> mp;
const char num[] = {' ', 'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
const char clr[] = {' ', 'D', 'C', 'H', 'S'};
int main(){
   freopen("poker.in", "r", stdin);
   freopen("poker.out", "w", stdout);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        string s;
        cin >> s;
        mp[s] = true;
    }
    int cnt = 52;
    for(int i = 1; i <= 4; i++){
        for(int j = 1; j <= 13; j++){
            string now;
            now += clr[i];
            now += num[j];
            if(int(mp.count(now)) == 1) cnt--;
        }
    }
    cout << cnt;
}
