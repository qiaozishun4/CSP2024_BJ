#include<bits/stdc++.h>
using namespace std;
string a[55];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,ans = 52,k = 0;
    cin >> n;
    for(int i = 1;i <= n;i++){
        bool flag = false;
        string t;
        cin >> t;
        for(int j = 1;j <= n;j++){
            if(a[j] == t) flag = true;
        }
        if(flag == false){
            k++;
            a[k] = t;
            ans--;
        }
    }
    cout << ans;
    return 0;
}