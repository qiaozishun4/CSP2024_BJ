#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 5;

int n,ans;
int a[N],q[N],st = 1,ed;

int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);

    cin >> n;
    ans = n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a + 1,a + n + 1);
    for(int i = 1;i <= n;i++){
        if(st <= ed && q[st] < a[i]){
            st++;
            ans--;
        }
        q[++ed] = a[i];
    }
    cout << ans;
}