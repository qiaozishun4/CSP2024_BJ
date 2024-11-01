#include<bits/stdc++.h>
using namespace std;
int t,n,a[20010],num,b[100010],c[100010];
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin >> t;
    for(int k=1;k<=t;k++){
        cin >> n;
        for(int i=1;i<=n;i++){
            cin >> a[i];
            b[i] = a[i];
            for(int j=1;j<=i-1;j++){
                if(a[i] == b[j]){
                    num = a[i];
                }
            }
        }
        c[k] += num;
    }
    for(int i=1;i<=t;i++){
        cout << c[i];
    }
    return 0;
}
