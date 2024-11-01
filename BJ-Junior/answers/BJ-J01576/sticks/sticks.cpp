#include<bits/stdc++.h>
using namespace std;
int a[10]={6,2,5,5,4,5,6,3,7,6};
string solve(int n,int k,bool s){
    if(k==1){
        if(n>7||n<2)return "n";
        if(n==2) return "1";
        if(n==3) return "7";
        if(n==4) return "4";
        if(n==5) return "3";
        if(n==6) return "0";
        if(n==7) return "8";
    }
    for(int i=0;i<=9;i++){
        if(i==3||i==5||i==9) continue;
        if(s){
            s=false;
            if(i==0) continue;
        }else{
            if(i==6) continue;
        }
        if(n-a[i]<2||n/7+1>k) return "n";
        if(n%7==0){
            string k="";
            for(int i=1;i<=n/7;i++) k+="8";
            return k;
        }
        if(solve(n-a[i],k-1,s)!="n"){
            return char('0'+i)+solve(n-a[i],k-1,s);
        }
    }
    return "n";
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T,n=0;
    cin>>T;
    int ans[51]={0,-1,1,7,4,3,6,8,10,18,33};
    while(T--){
        cin>>n;
        //n++;
        if(n<=10){
            cout<<ans[n]<<endl;
            continue;
        }
        if(n%7==0){
            for(int i=1;i<=n/7;i++) cout<<8;
            cout<<endl;
            continue;
        }
        int k=n/7+1;
        cout<<solve(n,k,true)<<endl;
    }
    return 0;
}
