#include<bits/stdc++.h>
using namespace std;
int a[5][14];
int n;
int cnt;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        int x,y;
        if(s[0]=='D'){
            x=1;
        }
        else if(s[0]=='C'){
            x=2;
        }
        else if(s[0]=='H'){
            x=3;
        }
        else if(s[0]=='S'){
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
        if(a[x][y]==0){
            cnt++;
            a[x][y]=1;
        }
    }
    cout<<52-cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
