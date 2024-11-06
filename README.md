Implement Min Stack


Implement a stack that supports the following operations in O(1) time complexity:

push(x) : Push the element x onto the stack.
pop() : Removes the element at the top of the stack.
top() : Get the topmost element of the stack.
getMin() : Get the minimum element in the stack.
Assume that pop, top and getMin will only be called on non-empty stack.

Example
push(1)
push(2)
push(-1)
getMin() → -1
pop()
top() → 2
getMin() → 1
Testing
Input Format
The first line contains an integer ‘T’, denoting the number of test cases.

For each test case, the input consists of the following lines:

First line consists of an integer ‘n’ denoting the number of operations to be performed on the stack.
The next n lines contain one of the following:
push x, where x is the element to be added to stack.
pop
top
getMin
Output Format
For each test case, one line containing space-separated values containing the results of pop, top, getMin in the order they are called.

Sample Input
1
7
push 1
push 2
push -1
getMin
pop
top
getMin
Expected Output
-1 2 1