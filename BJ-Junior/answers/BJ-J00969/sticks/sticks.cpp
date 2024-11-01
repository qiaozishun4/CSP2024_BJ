#include<bits/stdc++.h>
using namespace std;
int s[19],st[8]={-1,-1,1,7,4,2,0,8};
void dfs(int stick){
    s[8]+=stick/7-1;
    stick%=7;
    stick+=7;
    if(stick==7){
        s[8]++;
        while(s[8]--)cout<<8;
        return;
    }
    int k=st[stick%7];
    if(k==-1)k=9;
    if(k==0)k=6;
    int mi=k*10+8;
    for(int i=2;i<=6;i++){
        if(stick-i>=7)continue;
        int x=st[i];
        if(x==0)x=6;
        mi=min(mi,x*10+st[stick-i]);
    }
    cout<<mi;
    if(s[0]){
        for(int i=1;i<=9;i++){
            if(s[i]){
                cout<<i;
                s[i]--;
                break;
            }
        }
        while(s[0]--)cout<<0;
    }
    for(int i=1;i<=9;i++){
        if(s[i])while(s[i]--)cout<<i;
    }
}
int main(){
	freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        if(n<2){
            cout<<-1;
        }else if(n<8){
            if(n==6)cout<<6;
            else cout<<st[n];
        }else dfs(n);
        cout<<endl;
    }
    return 0;
}
