#include<bits/stdc++.h>

using namespace std;

//TO NAME
bool f[100010];
int n, a[100010];

int main(){

    //TO DO
    freopen("dule.in", "r", stdin);
    freopen("dule.out", "w", stdout);
    cin >> n;
    int ans = n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for(int i = 2;i <= n;i++){
        for(int j = 1;j <= i;j++){
            if(f[j] == 0 && a[i] > a[j]){
                f[j] = 1;
                ans--;

    }
    printf("%d", ans);

    return 0;
}
