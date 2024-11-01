#include<bits/stdc++.h>
using namespace std;
string a[101];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,sum = 0;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j < i; j++){
                if(a[i] == a[j]){
                    sum++;
                    break;
                }
        }
    }
    cout << 52 - n + sum;
    return 0;
}