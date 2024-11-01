#include<bits/stdc++.h>
using namespace std;
int T,n;
string s;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        if(n==1){
            puts("-1");
            continue;
        }
        s="";
        if(n%7==0){
            while(n){
                n-=7;
                s+="8";
            }
        }
        else if(n%7==1){
            n-=8;
            s+="10";
            while(n){
                n-=7;
                s+="8";
            }
        }
        else{

        }
        cout<<s<<endl;
    }
    return 0;
}
