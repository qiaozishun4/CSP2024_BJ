#include <iostream>
#include <cstdio>
using namespace std;
int t,n,cnt[10]={6,2,5,5,4,5,6,3,7,6};
void xxx(int x){
    for(int i = 0;i <= 9;i++){
        if(x>=cnt[i] && x-cnt[i]!=1 && (x-cnt[i]+6)/7==(x+6)/7-1){
            cout << i;
            xxx(x-cnt[i]);
            return ;
        }
    }
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        if(n==1){
            cout << "-1\n";
            continue;
        }
        for(int i = 1;i <= 9;i++){
            if(n>=cnt[i] && n-cnt[i]!=1 && (n-cnt[i]+6)/7==(n+6)/7-1){
                cout << i;
                xxx(n-cnt[i]);
                cout << "\n";
                break;
            }
        }
    }
    return 0;
}