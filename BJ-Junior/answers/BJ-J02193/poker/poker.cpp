#include<bits/stdc++.h>
using namespace std;
int n,ans=52;
string card[100];//小P借Q的
string memo[100];//借过的卡片

bool check(string card){
    for(int i=1;i<=n;i++){
        if(card == memo[i]){
            return false;
        }
        return true;
    }
}

int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>card[i];
    }
    for(int i=1;i<=n;i++){
        if(check(card[i]) == true){
            memo[i] = card[i];
            ans--;
        }
    }

    cout<<ans;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
