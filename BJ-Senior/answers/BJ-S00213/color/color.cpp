#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N]={};
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n,maxn=INT_MIN,cnt=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            int s;
            cin>>s;
            a[s]++;
            if(s>maxn) maxn=s;
        }
        for(int i=1;i<=maxn;i++){
            if(a[i]>1) cnt+=(a[i]-1)*i;
            else cnt+=0;
        }
        cout<<cnt<<endl;
        for(int i=1;i<=maxn;i++){
            a[i]=0;
        }
    }
    return 0;
}