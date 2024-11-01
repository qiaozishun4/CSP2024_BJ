#include <bits/stdc++.h>
using namespace std;
int n,ans=52;
map<string,bool> book;
string s;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        cin>>s;
        if(book[s]==0){
            book[s]=1;
            ans--;
        }
    }
    printf("%d",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
