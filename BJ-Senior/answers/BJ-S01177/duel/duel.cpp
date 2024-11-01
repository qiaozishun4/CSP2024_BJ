#include<bits/stdc++.h>
using namespace std;
int a[100005] , b[100005] , n;

int main(){

    freopen("duel.in" , "r" , stdin);
    freopen("duel.out" , "w" , stdout);
    cin >> n;
    int sum = n , last = 0;
    for(int i = 1;i <= n;i ++){
        cin >> a[i];
        b[a[i]]++;
    }
    for(int i = 0;i <= 100000;i ++){
        if(b[i] == 0)continue;
        if(last > 0)sum -= min(last , b[i]);
        last = b[i];
    }
    cout << sum;


    return 0;
}
