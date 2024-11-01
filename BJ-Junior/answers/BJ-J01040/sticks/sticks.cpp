//PASS
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,cnt[10]={6,2,5,5,4,5,6,3,7,6};
string eight(int x){
    if(x<=0)return "";
    string ret;
    while(x--)ret+="8";
    return ret;
}
string ans="-1";
bool smaller(string x,string y){
    if(y=="-1")return 1;
    if(x.size()==y.size())return x<y;
    return x.size()<y.size();
}
void dfs(int x,string y){
    if(x==0){
        if(smaller(y,ans)){
            ans=y;
        }
        return ;
    }
    if(!smaller(y,ans))return ;
    for(int i=0;i<10;i++){
        if(cnt[i]>x)continue;
        if(y==""&&i==0)continue;
        dfs(x-cnt[i],y+(char)('0'+i));
    }
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        if(n<14){
            ans="-1";
            dfs(n,"");
            cout<<ans<<"\n";
            continue;
        }
        int tmp=n/7;
        ans="";
        if(n%7==0){
            ans=""+eight(tmp);
        }
        else if(n%7==1){
            ans="10"+eight(tmp-1);
        }
        else if(n%7==2){
            ans="1"+eight(tmp);
        }
        else if(n%7==3){
            ans="200"+eight(tmp-2);
        }
        else if(n%7==4){
            ans="20"+eight(tmp-1);
        }
        else if(n%7==5){
            ans="2"+eight(tmp);
        }
        else{
            ans="6"+eight(tmp);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
