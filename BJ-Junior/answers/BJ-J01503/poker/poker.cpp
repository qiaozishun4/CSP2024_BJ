#include<bits/stdc++.h>
using namespace std;
int n;
bool a[6][15];
string s;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    if(n==1){
        cout<<"51";
    }
    else{
        for(int i=0;i<6;i++){
            for(int j=0;j<15;j++){
                a[i][j]=false;
            }
        }
        int x=0,y=0;
        for(int i=1;i<=n;i++){
            cin>>s;
            if(s[0]=='D'){
                x=1;
            }
            else if(s[0]=='C'){
                x=2;
            }
            else if(s[0]=='H'){
                x=3;
            }
            else{
                x=4;
            }
            if(s[1]=='A'){
                y=1;
            }
            else if(s[1]=='T'){
                y=10;
            }
            else if(s[1]=='J'){
                y=11;
            }
            else if(s[1]=='Q'){
                y=12;
            }
            else if(s[1]=='K'){
                y=13;
            }
            else{
                y=s[1]-'0';
            }
            a[x][y]=true;
        }
        int cnt=0;
        for(int i=1;i<=4;i++){
            for(int j=1;j<=13;j++){
                if(a[i][j]==false){
                    cnt++;
                }
            }
        }
        cout<<cnt;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
