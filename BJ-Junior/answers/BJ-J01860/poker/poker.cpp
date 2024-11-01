#include<bits/stdc++.h>
using namespace std;
string pai[60];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin >> n;
    int cnt = 52;
    for(int i=1;i<=n;i++){
        string a;
        cin >> a;
        bool flag = 1;
        for(int j=1;j<=52;j++){
            if(pai[j]==a){
                flag = 0;
                break;
            }
        }
        if(flag){
            pai[i]=a;
            cnt--;
        }
    }
    cout << cnt;
    return 0;
}
