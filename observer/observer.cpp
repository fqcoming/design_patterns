
/**************************************
 * 学习了腾讯课堂石磊老师课程总结的代码
 **************************************/


#include <iostream>
#include <string>
#include <unordered_map>
#include <list>


// 行为型模式：主要关注的是对象之间的通信
// 观察者-监听者模式(发布-订阅模式):
// 主要关注的是对象的一对多关系，也就是多个对象都依赖一个对象，
// 当该对象的状态发生改变时，其它对象都能够接收到相应的通知

// 例如：
// 一组数据（数据对象）=> 曲线图（对象1）、柱状图（对象2）、圆饼图（对象3）
// 当数据对象改变时，对象1、对象2、对象3应该及时的收到相应的通知。


class Observer {
public:
    virtual void handleMessage(int msgid) = 0;  // 处理消息的接口
};


class Observer1 : public Observer {
public:
    virtual void handleMessage(int msgid) {
        switch (msgid) {
        case 1:
            std::cout << "Observer1 recv 1 msg!" << std::endl;
            break;
        case 2:
            std::cout << "Observer1 recv 2 msg!" << std::endl;
            break;
        default:
            std::cout << "Observer1 recv unknown msg!" << std::endl;
            break;
        }
    }
};


class Observer2 : public Observer {
public:
    virtual void handleMessage(int msgid) {
        switch (msgid) {
        case 2:
            std::cout << "Observer2 recv 2 msg!" << std::endl;
            break;
        default:
            std::cout << "Observer2 recv unknown msg!" << std::endl;
            break;
        }
    }
};


class Observer3 : public Observer {
public:
    virtual void handleMessage(int msgid) {
        switch (msgid) {
        case 1:
            std::cout << "Observer3 recv 1 msg!" << std::endl;
            break;
        case 3:
            std::cout << "Observer3 recv 3 msg!" << std::endl;
            break;
        default:
            std::cout << "Observer3 recv unknown msg!" << std::endl;
            break;
        }
    }
};


class Subject {
public:
    void addObserver(Observer* obser, int msgid) {
        _subMap[msgid].push_back(obser);
    }
    // 主题检测发生改变，通知相应的观察者对象处理事件
    void dispatch(int msgid) {
        auto it = _subMap.find(msgid);
        if (it != _subMap.end()) {
            for (Observer *pObser : it->second) {
                pObser->handleMessage(msgid);
            }
        }
    }

private:
    std::unordered_map<int, std::list<Observer*>> _subMap;
};



// g++ -o observer observer.cpp -std=c++11

int main(int argc, char *argv[]) {

    Subject subject;
    Observer *pObser1 = new Observer1();
    Observer *pObser2 = new Observer2();
    Observer *pObser3 = new Observer3();

    subject.addObserver(pObser1, 1);
    subject.addObserver(pObser1, 2);
    subject.addObserver(pObser2, 2);
    subject.addObserver(pObser3, 1);
    subject.addObserver(pObser3, 3);

    subject.dispatch(1);
    subject.dispatch(2);
    subject.dispatch(3);
    subject.dispatch(4);


    for ( ; ; ) {
        int msgid;
        std::cout << "enter msgid: ";
        std::cin >> msgid;
        subject.dispatch(msgid);
    }


    return 0;
}
