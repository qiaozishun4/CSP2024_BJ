#include<iostream>
#include<cstdio>
using namespace std;

int n;
long long ans=0;
int a[100];

void dfs(int s,long long sum,string t){
    if(s==n){
        ans=max(ans,sum);
        return ;
    }

    int ti=-1,tj=-1;
    for(int i=0;i<t.size();i++){
        if(t[i]=='r') ti=i;
        if(t[i]=='b') tj=i;
    }

    if(ti==-1) dfs(s+1,sum,t+"r");
    else{
        if(a[s]!=a[ti]) dfs(s+1,sum,t+"r");
        else{
            int h=a[s];
            a[s]=a[ti];
            
            dfs(s+1,sum+a[s],t+"r");

            a[s]=h;
        }
    }
    
    if(tj==-1) dfs(s+1,sum,t+"b");
    else{
        if(a[s]!=a[tj]) dfs(s+1,sum,t+"b");
        else{
            int h=a[s];
            a[s]=a[tj];
            
            dfs(s+1,sum+a[s],t+"b");

            a[s]=h;
        }
    }
    return ;
}

int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);

    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++) cin>>a[i];

        ans=0;
        dfs(0,0,"");

        cout<<ans<<endl;
    }
    return 0;
}