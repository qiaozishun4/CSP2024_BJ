#include<bits/stdc++.h>
using namespace std;
int t;
void solve(){
    int n;
    cin>>n;
    if(n==1){
        cout<<"-1"<<'\n';
        return;
    }
    if(n==2){
        cout<<"1"<<'\n';
        return;
    }
    if(n==3){
        cout<<"7"<<'\n';
        return;
    }
    if(n==4){
        cout<<"4"<<'\n';
        return;
    }
    if(n==5){
        cout<<"2"<<'\n';
        return;
    }
    if(n==6){
        cout<<"6"<<'\n';
        return;
    }
    if(n==7){
        cout<<"8"<<'\n';
        return;
    }
    if(n==8){
        cout<<"10"<<'\n';
        return;
    }
    if(n==9){
        cout<<"18"<<'\n';
        return;
    }
    if(n==10){
        cout<<"22"<<'\n';
        return;
    }
    if(n==11){
        cout<<"20"<<'\n';
        return;
    }
    if(n==12){
        cout<<"28"<<'\n';
        return;
    }
    if(n==13){
        cout<<"68"<<'\n';
        return;
    }
    if(n==14){
        cout<<"88"<<'\n';
        return;
    }
    int wei=(n-1)/7-2;
    if(n%7==1)cout<<"108";
    if(n%7==2)cout<<"188";
    if(n%7==3)cout<<"200";
    if(n%7==4)cout<<"208";
    if(n%7==5)cout<<"288";
    if(n%7==6)cout<<"688";
    if(n%7==0)cout<<"888";
    while(wei--)cout<<"8";
    cout<<'\n';
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--)solve();
    return 0;
}