#include <stdio.h>

typedef struct LinkedList{
	int data;
	struct LinkedList *next;
	struct LinkedList *prev;
} LinkedList;

int main () {

	LinkedList temp = {1, NULL, NULL};

	for ( ;1; ) {
		LinkedList n;
		int input;
		scanf("%d", &input);
		if (input == -1)
		{
			printf("끼익!!!\n");
			printf("쿵\n");
			printf("치이이익\n");
			printf("활활\n");
			printf("펑\n");
			printf("hyunseo1201이(가) 폭파되었습니다.\n");
			printf("hyunseo1201 left the game\n");
			break;
		}
		n.data = input;
		n.prev = &temp;
		n.prev->next = &n;

		temp = n;
	}

	for ( LinkedList *a = &temp; a != NULL; a = a->prev ) {
		printf("%d\n", a->data);
	}
	
	return 0;
}
