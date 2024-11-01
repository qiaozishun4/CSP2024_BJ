#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n_,cnt1_=0;
    char h_[55]={},z_[55]={},a_[110]={},b_[110]={};
    cin>>n_;
    bool flag_;
    for(int i_=1;i_<=n_;i_++){
        cin>>a_[i_]>>b_[i_];

        flag_=1;
        for(int j_=1;j_<=strlen(h_)+1;j_++){
            if(h_[j_]==a_[i_]&&z_[j_]==b_[i_]){
                flag_=0;
                break;
            }
        }
        if(flag_){
            h_[i_]=a_[i_];
            z_[i_]=b_[i_];

            cnt1_++;
        }
    }
    cout<<52-cnt1_;
    return 0;
}
