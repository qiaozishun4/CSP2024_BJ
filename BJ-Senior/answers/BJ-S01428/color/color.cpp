#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <fstream>
#include <queue>
using namespace std;
int t,a[10000],lred,lblue,n,ans,sum,c[10000],colo[10000],b[1000000],cheat2sum;   //blue 1,red 2.
bool cheat = true,cheat2 = true;
int sumup(){
    sum = 0;
    for (int i=1;i<=n;i++){
        sum+=c[i];
    }
    return sum;
}
void dfs(int x){
    if (x==n+1){
        ans = max(ans,sumup());
        return ;
    }
    for (int i=1;i<=2;i++){
        int prvlblue = lblue,prvlred = lred;    //fixed:prd->prv(previous)
        if (i==1) lblue = x;
        else if (i==2) lred = x;
        colo[x] = i;    //blue or red qwq?
        if ((i==1&&prvlblue==-1)||(i==2&&prvlred==-1)){    //no previous
            c[x] = 0;
            dfs(x+1);
        }
        else if ((i==1&&a[prvlblue]!=a[x])||(i==2&&a[prvlred]!=a[x])){ //have previous but isn't equal
            c[x] = 0;
            dfs(x+1);
        }
        else if ((i==1&&a[prvlblue]==a[x])||(i==2&&a[prvlred]==a[x])){
            c[x] = a[x];
            dfs(x+1);
        }
        lred = prvlred; //this little preserve can pay off?
        lblue = prvlblue;
    }
}   //actually this is O(2^n)
//but example#1 accepted.
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    scanf ("%d", &t);
    for (int i=1;i<=t;i++){
        ans = 0;    cheat = true;
        scanf ("%d", &n);
        for (int j=1;j<=n;j++){
            scanf ("%d", &a[j]);
            b[a[j]]+=1;
            if (b[a[j]]>1){
                if (cheat == false&&b[a[j]]==2) cheat2 = false;
                if (cheat) cheat2sum = a[j];
                cheat = false;
            }
        }
        if (cheat){
            printf ("0\n");
            continue;
        }
        if (cheat2){
            printf ("%d\n", b[cheat2sum]-1 * cheat2sum);
            continue;
        }
        lred = lblue = -1;
        dfs(1);
        printf ("%d\n", ans);
    }
    return 0;
}
/*
----------------
|   zflll      |
|   PrintfCow  |
|   shi_zwd    |
----------------
    .   .   .
    |   |   |
    |   |   |
    |   |   |
    r   p
    +   +
*/
