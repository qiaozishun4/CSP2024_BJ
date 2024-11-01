#include <iostream>
#include <algorithm>
using namespace std;
int T,n,m,L,V,cnt;
int d[100005],v[1005],a[1005];
int c=1;
int p[100005];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n>>m>>L>>V;
        cnt=0;
        for(int i=1;i<=n;i++){
            cin>>d[i]>>v[i]>>a[i];
            if(v[i]>V){
                cnt++;
            }
        }
        for(int i=1;i<=m;i++){
            cin>>p[i];
        }
        cout<<cnt<<" ";
        if(cnt){
            cout<<m-1<<endl;
        }
        else{
            cout<<m<<endl;
        }



    }
        return 0;




}