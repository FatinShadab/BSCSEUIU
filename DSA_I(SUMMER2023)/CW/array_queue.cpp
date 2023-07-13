#include <bits/stdc++.h>
// #include <stdexcept> // used for exception
// #include <cstdlib> // to clear the screen
using namespace std;
const int MAX_SIZE = 3; // change the size as to you wish .


class ArrayQueue{
    public:
        bool allow_debug = false;

    private:
        int memory[MAX_SIZE];
        int eqPtr = 0;
        int dqPtr = 0;

    public:
        ArrayQueue(){}

        ArrayQueue(bool set_debug){
            this->allow_debug = set_debug;
        }

        ArrayQueue(int val){
            this->enqueue(val);
        }

        ArrayQueue(int val, bool set_debug) : ArrayQueue(val){
            this->allow_debug = set_debug;
        }

        void enqueue(int val){
            if (eqPtr < MAX_SIZE)
                this->memory[eqPtr++] = val;
            else{
                if (this->has_reuseable_memory()){
                    this->reuse_memory();
                    this->enqueue(val);
                }
                else
                    throw std::invalid_argument("StackOverflow");
            }
        }

        int dequeque(){
            if (!this->isEmpty()){
                int value = this->memory[dqPtr++];
                this->memory[dqPtr-1] = INT_MIN;
                return value;
            }
            else
                throw std::invalid_argument("StackUnderflow");
        }

        int peek(){
            if (!this->isEmpty())
                return this->memory[dqPtr];
            else
                throw std::invalid_argument("StackUnderflow");
        }

        bool isEmpty(){
            return (dqPtr > eqPtr) ||  (eqPtr == dqPtr);
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

                printf("\n\tele : ");
                for (int idx = 0; idx<MAX_SIZE; idx++){
                    printf("|%11d|", this->memory[idx]);
                }

                printf("\nPointer Status : \n=====================\n");
                printf("\tfront : %d\n\trear : %d\n=====================\n",
                    dqPtr, eqPtr);

                return;
            }

            throw std::invalid_argument("Debug Mode : False !");
        }

    private:
        bool has_reuseable_memory(){
            return (eqPtr - dqPtr) != MAX_SIZE;
        }

        void reuse_memory(){
            int idx;

            for (idx = 0; idx < (eqPtr - dqPtr); idx++){
                this->memory[idx] = this->dequeque();
            }
            
            eqPtr = idx;
            dqPtr = 0;
        }
};

int main(){
    int option;

    ArrayQueue* queue = new ArrayQueue(true);
    // replace above by below if want to see manual tracing and vice versa 
    //ArrayQueue* queue = new ArrayQueue(true);

    while (1){

        printf("\n1  | Enqueue\n2  | Dequeue\n3  | Peek\n4  | Check Empty\n0  | exit\n");
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
                    queue->enqueue(value);
                }
                catch (std::invalid_argument& e){
                    printf(" <!---- %s ----!> \n", e.what());
                }

                break;

            case 2:
                try{
                    printf("Dequequed element : %d\n", queue->dequeque());
                }
                catch (std::invalid_argument& e){
                    printf(" <!---- %s ----!> \n", e.what());
                }

                break;

            case 3:
                try{
                    printf("Next to dequeque : %d\n", queue->peek());
                }
                catch (std::invalid_argument& e){
                    printf(" <!---- %s ----!> \n", e.what());
                }

                break;
                
            case 4:
                printf("%s\n", (queue->isEmpty()) ? "The queue is empty.\n":"The queue isn't empty\n");
                
                break;

        }

        if (queue->allow_debug) queue->__status();
        
        printf("\nEnter to continue ...");
        getchar();
        getchar();

        // clear's the terminal window
        std::system("clear"); // if linux
        // std::system("cls"); // if windows
    }


    return 0;
}