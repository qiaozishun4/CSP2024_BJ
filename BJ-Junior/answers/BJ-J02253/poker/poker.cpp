#include<bits/stdc++.h>
#define f(i,a,b) for(int i = a ; i<=b ; i++)
using namespace std;
string s;
int used[60];
int n;
set<string> st;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
    cin>>n;
    f(i,1,n){
        cin>>s;
        st.insert(s);
    }
    cout<<52-st.size();
    return 0;
}
