#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int N=1e5+5;
int t,n,m,l,V,d[N],v[N],a[N],p[N],cnt;
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);

    cin>>t;
    while(t--){
        cnt=0;
        cin>>n>>m>>l>>V;
        for(int i=0;i<n;i++){
            cin>>d[i]>>v[i]>>a[i];
        }
        for(int i=0;i<m;i++){
            cin>>p[i];
        }
        sort(p,p+m);
        for(int i=0;i<n;i++){
            if(v[i]>V&&d[i]<=p[m-1]){
                cnt++;
            }
        }
        cout<<cnt<<" ";
        if(cnt) m--;
        cout<<m<<endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}