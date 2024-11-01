#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

char card[2];
bool poker[4][13];
int count_poker(){
    int ans=0;
    for(int i=0;i<4;i++){
        for(int j=0;j<13;j++){
            if(poker[i][j]==false){
                ans++;
                printf("%d",poker[i][j]);
            }
        }
    }
    return ans;
}
int place_card(char mark){
    if(mark=='T'){
        return 10;
    }
    else if(mark=='J'){
        return 11;
    }
    else if(mark=='Q'){
        return 12;
    }
    else if(mark=='K'){
        return 13;
    }
    else if(mark=='A'){
        return 1;
    }
    else{
        return mark-'0';
    }
}
int n;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n+1;i++){
        scanf("%c",&card);
        if(card[0]=='D'){
            //方片
            poker[0][place_card(card[1])-1]=true;
        }
        else if(card[0]=='C'){
            //草花
            poker[1][place_card(card[1])-1]=true;
        }
        else if(card[0]=='H'){
            //红桃
            poker[2][place_card(card[1])-1]=true;
        }
        else if(card[0]=='S'){
            //黑桃
            poker[3][place_card(card[1])-1]=true;
        }
    }
    int call=51;
    if(n==1){
        printf("%d",call);
        return 0;
    }
    else{
        int answer=count_poker();
        printf("%d",answer);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
