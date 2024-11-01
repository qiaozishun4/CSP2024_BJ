#include<bits/stdc++.h>
using namespace std;
bool s[5][14];
string st;
int n;
int sum;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>st;
        if(st[0]=='D'){
            if(st[1]>'1'&&st[1]<='9'){
                s[0][st[1]-'0'-1]=1;
            }
            if(st[1]=='T'){
                s[0][9]=1;
            }
            if(st[1]=='J'){
                s[0][10]=1;
            }
            if(st[1]=='Q'){
                s[0][11]=1;
            }
            if(st[1]=='K'){
                s[0][12]=1;
            }
            if(st[1]=='A'){
                s[0][0]=1;
            }
        }
        if(st[0]=='C'){
            if(st[1]>'1'&&st[1]<='9'){
                s[1][st[1]-'0'-1]=1;
            }
            if(st[1]=='T'){
                s[1][9]=1;
            }
            if(st[1]=='J'){
                s[1][10]=1;
            }
            if(st[1]=='Q'){
                s[1][11]=1;
            }
            if(st[1]=='K'){
                s[1][12]=1;
            }
            if(st[1]=='A'){
                s[1][0]=1;
            }
        }
        if(st[0]=='H'){
            if(st[1]>'1'&&st[1]<='9'){
                s[2][st[1]-'0'-1]=1;
            }
            if(st[1]=='T'){
                s[2][9]=1;
            }
            if(st[1]=='J'){
                s[2][10]=1;
            }
            if(st[1]=='Q'){
                s[2][11]=1;
            }
            if(st[1]=='K'){
                s[2][12]=1;
            }
            if(st[1]=='A'){
                s[2][0]=1;
            }
        }
        if(st[0]=='S'){
            if(st[1]>'1'&&st[1]<='9'){
                s[3][st[1]-'0'-1]=1;
            }
            if(st[1]=='T'){
                s[3][9]=1;
            }
            if(st[1]=='J'){
                s[3][10]=1;
            }
            if(st[1]=='Q'){
                s[3][11]=1;
            }
            if(st[1]=='K'){
                s[3][12]=1;
            }
            if(st[1]=='A'){
                s[3][0]=1;
            }
        }
    }
    for(int i=0;i<=3;i++){
        for(int j=0;j<=12;j++){
            if(s[i][j]==0){
                sum++;
            }
        }
    }
    cout<<sum;
    return 0;
}
