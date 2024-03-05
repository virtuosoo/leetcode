#include <bits/stdc++.h>
using namespace std;

class MyQueue {
public:
stack<int> s1, s2;
    MyQueue() {
    }
    
    void moveS2ToS1() {
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }
    void push(int x) {
        s2.push(x);
    }
    
    int pop() {
        int res;
        if (s1.empty()) {
            moveS2ToS1();
        } 
        res =  s1.top();
        s1.pop();
        return res;
    }
    
    int peek() {
        int res;
        if (s1.empty()) {
            moveS2ToS1();
        } 
        res =  s1.top();
        return res;
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */