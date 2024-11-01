#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb emplace_back
ll n;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        if(n<2){
            cout<<"-1\n";
            continue;
        }
        if(n<=7){
            if(n==2)cout<<"1\n";
            else if(n==3)cout<<"7\n";
            else if(n==4)cout<<"4\n";
            else if(n==5)cout<<"2\n";
            else if(n==6)cout<<"6\n";
            else cout<<"8\n";
            continue;
        }
        int cnt=n/7;n%=7;
        if(n==1)cout<<"10",cnt--;
        else if(n==2)cout<<"1";
        else if(n==3)cout<<"22",cnt--;
        else if(n==4)cout<<"20",cnt--;
        else if(n==5)cout<<"2";
        else if(n==6)cout<<"6";
        while(cnt--)cout<<'8';
        cout<<endl;
    }
    return 0;
}
