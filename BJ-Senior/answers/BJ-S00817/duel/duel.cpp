#include<bits/stdc++.h>
using namespace std;

int n , m , ma = 0;
int a[100010];
int b[100010];

int main(){
    freopen("duel.in" , "r" , stdin);
    freopen("duel.out" , "w" , stdout);
    scanf("%d" , &n);
    for(int i = 1; i <= n; i++){
        int x;
        scanf("%d" , &x);
        //a[x]++;
        b[x]++;
        ma = max(ma , x);
    }
    for(int i = 1; i <= ma; i++){
        for(int j = i + 1; j <= ma; j++){
            if(b[i] < b[j]){
                m += b[i];
                b[i] = 0;
                //a[i] = 0;
                b[j] -= b[i];
            }
            else{
                m += b[j];
                b[j] = 0;
                //a[j] = 0;
                b[i] -= b[j];
            }
        }
    }
    printf("%d" , n - m);
    return 0;
}
