#ifndef LL_HGUARD
#define LL_HGUARD

typedef struct LinkedListNode{
	void *data; /* generic linked list */
	struct LinkedListNode *next;
} LinkedListNode; 

typedef struct{
	LinkedListNode *head; 
	int count;
} LinkedList; 

typedef struct{
	int *iArray; 
	int minIndex;
	int swapTimes;
	int swapDetect;
	int noElements;
} Numbers; 

typedef void (*listFunc)(void *data); 

LinkedList *createLinkedList();
void insertLast(LinkedList *list, void *entry);
void printLinkedList(LinkedList *list, listFunc funcPtr);
void freeLinkedList(LinkedList *list, listFunc funcPtr);
void printResult(void *data);
void freeNode(void *data); 

#endif 
