class MinStack {
    stack<int> currentstack;        //定义一个当前栈
    stack<int> minstack;            //定义一个最小值栈
public:
    MinStack() {
        minstack.push(INT_MAX);
    }
    
    void push(int val) {
        currentstack.push(val);
        minstack.push(min(minstack.top(), val));        //将目前最小值与即将入push进currentstack的值比较
    }                                                   //保证minstack的栈顶元素是currentstack中的最小值
    
    void pop() {
        currentstack.pop();
        minstack.pop();                         //minstack与currentstack一起pop
    }
    
    int top() {
        return currentstack.top();
    }
    
    int getMin() {
        return minstack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
