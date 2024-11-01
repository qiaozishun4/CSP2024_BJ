#include<bits/stdc++.h>
using namespace std;
bool ans[5][15];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        char color,num;
        cin>>color>>num;
        if(color=='D'){
            if(num>='2'&&num<='9') ans[1][num-'0']=true;
            else if(num=='T') ans[1][10]=true;
            else if(num=='A') ans[1][1]=true;
            else if(num=='J') ans[1][11]=true;
            else if(num=='Q') ans[1][12]=true;
            else if(num=='K') ans[1][13]=true;
        }else if(color=='C'){
            if(num>='2'&&num<='9') ans[2][num-'0']=true;
            else if(num=='T') ans[2][10]=true;
            else if(num=='A') ans[2][1]=true;
            else if(num=='J') ans[2][11]=true;
            else if(num=='Q') ans[2][12]=true;
            else if(num=='K') ans[2][13]=true;
        }else if(color=='H'){
            if(num>='2'&&num<='9') ans[3][num-'0']=true;
            else if(num=='T') ans[3][10]=true;
            else if(num=='A') ans[3][1]=true;
            else if(num=='J') ans[3][11]=true;
            else if(num=='Q') ans[3][12]=true;
            else if(num=='K') ans[3][13]=true;
        }else if(color=='S'){
            if(num>='2'&&num<='9') ans[4][num-'0']=true;
            else if(num=='T') ans[4][10]=true;
            else if(num=='A') ans[4][1]=true;
            else if(num=='J') ans[4][11]=true;
            else if(num=='Q') ans[4][12]=true;
            else if(num=='K') ans[4][13]=true;
        }
    }
    int cnt=52;
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(ans[i][j]){
            cnt--;
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}