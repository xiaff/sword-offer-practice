/*
	面试题48：不能被继承的类
	写一个不能被继承的类
*/

//1
class SealedClass1
{
public:
	static SealedClass1* getInstance(){
		return new SealedClass1();
	}

	static void deleteInstance(SealedClass1* sc){
		delete sc;
	}
private:
	SealedClass1();
	~SealedClass1();
	
};

//2
template<typename T> class MakeSealed
{
	friend T;

private:
	MakeSealed();
	~MakeSealed();
	
};

class SealedClass2:virtual public MakeSealed<SealedClass2>
{
public:
	SealedClass2();
	~SealedClass2();
	
};