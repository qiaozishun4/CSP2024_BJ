#include <bits/stdc++.h>
using namespace std;
int a[10]={6,2,5,5,4,5,6,3,7,6};
string f(string a,string b){
    if(a.size()<b.size()){
        return a;
    }
    if(a.size()>b.size()){
        return b;
    }
    for(int i=0;i<a.size();i++){
        if(a.size()>b.size()){
            return b;
        }
    }
    return a;
}
void solve(){
    int x;
    cin >>x;
    if(x==1){
        cout <<-1<<endl;
        return ;
    }
    string ans;
    for(int i=1;i<=9;i++){
        int cnt=x;
        string tmp="";
        if(i==1) tmp="1";
        if(i==2) tmp="2";
        if(i==3) tmp="3";
        if(i==4) tmp="4";
        if(i==5) tmp="5";
        if(i==6) tmp="6";
        if(i==7) tmp="7";
        if(i==8) tmp="8";
        if(i==9) tmp="9";
        cnt-=a[i];
        while(cnt%7!=0 && cnt>=6){
            cnt-=a[0];
            tmp+='0';
        }
        while(cnt>=7){
            tmp+='8';
            cnt-=7;
        }
        if(cnt<0){
            continue;
        }
        if(cnt!=0){
            if(cnt==1) continue;
            if(cnt==2) tmp+='1';
            if(cnt==3) tmp+='7';
            if(cnt==4) tmp+='4';
            if(cnt==5) tmp+='2';
            if(cnt==6) tmp+='0';
        }
        if(ans==""){
            ans=tmp;
        }
        ans=f(ans,tmp);
    }
    cout <<ans<<endl;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin >>t;
    while(t--){
        solve();
    }
    return 0;
}
