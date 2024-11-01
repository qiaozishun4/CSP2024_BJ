#include<bits/stdc++.h>
using namespace std;
int a[100005]={};
//bool attack[100005]={};
//bool alive[100005]={};
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin >>n;
    int cnt=n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a,a+n+1);
    int fr=1,ba=2;
    while(ba<=n){
        if(a[ba]>a[fr]){
            cnt--;
            ba+=1;
            fr+=1;
        }
        else{
            ba+=1;
        }
    }
    cout <<cnt;
    return 0;
}

