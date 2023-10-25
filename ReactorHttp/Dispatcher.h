#pragma once
#include "Channel.h"
#include "EventLoop.h"
#include <string>
using namespace std;
class EventLoop;
class Dispatcher
{
public:
    Dispatcher(EventLoop* evloop);
    virtual ~Dispatcher();
    // 添加
    virtual int add();
    //如果写virtual int add()=0; 这是定义为纯虚函数，包含纯虚函数的类为抽象类，
    //抽象类不能实例化，不能创立类对象，在当前项目中恰好不需要创立类对象，也可以这么写
    // 删除
    virtual int remove();
    // 修改
    virtual int modify();
    // 事件监测 
    virtual int dispatch(int timeout = 2); // 单位: s
    inline void setChannel(Channel* channel)
    {
        m_channel = channel;
    }
protected:
    string m_name = string();
    Channel* m_channel;
    EventLoop* m_evLoop;
};