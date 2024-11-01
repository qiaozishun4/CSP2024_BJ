#include<iostream>
#include<map>
using namespace std;
map<int,int> m;
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t,n,d,cnt=0;
    cin>>t;
    while(t--){
        cin>>n;
        m.clear();
        for(int i=1;i<=n;i++){
            cin>>d;
            if(m[d]){
                m[d]--;
                cnt+=d;
            }else{
                m[d]++;
            }
        }
        cout<<cnt<<endl;
        cnt=0;
    }
}
