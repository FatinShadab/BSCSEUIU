//--------------------------------------------------------------------
//    Name : Fatin Shadab Turja / ID: 011222004 / Section : F 
//--------------------------------------------------------------------

/*
	Question:
		Make modifications to the algorithms provided to you for singly Linked 
		Lists in our common repository. (https://github.com/Abedeen25/CSE-2216)
		Create one new function for searching items within the linked list (LL).
		The function will return true if the item is present in the LL and false 
		otherwise. Modify all the functions so that they work for Doubly LL. 
		(Remember to only change the provided code.  Do not bring arbitrarily code
		from other online sources.) Modify all the functions so that they work for
		Circular LL.Now explain all your functions in a document detailing the parameters,
		algorithm and return types, etc below each function body. You shall submit the 
		document only in pdf form.
*/

//--------------------------------------------------------------------
//						***	  Imports	***
//--------------------------------------------------------------------
#include <iostream>
#include <stdbool.h>

using namespace std;
//--------------------------------------------------------------------


//			***	Node Class	***
// -------------------------------------------------------------------
class NodeV1{
	/*
		NodeV1 class is used as data container for SLL and CLL

		Instance Variables:
			data : (int)
				The data that will be stored
			next : (pointer of NodeV1 class object)
				Used to access the next node of the list
	*/
	public:
		int data;
		NodeV1* next;

	public:
		NodeV1(){}

		NodeV1(int data){
			/*
				param: data (int)
					The data to store in the container (NodeV1 Object)
			*/
			this->data = data;
			this->next = NULL;
		}

		NodeV1(int data, NodeV1* next) : NodeV1(data) {
			/*
				param: data (int)
					The data to store in the container (NodeV1 Object)
				param: next (pointer of NodeV1 class object)
					The node (NodeV1 object) that will be the next node of
					the current node
			*/
			this->next = next;
		}
};


class NodeV2{
	/*
		NodeV2 class is used as data container for DLL

		Instance Variables:
			data : (int)
				The data that will be stored
			prev : (pointer of NodeV2 class object)
				Used to access the next node of the list
			next : (pointer of NodeV2 class object)
				Used to access the previous node of the list
	*/
	public:
		int data;
		NodeV2* prev;
		NodeV2* next;

	public:
		NodeV2(){}

		NodeV2(int data){
			/*
				param: data (int)
					The data to store in the container (NodeV2 Object)
			*/
			this->data = data;
			this->prev = NULL;
			this->next = NULL;
		}

		NodeV2(NodeV2* prev, int data) : NodeV2(data) {
			/*
				param: data (int)
					The data to store in the container (NodeV2 Object)
				param: prev (pointer of NodeV2 class object)
					The node (NodeV2 object) that will be the previous 
					node of the current node
			*/
			this->prev = prev;
		}

		NodeV2(int data, NodeV2* next) : NodeV2(data) {
			/*
				param: data (int)
					The data to store in the container (NodeV2 Object)
				param: next (pointer of NodeV2 class object)
					The node (NodeV2 object) that will be the next node of
					the current node
			*/
			this->next = next;
		}

		NodeV2(NodeV2* prev, int data, NodeV2* next) : NodeV2(data) {
			/*
				param: data (int)
					The data to store in the container (NodeV2 Object)
				param: next (pointer of NodeV2 class object)
					The node (NodeV2 object) that will be the next node of
					the current node
				param: prev (pointer of NodeV2 class object)
					The node (NodeV2 object) that will be the previous 
					node of the current node
			*/
			this->prev = prev;
			this->next = next;
		}
};
// -------------------------------------------------------------------


//			***   Search function  ***
// -------------------------------------------------------------------
bool search_in_sll(NodeV1* &head, int target){
	/*
		param: head (pointer of NodeV1 class object)
			Current head of the Single linked List
		param: target (int)
			The value which we are looking for in the Single Linked List
		
		return type : bool

		Algo:
			1. store the address of the head into a variable temp

			2. use the temp variable to loop through the linked list
			until temp becomes NULL

			3. Inside the loop check if data of the temp node is the
			target data if so return true and break the loop

			4. if step 3 do not execute then return false
	*/
	NodeV1* temp = head;

	while (temp != NULL){
		if (temp->data == target){
			return true;
		}
		temp = temp->next;
	}

	return false;
}

bool search_in_dll(NodeV2* &head, int target){
	/*
		param: head (pointer of NodeV2 class object)
			Current head of the Double linked List
		param: target (int)
			The value which we are looking for in the Single Linked List

		return type : bool

		Algo:
			1. store the address of the head into a variable temp

			2. use the temp variable to loop through the linked list
			until temp becomes NULL

			3. Inside the loop check if data of the temp node is the
			target data if so return true and break the loop

			4. if step 3 do not execute then return false
	*/
	NodeV2* temp = head;

	while (temp != NULL){
		if (temp->data == target){
			return true;
		}
		temp = temp->next;
	}

	return false;
}

bool search_in_cll(NodeV1* &head, int target){
	/*
		param: head (pointer of NodeV1 class object)
			Current head of the Circula linked List
		param: target (int)
			The value which we are looking for in the Circular Linked List

		return type : bool

		Algo:
			1. store the address of the head into a variable temp

			2. use the temp variable to loop through the linked list
			until temp->next becomes head again

			3. Inside the loop check if data of the temp node is the
			target data if so return true and break the loop

			4. if step 3 do not execute then return false
	*/
	NodeV1* temp = head;

	while (temp->next != head){
		if (temp->data == target){
			return true;
		}
		temp = temp->next;
	}

	if (temp != head && temp->data == target){
		return true;
	}

	return false;
}
// -------------------------------------------------------------------


//		        ***  SLL functions  ***
// -------------------------------------------------------------------
void show_sll(NodeV1* &head){
	/*
		param: head (pointer of NodeV1 class object)
			Current head of the Single linked List

		return type : None/void

		Algo:
			1. store the address of the head into a variable temp

			2. use the temp variable to loop through the linked list
			until temp becomes NULL

			3. print the node data
	*/
	NodeV1* temp = head;

	printf("The SLL : ");

	while(temp){
		printf("%d --> ", temp->data);
		temp = temp->next;
	}

	printf("NULL\n");

	return;
}

void sll_insert_to_beginning(NodeV1* &head, int newData){
	/*
		param: head (pointer of NodeV1 class object)
			Current head of the Single linked List
		param: newData (int)
			The data to insert at the head

		return type : None/void

		Algo:
			1.Create a new node newNode with the given newData
			and set its next pointer to the current head of the
			linked list.

			2.Update the head pointer to point to the newly 
			created newNode.

			3.The new node is now at the beginning of the linked 
			list, and the insertion is complete.
	*/
    NodeV1* newNode = new NodeV1(newData, head);
    head = newNode;

	return;
}

void sll_insert_after(NodeV1* &head, int newData, int target){
	/*
		param: head (pointer of NodeV1 class object)
			Current head of the Single linked List
		param: newData (int)
			The data of the new node
		param: target (int)
			The target is used to identify the node, after which 
			we will insert new node

		return type : None/void

		Algo:
			1. Create temp to save the head node address

			2. loop through the linked list using the temp until
			found the target node to insert after or the end of 
			the linked list

			3. create the new node
			
			4. if found the targeted node then insert after it,
			else insert at the end;

	*/
    NodeV1* temp = head;

    while(temp -> next != NULL && temp -> data != target){
        temp = temp -> next;
    }

    NodeV1* newNode = new NodeV1();
    newNode -> data = newData;
    newNode -> next = temp -> next;
    temp -> next = newNode;

	return;
}

void sll_insert_at_end(NodeV1* &head, int newData){
	/*
		param: head (pointer of NodeV1 class object)
			Current head of the Single linked List
		param: newData (int)
			The data to insert at the tail

		return type : None/void

		Algo:
			1. Start with a pointer temp pointing to the head 
			of the linked list.

			2. Traverse the linked list using a loop as long as
			the next pointer of the current node (temp->next) is not NULL.

			3. Create a new node newNode with the given newData.

			4. Set the next pointer of the current last node (pointed by temp) 
			to point to the newNode, effectively inserting the newNode at the 
			end of the linked list.
	*/
    NodeV1* temp = head;

    while(temp -> next != NULL){
        temp = temp -> next;
    }

    NodeV1* newNode = new NodeV1();
    newNode -> data = newData;
    temp -> next = newNode;

	return;
}

void sll_delete_node(NodeV1* &head, int hasValue){
	/*
		param: head (pointer of NodeV1 class object)
			Current head of the Single linked List
		param: hasValue (int)
			Used to identify the node, which we have to delete

		return type : None/void

		Algo:
			1. Start with a pointer temp pointing to the head 
			of the linked list.

			2. check if the head node is the one to delete
			if so, update the head with head->next and free
			previous head and exit the function

			3. create and maintain a prevNode

			4. Use the temp node to run the loop until
			found the data to delete or until reach the
			end of the linked list and before changing
			the temp to temp->next save the temp to prevNode

			5. check if the temp node is NULL after the loop,
			then the value/data do not exists in the linked list
			so return from the function

			6. if temp is the node to be deleted then update the
			prevNode->next to temp->next

			5. delete the temp node

	*/
    NodeV1* temp = head;

    if(temp -> data == hasValue){
        head = temp -> next;
        free(temp);
        return;
    }

    NodeV1* prevNode;

    while(temp != NULL && temp -> data != hasValue){
        prevNode = temp;
        temp = temp -> next;
    }

    if(temp == NULL){
        cout << "The item doesn't exist \n";
        return;
    }
    prevNode -> next = temp -> next;
    free(temp);

	return;
}
// -------------------------------------------------------------------


//			***  DLL functions  ***
//--------------------------------------------------------------------
void show_dll(NodeV2* &head){
	/*
		param: head (pointer of NodeV1 class object)
			Current head of the Single linked List

		return type : None/void

		Algo:
			1. store the address of the head into a variable temp

			2. use the temp variable to loop through the linked list
			until temp becomes NULL

			3. print the node data
	*/
	NodeV2* temp = head;

	printf("The DLL : ");

	while(temp){
		printf("%d <--> ", temp->data);
		temp = temp->next;
	}

	printf("NULL\n");

	return;
}

void dll_insert_to_beginning(NodeV2* &head, int data){
	/*
		param: head (pointer of NodeV2 class object)
			Current head of the Doubly linked List
		param: data (int)
			The data to insert at the head

		return type : None/void

		Algo:
			1.Create a new node newNode with the given newData
			and set its next pointer to the current head of the
			linked list.

			2. update the prev pointer of the current head to 
			newNode

			3.Update the head pointer to point to the newly 
			created newNode.

			2.The new node is now at the beginning of the linked 
			list, and the insertion is complete.
	*/
	NodeV2* newNode = new NodeV2(data, head);
	head->prev = newNode;
	head = newNode;
	return;
}

void dll_insert_at_end(NodeV2* &head, int data){
	/*
		param: head (pointer of NodeV2 class object)
			Current head of the Doubly linked List
		param: data (int)
			The data to insert at the tail

		return type : None/void

		Algo:
			1. check if the head == NUll, if true
			call the function to perform inster at head

			2. Start with a pointer temp pointing to the head 
			of the linked list.

			3. Traverse the linked list using a loop as long as
			the next pointer of the current node (temp->next) is not NULL.

			4. Create a new node newNode with the given newData.

			5. Set the next pointer of the current last node (pointed by temp) 
			to point to the newNode, effectively inserting the newNode at the 
			end of the linked list.
	*/
	if (head == NULL){
		dll_insert_to_beginning(head, data);
		return;
	}

	NodeV2* temp = head;
	while (temp->next != NULL){
		temp = temp->next;
	}

	NodeV2* newNode = new NodeV2(temp, data);
	temp->next = newNode;

	return;
}

void dll_insert_after(NodeV2* &head, int data, int targetNodeData){
	/*
		param: head (pointer of NodeV2 class object)
			Current head of the Doubly linked List
		param: data (int)
			The data of the new node
		param: targetNodeData (int)
			The targetNodeData is used to identify the node, after which 
			we will insert new node

		return type : None/void

		Algo:
			1. If the head is NULL, return, as there is no list to insert into.

			2. Start with a pointer temp pointing to the head of the doubly linked list.

			3. Traverse the doubly linked list using a loop as long as temp is not NULL.

			4. Inside the loop, check if the data of the current node (temp) matches the targetNodeData.

			5. If a node with targetNodeData is found break the loop, create a new node newNode with the 
			given data, and set its prev pointer to the temp node, and next pointer to the node after temp.
			if not found call the function to do insert at tail and return from the function

			6. Update the next pointer of the temp node to point to the newly created newNode.

			7. The new node is now inserted after the node with targetNodeData in the doubly linked list.
	*/
	if (head == NULL){
		return;
	}

	NodeV2* temp = head;
	while(temp != NULL){
		if (temp->data == targetNodeData){
			break;
		}
		temp = temp->next;
	}

	if (temp == NULL){
		dll_insert_at_end(head, data);
		return;
	}

	NodeV2* newNode = new NodeV2(temp, data, temp->next);
	temp->next = newNode;

	return;
}

void dll_delete_node(NodeV2* &head, int data){
	/*
		param: head (pointer of NodeV2 class object)
			Current head of the Doubly linked List
		param: data (int)
			Used to identify the node, which we have to delete

		return type : None/void

		Algo:
			1. If the head is NULL, return, as there is no 
			list to delete from.

			2. Start with a pointer temp pointing to the head 
			of the doubly linked list.

			3. If the data of the first node (head) matches the 
			data to be deleted, update the head to point to the 
			next node, set the prev pointer of the new head to NULL,
			and free the memory occupied by the original head node.

			4. If the data to be deleted is not in the first node, 
			traverse the doubly linked list using a loop as long 
			as temp is not NULL.

			5. Inside the loop, check if the data of the current 
			node (temp) matches the data to be deleted.

			6. If the node with the data to be deleted is found, update 
			the next pointer of the previous node (temp->prev->next) to
			point to the node after temp, effectively bypassing the node
			 to be deleted.
			
			7. Free the memory occupied by the node to be deleted using free() or delete.
	*/
	if (head == NULL){
		return;
	}

	NodeV2* temp = head;

	if (temp->data == data){
		head = temp->next;
		head->prev = NULL;
		free(temp);
		return;
	}

	while(temp){
		if (temp->data == data){
			break;
		}
		temp = temp->next;
	}

	if (temp == NULL){
		return;
	}

	temp->prev->next = temp->next;

	free(temp);

	return;
}
//--------------------------------------------------------------------


//			***  CLL functions  ***
// -------------------------------------------------------------------
void show_cll(NodeV1* &head){
	/*
		param: head (pointer of NodeV1 class object)
			Current head of the Circular linked List

		return type : None/void

		Algo:
			1. store the address of the head into a variable temp

			2. if the temp is not NULL then print the data and update
			the temp with head->next;

			2. use the temp variable to loop through the linked list
			until temp becomes head again

			3. print the node data
	*/
	NodeV1* temp = head;

	printf("The CLL : \n");

	if (temp == NULL){
		printf("NULL");
		return;
	}else{
		printf("[head] %d --> ", temp->data);
		temp = temp->next;
	}

	while (temp != head){
                printf("%d --> ", temp->data);
                temp = temp->next;
	}

	printf("%d [head]\n", temp->data);

	return;
}

void cll_insert_to_beginning(NodeV1* &head, int data){
	/*
		param: head (pointer of NodeV1 class object)
			Current head of the Circular linked List
		param: data (int)
			The data to insert at the head

		return type : None/void

		Algo:
			1. Create a new node newNode with the given
			data and set its next pointer to the current
			head of the circular linked list.

			2. Check if the head is NULL. If it is NULL,
			it means the list is empty.
				a. Set the head to point to the newly created newNode.
				b. return from the function.

			3. If the head is not NULL, it means the list is not empty.
				a. Start with a pointer __tail pointing to the head of
				the circular linked list.

			4. Traverse the circular linked list using a loop as long as
			the next pointer of the current node (__tail->next) is not 
			equal to the head.
				a. Inside the loop, move the __tail pointer to the next
				node in the circular linked list.

			5. Once the loop exits, the __tail pointer will be pointing to
			the last node of the circular linked list.

			6. Update the head pointer to point to the newly created newNode.

			7. Set the next pointer of the last node (__tail->next) to point
			to the new head (i.e., head).

			8. The new node is now inserted at the beginning of the circular
			linked list.
	*/
	NodeV1* newNode = new NodeV1(data, head);

	if (head == NULL){
		head = newNode;
		return;
	}

	NodeV1* __tail = head;

	while (__tail->next != head){
		__tail = __tail->next;
	}

	head = newNode;
	__tail->next = head;

	return;
}

void cll_insert_at_end(NodeV1* &head, int data){
	/*
		param: head (pointer of NodeV1 class object)
			Current head of the Circular linked List
		param: data (int)
			The data to insert at the tail

		return type : None/void

		Algo:
			1. Create a new node newNode with the given data and set 
			its next pointer to the current head of the circular linked list.

			2. Check if the head is NULL. If it is NULL, it means the list is empty.
				a. Set the head to point to the newly created newNode.
				b. return from the function.

			3. If the head is not NULL, it means the list is not empty.
				a. Start with a pointer __tail pointing to the head of the
				circular linked list.

			4. Traverse the circular linked list using a loop as long as the next pointer
			of the current node (__tail->next) is not equal to the head.
				a. Inside the loop, move the __tail pointer to the next node in the circular
				linked list.

			5. Once the loop exits, the __tail pointer will be pointing to the last node of
			the circular linked list.

			7. Set the next pointer of the last node (__tail->next) to point to the newly
			created newNode.
	*/
	NodeV1* newNode = new NodeV1(data, head);

	if (head == NULL){
			head = new NodeV1(data);
			return;
	}

	NodeV1* __tail = head;

	while (__tail->next != head){
			__tail = __tail->next;
	}

	__tail->next = newNode;

	return;
}

void cll_insert_after(NodeV1* &head, int newData, int targetNodeData){
	/*
		param: head (pointer of NodeV1 class object)
			Current head of the Circular linked List
		param: data (int)
			The data of the new node
		param: targetNodeData (int)
			The targetNodeData is used to identify the node, after which 
			we will insert new node

		return type : None/void

		Algo:
			1. If head == NUll / linked list empty call function
			to insert at tail and return from the function

			2. Create a new node with the provided data to insert

			3. Check if the data of the first node (head) matches
			the targetNodeData.If the targetNodeData matches the data
			of the first node, it means we need to insert the new node
			after the head. Set the next pointer of the newNode to point
			to the node after the head (i.e., head->next).Update the next
			pointer of the head node to point to the newly created newNode
			and return from the function.

			4. create temp and set it to head->next

			5. Traverse the circular linked list using a loop as long as the
			data of the current node (temp->data) does not match the targetNodeData,
			and temp is not equal to the head.

			6. If the loop exits due to reaching the head again (i.e., temp == head),
			it means the targetNodeData does not exist in the linked list.
			call function to perform insert at tail and return from the function.

			7. If the loop exits due to finding the node with targetNodeData,
			perform the insertion:
				a. Set the next pointer of the newNode to point to the node 
				after temp (i.e., temp->next).
				b. Set the next pointer of temp to point to the newNode,
				effectively inserting the newNode after the temp node.
	*/
	if (head == NULL){
		cll_insert_at_end(head, newData);
		return;
	}

	NodeV1* newNode = new NodeV1(newData);

	if (head->data == targetNodeData){
		newNode->next = head->next;
		head->next = newNode;
		return;
	}

	NodeV1* temp = head->next;
	while (temp->data != targetNodeData && temp != head){
		temp = temp->next;
	}

	if (temp->data != targetNodeData){
		cll_insert_at_end(head, newData);
		return;
	}

	newNode->next = temp->next;
	temp->next = newNode;

	return;
}

void cll_delete_node(NodeV1* &head, int data){
	/*
		param: head (pointer of NodeV1 class object)
			Current head of the Circular linked List
		param: data (int)
			Used to identify the node, which we have to delete

		return type : None/void

		Algo:
			1. check if the linkedlist is empty, if so return from
			the function

			2. check if the node to be delete is head node, if so
				a. find the tail node and update it's pointer to current
				head's next node
				b. free(head/temp/current head); and return from the function

			3. create and maintain a prevNode pointer, pointing to the previos
			node of the temp node

			4. create temp and set to head->next and loop through the linkedlist
			until either find the node to delete or reach the end and update the
			temp and prevNode inside the loop

			5. if the loop breaks by reaching the end and not founding the data
			then return from the function

			6. else update the previous node's next and set it to the next node of
			the temp node.

			7. delete the temp node
	*/
	NodeV1* temp = head;

	if (head == NULL){
		return;
	}

	if (temp->data == data){
		NodeV1* __tail = head;

		while (__tail->next != head){
			__tail = __tail->next;
		}

		head = temp->next;
		__tail->next = head;

		free(temp);

		return;
	}else{
		if (temp->next == temp){
			return;
		}else{
			temp = temp->next;
		}
	}

	NodeV1* prevNode;
	while (temp->data != data && temp != head){
		prevNode = temp;
		temp = temp->next;
	}

	if (temp->data != data){
		return;
	}

	prevNode->next = temp->next;
	free(temp);

	return;
}
// -------------------------------------------------------------------


//			*** Test functions ***
//--------------------------------------------------------------------
void sll_test(){
	int data, _data;
	/*
		return type : None/void
	*/
	printf("\n\tSLL Test Activated !\n\n");

	// Creating a Single Linked List
	NodeV1* node_4 = new NodeV1(50);
	NodeV1* node_3 = new NodeV1(30, node_4);
	NodeV1* node_2 = new NodeV1(60, node_3);
	NodeV1* node_1 = new NodeV1(10, node_2);
	NodeV1* head = new NodeV1(5, node_1);
	// -------------------------------------

	// Printing the Single Linked List
	show_sll(head);
	// -------------------------------------

	// Searching a element in the Single Linked List
	printf("\nEnter A value to search in the SLL : ");
	scanf("%d", &data);

	printf("%s\n", (search_in_sll(head, data)) ? "Element exists":"Element doesn't exists");
	//---------------------------------------

	// insert at head of the Doubly Linked List
	printf("Enter a data to insert at head of the SLL : ");
	scanf("%d", &data);

	sll_insert_to_beginning(head, data);

	printf("\nAfter Insertion : \n");
	show_sll(head);
	// ---------------------------------------

	// insert at tail of the Doubly Linked List
    printf("Enter a data to insert at tail of the SLL : ");
    scanf("%d", &data);

    sll_insert_at_end(head, data);

    printf("\nAfter Insertion : \n");
    show_sll(head);
    // ---------------------------------------

	// insert after a targeted value of the Doubly Linked List
    printf("Enter the Node data to insert after from the SLL : ");
    scanf("%d", &_data);
    printf("Enter a data to insert after %d in the SLL : ", _data);
    scanf("%d", &data);

    sll_insert_after(head, data, _data);

    printf("\nAfter Insertion : \n");
    show_sll(head);
    // ---------------------------------------

	// delete a node of the Doubly Linked List
    printf("Enter the data to delete from the SLL : ");
    scanf("%d", &data);

    sll_delete_node(head, data);

    printf("\nAfter Deletion : \n");
    show_sll(head);
    // ---------------------------------------

	return;
}

void cll_test(){
	/*
		return type : None/void
	*/
	int data;
	int _data;

    printf("\n\tCLL Test Activated !\n\n");

	// Createing a Circular Linked List
	NodeV1* tail = new NodeV1(50);
    NodeV1* node_3 = new NodeV1(30, tail);
    NodeV1* node_2 = new NodeV1(60, node_3);
    NodeV1* node_1 = new NodeV1(10, node_2);
    NodeV1* head = new NodeV1(5, node_1);
	tail->next = head;
	// -------------------------------------

	// Printing the Circular Linked List
    show_cll(head);
	// -------------------------------------

	// Searching a element in the Circular Linked List
    printf("\nEnter A value to search in the SLL : ");
    scanf("%d", &data);

    printf("%s\n", (search_in_cll(head, data)) ? "Element exists":"Element doesn't exists");
	// --------------------------------------


	// insert at head of the Circular Linked List
	printf("Enter a data to insert at head of the CLL : ");
	scanf("%d", &data);

	cll_insert_to_beginning(head, data);

	printf("\nAfter Insertion : \n");
	show_cll(head);
	// ---------------------------------------

	// insert at tail of the Circular Linked List
    printf("Enter a data to insert at tail of the CLL : ");
    scanf("%d", &data);

    cll_insert_at_end(head, data);

    printf("\nAfter Insertion : \n");
    show_cll(head);
    // ---------------------------------------

	// insert after a targeted value of the Circular Linked List
    printf("Enter the Node data to insert after from the CLL : ");
    scanf("%d", &_data);
    printf("Enter a data to insert after %d in the CLL : ", _data);
    scanf("%d", &data);

    cll_insert_after(head, data, _data);

    printf("\nAfter Insertion : \n");
    show_cll(head);
    // ---------------------------------------

	// delete a node of the Circular Linked List
    printf("Enter the data to delete from the CLL : ");
    scanf("%d", &data);

    cll_delete_node(head, data);

    printf("\nAfter Deletion : \n");
    show_cll(head);
    // ---------------------------------------


	return;
}

void dll_test(){
	/*
		return type : None/void
	*/
	int data, _data;

	printf("\n\tDLL Test Activated !\n\n");

	// Creating a Doubly Linked List
	NodeV2* head = new NodeV2(5);
	NodeV2* node_1 = new NodeV2(head, 50);
	head->next = node_1;
	NodeV2* node_2 = new NodeV2(node_1,30);
	node_1->next = node_2;
	NodeV2* node_3 = new NodeV2(node_2,60);
	node_2->next = node_3;
	NodeV2* node_4 = new NodeV2(node_3,10);
	node_3->next = node_4;
	// -------------------------------------

	// Printing the Doubly Linked List
	show_dll(head);
	// -------------------------------------

	// Searching a element in the Doubly Linked List
	printf("\nEnter A value to search in the DLL : ");
	scanf("%d", &data);

	printf("%s\n", (search_in_dll(head, data)) ? "Element exists":"Element doesn't exists");
	//---------------------------------------

	// insert at head of the Doubly Linked List
	printf("Enter a data to insert at head of the DLL : ");
	scanf("%d", &data);

	dll_insert_to_beginning(head, data);

	printf("\nAfter Insertion : \n");
	show_dll(head);
	// ---------------------------------------

	// insert at tail of the Doubly Linked List
    printf("Enter a data to insert at tail of the DLL : ");
    scanf("%d", &data);

    dll_insert_at_end(head, data);

    printf("\nAfter Insertion : \n");
    show_dll(head);
    // ---------------------------------------

	// insert after a targeted value of the Doubly Linked List
    printf("Enter the Node data to insert after from the DLL : ");
    scanf("%d", &_data);
    printf("Enter a data to insert after %d in the DLL : ", _data);
    scanf("%d", &data);

    dll_insert_after(head, data, _data);

    printf("\nAfter Insertion : \n");
    show_dll(head);
    // ---------------------------------------

	// delete a node of the Doubly Linked List
    printf("Enter the data to delete from the DLL : ");
    scanf("%d", &data);

    dll_delete_node(head, data);

    printf("\nAfter Deletion : \n");
    show_dll(head);
    // ---------------------------------------

	return;
}
//--------------------------------------------------------------------


//			***  Main Function ***
//-------------------------------------------------------------------- 
int main(){
	/*
		return type : int
	*/

	sll_test();
	cll_test();
	dll_test();

	return 0;
}
//---------------------------------------------------------------------
//			***  Thank You @-@ ***
//---------------------------------------------------------------------
