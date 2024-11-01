#include<iostream>
using namespace std;
int main(){
freopen("detect.in","r",stdin);
freopen("detect.out","w",stdout);

    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,m,l,v1,cnt1=0,cnt2=0,d[100000],v[100000],a[100000],p[100000];
        cin>>n>>m>>l>>v1;
        for(int j=0;j<n;j++){
            cin>>d[j]>>v[j]>>a[j];
        }
        for(int j=0;j<m;j++){
            cin>>p[j];
        }
        for(int j=0;j<n;j++){
            if(a[j]<=0 && v[j]<=v1) continue;
            else cnt1++;
        }
        cout<<cnt1<<" "<<cnt2;
    }


    return 0;
}
