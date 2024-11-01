#include <bits/stdc++.h>
using namespace std;
string a[60];
int s,cnt = 0;
int k = 0;
int main(){
freopen("pocker.in","r",stdin);
freopen("pocker.out","w",stdout);
    cin >> s;
    for(int i = 1;i <= s;i++){
        cin >> a[i];
        for(int j = 1;j < i;j++){
            if(a[i] == a[j]){
                k = 1;
            }
        }
        if(k == 0){
            cnt++;
        }
        k = 0;
    }
    cout << cnt;



    return 0;
}