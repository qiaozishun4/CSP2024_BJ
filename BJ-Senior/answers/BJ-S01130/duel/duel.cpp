#include<bits/stdc++.h>
#define N 100005
using namespace std;
int n;
int r[N], vis[N];
int main(){
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    scanf("%d", &n);
    int num = n;
    for(int i = 1; i <= n; i++){
        scanf("%d", &r[i]);
    }
    sort(r+1, r+1+n);
    for(int i = 1; i <= n; i++){
        for(int j = i+1; j <= n; j++){
            if(r[j] > r[i] && !vis[j]){
                num--;
                vis[i] = 1;
                vis[j] = 1;
                break;
            }
        }
    }
    printf("%d", num);
    return 0;
}