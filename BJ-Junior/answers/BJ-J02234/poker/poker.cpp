#include <iostream>
using namespace std;
int po[10][20];
char ge[5];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,color,point;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>ge;
        if(ge[0]=='D'){
            color=1;
        }
        else if(ge[0]=='C'){
            color=2;
        }
        else if(ge[0]=='H'){
            color=3;
        }
        else{
            color=4;
        }
        if(ge[1]>='2' and ge[1]<='9'){
            point=ge[1]-'0';
        }
        else if(ge[1]=='A'){
            point=1;
        }
        else if(ge[1]=='T'){
            point=10;
        }
        else if(ge[1]=='J'){
            point=11;
        }
        else if(ge[1]=='Q'){
            point=12;
        }
        else if(ge[1]=='K'){
            point=13;
        }
        po[color][point]++;
    }
    int ans=0;
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(!po[i][j]){
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
