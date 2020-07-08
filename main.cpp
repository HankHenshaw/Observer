#include <iostream>
#include <chrono>
#include <queue>
#include <stack>
#include <thread>
#include "observer.h"

using namespace std::chrono_literals;

void printTime()
{
    /*Time since epoch*/
    auto tm = std::chrono::system_clock::now();
    std::cout << "Time Since Epoch:" << std::chrono::duration_cast<std::chrono::seconds>(tm.time_since_epoch()).count() << '\n';
}

void printRestQueue(std::queue<char> &queue)
{
    if(queue.empty()) return;

    printTime();
    while(!queue.empty())
    {
        std::cout << queue.front();
        queue.pop();
    }
    std::cout << '\n';
}

int main(int argc, char* argv[])
{
    int size;
    if(argc < 2)
    {
        
        size = 1; // Если не указано кол-во команд в пакете, то устанавливаем значение по умолчанию
    } else {
        if(atoi(argv[1]) < 1) {
            size = 1; //Если размер пакета меньше 1, то устанавливаем значение по умолчанию
        } else {
            size = atoi(argv[1]);
        }
    }

    std::queue<char> queue;
    std::stack<char> stack;
    int counter = 0;
    char temp;
    while(std::cin >> temp)
    {
        if(stack.empty() && temp == '{')
        {
            stack.push(temp);
            printRestQueue(queue);
            continue;
        } else if(temp == '{') {
            stack.push(temp);
            continue;
        } else if(temp == '}') {
            if(!stack.empty()) {
                stack.pop();
                if(stack.empty()) 
                {
                    printRestQueue(queue);
                }
            }
            continue;
        }
        queue.push(temp);

        ++counter;
        if((counter%size == 0) && (stack.empty()))
        {
            counter = 0;
            printRestQueue(queue);
        }
    }

    if(!queue.empty() && stack.empty())
    {
        printRestQueue(queue);
    }

    /*Real Code*/
    Subject subj;
    IObserver *fileOb = new FileObserver(subj);
    IObserver *coutOb = new CoutObserver(subj);

    subj.AddSub(fileOb);
    subj.AddSub(coutOb);
    /*Real Code*/

    std::cout << "\nDone\n";
    return 0;
}