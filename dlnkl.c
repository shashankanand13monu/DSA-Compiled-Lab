// C program for the all operations in
// the Doubly Linked List


// Linked List nde
struct nde {
	int info;
	struct nde *prev, *next;
};
struct nde* start = NULL;

// Function to traverse the linked list
void traverse()
{
	// List is empty
	if (start == NULL) {
		printf("\nList is empty\n");
		return;
	}
	// Else print the Data
	struct nde* temp;
	temp = start;
	while (temp != NULL) {
		printf("Data = %d\n", temp->info);
		temp = temp->next;
	}
}

// Function to insert at the front
// of the linked list
void insertAtFront()
{
	int data;
	struct nde* temp;
	temp = (struct nde*)malloc(sizeof(struct nde));
	printf("\nEnter number to be inserted: ");
	scanf("%d", &data);
	temp->info = data;
	temp->prev = NULL;

	// Pointer of temp will be
	// assigned to start
	temp->next = start;
	start = temp;
}

// Function to insert at the end of
// the linked list
void insertAtEnd()
{
	int data;
	struct nde *temp, *trav;
	temp = (struct nde*)malloc(sizeof(struct nde));
	temp->prev = NULL;
	temp->next = NULL;
	printf("\nEnter number to be inserted: ");
	scanf("%d", &data);
	temp->info = data;
	temp->next = NULL;
	trav = start;

	// If start is NULL
	if (start == NULL) {

		start = temp;
	}

	// Changes Links
	else {
		while (trav->next != NULL)
			trav = trav->next;
		temp->prev = trav;
		trav->next = temp;
	}
}

// Function to insert at any specified
// position in the linked list
void insertAtPosition()
{
	int data, pos, i = 1;
	struct nde *temp, *newnde;
	newnde = malloc(sizeof(struct nde));
	newnde->next = NULL;
	newnde->prev = NULL;

	// Enter the position and data
	printf("\nEnter position : ");
	scanf("%d", &pos);
	printf("\nEnter number to be inserted: ");
	scanf("%d", &data);
	newnde->info = data;
	temp = start;

	// If start==NULL,
	if (start == NULL) {
		start = newnde;
		newnde->prev = NULL;
		newnde->next = NULL;
	}

	// If position==1,
	else if (pos == 1) {
		newnde->next = start;
		newnde->next->prev = newnde;
		newnde->prev = NULL;
		start = newnde;
	}

	// Change links
	else {
		while (i < pos - 1) {
			temp = temp->next;
			i++;
		}
		newnde->next = temp->next;
		newnde->prev = temp;
		temp->next = newnde;
		temp->next->prev = newnde;
	}
}

// Function to delete from the front
// of the linked list
void deleteFirst()
{
	struct nde* temp;
	if (start == NULL)
		printf("\nList is empty\n");
	else {
		temp = start;
		start = start->next;
		if (start != NULL)
			start->prev = NULL;
		free(temp);
	}
}

// Function to delete from the end
// of the linked list
void deleteEnd()
{
	struct nde* temp;
	if (start == NULL)
		printf("\nList is empty\n");
	temp = start;
	while (temp->next != NULL)
		temp = temp->next;
	if (start->next == NULL)
		start = NULL;
	else {
		temp->prev->next = NULL;
		free(temp);
	}
}

// Function to delete from any specified
// position from the linked list
void deletePosition()
{
	int pos, i = 1;
	struct nde *temp, *position;
	temp = start;

	// If DLL is empty
	if (start == NULL)
		printf("\nList is empty\n");

	// Otherwise
	else {
		// Position to be deleted
		printf("\nEnter position : ");
		scanf("%d", &pos);

		// If the position is the first nde
		if (pos == 1) {
			position = start;
			start = start->next;
			if (start != NULL) {
				start->prev = NULL;
			}
			free(position);
			return;
		}

		// Traverse till position
		while (i < pos - 1) {
			temp = temp->next;
			i++;
		}
		// Change Links
		position = temp->next;
		if (position->next != NULL)
			position->next->prev = temp;
		temp->next = position->next;

		// Free memory
		free(position);
	}
}

// Driver Code
int dlnkl()
{
	int choce;
	while (1) {

		printf("\n\t1 To see list\n");
		printf("\t2 For insertion at"
			" starting\n");
		printf("\t3 For insertion at"
			" end\n");
		printf("\t4 For insertion at "
			"any position\n");
		printf("\t5 For deletion of "
			"first element\n");
		printf("\t6 For deletion of "
			"last element\n");
		printf("\t7 For deletion of "
			"element at any position\n");
		printf("\t8 To exit\n");
		printf("\nEnter Choice :\n");
		scanf("%d", &choce);

		switch (choce) {
		case 1:
			traverse();
			break;
		case 2:
			insertAtFront();
			break;
		case 3:
			insertAtEnd();
			break;
		case 4:
			insertAtPosition();
			break;
		case 5:
			deleteFirst();
			break;
		case 6:
			deleteEnd();
			break;
		case 7:
			deletePosition();
			break;

		case 8:
			exit(1);
			break;
		default:
			printf("Incorrect Choice. Try Again \n");
			continue;
		}
	}
	return 0;
}
