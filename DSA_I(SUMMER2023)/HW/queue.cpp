#include <bits/stdc++.h>
using namespace std;

// Define a Node class for a singly linked list
class Node {
    public:
        int data;
        Node* next;

        // Constructor to initialize data and next pointer
        Node(int data) {
            this->data = data;
            this->next = NULL;
        }
};

// Define a Queue class based on a linked list
class Queue {
    private:
        Node* front = NULL; // Pointer to the front of the queue
        Node* rear = NULL;  // Pointer to the rear of the queue

    public:
        // Constructor to create a queue with initial data
        Queue(int data) {
            Node* newNode = new Node(data);
            this->front = this->rear = newNode; 
        }

        // Add an element to the rear of the queue
        void enQueue(int data) {
            Node* newNode = new Node(data);

            this->rear->next = newNode; // Link new node to the current rear
            this->rear = newNode;       // Update rear pointer

            return;
        }

        // Remove an element from the front of the queue and return its data
        int deQueue() {
            Node* deQueuedNode = this->front; // Store the front node
            int deQueuedData = deQueuedNode->data; // Get the data from the front node

            this->front = deQueuedNode->next; // Update front pointer

            delete(deQueuedNode); // Delete the dequeued node

            return deQueuedData;
        }

        // Return the data of the front element without removing it
        int peek() {
            return (!this->isEmpty()) ? this->front->data : -1;
        }

        // Check if the queue is empty
        bool isEmpty() {
            return (this->front == NULL);
        }
};

int main() {
    // Create a queue with initial value 0
    Queue* myQ = new Queue(0);

    // Enqueue values from 1 to 10 into the queue
    for (int i = 1; i <= 10; i++) {
        myQ->enQueue(i);
    }

    // Dequeue and print values until the queue is empty
    while (!myQ->isEmpty()) {
        int frontData = myQ->peek();
        myQ->deQueue();

        cout << frontData << " ";
    }

    return 0;
}
