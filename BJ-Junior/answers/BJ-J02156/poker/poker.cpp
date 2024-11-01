#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    string s[55];
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    int x = 0;
    string u[55];
    for(int i=1;i<=n;i++){
        bool flag = true;
        for(int j=1;j<=x;j++){
            if(s[i] == s[j]){
                flag = false;
                break;
            }
        }
        if(flag == true) x++;
    }
    cout<<52-x<<endl;
    return 0;
}
