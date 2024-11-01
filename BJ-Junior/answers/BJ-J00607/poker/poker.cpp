#include<iostream>
#include<string>
#include<set>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    scanf("%d",&n);
    set<string> st;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        st.insert(s);
    }
    printf("%d\n",52-st.size());
    return 0;
}