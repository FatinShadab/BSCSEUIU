#include <bits/stdc++.h>

using namespace std;


class Node{
    public:
        int data;
        Node *next;

        // Constructor for Node class
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};


class Stack{
    private:
        Node *top = NULL; // Pointer to the top of the stack

    public:
        Stack() {} // Default constructor

        Stack(int data){
            this->top = new Node(data); // Constructor with initial data
        }

        // Push a new element onto the stack
        void push(int data){
            Node *newData = new Node(data); // Create a new node
            
            newData->next = this->top;      // Link the new node to the current top
            this->top = newData;            // Update the top to the new node
            
            return;
        }

        // Pop the top element from the stack and return its value
        int pop(){
            if (!this->isEmpty()){
                Node *poppedNode = this->top;      // Store the current top node
                int poppedData = poppedNode->data; // Get the data from the popped node

                this->top = poppedNode->next; // Update the top to the next node

                delete (poppedNode); // Delete the popped node from memory

                return poppedData; // Return the popped data
            }

            return -1; // Return -1 if stack is empty
        }

        // Return the value of the top element without popping it
        int peek(){
            return (!this->isEmpty()) ? this->top->data : -1; // Return top data if not empty, else -1
        }

        // Check if the stack is empty
        bool isEmpty(){
            return this->top == NULL; // Return true if top is NULL (empty), else false
        }
};


int main(){

    Stack *myStack = new Stack(0); // Create a stack with initial value 0

    for (int i = 1; i < 10; i++){
        myStack->push(i); // Push values from 1 to 9 onto the stack
    }

    while (!myStack->isEmpty()){ // Pop and print values until the stack is empty
        int topData = myStack->peek();
        
        myStack->pop();

        cout << topData << " ";
    }

    return 0;
}
