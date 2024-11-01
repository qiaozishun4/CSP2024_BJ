#include<iostream>
#include<string>
using namespace std;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin>>T;
    for(int x=1;x<=T;x++){
        int n;
        cin>>n;
        string ans;
        while(n>0){
            n-=7;
            ans+='8';
        }
        if(n<0&&n>-6)cout<<-1;
        else if(n==-6){ans.pop_back();ans.pop_back(); cout<<1<<6<<ans;}
        else cout<<ans;
        cout<<endl;
    }
    return 0;
}
