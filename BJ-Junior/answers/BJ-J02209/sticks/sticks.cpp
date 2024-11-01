#include <iostream>
using namespace std;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int oto50[100]={-1,-1,1,7,4,2,6,8,10,18,22,
                    20,28,68,88};
    int modt[10]={8,10,18,22,20,28,68};
    int T;
    cin>>T;
    for(int i=1; i<=T; i++){
        int n;
        cin>>n;
        if(n<=14){
            cout<<oto50[n]<<endl;
            continue;
        }
        int modd=n-n/7*7;
        cout<<modt[modd];
        for(int j=1; j<=n/7-1; j++){
                cout<<8;
            }
        cout<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
