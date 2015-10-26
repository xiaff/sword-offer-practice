/*
    面试题49：把字符串转换为整数
    将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。
*/

class Solution
{
public:
    enum Status {kValid=0,kInvalid};
    int g_nStatus=kInvalid;
     
    int StrToInt(const char* str){
        g_nStatus=kInvalid;
        long long num=0;
     
        bool minus=false;
     
        if(str!=NULL && *str!='\0'){
            while(*str==' '){
                str++;
                if(str==NULL)
                    return 0;
            }
            if(*str=='+')
                str++;
            if(*str=='-'){
                str++;
                minus=true;
            }
            if(*str!='\0')
                num=StrToIntCore(str,minus);
        }
     
        return (int)num;
    }

private:     
    long long StrToIntCore(const char* str,bool minus){
        long long num=0;
        int flag=minus?-1:1;
     
        while(*str!='\0'){
            if(*str>='0' && *str<='9'){
                num=num*10+flag*(*str-'0');
                if((!minus && num>0x7fffffff) || (minus && (signed int)num<0x80000000)){
                    num=0;
                    break;
                }
                str++;
            }
            else{
                num=0;
                break;
            }
        }
        if(*str=='\0')
            g_nStatus=kValid;
     
        return num;
    }
    
};