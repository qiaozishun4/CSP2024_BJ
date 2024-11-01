#include<bits/stdc++.h>
using namespace std;
int main()
{
    char s;
    while(1)
    {
        cout<<"问安奕泽是不是个大聪明？"<<endl;
        cout<<"a 是 b到z 不是"<<endl;
        char a;
        cin>>a;
        if(a=='a'||a<'b'||a>'z')
        {
            while(1)
            {
                cout<<"恭喜你，答错了。叫爸爸(b)"<<endl;
                cin>>s;
                if(s=='b')break;
            }
        }
        if(a=='h')
        {
            cout<<"答对了"<<endl;
            break;
        }
        else cout<<"重新开始"<<endl;
    }
    return 0;
}//重新开始
