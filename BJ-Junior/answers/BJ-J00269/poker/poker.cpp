#include<iostream>

using namespace std;

bool flag[1000000];

int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;

    while(n--){
        char a,b;
        cin>>a>>b;
        flag[(a<<9)|b]=true;
    }

    int cnt=0;
    for(int i=0;i<1000000;i++){
        if(flag[i])cnt++;
    }

    cout<<52-cnt;

    return 0;
}
