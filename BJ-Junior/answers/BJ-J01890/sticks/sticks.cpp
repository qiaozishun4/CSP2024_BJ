#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
string a[N];

int num(string s){
    if(s[0]=='0') s[0]='6';
    int x=0;
    for(int i=0;i<s.size();i++){
        x=x*10+s[i]-'0';
    }
    return x;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    a[2]="1",a[3]="7",a[4]="4",a[5]="2",a[6]="0",a[7]="8";
    for(int i=8;i<=1000;i++){
        for(int j=2;j<=7;j++){
            if(i-j==1) continue;
            if(a[i].empty() || num(a[j]+a[i-j])<num(a[i])){
                a[i]=a[j]+a[i-j];
            }
        }
    }

    for(int i=2;i<=1000;i++){
        if(a[i][0]=='0'){
            a[i][0]='6';
        }
    }

    while(t--){
        int n;
        cin>>n;
        if(n==1){
            cout<<"-1"<<endl;
        }else if(n%7==0){
            for(int i=1;i<=n/7;i++){
                cout<<8;
            }
            cout<<endl;
        }else if(n%7==1){
            cout<<1;
            for(int i=1;i<=n/7;i++){
                cout<<8;
            }
            cout<<endl;
        }else{
            cout<<a[n]<<endl;
        }
    }
    return 0;
}
