#include <bits/stdc++.h>
using namespace std;
int b[15] = {6,2,5,5,4,5,6,3,7,6},dp[1000001];
string nmin = "1000001";
void dfs(int a,int w,string c){
    if(a == 0){
        if(c[0]!='0'){
            if(nmin.size() > c.size()){
                nmin = c;
            }else if(nmin.size() == c.size()){
                nmin = min(nmin,c);
            }
        }
        return;
    }
    if(a < 0){
        return;
    }
    for(char i = '0';i <= '9';i++){
        if(w == 1 && i == '0'){
            i++;
        }
        dfs(a - b[i - '0'],w + 1,c + i);
    }
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    scanf("%d",&t);
    for(int i = 0;i < t;i++){
        int a;
        scanf("%d",&a);
        if(a == 1){
            cout << -1;
            continue;
        }
        if(a == 2){
            printf("1\n");
            continue;
        }
        if(a == 3){
            printf("7\n");
            continue;
        }
        if(a == 5){
            printf("2\n");
            continue;
        }
        if(a == 7){
            printf("8\n");
            continue;
        }
        dfs(a,1,"");
        cout << nmin;
    }
    return 0;
}
