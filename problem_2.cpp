/*
  面试题2：实现Singleton模式
  设计一个类，我们只能生成该类的一个实例
*/

class Singleton
{
public:
  static Singleton* getInstance(){
      if(instance==NULL){
        mtx.lock();
        if(instance==NULL){
          instance=new Singleton();
        }
        mtx.unlock();
      }
      return instance;
  }

private:
  Singleton();
  static Singleton* instance=NULL;
  static std::mutex mtx;
};
