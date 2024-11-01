#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int n,ans;
bool p[4][14];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        string temp;
        int a,b;
        cin>>temp;
        if(temp[0]=='D'){
            a=0;
        }
        else if(temp[0]=='C'){
            a=1;
        }
        else if(temp[0]=='H'){
            a=2;
        }
        else if(temp[0]=='S'){
            a=3;
        }
        
        if(temp[1]=='A'){
            b=1;
        }
        else if(temp[1]=='T'){
            b=10;
        }
        else if(temp[1]=='J'){
            b=11;
        }
        else if(temp[1]=='Q'){
            b=12;
        }
        else if(temp[1]=='K'){
            b=13;
        }
        else {
            b=(int)(temp[1]-'0');
        }
        p[a][b]=true;
    }
    for(int i=0;i<4;i++){
        for(int j=1;j<=13;j++){
            if(p[i][j]==false){
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}