#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int NR = 2e5;
const int MR = 1e2;
const LL inf = 1e18;
int a[NR + 10];
LL cal(int n, int s){
    int last[2] = {0, 0};
    LL ret = 0;
    for(int i = 1;i <= n;i++){
        if(s & (1 << (i - 1))){
            if(a[i] == a[last[1]]){
                ret += a[i];
            }
            last[1] = i;
        }
        else{
            if(a[i] == a[last[0]]){
                ret += a[i];
            }
            last[0] = i;
        }
    }
    return ret;
}

int main(){
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while(T--){
        int n;
        scanf("%d", &n);
        for(int i = 1;i <= n;i++){
            scanf("%d", &a[i]);
        }
        if(n <= 20){
            LL Max = 0;
            for(int s = 0;s <= 1 << (n - 1);s++){
                Max = max(Max, cal(n, s));
            }
            printf("%lld\n", Max);
        }
        else printf("0\n");
    }
    return 0;
}
/*
cd ~/GJH/color && g++ color.cpp && ./a.out

3
3
1 2 1
4
1 2 3 4
8
3 5 2 5 1 2 1 4


*/