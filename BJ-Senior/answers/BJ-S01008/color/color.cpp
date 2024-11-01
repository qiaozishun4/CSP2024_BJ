#include<bits/stdc++.h>
using namespace std;
int t,n,tmpcolorans,a[229028];
int cal(vector<bool>colors){
    int mycalres=0;
    for(int i=1;i<=n;i++)for(int j=i-1;j>0;j--)if(colors[j]==colors[i])mycalres+=(a[i]==a[j])*a[i],j=0;
    return mycalres;
}
void dfs(vector<bool>nowvec){
    ((nowvec.size()==n)?(tmpcolorans=max(tmpcolorans,cal(nowvec))):(nowvec.push_back(1),dfs(nowvec),nowvec.pop_back(),nowvec.push_back(0),dfs(nowvec),nowvec.pop_back(),0));
}
int main(){
    freopen("color.in","r",stdin),freopen("color.out","w",stdout),scanf("%d",&t);
    while(t--){
        scanf("%d",&n),tmpcolorans=0;
        for(int i=1;i<=n;i++)scanf("%d",a+i);
        dfs({}),cout<<tmpcolorans<<'\n';
    }
    return 0;
}