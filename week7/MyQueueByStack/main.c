// class MyQueue {
//     stack<int> Stack1, Stack2;

//     void one2two() {
//         while (!Stack1.empty()) {
//             Stack2.push(Stack1.top());
//             Stack1.pop();
//         }
//     }
// public:
//     MyQueue() {
//     }
    
//     void push(int x) {
//         Stack1.push(x);
//     }
    
//     int pop() {
//         if (Stack2.empty()) {
//             one2two();
//         }
//         int x = Stack2.top();
//         Stack2.pop();
//         return x;
//     }
    
//     int peek() {
//         if (Stack2.empty()) {
//             one2two();
//         }
//         return Stack2.top();
//     }
    
//     bool empty() {
//          return Stack1.empty() && Stack2.empty();
//     }
// };

class MyQueue {
    //定义两个栈，栈1用来存储队列元素，栈2用来在入队操作时先将栈1的数据暂存到此处，最后再返回栈1
    stack<int> Stack1, Stack2;
public:
    MyQueue() {}
    
    void push(int x) {
        while (!Stack1.empty()) {
            Stack2.push(Stack1.top());
            Stack1.pop();
        }
        Stack1.push(x);
        while (!Stack2.empty()) {
            Stack1.push(Stack2.top());
            Stack2.pop();
        }
    }
    
    int pop() {
        int x = Stack1.top();
        Stack1.pop();
        return x;
    }
    
    int peek() {
        //此处曾写成栈2，堆栈下溢报错
        return Stack1.top();
    }
    
    bool empty() {
         return Stack1.empty();
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
