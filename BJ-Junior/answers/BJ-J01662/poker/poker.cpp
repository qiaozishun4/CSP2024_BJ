#include<iostream>
using namespace std;
char s[3];
int a[10][20],m;
int main(){
        freopen("poker.in","r",stdin);
        freopen("poker.out","w",stdout);
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
                int x,y;
            cin>>s;
            if(s[0]=='D'){
                x=1;
            }else if(s[0]=='c'){
                x=2;
            }else if(s[0]=='H'){
                x=3;
            }else{
                x=4;
            }
            if(s[1]=='1'){
                y=1;
            }else if(s[1]=='2'){
                y=2;
            }else if(s[1]=='3'){
                y=3;
            }else if(s[1]=='4'){
                y=4;
            }else if(s[1]=='5'){
                y=5;
            }else if(s[1]=='6'){
                y=6;
            }else if(s[1]=='7'){
                y=7;
            }else if(s[1]=='8'){
                y=8;
            }else if(s[1]=='9'){
                y=9;
            }else if(s[1]=='T'){
                y=10;
            }else if(s[1]=='J'){
                y=11;
            }else if(s[1]=='Q'){
                y=12;
            }else{
                y=13;
            }
            a[x][y]=1;
        }
        for(int i=1;i<=4;i++){
            for(int j=1;j<=13;j++){
                if(a[i][j]==0){
                    m++;
                }
            }
        }
        cout<<m;

}
