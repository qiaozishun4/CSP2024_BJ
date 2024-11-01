#include<bits/stdc++.h>
using namespace std;
int n, cnt = 52;
bool flag = 1;
string s[100005], s1[100005];
int main(){
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> s[i];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < i; j++)
            if(s[j] == s[i])
            {
                s[i] = "";
                break;
            }
    for(int i = 0; i < n; i++)
        if(s[i] != "")
            cnt--;
    cout << cnt;
    return 0;
}
