#include<iostream>
#include<set>
#include<string>
#include<cstdio>
using namespace std;
set<string> st;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        string cur;
        cin>>cur;
        st.insert(cur);
    }
    printf("%d\n",52-st.size());
    return 0;
}