#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
vector<int> v;
int n,a[100005],ans=0;
void suan(){
    int c[100005]={0},sum=0;
    for(int i=0;i<n;i++){
        for(int j=i-1;j>=0;j--){
            if(v[i]==v[j]){
                if(a[i]==a[j]){
                    c[i]=a[i];
                }
                else{
                    c[i]=0;
                }
                break;
            }
        }
        sum+=c[i];
    }
    ans=max(ans,sum);
}
void fun(int x){
    if(x==n){
        suan();
        return;
    }
    v.push_back(1);
    fun(x+1);
    v.pop_back();
    v.push_back(0);
    fun(x+1);
    v.pop_back();
}
using namespace std;
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        ans=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        fun(0);
        cout<<ans<<endl;
    }
}
