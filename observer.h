#pragma once

#include <list>

class IObserver {
public:
    virtual ~IObserver() {};
    virtual void Update() = 0; // TODO
};

class Subject { //TODO Здесь должно обрабатываться stdin
    std::list<IObserver*> m_listOfSubs;
public:
    Subject() {};
    ~Subject() {};

    void AddSub(IObserver* sub);
    void RemSub(IObserver* sub);
    void Notify() const;
};

class FileObserver : public IObserver {
    Subject &m_subject;
public:
    FileObserver(Subject &sub) : m_subject(sub) {}

    virtual void Update() override; // TODO: Должен выводить в file
    virtual ~FileObserver() {};

    void printTime() const; // TODO
};

class CoutObserver : public IObserver {
    Subject &m_subject;
public:
    CoutObserver(Subject &sub) : m_subject(sub) {}

    virtual void Update() override; // TODO: Должен выводить в stdout
    virtual ~CoutObserver() {};
};