#include<bits/stdc++.h>
using namespace std;

int n;
long long ans;
bool flag[10][20];

int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin >> n;
    for(int i=0;i<n;i++){
        char color,num;
        cin >> color >> num;
        if(color=='D'){
            if(num=='A'){
                flag[1][1]=1;
            }else if(num=='T'){
                flag[1][10]=1;
            }else if(num=='J'){
                flag[1][11]=1;
            }else if(num=='Q'){
                flag[1][12]=1;
            }else if(num=='K'){
                flag[1][13]=1;
            }else{
                flag[1][int(num-'0')]=1;
            }
        }else if(color=='C'){
            if(num=='A'){
                flag[2][1]=1;
            }else if(num=='T'){
                flag[2][10]=1;
            }else if(num=='J'){
                flag[2][11]=1;
            }else if(num=='Q'){
                flag[2][12]=1;
            }else if(num=='K'){
                flag[2][13]=1;
            }else{
                flag[2][int(num-'0')]=1;
            }
        }else if(color=='H'){
            if(num=='A'){
                flag[3][1]=1;
            }else if(num=='T'){
                flag[3][10]=1;
            }else if(num=='J'){
                flag[3][11]=1;
            }else if(num=='Q'){
                flag[3][12]=1;
            }else if(num=='K'){
                flag[3][13]=1;
            }else{
                flag[3][int(num-'0')]=1;
            }
        }else if(color=='S'){
            if(num=='A'){
                flag[4][1]=1;
            }else if(num=='T'){
                flag[4][10]=1;
            }else if(num=='J'){
                flag[4][11]=1;
            }else if(num=='Q'){
                flag[4][12]=1;
            }else if(num=='K'){
                flag[4][13]=1;
            }else{
                flag[4][int(num-'0')]=1;
            }
        }
    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(!flag[i][j]){
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}
/*
D C H S
A=1
T=10
J=11
Q=12
K=13
*/
