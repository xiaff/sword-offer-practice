/*
  面试题1：复制运算符函数
  为 CMyString类型添加赋值运算符函数。
*/
class CMyString
{
public:
  CMyString(char* pData=NULL);
  CMyString(const CMyString& str);
  ~CMyString(void);

  CMyString& operator=(const CMyString &str){
    if(this!=&str){
      CMyString tempString(str);

      char* tempData=tempString.m_pData;
      tempString.m_pData=m_pData;
      m_pData=tempData;
    }
    return *this;
  }

private:
  char* m_pData;

}
