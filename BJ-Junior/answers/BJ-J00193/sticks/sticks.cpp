#include<bits/stdc++.h>
using namespace std;
int t,n,a,b;
string s;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        a=n/7;
        b=n%7;
        if(a>1){
            string m(a-1,'8');
            s=m;
        }else s="";
        if(b==0){
            cout<<8<<s<<"\n";
        }else if(b==1){
            if(n==1)cout<<"-1\n";
            else cout<<10<<s<<"\n";
        }else if(b==2){
            if(n==2)cout<<"1\n";
            else cout<<18<<s<<"\n";
        }else if(b==3){
            if(n==3)cout<<"7\n";
            else cout<<22<<s<<"\n";
        }else if(b==4){
            if(n==4)cout<<"4\n";
            else cout<<20<<s<<"\n";
        }else if(b==5){
            if(n==5)cout<<"2\n";
            else cout<<28<<s<<"\n";
        }else{
            if(n==6)cout<<"6\n";
            else cout<<68<<s<<"\n";
    }}return 0;
}
