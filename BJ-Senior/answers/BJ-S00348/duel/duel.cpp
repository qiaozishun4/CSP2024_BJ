#include <bits/stdc++.h>
using namespace std;
long long x , n , sum , c;
long long b[100010] , a[100010];
bool h(int m){
    for(int i = 1; i <= x; i++){
        if(b[i] == b[m]){
            return false;
        }
    }
    return true;
}
long long f(int m , int c){
    for(int i = c + 1; i <= n; i ++){
        if(a[i] > m){
            if(h(i) == true){
                a[c] = -1;
                x ++;
                b[x] = i;
            }
        }
        else{
            continue;
        }
    }
    return 0;
}
int main (){
    freopen("duel.in" , "r" , stdin);
    freopen("duel.out" , "w" , stdout);
    cin >>n;
    for(int i = 1; i <= n;i++){
        cin >> a[i];
    }
    sort(a + 1 , a + 1 + n);
    for(int i = 1; i <= n; i++){
        c = i;
        f(a[i] , c);
        if(a[i] == -1){
            sum++;
        }
    }
    cout <<sum;
    return 0;
}
