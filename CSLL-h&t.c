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

int get_len(struct node* head) {
    int length = 0;
    struct node *temp = head;
    if (temp != NULL) {
        do {
            length++;
            temp = temp->next;
        } while (temp != head);
    }
    return length;
}

struct node* add_beg(struct node *head, int data) {
    struct node *ptr = create_node(data);
    if (head == NULL) {
        ptr->next = ptr;
        head = ptr;
    } else {
        struct node *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = ptr;
        ptr->next = head;
        head = ptr;
    }
    return head;
}

struct node* add_at_end(struct node *head, int data) {
    struct node *ptr = create_node(data);
    if (head == NULL) {
        ptr->next = ptr;
        head = ptr;
    } else {
        struct node *temp = head;
        while (temp->next != head) {
			temp = temp->next;
		}
		temp->next = ptr;
		ptr->next = head;
    }
    return head;

}


/*struct node* create_Linked_List(struct node *head) {
    int data;
    printf("Enter the linked list elements: ");
    char input[20];
    fgets(input, sizeof(input), stdin);
    char* token = strtok(input, " \n");
    while (token != NULL) {
		sscanf(token, "%d", &data);
		head = add_at_end(head, data);
        token = strtok(NULL, " \n");
    }
    return head;
}*/

struct node* create_Linked_List(struct node* head) {
    int data;
    printf("Enter the circular linked list elements: ");
    while (scanf("%d", &data) == 1) {
        head = add_at_end(head, data);
        if (getchar() == '\n') {
            break;
        }
    }

    return head;
}

struct node* add_at_pos(struct node *head, int data, int pos) {
    int length = get_len(head);    
    if (pos == 1) {
        head = add_beg(head, data);
    } else if (pos == length + 1) {
        head = add_at_end(head, data);
    } else {
        struct node *ptr = create_node(data);
        struct node *temp = head;
        int i = 1;
        while (i < pos - 1) {
            temp = temp->next;
            i++;
        }
        ptr->next = temp->next;
        temp->next = ptr;
    }
    return head;
}

struct node* del_from_beg(struct node *head) {
    struct node *temp = head;
    if (head->next == head) {
        head = NULL;
    } else {
        struct node *ptr = head;
        while (ptr->next != head) {
            ptr = ptr->next;
        }
        ptr->next = head->next;
        head = head->next;
    }
    free(temp);
    return head;
}

struct node* del_from_end(struct node *head) {
	struct node *temp = head;
	if (head->next == head) {
        head = NULL;
    } else {
        struct node *temp2 = NULL;
        while (temp->next != head) {
            temp2 = temp;
            temp = temp->next;
        }
        temp2->next = head;
    }
    free(temp);
    return head;
}

struct node* del_from_pos(struct node *head, int pos) {
    int length = get_len(head);
    
    if (pos == 1) {
       head = del_from_beg(head);
    } else if (pos == length) {
       head = del_from_end(head);
    } else {
        struct node *temp = head;
        int i = 1;
        while (i < pos - 1) {
            temp = temp->next;
            i++;
        }
        struct node *temp2 = temp->next;
        temp->next = temp2->next;
        free(temp2);
    }
    return head;
}

struct node* reverse_List(struct node *head) {
	if (head != NULL) {
		struct node *prev = NULL;
		struct node *current = head;
		struct node *next = NULL;

		do {
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		} while (current != head);

		head->next = prev;
		head = prev;
		
	}
    return head;
}

void print_List(struct node *head) {
    struct node *temp = head;
    printf("[");
    if (head != NULL) {
		do{
			printf("%d", temp->data);
			temp = temp->next;
			if (temp != head) printf(", ");
		}while (temp != head);
	}
    printf("]\n");
}

#pragma GCC diagnostic ignored "-Wpointer-to-int-cast"
void print_Linked_List(struct node *head) {
	printf("head");
    if (head != NULL){
		printf("[%u] => ",(int)head);
		struct node *ptr = head;
		do {        
			printf("%u[%d,", (int)ptr, ptr->data);
			printf(" %u]", (int)ptr->next);
			ptr = ptr->next;
			if (ptr != head) printf(" -> ");
			else  {
				setlocale(LC_ALL, ""); 
				wprintf(L" %lc", L'¬');
			}
		}while (ptr != head) ;
		printf("\n");
	}
    else printf("[NULL]\n");    
}
 
 
void free_Linked_List(struct node *head) {
    if (head != NULL) {
		struct node *temp = head;
		struct node *temp1 = NULL;

		do {
			temp1 = temp->next;
			free(temp);
			temp = temp1;
		} while (temp != head);
	}
}


int main() {
    struct node *head = NULL;
    head = create_Linked_List(head);
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
                head = add_beg(head, data);
                printf("List after insertion at the beginning: ");
                print_List(head);
                break;
            case 2:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                head = add_at_end(head, data);
                printf("List after insertion at the end: ");
                print_List(head);
                break;
            case 3:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                printf("Enter the position: ");
                scanf("%d", &pos);
                int length = get_len(head);
				if (pos <= 0 || pos > length + 1) printf("Invalid position!\n");
				else {
					head = add_at_pos(head, data, pos);
                    printf("List after insertion at position %d: ", pos);
                    print_List(head);
                }
                break;
                
            case 4:
				if (head != NULL) {
                head = del_from_beg(head);
                    printf("List after deletion from beginning: ");
                    print_List(head);
                }
                else printf("List is already empty!\n");
                break;
            case 5:
				if (head != NULL) {
                head = del_from_end(head);
                    printf("List after deletion from end: ");
                    print_List(head);
                }
                else printf("List is already empty!\n");
                break;
            case 6:
                if (head != NULL) {
                    printf("Enter the position: ");
                    scanf("%d", &pos);
                    int length = get_len(head);
                    if (pos <= 0 || pos > length) {
                        printf("Invalid position!\n");
                    }
                    else{
                        head = del_from_pos(head, pos);
                        printf("List after deletion from position %d: ", pos);
                        print_List(head);
                    }
                }
                else printf("List is already empty!\n");
                break;
            case 7:
                printf("Length of the linked list: %d\n", get_len(head));
                break;
            case 8:
                head = reverse_List(head);
                printf("Reversed linked list: ");
                print_List(head);
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
					print_List(head);
				}
				else{
					printf("Singly Linked list = ");
					print_Linked_List(head);
				}
				break;
			case 10:
				free_Linked_List(head);
                printf("Exiting.....!");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
        getchar();
        
    }

    return 0;
}




