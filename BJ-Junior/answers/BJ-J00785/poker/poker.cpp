#include<iostream>
#include<cstdio>
using namespace std;
int n;
int a[101][101];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    string s;
    for(int i=1;i<=n;i++){
        cin>>s;
        if(s[0]=='D'){
            if(s[1]=='A'){
                a[1][1]=1;

            }else if(s[1]=='2'){
                a[1][2]=1;
            }else if(s[1]=='3'){
                a[1][3]=1;
            }else if(s[1]=='4'){
                a[1][4]=1;
            }else if(s[1]=='5'){
                a[1][5]=1;
            }else if(s[1]=='6'){
                a[1][6]=1;
            }else if(s[1]=='7'){
                a[1][7]=1;
            }else if(s[1]=='8'){
                a[1][8]=1;
            }else if(s[1]=='9'){
                a[1][9]=1;
            }else if(s[1]=='T'){
                a[1][10]=1;
            }else if(s[1]=='J'){
                a[1][11]=1;
            }else if(s[1]=='Q'){
                a[1][12]=1;
            }else if(s[1]=='K'){
                a[1][13]=1;
            }
        }else if(s[0]=='C'){
            if(s[1]=='A'){
                a[2][1]=1;
            }else if(s[1]=='2'){
                a[2][2]=1;
            }else if(s[1]=='3'){
                a[2][3]=1;
            }else if(s[1]=='4'){
                a[2][4]=1;
            }else if(s[1]=='5'){
                a[2][5]=1;
            }else if(s[1]=='6'){
                a[2][6]=1;
            }else if(s[1]=='7'){
                a[2][7]=1;
            }else if(s[1]=='8'){
                a[2][8]=1;
            }else if(s[1]=='9'){
                a[2][9]=1;
            }else if(s[1]=='T'){
                a[2][10]=1;
            }else if(s[1]=='J'){
                a[2][11]=1;
            }else if(s[1]=='Q'){
                a[2][12]=1;
            }else if(s[1]=='K'){
                a[2][13]=1;
            }
        }else if(s[0]=='H'){
            if(s[1]=='A'){
                a[3][1]=1;
            }else if(s[1]=='2'){
                a[3][2]=1;
            }else if(s[1]=='3'){
                a[3][3]=1;
            }else if(s[1]=='4'){
                a[3][4]=1;
            }else if(s[1]=='5'){
                a[3][5]=1;
            }else if(s[1]=='6'){
                a[3][6]=1;
            }else if(s[1]=='7'){
                a[3][7]=1;
            }else if(s[1]=='8'){
                a[3][8]=1;
            }else if(s[1]=='9'){
                a[3][9]=1;
            }else if(s[1]=='T'){
                a[3][10]=1;
            }else if(s[1]=='J'){
                a[3][11]=1;
            }else if(s[1]=='Q'){
                a[3][12]=1;
            }else if(s[1]=='K'){
                a[3][13]=1;
            }
        }else if(s[0]=='S'){
            if(s[1]=='A'){
                a[4][1]=1;
            }else if(s[1]=='2'){
                a[4][2]=1;
            }else if(s[1]=='3'){
                a[4][3]=1;
            }else if(s[1]=='4'){
                a[4][4]=1;
            }else if(s[1]=='5'){
                a[4][5]=1;
            }else if(s[1]=='6'){
                a[4][6]=1;
            }else if(s[1]=='7'){
                a[4][7]=1;
            }else if(s[1]=='8'){
                a[4][8]=1;
            }else if(s[1]=='9'){
                a[4][9]=1;
            }else if(s[1]=='T'){
                a[4][10]=1;
            }else if(s[1]=='J'){
                a[4][11]=1;
            }else if(s[1]=='Q'){
                a[4][12]=1;
            }else if(s[1]=='K'){
                a[4][13]=1;
            }
        }
    }
    int ans=0;

    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(a[i][j]==0){
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}