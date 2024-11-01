#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int f(int red,int blue,int d){
    if(d==v.size()){
        return 0;
    }else{
        int ans1,ans2;
        if(red==v[d]) ans1=f(red,blue,d+1)+v[d];
        else ans1=f(v[d],blue,d+1);
        if(blue==v[d]) ans2=f(red,blue,d+1)+v[d];
        else ans2=f(red,v[d],d+1);
        return max(ans1,ans2);
    }
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        v.clear();
        for(int i=0;i<n;i++){
            int tmp;
            cin>>tmp;
            v.push_back(tmp);
        }
        cout<<f(-114514,-114514,0)<<endl;
    }
}
