#include<bits/stdc++.h>
using namespace std;
const int N = 300100;

int n,t,a[N];
int main(){
    freopen("color.in","r",stdin);
    freopen("coler.out","w",stdin);
    cin >> t;
    for(int i = 1;i <= t;i++){
        cin >> n;
        int sum = 0;
        for(int j = 1;j <= n;j++){
            cin >> a[j];
            if(j != 1){
                for(int k = j-1;k >= 1;k--){
                    if(a[k] == a[j]){
                        sum+=a[j];
                        break;
                    }
                }
            }
        }
        cout << sum << endl;
    }
    return 0;
}
