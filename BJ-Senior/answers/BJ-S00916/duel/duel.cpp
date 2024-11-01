#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

const int maxn = 100005;

int n, arr[maxn], b[maxn], cnt;

int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    sort(arr+1, arr+1+n);
    for (int i = 1; i <= n; i++){
        if (b[0] == 0){
            b[++b[0]] = arr[i];
            continue;
        }
        if (arr[i] == b[b[0]]){
            int x = lower_bound(b+1, b+1+b[0], arr[i])-b-1;
            if (x == 0) b[++b[0]] = arr[i];
            else b[x] = arr[i];
        }
        else{
            b[b[0]] = arr[i];
        }
    }
    cout << b[0] << "\n";
    return 0;
}
