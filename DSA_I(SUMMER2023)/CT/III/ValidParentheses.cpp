/*
    Given a sting 's' containing a mathematical notation with the characters
    
                        '(', ')', '{', '}', '[', ']'
    
    determine if the input string is valid. An input string is valid if:

        a. Open brackets must be closed by the smae type of brackets.
        
        b. Open brackets must be closed in the correct order.

        c. Every close bracket has a corresponding bracket of the same type.

    Examples:

        input (s) -> "1+(2*3)"
        output    -> true

        input (s) -> "1+[{4*(2-3)}-7]"
        output    -> true

        input (s) -> "1+(2/3]"
        output    -> false
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


int main()
{
    int chk;
    string str;
    bool valid = true;

    cin >> str;

    Stack *myStack = new Stack();

    //cout << str << endl;

    for (char chr : str){
        //printf("\tfrom for %c\n", chr);
    
        if (!valid)
            break;

        switch (chr){
            case '(':
                //printf("pushed %c\n", chr);
                myStack->push(1);
                break;

            case '{':
                //printf("pushed %c\n", chr);
                myStack->push(2);
                break;

            case '[':
                //printf("pushed %c\n", chr);
                myStack->push(3);
                break;

            case ')':
                chk = myStack->peek();
                //printf("GOT %c AND IN TOP %d\n", chr, chk);
                switch (chk){
                    case 1:
                        myStack->pop();
                        break;

                    default:
                        valid = false;
                }

                break;

            case '}':
                chk = myStack->peek();
                //printf("GOT %c AND IN TOP %d\n", chr, chk);
                switch (chk){
                    case 2:
                        myStack->pop();
                        break;

                    default:
                        valid = false;
                }

                break;

            case ']':
                chk = myStack->peek();
                //printf("GOT %c AND IN TOP %d\n", chr, chk);
                switch (chk){
                    case 3:
                        myStack->pop();
                        break;

                    default:
                        valid = false;
                }
        }
    }

    printf("%s\n", (valid) ? "true" : "false");

    return 0;
}
