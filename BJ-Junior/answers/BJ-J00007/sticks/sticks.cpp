#include<bits/stdc++.h>
using namespace std;
string solve(int n){
        if(n<2)return "-1";
        else if(n==2) return "1";
        else if(n==3) return "7";
        else if(n==4) return "4";
        else if(n==5) return "2";
        else if(n==6) return "6";
        else if(n==7) return "8";
        else if(n==8) return "10";
        else if(n==9) return "18";
        else if(n==10) return "22";
        else if(n==11) return "20";
        else if(n==12) return "28";
        else if(n==13) return "68";
        else{
            string gg="",g="";
            for(int i=1;i<=n/7-1;i++) gg+='8';
            g=solve(n%7+7)+gg;
            return g;
        }
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<solve(n)<<'\n';
    }
    return 0;
}
