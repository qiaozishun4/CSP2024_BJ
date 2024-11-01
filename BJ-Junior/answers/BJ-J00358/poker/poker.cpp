#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;


char o[54] = {'m','m','m','m','m','m','m','m','m','m','m','m','m','m','m','m','m','m','m','m','m','m','m','m','m','m','m','m','m','m','m','m','m','m','m','m','m','m','m','m','m','m','m','m','m','m','m','m','m','m','m','m','m','m'};
char p[54] = {'m','m','m','m','m','m','m','m','m','m','m','m','m','m','m','m','m','m','m','m','m','m','m','m','m','m','m','m','m','m','m','m','m','m','m','m','m','m','m','m','m','m','m','m','m','m','m','m','m','m','m','m','m','m'};

bool fd(char a,char b)
{
    int i = 0;
    while(true)
    {
        if(o[i] == 'm' && p[i] == 'm')
            return false;
        if(o[i] == a && p[i] == b)
            return true;
        i ++;
    }
}

int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    scanf("%d",&n);
    int i = 0;

    int sum = 52;
    while(i < n)
    {
        char f,s,str[5];
        scanf("%s",&str);
        f = str[0];
        s = str[1];
        //printf("fd %c %c\n",f,s);
        if(!fd(f,s))
        {

            o[i] = f;
            p[i] = s;
            sum --;
        }
        i ++;
    }
    printf("%d",sum);
    return 0;
}
