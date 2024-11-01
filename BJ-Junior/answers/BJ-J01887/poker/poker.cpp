#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
bool puke[4][14];
int main(){
    memset(puke,sizeof(puke),0);
    int n;
    string temp;
    cin>>n;
    while(n--) {
        cin>>temp;
        int temp_=0;
        switch(temp[1]){
        case 'A':
            temp_=1;
            break;
        case 'T':
            temp_=10;
            break;
        case 'J':
            temp_=11;
            break;
        case 'Q':
            temp_=12;
            break;
        case 'K':
            temp_=13;
            break;
        }
        if(temp_==0)
            temp_=temp[1]-'0';
        switch(temp[0]){
            case 'D':
                puke[0][temp_]=true;
                break;
            case 'C':
                puke[1][temp_]=true;
                break;
            case 'H':
                puke[2][temp_]=true;
                break;
            case 'S':
                puke[3][temp_]=true;
        }
    }
    int ans=0;
    for(int i=0;i<4;++i){
        for(int j=1;j<=13;++j){
            if(!puke[i][j])
                ++ans;
        }
    }
    cout<<ans<<endl;
    return 0;
}
