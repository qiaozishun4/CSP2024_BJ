#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
size_t n,val,bucket[100005],mx[100005],siz,upto,nd,ans;
vector<size_t> arr;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(size_t i=1;i<=n;i++)
        cin>>val,++bucket[val];
    for(size_t i=1;i<=100005;i++)
        ans=max(ans,bucket[i]);
    cout<<ans<<endl;
    /*arr.push_back(0);
    for(size_t i=1;i<=100000;i++)
        if(bucket[i])
            arr.push_back(bucket[i]-1);
    siz=arr.size()-1;
    mx[siz]=arr[siz];
    for(size_t i=siz-1;i>0;i--)
        mx[i]=max(mx[i+1],arr[i]);
    /*for(size_t i=1;i<=siz;i++)
        cout<<mx[i]<<endl;*/
    /*
    for(size_t i=1;i<siz;i++){
        nd=mx[i]-mx[i+1];
        if(!nd) continue;
        else --nd;
        upto=max(upto,i)+nd;
        if(upto>=n){cout<<mx[i+1]+upto-n+1<<endl;return 0;}
    }*/
    return 0;
}
