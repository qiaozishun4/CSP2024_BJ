#include<bits/stdc++.h>
using namespace std;
int n;
bool cnt[6][15];
char color,num;
int cal(char s){
    if(s >= '2' && s <= '9')return (s - '0');
    else if(s == 'A')return 1;
    else if(s == 'T')return 10;
    else if(s == 'J')return 11;
    else if(s == 'Q')return 12;
    else if(s == 'K')return 13;
}
int ans = 0;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    for(int i = 1;i <= 4;i++)
        for(int j = 1;j <= 13;j++)
            cnt[i][j] = 0;
    scanf("%d",&n);
    for(int i = 1;i <= n;i++){
        cin >> color >> num;
        int number = cal(num);
        if(color == 'D')cnt[1][number] = 1;
        else if(color == 'C')cnt[2][number] = 1;
        else if(color == 'H')cnt[3][number] = 1;
        else if(color == 'S')cnt[4][number] = 1;
    }
    for(int i = 1;i <= 4;i++){
        for(int j = 1;j <= 13;j++){
            if(!cnt[i][j])ans++;
        }
    }
    printf("%d",ans);
    return 0;
}
