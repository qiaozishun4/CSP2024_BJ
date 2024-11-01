#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
int a[100005] = {0};
queue <int> q;
bool cmp(int x, int y){
    return x < y;
}
int main(){
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    int n = 0, ans = 0;
    scanf("%d", &n);
    ans = n;
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + n + 1, cmp);
    q.push(a[1]);
    for(int i = 2; i <= n; i++){
        if(a[i] > q.front()){
            ans--;q.pop();
        }
        q.push(a[i]);
    }
    printf("%d", ans);
    return 0;
}
