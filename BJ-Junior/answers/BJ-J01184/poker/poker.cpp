#include <bits/stdc++.h>
using namespace std;
int cnt1[55];
long long n;
int cnt2 = 52;
string s;
int main(){
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>s;
        int value;
        if(s[1] == 'T') value = 10;
        else if(s[1] == 'A') value = 1;
        else if(s[1] == 'J') value = 11;
        else if(s[1] == 'Q') value = 12;
        else if(s[1] == 'K') value = 13;
        else value = s[1] - '0';
        if(s[0] == 'D'){
            cnt1[value]++;
        }
        else if(s[0] == 'C'){
            cnt1[value + 13]++;
        }
        else if(s[0] == 'H'){
            cnt1[value + 26]++;
        }
        else if(s[0] == 'S'){
            cnt1[value + 39]++;
        }
    }
    for(int i = 1;i<=52;i++){
        if(cnt1[i] >= 1) cnt2--;
    }
    cout<<cnt2;
    return 0;
}
