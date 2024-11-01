#include<bits/stdc++.h>
using namespace std;
int n,a[100000010],x,d;
bool k[100000010];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin >> n;
    int num = n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        k[i] = false;
    }
    if(n%2 == 0){
        for(int i=1;i<=n;i++){
            if(a[i] <= a[n-i+1] && a[i] != true){
                k[i] = true;
            }
            if(a[i] > a[n-i+1] && a[i] != true){
                k[i] = true;
                num--;
            }
        }
    }
    if(n%2 == 1){
        for(int i=1;i<=n;i++){
            if(i != n/2+1){
                if(a[i] <= a[n-i+1] && a[i] != true){
                    k[i] = true;
                }
                if(a[i] > a[n-i+1] && a[i] != true){
                    k[i] = true;
                    num--;
                }
            }
            if(i == n/2+1){
                if(a[i] <= a[n] && a[i] != true){
                    k[i] = true;
                }
                if(a[i] > a[1] && a[i] != true){
                    k[i] = true;
                    num--;
                }
            }
        }
    }
    cout << num;
    return 0;
}
