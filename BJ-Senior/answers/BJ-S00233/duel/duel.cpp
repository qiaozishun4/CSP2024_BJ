#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5+100;
int a[maxn];

int main(){
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    int n;
    int one = 0, two = 0;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] == 1) one++;
        if(a[i] == 2) two++;
    }
    cout <<two;

    return 0;
}
