#include <iostream>
#include <string>
#include <sstream>

using namespace std;

//判断输入的字符串是否全是数字
bool allIsNum(string str)
{
    for(int i = 0; i < str.length(); i++)
    {
        int temp = int(str[i]);
        if(temp >= 48 && temp <= 57)
            continue;
        else
            return false;
    }
    return true;
}

//判断输入的IMSI是不是15个数字
bool isImsi(string imsi)
{
    int len = imsi.length();
    if(len != 15)
    {
        cout<<"It is not a imsi,please check it."<<endl;
        return false;
    }
    else if(!allIsNum(imsi))
        return false;

    cout<<"It is a right imsi."<<endl;
    return true;
}

//将输入的IMSI转换成对应手机号的前7位
string imsiToPhoneNum(string imsi)
{
    //首先判断输入的IMSI是否正确
    if(!isImsi(imsi))
        return "";
	
    string phoneNum = "";  //输出的手机号
    string result0 = "", result1 = "";

    if(imsi.substr(0,5) == "46000")
    {
        string x = imsi.substr(8,1);
        result0 = imsi.substr(5,3);
        if(x == "5" || x == "6" || x == "7" || x == "8" || x == "9")  //130开头
        {
            result1 = x;
            phoneNum = "13" + result1 + result0;
            return phoneNum;
        }
        else if(x == "0" || x == "1" || x == "2" || x == "3" || x == "4")  //13x开头
        {
            int n = atoi(x.c_str()) + 5;
            std::stringstream ssTemp;
            ssTemp<<n;
            result1 = ssTemp.str();
            string result2 = imsi.substr(9,1);
            phoneNum = "13" + result1 + result2 + result0;
            return phoneNum;
        }
    }

    if(imsi.substr(0,5) == "46001")
    {
        string front = imsi.substr(9,1);
        result0 = imsi.substr(5,3);
        result1 = imsi.substr(8,1);
        int x = atoi(front.c_str());

        switch(x)
        {
            case 0:
                phoneNum = "130" + result1 + result0;  //130开头
                return phoneNum;

            case 1:
                phoneNum = "130" + result1 + result0;  //130开头
                return phoneNum;

            case 2:
                phoneNum = "130" + result1 + result0;  //130开头
                return phoneNum;

            case 3:
                phoneNum = "156" + result1 + result0;  //156开头
                return phoneNum;

            case 4:
                phoneNum = "155" + result1 + result0;  //155开头
                return phoneNum;

            case 5:
                phoneNum = "185" + result1 + result0;  //185开头
                return phoneNum;

            case 6:
                phoneNum = "186" + result1 + result0;  //186开头
                return phoneNum;

            case 7:
                phoneNum = "145" + result1 + result0;  //145开头
                return phoneNum;

            case 8:
                phoneNum = "170" + result1 + result0;  //170开头
                return phoneNum;

            case 9:
                phoneNum = "131" + result1 + result0;  //131开头
                return phoneNum;
        }
    }

    if(imsi.substr(0,5) == "46003")
    {
        string x = imsi.substr(9,1);
        result0 = imsi.substr(5,1);
        result1 = imsi.substr(6,3);

        if(x == "7")
        {
            phoneNum = "180" + result0 + result1;  //180开头
            return phoneNum;
        }
        if(x == "8")
        {
            phoneNum = "153" + result0 + result1;  //153开头
            return phoneNum;
        }
        if(x == "9")
        {
            phoneNum = "189" + result0 + result1;  //189开头
            return phoneNum;
        }
    }
    else
    {
        result0 = imsi.substr(6,1);
        result1 = imsi.substr(7,3);
        string front = imsi.substr(0,5);
        int x = atoi(front.c_str());

        switch(x)
        {
            case 460020:
                phoneNum = "134" + result0 + result1;  //134开头
                return phoneNum;

            case 460021:
                phoneNum = "151" + result0 + result1;  //151开头
                return phoneNum;

            case 460022:
                phoneNum = "152" + result0 + result1;  //152开头
                return phoneNum;

            case 460023:
                phoneNum = "150" + result0 + result1;  //150开头
                return phoneNum;

            case 460024:
                phoneNum = "184" + result0 + result1;  //184开头
                return phoneNum;

            case 460025:
                phoneNum = "183" + result0 + result1;  //183开头
                return phoneNum;

            case 460026:
                phoneNum = "182" + result0 + result1;  //182开头
                return phoneNum;

            case 460027:
                phoneNum = "187" + result0 + result1;  //187开头
                return phoneNum;

            case 460028:
                phoneNum = "158" + result0 + result1;  //158开头
                return phoneNum;

            case 460029:
                phoneNum = "159" + result0 + result1;  //159开头
                return phoneNum;

            case 460070:
                phoneNum = "170" + result0 + result1;  //170开头
                return phoneNum;

            case 460075:
                phoneNum = "178" + result0 + result1;  //178开头
                return phoneNum;

            case 460077:
                phoneNum = "157" + result0 + result1;  //157开头
                return phoneNum;

            case 460078:
                phoneNum = "188" + result0 + result1;  //188开头
                return phoneNum;

            case 460079:
                phoneNum = "147" + result0 + result1;  //147开头
                return phoneNum;
        }
    }
    return phoneNum;
}

int main()
{
    std::string imsi = "***************";

    std::string phoneNum = imsiToPhoneNum(imsi);
    if(!phoneNum.empty())
        cout<<"The imsi is ："<<imsi<<" , the phone number is :"<<phoneNum<<"****"<<endl;
    else
        cout<<"The imsi is ："<<imsi<<" , the phone number is no found."<<endl;
    return 0;
}
