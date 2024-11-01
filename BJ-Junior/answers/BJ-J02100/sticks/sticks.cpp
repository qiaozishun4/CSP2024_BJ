#include <bits/stdc++.h>
using namespace std;
int T;
string minn(string a,string b){
    for(int i=0;i<int(a.size());i++){
        if(a[i]=='A')return b;
    }
    for(int i=0;i<int(b.size());i++){
        if(b[i]=='A')return a;
    }
    if(int(a.size())>int(b.size()))return b;
    if(int(a.size())<int(b.size()))return a;
    for(int i=0;i<int(a.size());i++){
        if((a[i]-'0')>(b[i]-'0'))return b;
        if((a[i]-'0')<(b[i]-'0'))return a;
    }
    return a;
}
string dfs(int x,bool f){
    string ans="A";
    if(x==0)return "";
    if(x<2)return ans;
    if(x>=2){
        ans=minn(ans,"1"+dfs(x-2,0));
    }
    if(x>=3){
        ans=minn(ans,"7"+dfs(x-3,0));
    }
    if(x>=4){
        ans=minn(ans,"4"+dfs(x-4,0));
    }
    if(x>=5){
        ans=minn(ans,"2"+dfs(x-5,0));
    }
    if(x>=6){
        if(f==true){
            ans=minn(ans,"6"+dfs(x-6,0));
        }else{
            ans=minn(ans,"0"+dfs(x-6,0));
        }
    }
    if(x>=7){
        ans=minn(ans,"8"+dfs(x-7,0));
    }
    return ans;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        if(n%7==0){
            for(int i=1;i<=n/7;i++){
                cout<<8;
            }
            cout<<endl;
        }else if((n-1)%7==0&&n!=1){
            int sum=(n-1)/7-1;
            cout<<10;
            for(int i=1;i<=sum;i++){
                cout<<8;
            }
            cout<<endl;
        }else if(n<=100){
            string outt=dfs(n,1);
            bool flag=true;
            for(int i=0;i<int(outt.size());i++){
                if(outt[i]=='A'){
                    flag=false;
                    break;
                }
            }
            if(flag)cout<<outt<<endl;
            else cout<<-1<<endl;
        }else{
            string outt=dfs(n,1);
            bool flag=true;
            for(int i=0;i<int(outt.size());i++){
                if(outt[i]=='A'){
                    flag=false;
                    break;
                }
            }
            if(flag)cout<<outt<<endl;
            else cout<<-1<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
