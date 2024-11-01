#include <iostream>
#include <cstdio>
#include <set>
using namespace std;
set<char>d,c,h,s;
int n;
char ch[5];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%s",ch);
        switch(ch[0]){
            case 'D':d.insert(ch[1]);break;
            case 'C':c.insert(ch[1]);break;
            case 'H':h.insert(ch[1]);break;
            case 'S':s.insert(ch[1]);break;
        }
    }
    cout<<52-d.size()-c.size()-h.size()-s.size();
    return 0;
}