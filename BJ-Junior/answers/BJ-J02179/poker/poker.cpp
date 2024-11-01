#include<bits/stdc++.h>
using namespace std;
int q[10][20],res,n;
string str;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>str;
        if(str[1]>='2'&&str[1]<='9'){
            if(str[0]=='D'){
                q[1][str[1]-'0']=1;
            }
            else if(str[0]=='C'){
                q[2][str[1]-'0']=1;
            }
            else if(str[0]=='H'){
                q[3][str[1]-'0']=1;
            }
            else if(str[0]=='S'){
                q[4][str[1]-'0']=1;
            }
        }
        else if(str[1]=='A'){
            if(str[0]=='D'){
                q[1][1]=1;
            }
            else if(str[0]=='C'){
                q[2][1]=1;
            }
            else if(str[0]=='H'){
                q[3][1]=1;
            }
            else if(str[0]=='S'){
                q[4][1]=1;
            }
        }
        else if(str[1]=='T'){
            if(str[0]=='D'){
                q[1][10]=1;
            }
            else if(str[0]=='C'){
                q[2][10]=1;
            }
            else if(str[0]=='H'){
                q[3][10]=1;
            }
            else if(str[0]=='S'){
                q[4][10]=1;
            }
        }
        else if(str[1]=='J'){
            if(str[0]=='D'){
                q[1][11]=1;
            }
            else if(str[0]=='C'){
                q[2][11]=1;
            }
            else if(str[0]=='H'){
                q[3][11]=1;
            }
            else if(str[0]=='S'){
                q[4][11]=1;
            }
        }
        else if(str[1]=='Q'){
            if(str[0]=='D'){
                q[1][12]=1;
            }
            else if(str[0]=='C'){
                q[2][12]=1;
            }
            else if(str[0]=='H'){
                q[3][12]=1;
            }
            else if(str[0]=='S'){
                q[4][12]=1;
            }
        }
        else if(str[1]=='K'){
            if(str[0]=='D'){
                q[1][13]=1;
            }
            else if(str[0]=='C'){
                q[2][13]=1;
            }
            else if(str[0]=='H'){
                q[3][13]=1;
            }
            else if(str[0]=='S'){
                q[4][13]=1;
            }
        }
    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(q[i][j]!=1){
                res++;
            }
        }
    }
    cout<<res;
    return 0;
}
