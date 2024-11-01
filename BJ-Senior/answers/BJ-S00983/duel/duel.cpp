#include <bits/stdc++.h>
using namespace std;
int n, r[100005];
int tong[100005];
int k[100005];
int maxr, cnt;
//2  2  1
//1  2  3

//3 1 2 3 2
//1 2 3 4 5
int main(){
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>r[i];
        tong[r[i]]++;
        k[r[i]]++;
        maxr = max(maxr, r[i]);
    }
    for(int i = 2;i<=maxr;i++){
        for(int j = 1;j<i;j++){
            if(k[i] <= tong[j]){
                tong[j] -= k[i];
                break;
            }
            else{
                k[i] -= tong[j];
                tong[j] = 0;
            }
        }
    }
    for(int i = 1;i<=maxr;i++){
        cnt += tong[i];
    }
    cout<<cnt;
    return 0;
}
