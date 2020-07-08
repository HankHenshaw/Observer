#include "observer.h"
#include <iostream>
#include <chrono>
#include <algorithm>

void Subject::Notify() const
{
    std::for_each(m_listOfSubs.begin(), m_listOfSubs.end(), [](const auto& sub){sub->Update();}); // TODO: Проверить
}

void Subject::AddSub(IObserver *sub)
{
    m_listOfSubs.push_back(sub);
}

void Subject::RemSub(IObserver *sub)
{
    auto it = std::find(m_listOfSubs.begin(), m_listOfSubs.end(), sub);
    if(it == m_listOfSubs.end())
    {
        throw std::logic_error("Subscriber not found\n");
    } else {
        m_listOfSubs.erase(it);
    }
}

void FileObserver::printTime() const
{
    auto tm = std::chrono::system_clock::now();
    std::cout << "Time Since Epoch:" << std::chrono::duration_cast<std::chrono::seconds>(tm.time_since_epoch()).count() << '\n';
    //TODO Перенаправить ^ в файл
}

void FileObserver::Update()
{

}

void CoutObserver::Update()
{
    
}