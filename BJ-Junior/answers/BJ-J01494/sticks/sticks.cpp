#include <bits/stdc++.h>
using namespace std;

char ans[100010];
int stk[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int num[10] = {0, 1, 2, 4, 6, 7, 8};

int sch(int stick, int pos, int lay){
    if(lay==0)
        return 0;
    int nn=0;
    if(pos==0) nn++;
    for(int i=nn; i<=6; i++){
        int lft = stick-stk[num[i]];
        if((lay-1)*7<lft||lft<0){
            continue;
        }
        else{
            ans[pos]=num[i]+48;
            sch(lft, pos+1, lay-1);
            break;
        }
    }
}

int main(){
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int t;
    scanf("%d", &t);
    for(int q=0; q<t; q++){
        memset(ans, 0, sizeof(ans));
        int n;
        scanf("%d", &n);
        if(n==1){
            printf("-1\n");
            continue;
        }
        int layer=(n-1)/7+1;
        sch(n, 0, layer);
        printf("%s\n", ans);
    }
    return 0;
}
