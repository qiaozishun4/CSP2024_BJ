#include<iostream>
#include<map>
using namespace std;
int n;
string a[53];
map<string,int> b;
int ans=0;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
//    for(int i=1;i<=n;i++)cout<<a[i]<<" ";
//    cout<<endl;
    for(int i=1;i<=n;i++){
        if(b[a[i]]==0){
 //           cout<<a[i]<<" "<<b[a[i]]<<endl;
            b[a[i]]=1;
            ans++;
        }
    }
    cout<<(52-ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
