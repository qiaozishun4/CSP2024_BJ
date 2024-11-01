#include<bits/stdc++.h>
using namespace std;
long long n,l,V,d[3010],v[3010],a[3010];
long long m;
long long t;
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    for(int h=1;h<=t;h++){
        int num=0;
        cin>>n>>m>>l>>V;
        for(int i=1;i<=n;i++){
            cin>>d[i]>>v[i]>>a[i];
            if(v[i]>V){
                num++;
            }
        }
        for(int i=1;i<=m;i++){
            int x;
            cin>>x;
        }
        cout<<num<<" "<<m-1;
    }

    return 0;
}
