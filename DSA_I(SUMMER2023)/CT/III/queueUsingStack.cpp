/*
    Implement a queue using only two stacks. The implemented queue should
    support all the functions of a normal queue,

            i) push / enqueue
            ii) peek / peek
            iii) pop / dequeue
            iV) empty

    hint : consider reverse stack.
*/

#include <iostream>
#include <stdbool.h>

using namespace std;

class Node{
    public:
        int data;
        Node *next;

    public:
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

class Stack{
    private:
        Node *top = NULL;

    public:
        Stack() {}

        void push(int data){
            Node *newNode = new Node(data);

            newNode->next = this->top;
            this->top = newNode;

            return;
        }

        void pop(){
            if (this->isEmpty()){
                return;
            }

            Node *toBePoped = this->top;

            this->top = toBePoped->next;
            delete (toBePoped);

            return;
        }

        int peek(){
            return (this->isEmpty()) ? -1 : this->top->data;
        }

        bool isEmpty(){
            return (this->top == NULL);
        }
};

class Queue{
    private:
        Stack *enQueueHandler;
        Stack *deQueueHandler;

        void setDeQueueHandler(){
            while (!this->enQueueHandler->isEmpty()){
                this->deQueueHandler->push(this->enQueueHandler->peek());
                this->enQueueHandler->pop();
            }

            return;
        }

        void setEnQueueHandler(){
            while (!this->deQueueHandler->isEmpty()){
                this->enQueueHandler->push(this->deQueueHandler->peek());
                this->deQueueHandler->pop();
            }

            return;
        }

    public:
        Queue(){
            this->enQueueHandler = new Stack();
            this->deQueueHandler = new Stack();
        }

        void enQueue(int data){
            this->setEnQueueHandler();

            this->enQueueHandler->push(data);

            return;
        }

        void deQueue(){
            if (this->isEmpty()){
                return;
            }

            this->deQueueHandler->pop();

            return;
        }

        int peek(){
            if (this->isEmpty()){
                return -1;
            }

            return this->deQueueHandler->peek();
        }

        bool isEmpty(){
            this->setDeQueueHandler();
            return this->deQueueHandler->isEmpty();
        }
};

int main(){

    Queue *myQ = new Queue();

    for (int data = 1; data < 10; myQ->enQueue(data++));

    while (!myQ->isEmpty()){
        printf("%d ", myQ->peek());
        myQ->deQueue();
    }

    myQ->enQueue(10);
    myQ->enQueue(20);
    myQ->enQueue(30);
    myQ->deQueue();
    myQ->enQueue(500);

    while (!myQ->isEmpty()){
        printf("%d ", myQ->peek());
        myQ->deQueue();
    }

    return 0;
}
