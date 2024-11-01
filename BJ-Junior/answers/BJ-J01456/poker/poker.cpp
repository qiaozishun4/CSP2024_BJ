#include<bits/stdc++.h>
using namespace std;
int t[5][15];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        if(s[0]=='D'){
            if(s[1]>='2'&&s[1]<='9'){
                t[1][s[1]-'0']=1;
            }else if(s[1]=='A'){
                t[1][1]=1;
            }else if(s[1]=='T'){
                t[1][10]=1;
            }else if(s[1]=='J'){
                t[1][11]=1;
            }else if(s[1]=='Q'){
                t[1][12]=1;
            }else if(s[1]=='K'){
                t[1][13]=1;
            }
        }else if(s[0]=='C'){
            if(s[1]>='2'&&s[1]<='9'){
                t[2][s[1]-'0']=1;
            }else if(s[1]=='A'){
                t[2][1]=1;
            }else if(s[1]=='T'){
                t[2][10]=1;
            }else if(s[1]=='J'){
                t[2][11]=1;
            }else if(s[1]=='Q'){
                t[2][12]=1;
            }else if(s[1]=='K'){
                t[2][13]=1;
            }
        }else if(s[0]=='H'){
            if(s[1]>='2'&&s[1]<='9'){
                t[3][s[1]-'0']=1;
            }else if(s[1]=='A'){
                t[3][1]=1;
            }else if(s[1]=='T'){
                t[3][10]=1;
            }else if(s[1]=='J'){
                t[3][11]=1;
            }else if(s[1]=='Q'){
                t[3][12]=1;
            }else if(s[1]=='K'){
                t[3][13]=1;
            }
        }else{
            if(s[1]>='2'&&s[1]<='9'){
                t[4][s[1]-'0']=1;
            }else if(s[1]=='A'){
                t[4][1]=1;
            }else if(s[1]=='T'){
                t[4][10]=1;
            }else if(s[1]=='J'){
                t[4][11]=1;
            }else if(s[1]=='Q'){
                t[4][12]=1;
            }else if(s[1]=='K'){
                t[4][13]=1;
            }
        }
    }
    int ans=0;
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(t[i][j]==0){
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}