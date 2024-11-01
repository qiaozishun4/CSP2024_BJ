#include<bits/stdc++.h>
using namespace std;
int p[10]={1,7,4,2,3,5,0,6,9,8};
int uses[10]={6,2,5,5,4,5,6,3,7,6};
string ans;
string r="";
int dfs(int k,int deep,int ik){
    if(k==0){
        if(r[deep-1]==0) return true;
        if(deep>ans.size()&&ans.size()!=0) return true;
        if(deep<ans.size()||ans.size()==0){
            ans="";
            for(int i=0;i<=deep-1;i++){
                ans+=r[i];
            }
            return true;
        }else{
            for(int i=0;i<ans.size();i++){
                if(r[i]<ans[i]){
                    ans="";
                    for(int i=0;i<=deep-1;i++) ans+=r[i];
                    return true;
                }else if(r[i]>ans[i]) break;
            }
            return true;
        }

    }
    int flag=0;
    for(int i=0;i<=9;i++){
        if(deep==0&&i==6) continue;
        if(k>=uses[p[i]]){
            r[deep]=p[i]+'0';
            flag+=dfs(k-uses[p[i]],deep+1,0);
        }
    }
    return flag;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        ans="";
        if(!dfs(n,0,1)){
            cout<<-1<<endl;
        }else{
            cout<<ans<<endl;
        }
    }
    return 0;
}
