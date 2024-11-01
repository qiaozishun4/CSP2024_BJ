#include<bits/stdc++.h>
using namespace std;
char st[9]={'1','7','4','2'}
int main(){
    freopen("sticks.out","w",stdout);
    freopen("sticks.in","r",stdin);
    int n;
    cin>>n;
    for(int u=1;u<=n;u++){
        cint t;
        cin>>t;
        string s="";
        if(t%7==0){
            t-=2;
            s+='1';
            if(t%6==1){
                for(int i=1;i<t/6;i++)s+='0';
                s+='8';
            }else{
                for(int i=1;i<=t/6;i++) s+='0';
            }
            cout<<s<<endl;
        }
    }
return 0;
}