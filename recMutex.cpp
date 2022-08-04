#include <chrono>
#include <iostream>
#include <thread>
#include <mutex>
 
class X {
    std::recursive_mutex m;
    std::string shared;
    volatile int i=0;
  public:
    void fun1(const std::string& caller) {
      std::this_thread::sleep_for(std::chrono::seconds(1));
      shared = "fun1";
      std::lock_guard<std::recursive_mutex> lk(m);
      std::cout << caller << "in fun1, shared variable is now " << shared << '\n';
    }
    void fun2() {
      std::lock_guard<std::recursive_mutex> lk(m);
      shared = "fun2";
      std::cout << "in fun2, shared variable is now " << shared << '\n';
      fun1("fun2 is calling:"); // recursive lock becomes useful here
      std::cout << "back in fun2, shared variable is " << shared << '\n';
    };
};
 
int main() 
{
    X x;
    //std::thread t1(&X::fun1, &x, "main is calling:");
    std::thread t2(&X::fun2, &x);
    //t1.join();
    t2.join();
}
