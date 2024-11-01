#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool a[60];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    for(int i=0;i<52;i++){
        a[i]=0;
    }
    int n=0;
    scanf("%d",&n);
    char c1,c2;
    for(int i=0;i<n;i++){
        int x=0;
        scanf("%c%c%c",&c1,&c1,&c2);
        if(c1=='C')x+=13;
        else if(c1=='H')x+=26;
        else if(c1=='S')x+=39;
        if(c2>='2' && c2<='9')x+=c2-'1';
        else if(c2=='T')x+=9;
        else if(c2=='J')x+=10;
        else if(c2=='Q')x+=11;
        else if(c2=='K')x+=12;
        a[x]=true;
    }
    int num=0;
    for(int i=0;i<52;i++){
        if(a[i]==false)num++;
    }
    printf("%d",num);
    return 0;
}
