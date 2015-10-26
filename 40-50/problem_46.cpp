/*
    面试题46:求1+2+3+....+n
    求1+2+3+...+n，要求不能使用乘除法，
    for,while,if,else,switch,case等关键字及条件判断语句(a?b:c)。
*/

/*
1. 使用构造函数
*/

class Temp
{
public:
    static int N=0;
    static int Sum=0;

    Temp(){
        N++;
        Sum+=N;
    }

    static void Reset(){
        N=0;
        Sum=0;
    }

    static int getSum(){
        return Sum;
    }
    
};

int getSum1(int n){
    Temp t[n];
    int sum=Temp::getSum();
    delete[] t;
    t=NULL;
    Temp::Reset();

    return sum;
}

/*
2. 利用纯虚函数
*/

class A
{
public:
    virtual unsigned int Sum(unsigned int n){
        return 0;
    }
};

A* array[2];

class B:public A
{
public:
    virtual unsigned int Sum(unsigned int n){
        return A[!(!n)]->Sum(n-1)+n;
    }
    
};

int getSum2(int n){
    A a;
    B b;
    array[0]=&a;
    array[1]=&b;
    return array[1]->Sum(n);
}

/*
3. 利用函数指针
*/
typedef unsigned int (*fun)(unsigned int)

unsigned int Sum_Terminator(unsigned int n){
    return 0;
}

unsigned int Sum_3(unsigned int n){
    static fun f[2]={Sum_Terminator,Sum_3};
    return f[!(!n)](n-1)+n;
}

/*
4. 利用模板类型
*/

template<unsigned int n>struct Sum_4
{
    enum Value
    {
        N=Sum_4<n-1>::N+n;
    };
};

template<> struct Sum_4<1>
{
    enum Value
    {
        N=1;
    };
    
};