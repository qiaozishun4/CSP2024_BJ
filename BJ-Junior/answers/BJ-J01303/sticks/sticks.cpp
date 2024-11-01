#include<bits/stdc++.h>
using namespace std;
string ret;
int flag;
bool vis[114514];
void dfs(int n){
    if(vis[n])return ;
    vis[n]=1;
    if(n==0){
        flag=1;
        return ;
    }
    if(n>=7&&!vis[n-7]){
        ret+='8';
        dfs(n-7);
        if(flag)return ;
        ret.pop_back();
    }
    if(n>=6&&!vis[n-6]){
        ret+='0';
        dfs(n-6);
        if(flag)return ;
        ret.pop_back();
    }
    if(n>=5&&!vis[n-5]){
        ret+='2';
        dfs(n-5);
        if(flag)return ;
        ret.pop_back();
    }
    if(n>=4&&!vis[n-4]){
        ret+='4';
        dfs(n-4);
        if(flag)return ;
        ret.pop_back();
    }
    if(n>=3&&!vis[n-3]){
        ret+='7';
        dfs(n-3);
        if(flag)return ;
        ret.pop_back();
    }
    if(n>=2&&!vis[n-2]){
        ret+='1';
        dfs(n-2);
        if(flag)return ;
        ret.pop_back();
    }
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdin);
    int T;
    cin>>T;
    while(T--){
		memset(vis,0,sizeof vis);
        int n;
        cin>>n;
        if(n==0||n==1){
            cout<<-1<<endl;
            continue;
        }
        if(n%7==0){
            while(n){
                cout<<8;
                n-=7;
            }
            cout<<endl;
            continue;
        }
        if(n%7==1){
            cout<<10;
            n-=8;
            while(n){
                cout<<8;
                n-=7;
            }
            cout<<endl;
            continue;
        }
        ret="";
        flag=0;
        if(n>=7&&flag==0){
            ret+='8';
            dfs(n-7);
            if(flag==0)ret.pop_back();
        }
        if(n>=6&&flag==0){
            ret+='6';
            dfs(n-6);
            if(flag==0)ret.pop_back();
        }
        if(n>=5&&flag==0){
            ret+='2';
            dfs(n-5);
            if(flag==0)ret.pop_back();
        }
        if(n>=4&&flag==0){
            ret+='4';
            dfs(n-4);
            if(flag==0)ret.pop_back();
        }
        if(n>=3&&flag==0){
            ret+='7';
            dfs(n-3);
            if(flag==0)ret.pop_back();
        }
        if(n>=2&&flag==0){
            ret+='1';
            dfs(n-2);
            if(flag==0)ret.pop_back();
        }
        if(flag==1)cout<<ret<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}