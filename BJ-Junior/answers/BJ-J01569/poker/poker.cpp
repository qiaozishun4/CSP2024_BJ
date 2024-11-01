#include<bits/stdc++.h>
using namespace std;
int n;
string s[60];
bool flag[5][15];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=0;i<=3;i++){
        for(int j=1;j<=13;j++){
            flag[i][j]=true;
        }
    }
    for(int i=1;i<=n;i++){
        cin>>s[i];
        char s0=s[i][0],s1=s[i][1];
        if(s0=='D'){
            if(s1=='A'){
                flag[0][1]=false;
            }
            else if(s1=='2'){
                flag[0][2]=false;
            }
            else if(s1=='3'){
                flag[0][3]=false;
            }
            else if(s1=='4'){
                flag[0][4]=false;
            }
            else if(s1=='5'){
                flag[0][5]=false;
            }
            else if(s1=='6'){
                flag[0][6]=false;
            }
            else if(s1=='7'){
                flag[0][7]=false;
            }
            else if(s1=='8'){
                flag[0][8]=false;
            }
            else if(s1=='9'){
                flag[0][9]=false;
            }
            else if(s1=='T'){
                flag[0][10]=false;
            }
            else if(s1=='J'){
                flag[0][11]=false;
            }
            else if(s1=='Q'){
                flag[0][12]=false;
            }
            else if(s1=='K'){
                flag[0][13]=false;
            }
        }
        if(s0=='C'){
            if(s1=='A'){
                flag[1][1]=false;
            }
            else if(s1=='2'){
                flag[1][2]=false;
            }
            else if(s1=='3'){
                flag[1][3]=false;
            }
            else if(s1=='4'){
                flag[1][4]=false;
            }
            else if(s1=='5'){
                flag[1][5]=false;
            }
            else if(s1=='6'){
                flag[1][6]=false;
            }
            else if(s1=='7'){
                flag[1][7]=false;
            }
            else if(s1=='8'){
                flag[1][8]=false;
            }
            else if(s1=='9'){
                flag[1][9]=false;
            }
            else if(s1=='T'){
                flag[1][10]=false;
            }
            else if(s1=='J'){
                flag[1][11]=false;
            }
            else if(s1=='Q'){
                flag[1][12]=false;
            }
            else if(s1=='K'){
                flag[1][13]=false;
            }
        }
        if(s0=='H'){
            if(s1=='A'){
                flag[2][1]=false;
            }
            else if(s1=='2'){
                flag[2][2]=false;
            }
            else if(s1=='3'){
                flag[2][3]=false;
            }
            else if(s1=='4'){
                flag[2][4]=false;
            }
            else if(s1=='5'){
                flag[2][5]=false;
            }
            else if(s1=='6'){
                flag[2][6]=false;
            }
            else if(s1=='7'){
                flag[2][7]=false;
            }
            else if(s1=='8'){
                flag[2][8]=false;
            }
            else if(s1=='9'){
                flag[2][9]=false;
            }
            else if(s1=='T'){
                flag[2][10]=false;
            }
            else if(s1=='J'){
                flag[2][11]=false;
            }
            else if(s1=='Q'){
                flag[2][12]=false;
            }
            else if(s1=='K'){
                flag[2][13]=false;
            }
        }
        if(s0=='S'){
            if(s1=='A'){
                flag[3][1]=false;
            }
            else if(s1=='2'){
                flag[3][2]=false;
            }
            else if(s1=='3'){
                flag[3][3]=false;
            }
            else if(s1=='4'){
                flag[3][4]=false;
            }
            else if(s1=='5'){
                flag[3][5]=false;
            }
            else if(s1=='6'){
                flag[3][6]=false;
            }
            else if(s1=='7'){
                flag[3][7]=false;
            }
            else if(s1=='8'){
                flag[3][8]=false;
            }
            else if(s1=='9'){
                flag[3][9]=false;
            }
            else if(s1=='T'){
                flag[3][10]=false;
            }
            else if(s1=='J'){
                flag[3][11]=false;
            }
            else if(s1=='Q'){
                flag[3][12]=false;
            }
            else if(s1=='K'){
                flag[3][13]=false;
            }
        }
    }
    int ans=52;
    for(int i=0;i<=3;i++){
        for(int j=1;j<=13;j++){
            if(flag[i][j]==false){
                ans--;
            }
        }
    }
    cout<<ans;
    return 0;
}
