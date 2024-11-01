#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

bool x[5][20];
string s;
int n,ans=52;

int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        s="";
        cin>>s;
        if(s[0]=='D'){
            if(s[1]=='A'){
                x[1][1]=true;
            }
            else if(s[1]-'0'<=10){
                x[1][s[1]-'0']=true;
            }
            else if(s[1]=='T'){
                x[1][10]=true;
            }
            else if(s[1]=='J'){
                x[1][11]=true;
            }
            else if(s[1]=='Q'){
                x[1][12]=true;
            }
            else{
                x[1][13]=true;
            }
        }
        else if(s[0]=='C'){
            if(s[1]=='A'){
                x[2][1]=true;
            }
            else if(s[1]-'0'<=10){
                x[2][s[1]-'0']=true;
            }
            else if(s[1]=='T'){
                x[2][10]=true;
            }
            else if(s[1]=='J'){
                x[2][11]=true;
            }
            else if(s[1]=='Q'){
                x[2][12]=true;
            }
            else{
                x[2][13]=true;
            }
        }
        else if(s[0]=='H'){
            if(s[1]=='A'){
                x[3][1]=true;
            }
            else if(s[1]-'0'<=10){
                x[3][s[1]-'0']=true;
            }
            else if(s[1]=='T'){
                x[3][10]=true;
            }
            else if(s[1]=='J'){
                x[3][11]=true;
            }
            else if(s[1]=='Q'){
                x[3][12]=true;
            }
            else{
                x[3][13]=true;
            }
        }
        else{
            if(s[1]=='A'){
                x[4][1]=true;
            }
            else if(s[1]-'0'<=10){
                x[4][s[1]-'0']=true;
            }
            else if(s[1]=='T'){
                x[4][10]=true;
            }
            else if(s[1]=='J'){
                x[4][11]=true;
            }
            else if(s[1]=='Q'){
                x[4][12]=true;
            }
            else{
                x[4][13]=true;
            }
        }
    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(x[i][j]==true){
                ans--;
            }
        }
    }
    cout<<ans;
    return 0;
}
