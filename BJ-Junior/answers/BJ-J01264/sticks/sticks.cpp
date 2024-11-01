#include <iostream>
using namespace std;
int a[20] = {0,-1,1,7,4,2,6,8,10,18,22,20,28,68};
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if (n<14) cout<<a[n];
        else {
            cout<<a[n%7+7];
            for (int i = 1;i<=n/7-1;i++){
                cout<<"8";
            }
        }
        cout<<endl;
    }
    return 0;
}
