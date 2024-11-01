#include<bits/stdc++.h>
using namespace std;

int n, ans, cnt;
int r[100010], num[100010], atk[100010];

int main(){
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    scanf("%d", &n);
    for(int i = 0; i < n; i ++){
        scanf("%d", &r[i]);
    }
    sort(r, r + n);
    num[0] = 1;
    int id = 0;
    for(int i = 1; i < n; i ++){
        if(r[i] == r[i - 1]){
            num[id] ++;
        }else{
            id ++;
            num[id] ++;
        }
    }
    for(int i = 0; i <= id; i ++){
        while(num[i] > 0){
            int zc = 1;
            while((num[i + zc] == 0 || atk[i + zc] == num[i + zc]) && i + zc <= id){
                zc ++;
                if(i + zc > id){
                    zc --;
                    break;
                }
            }
            if(atk[i + zc] == num[i + zc]){
                break;
            }
            num[i] --;
            atk[i + zc] ++;
        }
    }
    for(int i = 0; i <= id; i ++){
        ans += num[i];
    }
    printf("%d", ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
