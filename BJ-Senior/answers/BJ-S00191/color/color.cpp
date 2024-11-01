#include<bits/stdc++.h>

using namespace std;

int T;
int t[1000001];
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>T;
    while(T--){
        int maxi=INT_MIN;
        set<int> s;
        long long int n,ans=0;
        int lst[200005];
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>lst[i];
            t[lst[i]]++;
            if(t[lst[i]]>1){
                ans+=lst[i];
            }
            maxi=max(maxi,lst[i]);
        }
        cout<<ans<<endl;
        for(int i=0;i<=maxi;i++){
            t[i]=0;
        }
    }
    return 0;
}
