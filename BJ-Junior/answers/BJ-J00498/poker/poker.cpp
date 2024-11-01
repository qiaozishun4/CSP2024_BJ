#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,len=1;
    cin>>n;
    string s,s1;
    cin>>s;
    while(n-2>=0)
    {
        cin>>s1;
        if(s[0]==s1[0]&&s[1]==s1[1]){
            len+=0;
        }
        else{
            len++;
        }
        s=s1;
        n--;
    }
    cout<<(52-len)<<endl;
    return 0;
}