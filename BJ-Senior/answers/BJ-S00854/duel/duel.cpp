#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int N=1e5+5;
int n;
int r[N];
int cnt;
int dead[N];
void solution(){
    //n>30,r<=2;
    int one=0,two=0;
    for(int i=1;i<=n;i++){
        if(r[i]==1)one++;
        else two++;
    }
    if(one>=two)cout<<n-two;
    else cout<<two;
    return ;
}
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    int maxn=0;
    for(int i=1;i<=n;i++){
        cin>>r[i];
        maxn=max(maxn,r[i]);
    }
    if(maxn<=2&&n>30){
        solution();
        return 0;
    }
    sort(r+1,r+n+1);
    cnt=n;
    for(int i=2;i<=n;i++){
        for(int j=1;j<i;j++){
            if(r[j]<r[i]&&dead[j]==0){
                dead[j]=1;
                cnt--;
                break;
            }
        }
    }
    cout<<cnt;
    return 0;
}