#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    cin >> T;
    while(T--){
        int n, a[100005] = {}, tong[100005] = {}, cnt = 0;
        bool flag = true;
        cin >>n;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            tong[a[i]]++;
            if(tong[a[i]]>1) flag = false;
            if(tong[a[i]] >= 2) cnt++;
        }
        if(flag){
             cout << 0 << endl;
        }
        else if(cnt == 1){
            cout << 1 << endl;
        }
        else cout << n <<endl;
    }
    return 0;
    fclose(stdin);
    fclose(stdout);
}