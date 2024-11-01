#include <bits/stdc++.h>
using namespace std;
string s[60];
bool a[5][15];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,ans=52;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        if(s[i][0]=='D'){
            if(s[i][1]=='A'){
                a[1][1]=1;
            }
            else if(s[i][1]=='T'){
                a[1][10]=1;
            }
            else if(s[i][1]=='J'){
                a[1][11]=1;
            }
            else if(s[i][1]=='Q'){
                a[1][12]=1;
            }
            else if(s[i][1]=='K'){
                a[1][13]=1;
            }else a[1][s[i][1]-'0']=1;
        }
        if(s[i][0]=='C'){
            if(s[i][1]=='A'){
                a[2][1]=1;
            }
            else if(s[i][1]=='T'){
                a[2][10]=1;
            }
            else if(s[i][1]=='J'){
                a[2][11]=1;
            }
            else if(s[i][1]=='Q'){
                a[2][12]=1;
            }
            else if(s[i][1]=='K'){
                a[2][13]=1;
            }else a[2][s[i][1]-'0']=1;
        }if(s[i][0]=='H'){
            if(s[i][1]=='A'){
                a[3][1]=1;
            }
            else if(s[i][1]=='T'){
                a[3][10]=1;
            }
            else if(s[i][1]=='J'){
                a[3][11]=1;
            }
            else if(s[i][1]=='Q'){
                a[3][12]=1;
            }
            else if(s[i][1]=='K'){
                a[3][13]=1;
            }else a[3][s[i][1]-'0']=1;
        }if(s[i][0]=='S'){
            if(s[i][1]=='A'){
                a[4][1]=1;
            }
            else if(s[i][1]=='T'){
                a[4][10]=1;
            }
            else if(s[i][1]=='J'){
                a[4][11]=1;
            }
            else if(s[i][1]=='Q'){
                a[4][12]=1;
            }
            else if(s[i][1]=='K'){
                a[4][13]=1;
            }else a[4][s[i][1]-'0']=1;
        }
    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){

            if(a[i][j]){
                ans--;
            }
        }
    }
    cout<<ans;
    return 0;
}
