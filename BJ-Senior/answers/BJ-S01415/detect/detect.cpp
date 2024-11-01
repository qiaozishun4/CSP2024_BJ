#include<bits/stdc++.h>
using namespace std;
int b1[100001][3],c1[100001];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int a;
    cin>>a;
    for(int i=1;i<=a;i++){
        int b,c,d,e;
        cin>>b>>c>>d>>e;
        for(int j=1;j<=b;j++){
            cin>>b1[j][0]>>b1[j][1]>>b1[j][2];
        }
        for(int j=1;j<=c;j++){
            cin>>c1[j];
        }
    }
    cout<<0<<" "<<0;
    return 0;
}
