#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n,len = 1;
int a[N],f[N];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        f[i] = INT_MAX;
    }
    sort(a + 1,a + n + 1,greater<int>());
    for(int i = 1;i <= n;i++){
        int l = 1,r = len;
        int mid;
        while(l <= r){
            mid = (l + r) / 2;
            if(f[mid] > a[i]){
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        f[l] = a[i];
        len = max(l,len);
    }

    cout << len << endl;
    return 0;
}
