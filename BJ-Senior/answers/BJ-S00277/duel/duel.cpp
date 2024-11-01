
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
int n, r[MAXN], t[MAXN];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin >> r[i];
        t[r[i]]++;
    }
    int min_ = MAXN;
    for(int i = 1; i <= n; i++){
        if(t[i]!=0){
            min_ = min(min_,t[i]);
        }
    }
    cout << n-min_;
    return 0;
}

