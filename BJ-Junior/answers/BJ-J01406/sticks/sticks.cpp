#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long T;
long long n;
int p[]={6,2,5,5,4,5,6,3,7,6};
long long min_;
long long ans[N];
long long q;
void dfs(int sum){
    if(sum==n){
        long long su=0;
        long long po=pow(10,q-1);
        for(int i=1;i<=q;i++){
            su+=ans[i]*po;
            po/=10;
        }
        min_=min(min_,su);

        return;
    }
    for(int i=0;i<=9;i++){
        if(sum+p[i]>n)continue;
        else{
            ans[++q]=i;
            int ui=q-1;
            dfs(sum+p[i]);
            q=ui;
        }
    }

}
int main(){
    freopen("skicks.in","r",stdin);
    freopen("skicks.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        min_=INT_MAX;
        bool flag=false;
        for(int i=1;i<=9;i++){
            if(n>=p[i]){
                flag=true;
                q=1;
                ans[q]=i;
                dfs(p[i]);
            }
        }
        if(!flag)cout<<-1<<endl;
        else if(min_==INT_MAX)cout<<-1<<endl;
        else cout<<min_<<endl;
    }

    return 0;
}
