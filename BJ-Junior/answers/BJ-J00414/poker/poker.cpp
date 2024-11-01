#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int n,ans=0;
bool f[27][56] = {0};
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i = 1;i<=n;i++){
        string str;
        cin>>str;
        if(f[str[0]-'A'][str[1]-'0']==0){
                ans++;
                //cout<<"found "<<str<<endl;
        }
        f[str[0]-'A'][str[1]-'0']=1;
    }
    cout<<52-ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

