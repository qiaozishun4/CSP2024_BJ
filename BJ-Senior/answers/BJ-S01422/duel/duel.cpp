#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    int n;
    cin >> n;
    const int o = n;
    int a[o];
    int b[10005];
    for(int i = 0;i < 10005;i++){
        b[i] = 0;
    }
    for(int i = 0;i< n;i++){
        cin >> a[i];
        b[a[i]]++;
    }
    int x = 0;
    for(int i = 1;i < 10005;i++){
        x+=b[i];
        x-=b[i+1];
        if(x<0){
            x=0;
        }
    }
    cout <<x << endl;
    return 0;
}