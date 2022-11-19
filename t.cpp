#include<iostream>
#include<string>
using namespace std;
int flag;
double bigtosmall(string str){
    string dir[10];
    dir[0]="零";
    dir[1]="壹";
    dir[2]="贰";
    dir[3]="叁";
    dir[4]="肆";
    dir[5]="伍";
    dir[6]="陆";
    dir[7]="柒";
    dir[8]="捌";
    dir[9]="玖";
    int len=str.length();
    double sum=0;
    double db=1;
    double aaa=1;
    for(int i=0;i<len;i++)
    {
        if(str[i]=="拾"){
            aaa=10*db;
        }else if((string)str[i]=="佰"){
            aaa=100*db;
        }else if(str[i]=="仟"){
            aaa=1000*db;
        }
        else if (str[i]=="万")
        {
            db=10000;
            continue;
        }
        else if(str[i]=="亿")
        {
            db=100000000;
            continue;
        }
        else if(str[i]=="零")
        {
            continue;
        }
        else
        {
            for (int j=0;j<10;j++)
            {
                if (str[i]==dir[j])
                sum=sum+j*aaa;
            }
        }
    return sum;
    }

}
    int main()
    {
        string b="捌佰陆拾壹万零五";
        double a=bigtosmall(b);
        cout<<a;
    }
