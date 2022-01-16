class MyStack {
public:
    queue<int> queue1;
    queue<int> queue2;
    MyStack() {
    }

    void push(int x) {
        queue2.push(x);
        while (!queue1.empty()) {   //将队1的元素全都压入队2
            queue2.push(queue1.front());
            queue1.pop();
        }
        //然后交换队1队2，因为队2还是要来当辅助队列，队1是栈里面的存的元素
        swap(queue1, queue2);
    }
    
    int pop() {         //取队1的最前面元素，也就是栈顶元素
        int temp = queue1.front();
        queue1.pop();
        return temp;
    }
    
    int top() {
        return queue1.front();
    }
    
    bool empty() {
        return queue1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
