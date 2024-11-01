#include<bits/stdc++.h>
using namespace std;
string a[100];
bool vis[100];
bool chk(int num, int n){
    for(int i = 1; i <= n; i++){
        if(i != num && a[num] == a[i] && !vis[i]){
            vis[num] = 1;
            vis[i] = 1;
            return false;
        }
    }
    return true;
}
int main(){
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    string s;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> s;
        a[i] = s;
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(!chk(i, n)){
            //cout << a[i] << endl;
            cnt++;
        }
    }
    cout << 52 - n + cnt << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}