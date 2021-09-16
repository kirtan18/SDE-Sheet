https://practice.geeksforgeeks.org/problems/implement-stack-using-array/1#

int a[100]; 
int top = -1;
//Function to push an integer into the stack.
void MyStack :: push(int x)
{
    top++;
    a[top] = x;
}
//Function to remove an item from top of the stack.
int MyStack :: pop()
{   
    if(top == -1){
        return -1;
    }
    int ans = a[top];
    top--;
    return ans;
}

int MyStack :: top(){
    return a[top];
}

int MyStack :: size(){
    return top+1;
}

int MyStack :: isEmpty(){
    if(top == -1)return true;
    else{
        return false;
    }
}
