#include<iostream>

using namespace std;

const int dabiao[22]={0,-1,1,7,4,2,6,8,10,18,22,20,28,68,88,108,188,200,208,288,688,888};
const string guilv[7]={"888","108","188","200","208","288","688"};

int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        if(n<=21)cout<<dabiao[n]<<endl;
        else{
            string ans=guilv[n%7];
            for(int i=0;i<(n-2*7-1)/7;i++)ans+='8';
            cout<<ans<<endl;
        }
    }

    return 0;
}
