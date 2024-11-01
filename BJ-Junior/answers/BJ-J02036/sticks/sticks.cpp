#include<bits/stdc++.h>
using namespace std;
int a[7]={6,2,5,4,6,3,7};//0124678
string minn(string s,string s2){
    if(s=="n") return s2;
    if(s2=="n") return s;
    if(s.size()!=s2.size()){
        if(s.size()>s2.size()) return s2;
        else return s;
    }else{
        if(s>s2){
            return s2;
        }else{
            return s;
        }
    }

}
string f(int n,int d=0,string s="0"){
    if(n==0) return s;
    if(n<2) return "n";
    if(n%7==0){
        string ans;
        for(int i=0;i<(n/7);i++){
            ans+='8';
        }
        if(s!="0") return s+ans;
        else return ans;
    }
    if((n-1)%7==0){
        string ans;
        ans+='1';
        ans+='0';
        for(int i=0;i<n/7-1;i++){
            ans+='8';
        }
        if(s!="0") return s+ans;
        else return ans;
    }
    if(d==0){
        return minn(f(n-6,d+1,"6"),minn(f(n-2,d+1,"1"),minn(f(n-5,d+1,"2"),minn(f(n-4,d+1,"4"),minn(f(n-3,d+1,"7"),f(n-7,d+1,"8"))))));
    }else{
        return minn(f(n-6,d+1,s+'0'),minn(f(n-2,d+1,s+'1'),minn(f(n-5,d+1,s+'4'),minn(f(n-4,d+1,s+'4'),minn(f(n-3,d+1,s+'7'),f(n-7,d+1,s+'8'))))));
    }
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int n;
    cin>>n;
    while(n--){
        int m;
        cin>>m;
        string ans=f(m);
        if(ans!="n"){
            cout<<ans<<"\n";
        }else{
            cout<<-1<<"\n";
        }
    }
}
