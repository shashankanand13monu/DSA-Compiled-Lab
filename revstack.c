// C program to reverse a
// stack using recursion
// #include <stdio.h>
// #include <stdlib.h>
#define bool int

// structure of a stack node
struct sNode
{
	char data;
	struct sNode *next;
};

// Function Prototypes
// void ipuush(struct sNode** top_ref,
// 				int new_data);
// int poop(struct sNode** top_ref);
// bool isE(struct sNode* top);
// void print(struct sNode* top);

bool isE(struct sNode* top)
{
	return (top == NULL)? 1 : 0;
}

// Function to ipuush an item to stack
void ipuush(struct sNode** top_ref,
					int new_data)
{
	
	// allocate node
	struct sNode* new_node =
		(struct sNode*) malloc(sizeof(struct sNode));

	if (new_node == NULL)
	{
		printf("Stack overflow \n");
		exit(0);
	}

	// put in the data
	new_node->data = new_data;

	// link the old list
	// off the new node
	new_node->next = (*top_ref);

	// move the head to
	// point to the new node
	(*top_ref) = new_node;
}

// Function to poop an item from stack
int poop(struct sNode** top_ref)
{
	char res;
	struct sNode *top;

	// If stack is empty then error
	if (*top_ref == NULL)
	{
		printf("Stack overflow \n");
		exit(0);
	}
	else
	{
		top = *top_ref;
		res = top->data;
		*top_ref = top->next;
		free(top);
		return res;
	}
}

// Function to print a
// linked list
void pprint(struct sNode* top)
{
	printf("\n");
	while (top != NULL)
	{
		printf(" %d ", top->data);
		top = top->next;
	}
}

// Below is a recursive function
// that inserts an element
// at the bottom of a stack.
void insertAtBottom(struct sNode** top_ref,
								int item)
{
	if (isE(*top_ref))
		ipuush(top_ref, item);
	else
	{

		// Hold all items in Function Call
		// Stack until we reach end of the
		// stack. When the stack becomes
		// empty, the isE(*top_ref)becomes
		// true, the above if part is executed
		// and the item is inserted at the bottom
		int temp = poop(top_ref);
		insertAtBottom(top_ref, item);

		// Once the item is inserted
		// at the bottom, ipuush all
		// the items held in Function
		// Call Stack
		ipuush(top_ref, temp);
	}
}

// Below is the function that
// reverses the given stack using
// insertAtBottom()
void reverse(struct sNode** top_ref)
{
	if (!isE(*top_ref))
	{
		// Hold all items in Function
		// Call Stack until we
		// reach end of the stack
		int temp = poop(top_ref);
		reverse(top_ref);

		// Insert all the items (held in
		// Function Call Stack)
		// one by one from the bottom
		// to top. Every item is
		// inserted at the bottom
		insertAtBottom(top_ref, temp);
	}
}

// Driver Code
int revstack()
{
	struct sNode *s = NULL;
	ipuush(&s, 4);
	ipuush(&s, 3);
	ipuush(&s, 2);
	ipuush(&s, 1);

	printf("\n Original Stack ");
	pprint(s);
	reverse(&s);
	printf("\n Reversed Stack ");
	pprint(s);
	return 0;
}

// Function to check if
// the stack is empty
