#include<iostream>
#define ll long long
using namespace std;
string ans;
bool f;
ll T, n;
void Dfs(ll x, string s){
    if(x == 0){
        if(!f){
            ans = s;
            f = true;
        }
        else if(s.size() < ans.size()){
            ans = s;
        }
        else if(s.size() == ans.size() && s < ans){
            ans = s;
        }
        return;
    }
    else if(x < 0){
        return;
    }
    if(s.size()){
        Dfs(x - 6, s + "0");
    }
    Dfs(x - 2, s + "1");
    Dfs(x - 5, s + "2");
    Dfs(x - 5, s + "3");
    Dfs(x - 4, s + "4");
    Dfs(x - 5, s + "5");
    Dfs(x - 6, s + "6");
    Dfs(x - 3, s + "7");
    Dfs(x - 7, s + "8");
    Dfs(x - 6, s + "9");
}
int main(){
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    cin >> T;
    while(T--){
        ans = "";
        f = false;
        n = 0;
        cin >> n;
        Dfs(n, "");
        if(ans == ""){
            cout << -1 << endl;
        }
        else{
            cout << ans << endl;
        }
    }
    return 0;
}
