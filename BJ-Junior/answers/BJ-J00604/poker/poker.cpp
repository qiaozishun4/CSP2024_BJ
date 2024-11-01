#include <iostream>
#include <cstring>
using namespace std;
int n;
int cnt[15][6];
string str;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    memset(cnt,0,sizeof(cnt));
    scanf("%d",&n);
    while(n--){
        cin>>str;
        char color = str[0],number = str[1];
        int color_p,number_p;
        switch(color){
            case'D':color_p = 1;break;
            case'C':color_p = 2;break;
            case'H':color_p = 3;break;
            case'S':color_p = 4;break;
        }
        switch(number){
            case'A':number_p = 1;break;
            case'2':number_p = 2;break;
            case'3':number_p = 3;break;
            case'4':number_p = 4;break;
            case'5':number_p = 5;break;
            case'6':number_p = 6;break;
            case'7':number_p = 7;break;
            case'8':number_p = 8;break;
            case'9':number_p = 9;break;
            case'T':number_p = 10;break;
            case'J':number_p = 11;break;
            case'Q':number_p = 12;break;
            case'K':number_p = 13;break;
        }
        cnt[number_p][color_p] = 1;
    }

    int ans = 0;
    for(int i = 1; i <= 13; i++){
        for(int j = 1; j <= 4; j++){
                //printf("%d ",cnt[i][j]);
            if(cnt[i][j] == 0){
                ans++;
            }
        }
        //printf("\n");
    }
    printf("%d",ans);
    return 0;
}
/*
4
DQ
H3
DQ
DT
*/
