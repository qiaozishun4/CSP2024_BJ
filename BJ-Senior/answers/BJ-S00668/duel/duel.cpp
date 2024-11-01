#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    fcloseall();
    int n,cnt = 0;
    cin >> n;
    int a[n];
    for (int i = 0;i<n;i++){
        cin >> a[i];
    }
    int tab = 0;
    for (int i = 0;i<n;i++){
        for (int j = 0;j<n;j++){
                if (i < j && a[i] == a[j]&&tab==0){
                    cnt++;
                    tab++;
                }
            }
            tab = 0;
        }
    cout << cnt;
    return 0;
}