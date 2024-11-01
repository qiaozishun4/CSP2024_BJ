#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    int all = 52;
    char poker[n+5][3];
    char color,num;

    cin>>color>>num;
    poker[1][1] = color;
    poker[1][2] = num;
    all-=1;

    for(int i = 2;i<=n;i++){
        cin>>color>>num;
        poker[i][1] = color;
        poker[i][2] = num;
        bool flag = true;
        for(int j = 1;j<i;j++){
            if(poker[j][1] == color && poker[j][2] == num){
                flag = false;
                break;
            }
        }
        if(flag) all-=1;
    }

    cout<<all;

    return 0;
}
