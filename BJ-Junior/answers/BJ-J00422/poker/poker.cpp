#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    string a[52] = {};
    int n,cnt = 0;
    cin >> n;
    for (int i = 0;i < n;i++){
        cin >> a[i];
    }
    for (int i = 0;i < n;i++){
        for (int j = i+1;j < n;j++){
            if (a[i] == a[j]){
                cnt++;
            }
        }
    }
    cout << 52-n+cnt;
    return 0;
}