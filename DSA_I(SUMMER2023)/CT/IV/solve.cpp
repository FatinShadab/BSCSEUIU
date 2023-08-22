#include <bits/stdc++.h>

using namespace std;


class Node {
    private:
        int data;
        Node *next;

    public:
        Node(){}

        Node(int data){
            this->data = data;
            this->next = NULL;
        }

        Node(int data, int next_data) : Node(data) {
            this->next = new Node(next_data);
        }

        Node(int data, Node* next) : Node(data) {
            this->next = next;
        }

        void set_data(int data) {
            this->data = data;
        }

        int get_data() {
            return this->data;
        }

        void set_next(Node* next) {
            this->next = next;
        }

        Node* get_next(){
            return this->next;
        }
};


class Queue {
    private:
        Node* front;
        Node* rear;
    
    public:
        Queue() {
            this->front = this->rear = NULL;
        };

        bool isEmpty() {
            return this->front == NULL;
        }

        int peek() {
            return this->front->get_data();
        }

        void enQueue(int data) {
            Node* new_node = new Node(data);

            if (this->isEmpty()){
                this->front = this->rear = new_node;
                return;
            }

            this->rear->set_next(new_node);
            this->rear = new_node;

            return;
        }

        int deQueue() {
            int requested_data = this->front->get_data();

            Node* to_be_deleted = this->front;

            this->front = to_be_deleted->get_next();

            delete to_be_deleted;

            return requested_data;
        }
};


class Stack {
    private:
        Node* top;

    public:
        Stack() {
            this->top = NULL;
        }

        bool isEmpty() {
            return this->top == NULL;
        }

        int peek() {
            if (isEmpty()) {
                return -1;
            }
            return this->top->get_data();
        }

        void push(int data) {
            Node* new_node = new Node(data);
            new_node->set_next(this->top);
            this->top = new_node;
        }

        int pop() {
            if (isEmpty()) {
                return -1;
            }

            int popped_data = this->top->get_data();

            Node* to_be_deleted = this->top;

            this->top = to_be_deleted->get_next();

            delete to_be_deleted;

            return popped_data;
        }
};


class CustomContainer {
    private:
        int size;
        int max_index;

        Node* arr[1000000];

    public:
        CustomContainer(int size){
            this->size = size;
            this->max_index = size-1;
        }

        bool isValidIdx(int idx) {
            return !(idx < 0 || idx > this->max_index);
        }

        void insertAt(int idx, int data){
            if (!this->isValidIdx(idx)){
                return;
            }

            Node* head = this->arr[idx];

            if (head == NULL){
                this->arr[idx] = new Node(data);
                return;
            }

            while (head->get_next() != NULL){
                head = head->get_next();
            }

            head->set_next(new Node(data));

            return;
        }

        Node* atIdx(int idx){
            if (!this->isValidIdx(idx)){
                return NULL;
            }

            return this->arr[idx];
        }
};


class Graph {
    private:
        int number_of_nodes;
        CustomContainer* container;

    public:
        Graph(int number_of_nodes) {
            this->number_of_nodes = number_of_nodes;
            container = new CustomContainer(this->number_of_nodes);
        }

        void addBiDirectionalEdge(int u, int v) {
            this->container->insertAt(u, v);
            this->container->insertAt(v, u);
        }

        void addDirectedEdge(int u, int v) {
            this->container->insertAt(u, v);
        }

        Node* getAdjNodes(int idx) {
            return this->container->atIdx(idx);
        }

        void bfs(int src){
            Queue* myQ = new Queue();
            bool visited_arr[number_of_nodes];
            for (int i = 0; i < number_of_nodes; visited_arr[i++] = false);

            myQ->enQueue(src);
            visited_arr[src] = true;

            printf("Graph Traversal Order (BFS) : ");

            while (!myQ->isEmpty()){
                int current_node = myQ->deQueue();
                Node* adj_node = this->getAdjNodes(current_node);

                printf("%d -> ", current_node);

                while (adj_node != NULL){
                    int adj_node_data = adj_node->get_data();

                    if (!visited_arr[adj_node_data]){
                        visited_arr[adj_node_data] = true;
                        myQ->enQueue(adj_node_data);
                    }

                    adj_node = adj_node->get_next();
                }
            }

            printf(" END\n");
        }

        void dfs(int src) {
            Stack *myS = new Stack();
            bool visited_arr[number_of_nodes];
            for (int i = 0; i < number_of_nodes; visited_arr[i++] = false);

            myS->push(src);

            printf("Graph Traversal Order (DFS) : ");

            while (!myS->isEmpty()) {
                int current_node = myS->pop();

                if (!visited_arr[current_node]){
                    printf("%d -> ", current_node);
                    visited_arr[current_node] = true;
                }

                Node* adj_node = this->getAdjNodes(current_node);

                while (adj_node != NULL) {
                    int adj_node_data = adj_node->get_data();

                    if (!visited_arr[adj_node_data]) {
                        myS->push(adj_node_data);
                    }

                    adj_node = adj_node->get_next();
                }
            }

            printf(" END\n");
        }

        bool isPerfectRoot(int src) {
            Queue* myQ = new Queue();
            bool visited_arr[number_of_nodes];
            for (int i = 0; i < number_of_nodes; visited_arr[i++] = false);

            myQ->enQueue(src);
            visited_arr[src] = true;

            //printf("Graph Traversal Order (BFS) : ");

            while (!myQ->isEmpty()){
                int current_node = myQ->deQueue();
                Node* adj_node = this->getAdjNodes(current_node);

                //printf("%d -> ", current_node);

                while (adj_node != NULL){
                    int adj_node_data = adj_node->get_data();

                    if (!visited_arr[adj_node_data]){
                        visited_arr[adj_node_data] = true;
                        myQ->enQueue(adj_node_data);
                    }

                    adj_node = adj_node->get_next();
                }
            }

            bool visited_all = true;

            for (int node = 0; node < number_of_nodes; node++){
                if (!visited_arr[node]){
                    visited_all = false;
                    break;
                }
            }

            return visited_all;
        }

        int nodeWithMaxChildren(int src) {
            int number_of_children[this->number_of_nodes];
            for (int node = 0; node < this->number_of_nodes; number_of_children[node++] = 0);

            Queue* myQ = new Queue();
            bool visited_arr[number_of_nodes];
            for (int i = 0; i < number_of_nodes; visited_arr[i++] = false);

            myQ->enQueue(src);
            visited_arr[src] = true;

            //printf("Graph Traversal Order (BFS) : ");

            while (!myQ->isEmpty()){
                int current_node = myQ->deQueue();
                Node* adj_node = this->getAdjNodes(current_node);

                //printf("%d -> ", current_node);

                while (adj_node != NULL){
                    number_of_children[current_node]++;

                    int adj_node_data = adj_node->get_data();

                    if (!visited_arr[adj_node_data]){
                        visited_arr[adj_node_data] = true;
                        myQ->enQueue(adj_node_data);
                    }

                    adj_node = adj_node->get_next();
                }
            }

            int parent_with_max_children = 0;

            for (int parent = 0; parent < number_of_nodes; parent++){
                if (number_of_children[parent] > number_of_children[parent_with_max_children]){
                    parent_with_max_children = parent;
                }
            }

            return parent_with_max_children;
        }
};


void testNode() {
    // Test Node

    // way 1
    Node* n1 = new Node();

    n1->set_data(10);
    n1->set_next(NULL);


    printf("D: %d\n", n1->get_data());

    // way 2
    Node* n2 = new Node(9, n1);

    printf("D2: %d, D1: %d\n", n2->get_data(), n2->get_next()->get_data());

    // way 3
    Node* head = new Node(1, 2);

    printf("h: %d, tail: %d\n", head->get_data(), head->get_next()->get_data());

    return;
}

void testQueue() {
    Queue *myQ = new Queue();

    for (int i = 1; i < 11; i++) {
        myQ->enQueue(i);
    }

    printf("Queue : ");
    while (!myQ->isEmpty()) {
        printf("%d -> ", myQ->deQueue());
    }
    printf(" NULL \n");

    return;
}

void graphTest() {
    Graph *graph = new Graph(6);

    graph->addBiDirectionalEdge(0, 1);
    graph->addBiDirectionalEdge(0, 4);
    graph->addBiDirectionalEdge(0, 2);
    graph->addBiDirectionalEdge(1, 3);
    graph->addBiDirectionalEdge(2, 3);
    graph->addBiDirectionalEdge(1, 5);
    graph->addBiDirectionalEdge(3, 5);
    graph->addBiDirectionalEdge(3, 4);
    

    graph->bfs(0);

    graph->dfs(1);
}

void solveOfP1() {
    /*
     *  -> A root of a directed graph is a vertex with a directed path from
     *          'u' to 'v' for any pair of graph vertices(u, v). In other words,
     *          the root vertex can reach every other vertex in the graph.
     *          (According to the condition of the question, it is possible that
     *          no node is a perfect Root !!!)
     * */

    Graph *graph = new Graph(5);

    graph->addDirectedEdge(1, 2);
    graph->addDirectedEdge(1, 0);
    graph->addDirectedEdge(2, 4);
    graph->addDirectedEdge(3, 0);
    graph->addDirectedEdge(3, 1);
    graph->addDirectedEdge(3, 2);
    graph->addDirectedEdge(3, 4);


    for (int node = 0; node < 5; node++){
        printf("Is %d is root ? %s\n", node, (graph->isPerfectRoot(node)) ? "Yes":"No");
    }


    return;
}

void solveOfP2() {
    /*
     *  -> Imagine the number of friends on a social media platform is used as
     *          the basis of a person's popularity. Now consider each person as
     *          a node and their friendship as edges. Your task is to find out
     *          who has the most number of friends and hence the most popular.
     *          (The input graph will be undirected and connected !!!)
     * */
    Graph *graph = new Graph(6);

    graph->addBiDirectionalEdge(0, 1);
    graph->addBiDirectionalEdge(0, 2);
    graph->addBiDirectionalEdge(0, 3);
    graph->addBiDirectionalEdge(1, 4);
    graph->addBiDirectionalEdge(2, 5);

    printf("Most popular user : %d\n", graph->nodeWithMaxChildren(0));

    return;
}


int main() {
    // Node test
    printf("Node Class Test :\n\n");
    testNode();

    // Queue test
    printf("\nQueue Class Test :\n\n");
    testQueue();

    // Graph test
    printf("\nGraph Class Test :\n\n");
    graphTest();

    // Solve of Problem 1
    printf("\nSolve of Q-1:\n\n");
    solveOfP1();

    // Solve of Problem 2
    printf("\nSolve of Q-2:\n\n");
    solveOfP2();

    return 0;
}