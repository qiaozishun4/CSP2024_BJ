#include <iostream>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int ans2;
    int n=52;int poker[52][1];
    for(int i=1;i<=52;i++){
        for(int j=1;j<=1;j++){
            cin>>poker[i][j];
            int num;
            num=poker[i][1];
            ans2++;
            if(poker[i+1][1]!=num){
                ans++;
                return num;
                num=poker[i+1][1];
            }else{
                break;
            }
        }
    }
    return 0;
}
