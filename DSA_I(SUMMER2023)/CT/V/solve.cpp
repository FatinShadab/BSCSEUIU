/*
Topic : Single Source Shortest and longest path length
and Palindrome using stack.
*/

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

/* Code Block For 'solveOfFinalP1' */

/*
 You are given an DAG graph G represented as adjacency list
 and two vertices, start and end. Your task is to find the
 length of both the shortest and longest path between start 
 and end using BFS and DFS.

 The first line of input will be two integers 'n' and 'm' 
 representing the number of vertices and edges of the graph 
 respectively. The following 'm' lines will contain two integers
 'p' and 'q' representing the start and the end vertex for which
 you will find the shortest and longest paths using BFS and DFS
 respectively.
 
 sample input:
 5 7
 0 1
 0 2
 1 2
 1 3
 2 3
 2 4
 3 4
 0 4

 sample output:
 Shortest Path Length From 0 -> 4: 2
 Longest Path Length From 0 -> 4: 3
 * */

const int N = 1e3;

int n, m, s, d;
bool visited[N];
int parent[N];
int distance_arr[N];
Graph *graph;

int len_of_sssp() {
    Queue* myQ = new Queue();
    int path_len = 0;

    visited[s] = true;
    myQ->enQueue(s);

    while (!myQ->isEmpty()){
        int node = myQ->deQueue();

        Node* adj_node = graph->getAdjNodes(node);

        while (adj_node != NULL){
            int adj_node_data = adj_node->get_data();

            if (!visited[adj_node_data]){
                visited[adj_node_data] = true;
                myQ->enQueue(adj_node_data);
                parent[adj_node_data] = node;

                if (adj_node_data == d){
                    while (!myQ->isEmpty()){ myQ->deQueue(); }
                    break;
                }
            }

            adj_node = adj_node->get_next();
        }
    }

    if (visited[d]){
        int node = d;
        while (node != s){
            node = parent[node];
            path_len++;
        }
    }

    return path_len;
}

int len_of_sslp() {
    Stack *myS = new Stack();

    myS->push(s);

    while (!myS->isEmpty()) {
        int current_node = myS->pop();

        if (!visited[current_node]){
            visited[current_node] = true;
        }

        Node* adj_node = graph->getAdjNodes(current_node);

        while (adj_node != NULL) {
            int adj_node_data = adj_node->get_data();

            if (!visited[adj_node_data]) {
                myS->push(adj_node_data);
            }

            distance_arr[adj_node_data] = max(distance_arr[adj_node_data], distance_arr[current_node] + 1);

            adj_node = adj_node->get_next();
        }
    }

    return distance_arr[d];
}

void solveOfFinalP1(){
    scanf("%d %d", &n, &m);

    graph = new Graph(n);

    while (m--){
        int u, v;
        scanf("%d %d", &u, &v);
        graph->addDirectedEdge(u, v);
    }

    scanf("%d %d", &s, &d);

    printf("Shortest Path Length From %d -> %d: %d\n", s, d, len_of_sssp());
    for (int i=0; i<n; visited[i++] = false);
    printf("Longest Path Length From %d -> %d: %d\n", s, d, len_of_sslp());
}

/*  END */

/* Code Block For 'solveOfFinalP2' */

/*
P2 Question:

    You are given a string S consisting of lowercase English letters.
    You need to determine whether or not it's a palindrome.
    A palindrome is a word tat is spelled same way forwards and backwords.
    For example, "racecar" is a palindrome.

        Sample input:                  Sample output
        ------------------------------------------------
        radar                          Palindrome
        ------------------------------------------------
        student                        Not a palindrome
    ------------------------------------------------
*/

void solveOfFinalP2() {
    Stack* stack = new Stack();
    string str;
    cin >> str;

    int start = 1;
    int stop = (str.length()%2) ? (str.length()/2)+1:str.length()/2;
    
    for (char chr : str) {
        int ascii = chr;

        if (start < stop) {
            stack->push(ascii);
            printf("pushed %d <-> %c\n", ascii, chr);
        }
        else if (start == stop && !(str.length()%2)){
            printf("pushed (mid) %d <-> %c\n", ascii, chr);
            stack->push(ascii);
        }
        else if (start > stop){
            int chk = stack->pop();
            printf("\ncompare (mid) (s)%d <-> (input) %d(%c)", chk, ascii, chr);
            if (chk != ascii){
                cout << "\nNot a palindrome !\n";
                return;
            }
        }

        start++;
    }

    cout << "\nPalindrome !\n";

    return;
}

/*  END */


int main() {


    printf("\n Solve of Q-1(final)\n\n");
    solveOfFinalP1();

    printf("\n Solve of Q-2(final)\n\n");
    solveOfFinalP2();

    return 0;
}