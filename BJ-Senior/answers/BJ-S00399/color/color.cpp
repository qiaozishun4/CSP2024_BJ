#include<bits/stdc++.h>
using namespace std;
int t;
struct {
    int n;
    int ans;
    int a[1000000];
}a[15];
int main()
{
    ifstream fin("color.in",ios::in);
    ofstream fout("color.out",ios::out);
    fin>>t;
    for(int i=0;i<t;i++)
    {
        fin>>a[i].n;
        for(int j=0;j<n;j++)
            fin>>a[i].a[j];
    }
    for(int i=0;i<t;i++)
    {
        bool rt=0,bt=0;
        int red,blue;
        for(int j=0;j<a[i].n;j++)
        {
            if(rt==1&&red==a[i]){a[i].ans+=a[i].a[i];rt==0;}
            else if(bt==1&&blue==a[i]){a[i].ans+=a[i].a[i];bt==0;}
            else if(rt==0){rt=1;red=a[i];}
            else if(bt==0){bt=1;blue=a[i];}
            else red=a[i];
        }
    }
    for(int i=0;i<t;i++)fout<<a[i].ans<<endl;
    fin.close();
    fout.close();
    return 0;
}
