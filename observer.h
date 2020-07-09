#pragma once

#include <list>
#include <stack>
#include <queue>
#include <memory>

class IObserver {
public:
    virtual ~IObserver() {};
    virtual void Update(std::queue<char> queue) = 0;
};

class Subject {
    std::list<std::unique_ptr<IObserver>> m_listOfSubs2;
    std::list<IObserver*> m_listOfSubs;
    std::stack<char> m_stack;
    std::queue<char> m_queue;
    int m_counter;
    int m_blockSize;
    bool isNestedBlock;
public:
    Subject(int blockSize) : m_counter(0), m_blockSize(blockSize), isNestedBlock(false) {};
    ~Subject() {};

    void AddCmd(char ch);
    void AddCmd();
    void AddSub(IObserver* sub);
    void RemSub(IObserver* sub);
    void AddSub(std::unique_ptr<IObserver> &&sub);
    void RemSub(std::unique_ptr<IObserver> &&sub);
    void Notify();
    size_t SizeOfSubs() const;
};

class FileObserver : public IObserver {
    Subject &m_subject;
public:
    FileObserver(Subject &sub) : m_subject(sub) {}

    virtual void Update(std::queue<char> queue) override;
    virtual ~FileObserver() {};

    long printTime() const;
    void printRestQueue(std::queue<char> &queue);
};

class CoutObserver : public IObserver {
    Subject &m_subject;
public:
    CoutObserver(Subject &sub) : m_subject(sub) {}

    virtual void Update(std::queue<char> queue) override;
    virtual ~CoutObserver() {};

    void printRestQueue(std::queue<char> &queue);
};