#include<bits/stdc++.h>
using namespace std;
int n,cnt,sum;
char ch[501];
char ch3[3];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    int i=0;
    while(n--){
        cin>>ch3;
        ch[i]=ch3[0];
        i++;
        ch[i]=ch3[1];
        i++;
        for(i;i>=0;i-=2){
             if(ch3[0]==ch[i-2]&&ch3[1]==ch[i-1]){
                  cnt++;
            }
             if(cnt>=2){
               cnt=1;
             }

         }
        sum+=cnt;
    }
    cout<<52-sum;
    return 0;
}
