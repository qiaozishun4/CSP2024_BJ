#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
struct Node{
    int hp;
    bool b,t;
}a[N];
int cmp(const Node &a, const Node &b){
    return a.hp < b.hp;
}
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i].hp;
        a[i].b = 1;
        a[i].t = 1;
    }
    sort(a,a+n,cmp);
    int ans = n;
    for(int i = 0; i < n - 1; i++){
        if(a[i].b){
            for(int j = i + 1; j  < n; j++){
                if(a[j].hp > a[i].hp && a[j].t){
                    ans--;
                    a[j].t = 0;
                    break;
                }
            }
        }
    }
    cout << ans;
    return 0;
}
