#include<bits/stdc++.h>
using namespace std;
int n,cnt;
string s,a[100010];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> s;
        a[i] = s;
    }
    for(int i=1;i<=n;i++){
        if(n != 1){
            if(s != a[i]){
                cnt++;
            }
        }
        if(n == 1){
            cnt = 1;
        }
    }
    cout << 52-cnt;
    return 0;
}
