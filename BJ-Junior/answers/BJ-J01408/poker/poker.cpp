#include<bits/stdc++.h>
using namespace std;
int noit[4][13];
int main(){
    int n;
    char s[2];
    int ans=0;
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s;
        if(s[0]=='D'){
            if('2'<=s[1] and s[1]<='9'){
                noit[0][s[1]-'0'-1]=1;
            }
            else if(s[1]=='A'){
                noit[0][0]=1;
            }
            else if(s[1]=='T'){
                noit[0][9]=1;
            }
            else if(s[1]=='J'){
                noit[0][10]=1;
            }
            else if(s[1]=='Q'){
                noit[0][11]=1;
            }
            else if(s[1]=='K'){
                noit[0][12]=1;
            }
        }
        if(s[0]=='C'){
            if('2'<=s[1] and s[1]<='9'){
                noit[1][s[1]-'0'-1]=1;
            }
            else if(s[1]=='A'){
                noit[1][0]=1;
            }
            else if(s[1]=='T'){
                noit[1][9]=1;
            }
            else if(s[1]=='J'){
                noit[1][10]=1;
            }
            else if(s[1]=='Q'){
                noit[1][11]=1;
            }
            else if(s[1]=='K'){
                noit[1][12]=1;
            }
        }
        if(s[0]=='H'){
            if('2'<=s[1] and s[1]<='9'){
                noit[2][s[1]-'0'-1]=1;
            }
            else if(s[1]=='A'){
                noit[2][0]=1;
            }
            else if(s[1]=='T'){
                noit[2][9]=1;
            }
            else if(s[1]=='J'){
                noit[2][10]=1;
            }
            else if(s[1]=='Q'){
                noit[2][11]=1;
            }
            else if(s[1]=='K'){
                noit[2][12]=1;
            }
        }
        if(s[0]=='S'){
            if('2'<=s[1] and s[1]<='9'){
                noit[3][s[1]-'0'-1]=1;
            }
            else if(s[1]=='A'){
                noit[3][0]=1;
            }
            else if(s[1]=='T'){
                noit[3][9]=1;
            }
            else if(s[1]=='J'){
                noit[3][10]=1;
            }
            else if(s[1]=='Q'){
                noit[3][11]=1;
            }
            else if(s[1]=='K'){
                noit[3][12]=1;
            }
        }
    }
    for(int i=0;i<=3;i++){
        for(int r=0;r<=12;r++){
            if(noit[i][r]==0){
                ans++;
            }
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
