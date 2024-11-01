#include<bits/stdc++.h>
using namespace std;
int zh[10]={6,2,5,5,4,5,6,3,7,6};
void Main(){
    int n;
    cin>>n;
    if(n%7==0){
        for(int i=1;i<=n/7;i++)cout<<"8";
    }else if(n%7==1){
        if(n==1)cout<<"-1";
        else {
            cout<<"10";
            n-=8;
            for(int i=1;i<=n/7;i++)cout<<"8";
        }
    }else if(n%7==2){
        cout<<"1";
        n-=2;
        for(int i=1;i<=n/7;i++)cout<<"8";
    }else if(n%7==3){
        if(n==3)cout<<"7";
        else if(n==10)cout<<"22";
        else{
            cout<<"200";
            n-=17;
            for(int i=1;i<=n/7;i++)cout<<"8";
        }
    }else if(n%7==4){
        if(n==4)cout<<"4";
        else {
            cout<<"20";
            n-=11;
            for(int i=1;i<=n/7;i++)cout<<"8";
        }
    }else if(n%7==5){
        cout<<"2";
        n-=5;
        for(int i=1;i<=n/7;i++)cout<<"8";
    }else if(n%7==6){
        cout<<"6";
        n-=6;
        for(int i=1;i<=n/7;i++)cout<<"8";
    }
    cout<<"\n";
    return;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)Main();
    return 0;
}
