#include <bits/stdc++.h>
using namespace std;

struct node{
    int r;
    bool cj, gj;
}a[100005];

bool cmp(node x, node y){
    return x.r < y.r;
}
int main(){
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    int n;
    cin >>n;
    for(int i = 1; i <= n; i++){
        cin >>a[i].r;
        a[i].cj = 1;
        a[i].gj = 1;
    }
    sort(a+1, a+n+1, cmp);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i!=j){
                if(a[i].cj == 1 && a[j].cj == 1 &&a[j].gj == 1){
                    //都没访问过
                    if(a[j].r > a[i].r){//能打败
                        a[i].cj = 0;
                        a[j].gj = 0;
                    }
                }
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(a[i].cj == 1) ans++;
    }
    cout << ans;
    return 0;
    fclose(stdin);
    fclose(stdout);
}
