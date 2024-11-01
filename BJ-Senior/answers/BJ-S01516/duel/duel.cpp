#include <stdio.h>
#include <memory.h>
// #include <vector>
// using namespace std;
inline int max(int a, int b){
    return a>b?a:b;
}
int t[100001];
int main(){
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    int n, tmp, ans=0;
    register int i,j=0;
    memset(t, 0, sizeof(t));
    scanf("%d", &n);
    for(i=0;i<n;i++){
        scanf("%d", &tmp);
        t[tmp]++;
        j=max(j, tmp);
    }
    // printf("Debug: max = %d\n", j);
    i=j;
    j=0;
    while(i>=0){
        if(t[i]>j){
            ans+=t[i]-j;
            j=t[i];
        }
        i--;
    }
    printf("%d", ans);
    return 0;
}