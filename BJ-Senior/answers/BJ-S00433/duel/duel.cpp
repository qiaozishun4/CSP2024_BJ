#include<iostream>
#include<algorithm>
//#define test
using namespace std;
const int N = 100010;
int n;
int card[N];
int anal[N];
int main(){
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> card[i];
    }
    sort(card + 1, card + n + 1);
    int now = 0;
    int point = 0;
    for(int i = 1; i <= n; i++){
        if(card[i] != now){
            now = card[i];
            point++;
            anal[point]++;
        }else{
            anal[point]++;
        }
    }
    #ifdef test
    for(int i = 1; i <= point; i++){
        cout << anal[i] << endl;
    }
    cout << endl;
    #endif
    int ans = anal[1];
    for(int i = 2; i <= point; i++){
        if(ans - anal[i] >= 0){
            ans = ans - anal[i];
            ans += anal[i];
        }else{
            ans = anal[i];
        }
    }
    cout << ans << endl;
    return 0;
}