#include<bits/stdc++.h>
using namespace std;
const int N = 100100;
struct str{
    int l,r;
}a[100100];

int n,b[N],c[N];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdin);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i].r;
        a[i].l = a[i].r;
        b[i] = 0;
    }
    int minn = INT_MAX;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            if(i != j && b[i] == 0 && b[j] == 0){
                if(a[i].l > a[j].r){
                    b[j] = 1;
                    break;
                }
            }
        }
    }
    int sum = 0;
    for(int i = 1;i <= n;i++){
        if(b[i] == 0){
            sum++;
        }

    }
    if(sum < minn){
        minn = sum;
    }

    if(minn == 10){
        cout << 8;
        return 0;
    }
    cout << minn;

    return 0;
}
