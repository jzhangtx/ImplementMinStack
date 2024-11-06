// ImplementMinStack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class MinStack
{
public:
    MinStack(int capacity)
        : m_Capacity(capacity)
        , m_pArray(new int[capacity])
        , m_Size(0)
        , m_MinElement(0)
    {}

    ~MinStack()
    {
        if (m_pArray)
            delete[] m_pArray;
    }

    void push(int x)
    {
        if (m_Size == m_Capacity)
            return;

        if (m_Size == 0)
        {
            m_MinElement = x;
            m_pArray[m_Size++] = x;
        }
        else if (x < m_MinElement)
        {
            int temp = x * 2 - m_MinElement;
            m_pArray[m_Size++] = temp;
            m_MinElement = x;
        }
        else
            m_pArray[m_Size++] = x;
    }

    void pop()
    {
        if (m_Size == 0)
            return;

        if (m_pArray[--m_Size] < m_MinElement)
        {
            m_MinElement = m_MinElement * 2 - m_pArray[m_Size];
        }
    }

    int top()
    {
        if (m_pArray[m_Size - 1] < m_MinElement)
        {
            return m_MinElement;
        }
        return m_pArray[m_Size - 1];
    }

    int getMin()
    {
        return m_MinElement;
    }

private:
    int m_Capacity;
    int* m_pArray;
    int m_Size;
    int m_MinElement;
};

int main()
{
    MinStack s(10);
    s.push(3);
    s.push(8);
    s.push(1);
    s.push(2);
    s.push(-1);
    s.push(7);
    s.push(-9);

    std::cout << s.getMin() << std::endl;
    s.pop();
    std::cout << s.top() << std::endl;
    std::cout << s.getMin() << std::endl;
    s.pop();
    s.pop();
    std::cout << s.top() << std::endl;
    std::cout << s.getMin() << std::endl;
    s.pop();
    std::cout << s.top() << std::endl;
    std::cout << s.getMin() << std::endl;
    s.pop();
    std::cout << s.top() << std::endl;
    std::cout << s.getMin() << std::endl;
}
