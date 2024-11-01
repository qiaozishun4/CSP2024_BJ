#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
    freopen("duel.in" , "r" , stdin);
    freopen("duel.out" , "w" , stdout);
    int n , r[100005] = {0}, minm = 100000, sum = 0, min1 = 0;
    bool g[100005] = {1};
    cin>>n;
    sum = n;
    for (int i = 1; i <= n; i++){
        cin>> r[i];
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (r[j] < minm && g[j] != 0 && r[j] > r[i]){
                minm = r[j];
                min1 = j;
            }
        }
        if (minm == 100000){
            minm = 100000;
            for (int j = 1; j <= n; j++){
                if (r[j] < minm && i != j){
                    minm = r[j];
                    min1 = j;
                }
            }
            g[i] = 0;
            r[min1] = 0;
            g[min1] = 0;
            continue;
        }
        r[i] == 0;
        g[min1] = 0;
        sum--;
        minm = 100000;
    }
    cout<< sum;
    return 0;
}