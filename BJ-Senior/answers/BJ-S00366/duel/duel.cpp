#include<bits/stdc++.h>
using namespace std;
int n;
long long r[100005];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int a;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a;
        r[a]++;
    }
    long long p=0,num=n;
    for(int i=1;i<=100005;i++){
        if(r[i]!=0){
            if(p>=r[i]){
                num-=r[i];
            }else{
                num-=p;
                p=r[i];
            }
        }
    }
    cout<<num;
    return 0;
}
