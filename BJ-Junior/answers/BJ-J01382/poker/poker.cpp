#include <bits/stdc++.h>
using namespace std;
int n;
int b[6][15];
int sum=0;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        if(s[0]=='D'){
            if(s[1]=='A'){
                b[1][1]++;
            }else if(s[1]>='2'&&s[1]<='9'){
                b[1][s[1]-'0']++;
            }else if(s[1]=='T'){
                b[1][10]++;
            }else if(s[1]=='J'){
                b[1][11]++;
            }else if(s[1]=='Q'){
                b[1][12]++;
            }else if(s[1]=='K'){
                b[1][13]++;
            }
        }else if(s[0]=='C'){
            if(s[1]=='A'){
                b[2][1]++;
            }else if(s[1]>='2'&&s[1]<='9'){
                b[2][s[1]-'0']++;
            }else if(s[1]=='T'){
                b[2][10]++;
            }else if(s[1]=='J'){
                b[2][11]++;
            }else if(s[1]=='Q'){
                b[2][12]++;
            }else if(s[1]=='K'){
                b[2][13]++;
            }
        }else if(s[0]=='S'){
            if(s[1]=='A'){
                b[3][1]++;
            }else if(s[1]>='2'&&s[1]<='9'){
                b[3][s[1]-'0']++;
            }else if(s[1]=='T'){
                b[3][10]++;
            }else if(s[1]=='J'){
                b[3][11]++;
            }else if(s[1]=='Q'){
                b[3][12]++;
            }else if(s[1]=='K'){
                b[3][13]++;
            }
        }else if(s[0]=='H'){
            if(s[1]=='A'){
                b[4][1]++;
            }else if(s[1]>='2'&&s[1]<='9'){
                b[4][s[1]-'0']++;
            }else if(s[1]=='T'){
                b[4][10]++;
            }else if(s[1]=='J'){
                b[4][11]++;
            }else if(s[1]=='Q'){
                b[4][12]++;
            }else if(s[1]=='K'){
                b[4][13]++;
            }
        }
    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(b[i][j]!=0){
                sum++;
            }
        }
    }
    cout<<52-sum;
    return 0;
}
