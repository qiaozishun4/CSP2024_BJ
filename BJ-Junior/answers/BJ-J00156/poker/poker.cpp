#include <bits/stdc++.h>
using namespace std;
char a;
char b;
int summ[1005][1005],ansn;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin >> n;
    for(int i = 1;i<=n;i++){
        scanf("\n%c%c ",&a,&b);
        summ[a][b]++;
    }
    char shu,hua;
    for(int i = 1;i<=13;i++){
        if(i >= 10){
            if(i == 10) shu = 'T';
            else if(i == 11) shu = 'J';
            else if(i == 12) shu = 'Q';
            else if(i == 13) shu = 'K';
        }else if(i == 1){
            shu = 'A';
        }else{
            shu = '0' + i;
        }
        for(int j = 1;j<=4;j++){
            if(j == 1) hua = 'D';
            else if(j == 2) hua = 'C';
            else if(j == 3) hua = 'H';
            else if(j == 4) hua = 'S';

            if(!summ[hua][shu]) ansn++;
        }
    }
    cout << ansn;
    return 0;
}
