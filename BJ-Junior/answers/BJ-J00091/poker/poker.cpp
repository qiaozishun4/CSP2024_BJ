#include<iostream>
#include<string>
using namespace std;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    string all[100];
    string a;
    int n,cnt;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>a;
        for (int j=0;j<=i;j++){
            if (a==all[j]) cnt-=1;
        }
        all[i]=a;
        cnt+=1;

    }
    cout<<52-cnt;
    return 0;
}
