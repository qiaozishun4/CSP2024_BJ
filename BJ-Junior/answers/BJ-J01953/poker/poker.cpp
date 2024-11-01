#include <bits/stdc++.h>
using namespace std;
int n,ans,a3;
bool l[5][15];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        char a1,a2;
        cin>>a1>>a2;
        a3 = 0;
        if(a2 == 'A')a3 = 1;
        else if(a2 == 'T')a3 = 10;
        else if(a2 == 'J')a3 = 11;
        else if(a2 == 'Q')a3 = 12;
        else if(a2 == 'K')a3 = 13;
        else if(a2 == '2')a3 = 2;
        else if(a2 == '3')a3 = 3;
        else if(a2 == '4')a3 = 4;
        else if(a2 == '5')a3 = 5;
        else if(a2 == '6')a3 = 6;
        else if(a2 == '7')a3 = 7;
        else if(a2 == '8')a3 = 8;
        else if(a2 == '9')a3 = 9;
        if(a1 == 'D')l[1][a3] = 1;
        if(a1 == 'C')l[2][a3] = 1;
        if(a1 == 'H')l[3][a3] = 1;
        if(a1 == 'S')l[4][a3] = 1;
        //for(int j=1;j<=13;j++)cout<<l[1][j];
    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(!l[i][j])ans++;
        }
    }
    cout<<ans;
    return 0;
}
