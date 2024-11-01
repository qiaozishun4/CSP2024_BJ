#include<bits/stdc++.h>
using namespace std;
int n,num[4][13],cnt = 0;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    string pok;
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>pok;
        if(pok[0] == 'D'){
            if(pok[1] == 'T'){
                num[0][9]++;
            }
            else if(pok[1] == 'J'){
                num[0][10]++;
            }
            else if(pok[1] == 'Q'){
                num[0][11]++;
            }
            else if(pok[1] == 'K'){
                num[0][12]++;
            }
            else if(pok[1] == 'A'){
                num[0][0]++;
            }
            else{
                num[0][pok[1]-'1']++;
            }
        }
        else if(pok[0] == 'C'){
            if(pok[1] == 'T'){
                num[1][9]++;
            }
            else if(pok[1] == 'J'){
                num[1][10]++;
            }
            else if(pok[1] == 'Q'){
                num[1][11]++;
            }
            else if(pok[1] == 'K'){
                num[1][12]++;
            }
            else if(pok[1] == 'A'){
                num[1][0]++;
            }
            else{
                num[1][pok[1]-'1']++;
            }
        }
        else if(pok[0] == 'H'){
            if(pok[1] == 'T'){
                num[2][9]++;
            }
            else if(pok[1] == 'J'){
                num[2][10]++;
            }
            else if(pok[1] == 'Q'){
                num[2][11]++;
            }
            else if(pok[1] == 'K'){
                num[2][12]++;
            }
            else if(pok[1] == 'A'){
                num[2][0]++;
            }
            else{
                num[2][pok[1]-'1']++;
            }
        }
        else if(pok[0] == 'S'){
            if(pok[1] == 'T'){
                num[3][9]++;
            }
            else if(pok[1] == 'J'){
                num[3][10]++;
            }
            else if(pok[1] == 'Q'){
                num[3][11]++;
            }
            else if(pok[1] == 'K'){
                num[3][12]++;
            }
            else if(pok[1] == 'A'){
                num[3][0]++;
            }
            else{
                num[3][pok[1]-'1']++;
            }
        }
    }
    for(int i = 0;i<4;i++){
        for(int j = 0;j<13;j++){
            if(num[i][j]==0){
                cnt++;
            }
        }
    }
    cout<<cnt;
    return 0;
}
