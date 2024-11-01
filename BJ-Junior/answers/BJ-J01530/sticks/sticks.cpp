#include<iostream>
#include<string>
using namespace std;

int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin>>T;
    int mbs[10];
    while(T--){
        mbs[0] = 6,mbs[1] = 2,mbs[2] = 6,mbs[3] = 5,mbs[4] = 5,mbs[5] = 4,mbs[6] = 5,mbs[7] = 6,mbs[8] = 7,mbs[9] = 6;
        int n;
        cin>>n;
        int maxn = n/2 +1,num = 1;
        bool tf = 0;
        for(int i = 0;i <= maxn;i++) num *= 10;
        for(int i = 0;i <= num;i++){
            string xzs = to_string(i);
            int ymbs = 0;
            for(int i = 0;i < xzs.size();i++){
                int xzw = (int)xzs[i];
                xzw -= 48;
                ymbs += mbs[xzw];
            }
            if(tf == 0 && ymbs == n){
                cout<<i<<endl;
                tf = 1;
                break;
            }
        }
        if(tf == 0) cout<<-1<<endl;
    }
    return 0;
}
