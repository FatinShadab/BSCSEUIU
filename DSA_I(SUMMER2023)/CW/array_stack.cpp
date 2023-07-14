#include <bits/stdc++.h>
// #include <cstdlib> // to clear the screen
//#include <stdexcept> // used for exception
using namespace std;
const int MAX_SIZE = 5;

class ArrayStack{
    private:
        int memory[MAX_SIZE];
        int idxPtr = -1;

    public:
        bool allow_debug = false;

    ArrayStack(){}

    ArrayStack(int val){
        this->push(val);
    }

    ArrayStack(bool allow_debug){
        this->allow_debug = allow_debug;
    }

    ArrayStack(int val, bool allow_debug) : ArrayStack(val){
        this->allow_debug = allow_debug;
    }

    void push(int val){
        if (idxPtr < MAX_SIZE)
            this->memory[++idxPtr] = val;
        else
            throw std::invalid_argument("StackOverflow");
    }

    int pop(){
        if (!this->isEmpty())
            return this->memory[idxPtr--];
        else
            throw std::invalid_argument("StackUnderflow");
    }

    int peek(){
        if (!this->isEmpty())
            return this->memory[idxPtr];
        else
            throw std::invalid_argument("StackUnderflow");
    }

    bool isEmpty(){
        return idxPtr == -1;
    }

    void __status(){
        if (this->allow_debug){
            printf("\n=====================\n");
            printf("Memory Status :");            
            printf("\n=====================\n");

            printf("\tMAX SIZE : %d\n", MAX_SIZE);

            printf("\tidx : ");
            for (int idx = 0; idx<MAX_SIZE; idx++){
                printf("| %9d |", idx);
            }
            printf("\n\t------");
            for (int idx = 0; idx<MAX_SIZE; idx++){
                printf("-------------");
            }
            printf("\n\tele : ");
            for (int idx = 0; idx<MAX_SIZE; idx++){
                printf("|%11d|", this->memory[idx]);
            }
            printf("\n\t      ");
            for (int idx = 0; idx<MAX_SIZE; idx++){
                (this->idxPtr == idx) ? printf("      ^      "):printf("             ");
            }

            return;
        }
        throw std::invalid_argument("Debug Mode : False !");
    }
};

int main(){

    int option;

    ArrayStack* stack = new ArrayStack(true);
    // replace above by below if want to see manual tracing and vice versa 
    //ArrayStack* Stack = new ArrayStack(false);

    while (1){

        printf("\n1  | Push\n2  | Pop\n3  | Peek\n4  | Check Empty\n0  | exit\n");
        printf("Enter (0/1/2/3/4) : "); 
        scanf("%d", &option);
        printf("\n");

        switch (option){
            case 0:
                return 0;

            case 1:
                int value;

                printf("\tEnter the value : ");
                scanf("%d", &value);

                try{
                    stack->push(value);
                }
                catch (std::invalid_argument& e){
                    printf(" <!---- %s ----!> \n", e.what());
                }

                break;

            case 2:
                try{
                    printf("Poped element : %d\n", stack->pop());
                }
                catch (std::invalid_argument& e){
                    printf(" <!---- %s ----!> \n", e.what());
                }

                break;

            case 3:
                try{
                    printf("Next to pop : %d\n", stack->peek());
                }
                catch (std::invalid_argument& e){
                    printf(" <!---- %s ----!> \n", e.what());
                }

                break;
                
            case 4:
                printf("%s\n", (stack->isEmpty()) ? "The Stack is empty.\n":"The Stack isn't empty\n");
                
                break;

        }

        if (stack->allow_debug) stack->__status();
        
        printf("\nEnter to continue ...");
        getchar();
        getchar();

        // clear's the terminal window
        std::system("clear"); // if linux
        // std::system("cls"); // if windows
    }

    return 0;
}