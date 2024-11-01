#include<bits/stdc++.h>
using namespace std;
int a[10]={6,2,5,5,4,5,6,3,7,6},T,n;
string ans;
bool mi(string a,string b){
    if(a.size()<b.size()){
        return 0;
    }else if(a.size()>b.size()){
        return 1;
    }
    for(int i=0;i<a.size();i++){
        if(a[i]<b[i]){
            return 0;
        }else if(a[i]>b[i]){
            return 1;
        }
    }
    return 0;
}
void dfs(int n,string i){
    
    if(n==0){
    	if(ans=="-1"){
    		ans=i;
    	}
        if(mi(ans,i)){
            ans=i;
        }
        return ;
    }else{
        for(int j=0;j<=9;j++){
            if(a[j]<=n){
                string s=" ";
                s[0]=char('0'+j);
                dfs(n-a[j],i+s);
            }
        }
    }
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>T;
    while(T--){
        ans="-1";
        cin>>n;
        if(n%7==0&&n>=7){
            for(int i=1;i<=n/7;i++){
                cout<<8;
            }
            cout<<endl;
        }else if(n%7==1&&n>7){
            cout<<10;
            for(int i=1;i<(n-1)/7;i++){
                cout<<8;
            }
            cout<<endl;
        }else{
            for(int i=1;i<=9;i++){
                if(a[i]<=n){
                    string s=" ";
                    s[0]=char('0'+i);
                    dfs(n-a[i],s);
                }
            }
            cout<<ans<<endl;
        }
        
    }
    return 0;
}