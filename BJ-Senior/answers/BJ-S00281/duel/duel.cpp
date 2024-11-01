#include<bits/stdc++.h>
using namespace std;
const int N = 10001;
long long n, ans = 1000, w = 1000;
long long a[N], cnt = 0;
bool v[10001] = {1};
int main(){
    freopen("duel.in", "r", stdin);
    freopen("duel.ans", "w", stdout);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int sum = n;
  while(sum--){
    for(int i = 0; i < n; i++){
        if(ans > a[i] && v[i] == true) ans = a[i];
    }
    if(w != 0 && ans == w){
        ans -= w;
        cnt++;
        break;
    }else if(w != 0 && ans > w){
        ans -= w;
        for(int i = 0;i < n; i++){
            if(a[i] == ans && v[i] == true){
                v[i] == false;
            }

        }
    }
    for(int i = 0; i < n; i++)
        if(w >= ans && w > a[i] && v[i] == true) w = a[i];
    w -= ans;
    for(int i = 0; i < n; i++){
        if(ans == a[i] && v[i] == true){
            v[i] == false;
            cnt++;
        }
    }

  }
    cout << cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
