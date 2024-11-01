#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n;
    cin>>n;
    string s;
    set<string> poker;
    for(int i = 1;i<=n;i++) {
        cin>>s;
        poker.insert(s);
    }
    cout<<52-poker.size();
    return 0;
}