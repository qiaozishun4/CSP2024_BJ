#include <fstream>
#include <string>
#include <cstring>
using namespace std;
ifstream cin("sticks.in");
ofstream cout("sticks.out");
string newans,strans,maxstr;
int pai[60]={0,-1,1,7,4,2,6,8,10,18,22,20,28,68,88,108,188,200,208,288,688,888,1088,1888,2008,2088,2888,6888,8888,10888,18888,20088,20888,28888,68888,88888,108888,188888,200888,208888,288888,688888,888888,1088888,1888888,2008888,2088888,2888888,6888888,8888888,10888888,18888888,20088888,20888888,28888888,68888888,88888888,0,0,0};
int cd[10];
int T,n;
bool apart(int llp)
{
    if(llp==1)
    {
        cd[9]=14286;
    }
    int lin=pai[llp];
    while(lin>0)
    {
        int u=lin%10;
        lin/=10;
        cd[u]++;
    }
    return true;
}
string ciallo(string s1,string s2)
{
    if(s1.length()<s2.length())
        return s1;
    if(s1.length()>s2.length())
        return s2;
    if(s1.length()==s2.length())
    {
        if(s1<s2)
            return s1;
        if(s2<s1)
            return s2;
    }
    return s1;
}
string opbuild()
{
    string str="";
    bool opt=0;
    for(int p=1;p<=9;p++)
    {
        if(cd[p]!=0)
        {
            cd[p]--;
            str+=char(p+'0');
            opt=1;
            break;
        }
    }
    if(opt==0)
    {
        str=maxstr;
        return str;
    }
    while(cd[0]>0)
    {
        cd[0]--;
        str+='0';
    }
    for(int p=1;p<=9;p++)
    {
        while(cd[p]>0)
        {
            cd[p]--;
            str+=char(p+'0');
        }
    }
    return str;
}
int main()
{
     for(int p=1;p<=2381;p++)
    {
        maxstr+="999999";
    }
    cin>>T;
    while(T--)
    {
        strans=maxstr;
        cin>>n;
        if(n<=56)
        {
            cout<<pai[n]<<endl;
            continue;
        }
        int lpo=n%7;
        int opl=n/7;
        while(lpo<=56)
        {
            memset(cd,0,sizeof(cd));
            bool un=apart(lpo);
            if(un==false)
                continue;
            cd[8]+=opl;
            newans=opbuild();
            strans=ciallo(strans,newans);
            opl--;
            lpo+=7;
        }
        cout<<strans<<endl;
    }
    return 0;
}
