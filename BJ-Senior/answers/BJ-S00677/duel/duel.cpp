#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
#define MAXM
int n;
int t[MAXN];
void work(){
    int lst=0;
    for(int i=1;i<MAXN;i++){
        if(lst<=t[i]){
            lst=t[i];
        }
    }
    cout<<lst<<endl;
    return ;
}
void init(){
    cin>>n;
    for(int i=1,r;i<=n;i++){
        cin>>r;
        t[r]++;
    }
    work();
    return ;
}
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    init();
    return 0;
}