#include<bits/stdc++.h>
using namespace std;
int a[5][100];
int sum;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    char n[2];
    int  m;
    cin>>m;
    string s,t;
    while(m--){
        cin>>n;
         s=n[0];
         t=n[1];
        if(s=="D"){
            if(t=="A"){
                a[1][1]=1;
            }
            else if(t=="T"){
                a[1][10]=1;
            }
            else if(t=="J"){
                a[1][11]=1;
            }
            else if(t=="K"){
                a[1][13]=1;
            }
            else if(t=="Q"){
                a[1][12]=1;
            }
            else{
                a[1][n[1]-'0']=1;
            }
        }
        if(s=="C"){
            if(t=="A"){
                a[2][1]=1;
            }
            else if(t=="T"){
                a[2][10]=1;
            }
            else if(t=="J"){
                a[2][11]=1;
            }
            else if(t=="K"){
                a[2][13]=1;
            }
            else if(t=="Q"){
                a[2][12]=1;
            }
            else{
                a[2][n[1]-'0']=1;
            }
        }
        if(s=="H"){
            if(t=="A"){
                a[3][1]=1;
            }
            else if(t=="T"){
                a[3][10]=1;
            }
            else if(t=="J"){
                a[3][11]=1;
            }
            else if(t=="K"){
                a[3][13]=1;
            }
            else if(t=="Q"){
                a[3][12]=1;
            }
            else{
                a[3][n[1]-'0']=1;
            }
        }
        if(s=="S"){
            if(t=="A"){
                a[4][1]=1;
            }
            else if(t=="T"){
                a[4][10]=1;
            }
            else if(t=="J"){
                a[4][11]=1;
            }
            else if(t=="K"){
                a[4][13]=1;
            }
            else if(t=="Q"){
                a[4][12]=1;
            }
            else{
                a[4][n[1]-'0']=1;
            }
        }
    }
        for(int i=1;i<=4;i++){
            for(int j=1;j<=13;j++){
                if(a[i][j]==1){
                    a[i][j]=0;
                    sum++;
                }
        }
    }
    cout<<52-sum;
return 0;
}
