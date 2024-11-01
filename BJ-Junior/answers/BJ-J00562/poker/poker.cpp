#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    string pokers[53];
    int n;
    cin>>n;
    string your_poker;
    bool x;
    int poker_size=0;
    if(n==1){
        cin>>your_poker;
        cout<<51<<endl;
        return 0;
    }else{
        for(int i=1;i<=n;i++){
            cin>>your_poker;
            x=false;
            for(int j=1;j<=poker_size;j++){
                if(pokers[j]==your_poker){
                    x=true;
                }
            }
            if(!x){
                poker_size++;
                pokers[poker_size]=your_poker;
            }
        }
        cout<<52-poker_size;
    }

    return 0;
}
