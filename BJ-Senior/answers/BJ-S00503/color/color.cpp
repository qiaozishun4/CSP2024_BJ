#include<iostream>
#include<climits>
#include<functional>
using namespace std;
int main(){
	int T;
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
    cin.tie(nullptr)->sync_with_stdio(0);
    for(cin>>T;T;T--){
        int n;
        cin>>n;
        int a[n];
        bool red[n]={0};
        for(int i=0;i<n;i++) cin>>a[i];
        function<int(int)> dfs=[&](int pos){
            if(pos>=n){
                int ans=0;
                int red_pre=-1,blue_pre=-1;
                for(int i=0;i<n;i++){
                    if(red[i]){
                        if(red_pre!=-1&&a[i]==a[red_pre]) ans+=a[i];
                        red_pre=i;
                    }
                    else{
                        if(blue_pre!=-1&&a[blue_pre]==a[i]) ans+=a[i];
                        blue_pre=i;
                    }
                    if(red[i]) red_pre=i;
                    else blue_pre=i;
                }
                return ans;
            }
            int ret=INT_MIN;
            ret=max(ret,dfs(pos+1));
            red[pos]=1;
            ret=max(ret,dfs(pos+1));
            red[pos]=0;
            return ret;
        };
        cout<<dfs(0)<<'\n';
    }
}
