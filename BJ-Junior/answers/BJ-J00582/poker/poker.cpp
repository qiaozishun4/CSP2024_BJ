#include<bits/stdc++.h>
using namespace std;
int n, cnt = 0;
string s[107];
bool cmp(string a, string b){
    if(a[0] == b[0]) return a[1] <= b[1];
    return a[0] < b[0];
}
int main(){
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> s[i];
    }
    sort(s + 1, s + 1 + n);
    for(int i = 1;i <= n;i++){
        while(s[i] == s[i + 1]){
            i++;
            cnt++;
        }
    }
    cout << (52 - n + cnt) << '\n';
    return 0;
}