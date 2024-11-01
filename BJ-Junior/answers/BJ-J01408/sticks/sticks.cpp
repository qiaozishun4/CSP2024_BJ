#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int n;
    int T;
    int sy[15]={6,2,5,5,4,5,6,3,7,6};
    cin>>T;
    for(int i=1;i<=T;i++){
        cin>>n;
        if(n<2){
            cout<<"-1"<<endl;
            continue;
        }
        int yd=0;
        int dqs=1;
        while(yd!=n){
            yd=0;
            if(dqs<=9 and dqs>=1){
                yd+=sy[dqs];
            }
            else if(dqs<=99 and dqs>=10){
                yd+=sy[dqs%10];
                yd+=sy[dqs/10];
            }
            else if(dqs<=999 and dqs>=100){
                yd+=sy[dqs%10];
                yd+=sy[dqs/10%10];
                yd+=sy[dqs/100];
            }
            else if(dqs<=9999 and dqs>=1000){
                yd+=sy[dqs%10];
                yd+=sy[dqs/10%10];
                yd+=sy[dqs/100%10];
                yd+=sy[dqs/1000];
            }
            else if(dqs<=99999 and dqs>=10000){
                yd+=sy[dqs%10];
                yd+=sy[dqs/10%10];
                yd+=sy[dqs/100%10];
                yd+=sy[dqs/1000%10];
                yd+=sy[dqs/10000];
            }

            if(yd==n){
                break;
            }
            dqs++;
        }
        cout<<dqs<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}