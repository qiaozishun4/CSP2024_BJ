#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    cin>>T;
    for(int i=1;i<=T;i++){
        int n;
        cin>>n;
        long long a[114514];
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int to[1000001];
        long long cnt=0;
        for(int i=1;i<=1000000;i++){
            to[i]=0;
        }
        for(int i=1;i<=n;i++){
            to[a[i]]+=1;
        }for(int i=1;i<=1000000;i++){
            if(to[i]>=2){
                cnt+=1l*i*(to[i]/2);


            }

        }
        cout<<cnt;
    }
}