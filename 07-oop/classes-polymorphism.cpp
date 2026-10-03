/*
 * 07 类 / 继承 / 多态
 * 一句话要点：基类函数前面加 virtual 才有多态；派生类写同名同参数的函数叫"重写"；
 * 同一句 w.work() 在运行时根据对象真实类型决定跑哪个版本，这才是"多态"；
 * 纯虚函数（= 0）只定规矩不实现，带它的类不能实例化，只能当接口用。
 */
#include <iostream>
#include <string>
using namespace std;

// ============ 基类 ============
class Worker {
public:
    Worker(const string& n, double s) : name(n), salary(s) {}
    virtual ~Worker() {}                 // 基类析构函数加 virtual，是习惯

    virtual void work() {                // virtual：为多态留口子
        cout << name << " 在上班" << endl;
    }
    string getName() const { return name; }
    double getSalary() const { return salary; }

protected:
    string name;
    double salary;                       // protected：子类能摸，外面不能碰
};

// ============ 派生类 1：继承 ============
class Engineer : public Worker {
public:
    Engineer(const string& n, double s) : Worker(n, s) {}
    void work() {                        // 重写基类的 work()
        cout << name << " 在写 C++ 代码，月薪 " << salary << endl;
    }
};

// ============ 派生类 2：继续往下继承 ============
class RoboMasterPlayer : public Engineer {
public:
    RoboMasterPlayer(const string& n, double s) : Engineer(n, s) {}
    void work() {
        cout << name << " 在调机器人电机，月薪 " << salary << endl;
    }
};

// ============ 多态：同一句调用，跑不同实现 ============
void makeEveryoneWork(Worker& w) {       // 用基类引用接派生类对象
    w.work();
}

int main() {
    Worker w("张三", 8000);
    Engineer e("李四", 12000);
    RoboMasterPlayer r("邦邦", 15000);

    // 正常调用：看变量的类型
    w.work();                            // 张三 在上班
    e.work();                            // 李四 在写 C++ 代码
    r.work();                            // 邦邦 在调机器人电机

    // 多态：变量是基类类型，但绑定的是派生类对象 -> 跑派生类的实现
    Worker& p = r;
    p.work();                            // 打印的还是"在调机器人电机"

    cout << "用函数统一调度:" << endl;
    makeEveryoneWork(w);
    makeEveryoneWork(e);
    makeEveryoneWork(r);                 // 三个都各自干各自的活

    // ============ 纯抽象类 ============
    class Shape {
    public:
        virtual double area() const = 0; // 纯虚：只定规矩，不写实现
        virtual ~Shape() {}
    };
    // Shape s;   // 报错：抽象类不能实例化，只能拿来当接口

    return 0;
}
