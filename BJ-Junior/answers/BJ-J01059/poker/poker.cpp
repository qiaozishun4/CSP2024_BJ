#include<bits/stdc++.h>
using namespace std;
bool b[10][20];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    string s[55];
    for(int i=1;i<=n;i++){
        cin>>s[i];
        if(s[i][0]=='D'){
            if(s[i][1]=='A'){
                b[1][1]=1;
            }
            else if(s[i][1]=='2'){
                b[1][2]=1;
            }
            else if(s[i][1]=='3'){
                b[1][3]=1;
            }
            else if(s[i][1]=='4'){
                b[1][4]=1;
            }
            else if(s[i][1]=='5'){
                b[1][5]=1;
            }
            else if(s[i][1]=='6'){
                b[1][6]=1;
            }
            else if(s[i][1]=='7'){
                b[1][7]=1;
            }
            else if(s[i][1]=='8'){
                b[1][8]=1;
            }
            else if(s[i][1]=='9'){
                b[1][9]=1;
            }
            else if(s[i][1]=='T'){
                b[1][10]=1;
            }
            else if(s[i][1]=='J'){
                b[1][11]=1;
            }
            else if(s[i][1]=='Q'){
                b[1][12]=1;
            }
            else if(s[i][1]=='K'){
                b[1][13]=1;
            }
        }
        else if(s[i][0]=='C'){
            if(s[i][1]=='A'){
                b[2][1]=1;
            }
            else if(s[i][1]=='2'){
                b[2][2]=1;
            }
            else if(s[i][1]=='3'){
                b[2][3]=1;
            }
            else if(s[i][1]=='4'){
                b[2][4]=1;
            }
            else if(s[i][1]=='5'){
                b[2][5]=1;
            }
            else if(s[i][1]=='6'){
                b[2][6]=1;
            }
            else if(s[i][1]=='7'){
                b[2][7]=1;
            }
            else if(s[i][1]=='8'){
                b[2][8]=1;
            }
            else if(s[i][1]=='9'){
                b[2][9]=1;
            }
            else if(s[i][1]=='T'){
                b[2][10]=1;
            }
            else if(s[i][1]=='J'){
                b[2][11]=1;
            }
            else if(s[i][1]=='Q'){
                b[2][12]=1;
            }
            else if(s[i][1]=='K'){
                b[2][13]=1;
            }
        }
        else if(s[i][0]=='H'){
            if(s[i][1]=='A'){
                b[3][1]=1;
            }
            else if(s[i][1]=='2'){
                b[3][2]=1;
            }
            else if(s[i][1]=='3'){
                b[3][3]=1;
            }
            else if(s[i][1]=='4'){
                b[3][4]=1;
            }
            else if(s[i][1]=='5'){
                b[3][5]=1;
            }
            else if(s[i][1]=='6'){
                b[3][6]=1;
            }
            else if(s[i][1]=='7'){
                b[3][7]=1;
            }
            else if(s[i][1]=='8'){
                b[3][8]=1;
            }
            else if(s[i][1]=='9'){
                b[3][9]=1;
            }
            else if(s[i][1]=='T'){
                b[3][10]=1;
            }
            else if(s[i][1]=='J'){
                b[3][11]=1;
            }
            else if(s[i][1]=='Q'){
                b[3][12]=1;
            }
            else if(s[i][1]=='K'){
                b[3][13]=1;
            }
        }
        else if(s[i][0]=='S'){
            if(s[i][1]=='A'){
                b[4][1]=1;
            }
            else if(s[i][1]=='2'){
                b[4][2]=1;
            }
            else if(s[i][1]=='3'){
                b[4][3]=1;
            }
            else if(s[i][1]=='4'){
                b[4][4]=1;
            }
            else if(s[i][1]=='5'){
                b[4][5]=1;
            }
            else if(s[i][1]=='6'){
                b[4][6]=1;
            }
            else if(s[i][1]=='7'){
                b[4][7]=1;
            }
            else if(s[i][1]=='8'){
                b[4][8]=1;
            }
            else if(s[i][1]=='9'){
                b[4][9]=1;
            }
            else if(s[i][1]=='T'){
                b[4][10]=1;
            }
            else if(s[i][1]=='J'){
                b[4][11]=1;
            }
            else if(s[i][1]=='Q'){
                b[4][12]=1;
            }
            else if(s[i][1]=='K'){
                b[4][13]=1;
            }
        }
    }
    int ans=0;
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(b[i][j]==0) ans++;
        }
    }
    cout<<ans;
    return 0;
}