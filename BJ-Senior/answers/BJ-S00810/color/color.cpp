#include <bits/stdc++.h>
using namespace std;
int b[200000];

int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int n,x,a[200000];
    cin >> n;
    for(int i = 0;i < n;i++){
        //input
        cin >> x;
        for(int j = 0;j < x;j++){
            cin >> a[j];
        }
        //what color?
        for(int j = 0;j < x;j++){
            for(int k = j;k >= 0;k--){
                if(a[k] == a[j]){
                    b[j] = a[k];
                }
            }
        }
        //add
        int ans = 0;
        for(int j = 0;j < x;j++){
            ans += b[j];
        }
        cout << ans << endl;
    }
    return 0;
}