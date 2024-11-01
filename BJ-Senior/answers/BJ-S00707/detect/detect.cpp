#include<bits/stdc++.h>
using namespace std;
struct cars{
    int d,v,a,get_num = -1,lose_num = -1;
    double detect_dis = 0,lose_dis = 0;
}car[100005];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T,n,m,cnt1;
    double L,V,dec[100001];
    cin>>T;
    for(int z = 0;z<T;z++){
        cnt1 = 0;
        cin>>n>>m>>L>>V;
        for(int i = 0;i<n;i++){
            cin>>car[i].d>>car[i].v>>car[i].a;
            if(car[i].a==0){
                if(car[i].v > V) cnt1++;
            }
        }
        for(int i = 0;i<m;i++){
            cin>>dec[i];
        }
        cout<<cnt1<<" "<<m-1<<endl;
    }
    return 0;
}
