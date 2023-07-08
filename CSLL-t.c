#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>

struct node {
    int data;
    struct node *next;
};

struct node* create_node(int data) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int get_len(struct node* tail) {
    int length = 0;    
    if (tail != NULL) {
		struct node *temp = tail->next;
        do {
            length++;
            temp = temp->next;
        } while (temp != tail->next);
    }
    return length;
}

int get_length(struct node* tail) {   
    int length = 0;
    if (tail != NULL) {
		struct node* temp = tail->next;
		while (temp != tail) {
			length++;
			temp = temp->next;
		}
		length++;	    
    }
    return length;
}


struct node* add_beg(struct node* tail, int data) {
    struct node* ptr = create_node(data);
    if (tail == NULL) {
        ptr->next = ptr;
        tail = ptr;
    } else {
        ptr->next = tail->next;
        tail->next = ptr;
    }
    return tail;
}

struct node* add_at_end(struct node* tail, int data) {
    struct node* ptr = create_node(data);
    if (tail == NULL) {
        ptr->next = ptr;
        tail = ptr;
    } else {
        ptr->next = tail->next;
        tail->next = ptr;
        tail = ptr;
    }
    return tail;
}


/*struct node* create_Linked_List(struct node *tail) {
    int data;
    printf("Enter the linked list elements: ");
    char input[20];
    fgets(input, sizeof(input), stdin);
    char* token = strtok(input, " \n");
    while (token != NULL) {
		sscanf(token, "%d", &data);
		head = add_at_end(tail, data);
        token = strtok(NULL, " \n");
    }
    return tail;
}*/

struct node* create_Linked_List(struct node* tail) {
    int data;
    printf("Enter the circular linked list elements: ");
    while (scanf("%d", &data) == 1) {
        tail = add_at_end(tail, data);
        if (getchar() == '\n') {
            break;
        }
    }

    return tail;
}

struct node* add_at_pos(struct node* tail, int data, int pos){
	int length = get_len(tail);    
    if (pos == 1) {
        tail = add_beg(tail, data);
    } else if (pos == length + 1) {
        tail = add_at_end(tail, data);
    } else {
		struct node *ptr = create_node(data);
        struct node *temp = tail->next;
        int i = 1;
        while (i < pos - 1) {
            temp = temp->next;
            i++;
        }
        ptr->next = temp->next;
        temp->next = ptr;		
	}
	return tail;
}

struct node* del_from_beg(struct node *tail) {
    struct node *temp = tail->next;
    if (temp == tail) {
        tail = NULL;
    } else {
        tail->next = temp->next;
    }
    free(temp);
    return tail;
}

struct node* del_from_end(struct node *tail) {
	struct node *temp = tail->next;
	if (temp->next == temp) {
		tail = NULL;        
    } else {   
		struct node *temp2 = NULL;     
        while (temp->next != tail->next) {
			temp2 = temp;
            temp = temp->next;
        }
        temp2->next = temp->next;
        tail = temp2;
        
    }
    free(temp);    
    return tail;
}

struct node* del_from_pos(struct node *tail, int pos) {
    int length = get_len(tail);
    
    if (pos == 1) {
       tail = del_from_beg(tail);
    } else if (pos == length) {
       tail = del_from_end(tail);
    } else {
        struct node *temp = tail->next;
        int i = 1;
        while (i < pos - 1) {
            temp = temp->next;
            i++;
        }
        struct node *temp2 = temp->next;
        temp->next = temp2->next;
        free(temp2);
    }
    return tail;
}


struct node* reverse_List(struct node *tail) {
	if (tail != NULL) {
		struct node *prev = tail;
		struct node *current = tail->next;
		struct node *next = NULL;

		while(current != tail){
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;			
		}
		current->next = prev;
		
		while(tail->next != current){
			tail = tail->next;
		}
	}
    return tail;
}


void print_List(struct node *tail) {    
    printf("[");
    if (tail != NULL) {
		struct node *temp = tail->next;
		do{
			printf("%d", temp->data);
			temp = temp->next;
			if (temp != tail->next) printf(", ");
		}while (temp != tail->next);
	}
    printf("]\n");
}

#pragma GCC diagnostic ignored "-Wpointer-to-int-cast"
void print_Linked_List(struct node *tail) {	
    if (tail != NULL){
		printf(" -> ");
		struct node *ptr = tail->next;
		do {        
			printf("%u[%d,", (int)ptr, ptr->data);
			printf(" %u]", (int)ptr->next);
			ptr = ptr->next;
			if (ptr != tail->next) printf(" -> ");
			else  {
				setlocale(LC_ALL, ""); 
				wprintf(L" %lc", L'¬');
			}
		}while (ptr != tail->next) ;		
		printf("<- tail");
		printf("[%u]",(int)tail);
		printf("\n");
	}
    else {
		printf("tail[NULL]\n"); 
	}   
}

void free_Linked_List(struct node* tail) {
    if (tail != NULL) {
        struct node* ptr = tail->next;
		struct node* temp = NULL;
		do {
			temp = ptr;			
			ptr = ptr->next;
			free(temp);;
		} while (ptr != tail);
    }
    
}

int main() {
    struct node *tail = NULL;
    tail = create_Linked_List(tail);
    int choice, data, pos, ch;  
    while (1) {
        printf("\n");
        printf("Operations.....\n");
        printf("1. Insertion at beginning\n");
        printf("2. Insertion at end\n");
        printf("3. Insertion at specific position\n");
        printf("4. Deletion from beginning\n");
        printf("5. Deletion from end\n");
        printf("6. Deletion from specific position\n");
        printf("7. Find the length of the linked list\n");
        printf("8. Reverse the linked list\n");
        printf("9. Traverse the linked list\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                tail = add_beg(tail, data);
                printf("List after insertion at the beginning: ");
                print_List(tail);
                break;
            case 2:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                tail = add_at_end(tail, data);
                printf("List after insertion at the end: ");
                print_List(tail);
                break;
            case 3:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                printf("Enter the position: ");
                scanf("%d", &pos);
                int length = get_len(tail);
				if (pos <= 0 || pos > length + 1) printf("Invalid position!\n");
				else {
					tail = add_at_pos(tail, data, pos);
                    printf("List after insertion at position %d: ", pos);
                    print_List(tail);
                }
                break;
                
            case 4:
				if (tail != NULL) {
                tail = del_from_beg(tail);
                    printf("List after deletion from beginning: ");
                    print_List(tail);
                }
                else printf("List is already empty!\n");
                break;
            case 5:
				if (tail != NULL) {
                tail = del_from_end(tail);
                    printf("List after deletion from end: ");
                    print_List(tail);
                }
                else printf("List is already empty!\n");
                break;
            case 6:
                if (tail != NULL) {
                    printf("Enter the position: ");
                    scanf("%d", &pos);
                    int length = get_len(tail);
                    if (pos <= 0 || pos > length) {
                        printf("Invalid position!\n");
                    }
                    else{
                        tail = del_from_pos(tail, pos);
                        printf("List after deletion from position %d: ", pos);
                        print_List(tail);
                    }
                }
                else printf("List is already empty!\n");
                break;
            case 7:
                printf("Length of the linked list: %d\n", get_len(tail));
                break;
            case 8:
                tail = reverse_List(tail);
                printf("Reversed linked list: ");
                print_List(tail);
                break;
            case 9:
				
				while (1) {
					printf("\nWays to print\n");
					printf("1. Print like List\n");
					printf("2. Print like Linked List\n");
					printf("Enter your choice: ");
					scanf("%d", &ch);
					if (ch==1 || ch==2) break;
					else printf("Invalid choice! Please try again.\n");
					getchar();
				}
				if (ch==1){	
					printf("List = ");
					print_List(tail);
				}
				else{
					printf("Singly Linked list = ");
					print_Linked_List(tail);
				}
				break;
			case 10:
				free_Linked_List(tail);
                printf("Exiting.....!");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
        getchar();
        
    }

    return 0;
}
