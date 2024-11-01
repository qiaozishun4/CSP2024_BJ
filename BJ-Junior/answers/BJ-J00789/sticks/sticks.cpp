#include<bits/stdc++.h>
using namespace std;
int T;
int s[10]={6,2,5,5,4,5,6,3,7,6},ans[100001],minn;
bool f=false;
void dfs(int v,int p){
    if(f==true){
        return;
    }
    if(v==0){
        f=true;
        for(int i=1;i<p;i++){
            cout<<ans[i];
        }
        return;
    }
    if(v<2||p>minn){
        return;
    }
    if(p==1){
        for(int i=1;i<=9;i++){
            if(f==true){
                return;
            }
            if(v<s[i]){
                continue;
            }
            ans[p]=i;
            dfs(v-s[i],p+1);
        }
    }else{
        for(int i=0;i<=10;i++){
            if(f==true){
                return;
            }
            if(v<s[i]){
                continue;
            }
            ans[p]=i;
            dfs(v-s[i],p+1);
        }
    }
    return;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        f=false;
        if(n%7==0){
            minn=n/7;
        }else{
            minn=n/7+1;
        }
        dfs(n,1);
        if(f==false){
            cout<<-1;
        }
        cout<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

