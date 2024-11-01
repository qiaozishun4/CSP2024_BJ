#include<iostream>
#include<cstdio>
using namespace std;
bool a[6][20];
int n,ans;
string ain;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<n;i++){
        cin>>ain;
        int x,y;
        if(ain[0] == 'D'){
            x = 1;
        }
        if(ain[0] == 'C'){
            x = 2;
        }
        if(ain[0] == 'H'){
            x = 3;
        }
        if(ain[0] == 'S'){
            x = 4;
        }
        if(ain[1] == 'A'){
            y = 1;
        }
        if(ain[1] == 'T'){
            y = 10;
        }
        if(ain[1] == 'J'){
            y = 11;
        }
        if(ain[1] == 'Q'){
            y = 12;
        }
        if(ain[1] == 'K'){
            y = 13;
        }
        if(ain[1] <= '9' && ain[1]>='2'){
            y = ain[1];
        }
        a[x][y] = 1;
    }
    for(int i=1;1<=4;i++){
        for(int j=1;j<=13;j++){
            if(a[i][j] == 0){
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
