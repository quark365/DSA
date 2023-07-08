#include <stdio.h>
#include <stdlib.h>

int* insertAtStart(int* list, int* size, int value) {
    *size += 1;
    list = realloc(list, *size * sizeof(int));    
    for (int i = *size - 1; i > 0; i--) {
        list[i] = list[i - 1];
    }
    list[0] = value;    
    return list;
}

int* insertAtEnd(int* list, int* size, int value) {
    *size += 1;
    list = realloc(list, *size * sizeof(int));    
    list[*size - 1] = value;
    return list;
}

int* createlist(int *size) {
	int value; 
    int* list = malloc(sizeof(int));
    printf("Enter the elements of the list: ");
    while (scanf("%d", &value) == 1) {
        list = insertAtEnd(list, &*size, value);
        if (getchar() == '\n') {
            break;
        }
    }
    return list;
}

int* insertAtIndex(int* list, int* size, int index, int value) {   
	*size += 1;
	list = realloc(list, *size * sizeof(int)); 
	if (index != *size - 1){   
		for (int i = *size - 1; i > index; i--) {
			list[i] = list[i - 1];
		}		
	}
	list[index] = value;
    return list;
}

int* insertAfterValue(int* list, int* size, int after, int value, int* v) {
    int index = -1;
    for (int i = 0; i < *size; i++) {
        if (list[i] == after) {
            index = i + 1;
            break;
        }
    }
    if (index == -1) *v = 0;
    else{
		list = insertAtIndex(list, &*size, index, value);
	}
    return list;

}

int* deleteAtStart(int* list, int* size) {  
	for (int i = 0; i < *size - 1; i++) {
        list[i] = list[i + 1];
    }
    *size -= 1;
    list = realloc(list, *size * sizeof(int)); 
    return list;
}

int* deleteAtEnd(int* list, int* size) {
    *size -= 1;
    list = realloc(list, *size * sizeof(int)); 
    return list;
}

int* deleteAtIndex(int* list, int* size, int index) {
	if (index != *size - 1){
		for (int i = index; i < *size - 1; i++) {
			list[i] = list[i + 1];
		}
	}
    *size -= 1;
    list = realloc(list, *size * sizeof(int)); 
    return list;
}

int* deleteByValue1(int* list, int* size, int value, int* v) {
    int index = -1;
    for (int i = 0; i < *size; i++) {
        if (list[i] == value) {
            index = i;
            break;
        }
    }
    if (index == -1) *v = 0;
    else{
		list = deleteAtIndex(list, &*size, index);
	}
    return list;
}

int* deleteByValue(int* list, int* size, int value, int* v) {
    int y = 0;
    for (int i = 0; i < *size; i++) {
        if (list[i] == value) {
            y += 1;
            if (i != *size - 1) list[i] = list[i + 1];
        }
    }
    if (y == 0) *v = 0;
    else{
		*size -= y;
		list = realloc(list, *size * sizeof(int)); 
	}
    return list;
}

int* deleteNthValueOccurrence(int* list, int* size, int value, int n, int* v, int* u) {
    int index = -1;
    for (int i = 0; i < *size; i++) {
        if (list[i] == value) {
            *u += 1;
            if (*u == n) {
                index = i;
                break;
            }
        }
    }
    if (index == -1) *v = 0;
    else{
		list = deleteAtIndex(list, &*size, index);
	}
    return list;
}


void traverselist(int* list, int size) {
    printf("["); 
    for (int i = 0; i < size; i++) {
        printf("%d", list[i]);
        if (i!=size-1) printf(", "); 
    }
    printf("]\n"); 
}

void searchByValue(int* list, int size, int value) {
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (list[i] == value) {
            found = 1;
            printf("%d found at index %d\n", value, i);
            break;
        }
    }
    if (!found) {
        printf("%d not found in list.\n", value);
    }
}

void searchByIndex(int* list, int size, int index) {
    if (index >= 0 && index < size) {
        printf("Element at index %d is %d\n", index, list[index]);
    } else {
        printf("Invalid index.\n");
    }
}

int main() {
	int* list = NULL;
    int size = 0, choice, value, after, index, pos, ch, v, c, n, u;      
	list = createlist(&size);
    while (1) {
        printf("\n");
        printf("Choose an operation:\n");
        printf("1. Insertion\n");
        printf("2. Deletion\n");
        printf("3. Traversal\n");
        printf("4. Searching an element\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
				while (1) {
                    printf("\n");
					printf("1. Insert at start\n");
                    printf("2. Insert at end\n");
                    printf("3. Insert at index\n");
                    printf("4. Insert at position\n");
                    printf("5. Insert after value\n");
                    printf("Enter your choice: ");
                    scanf("%d", &ch);
                    c = 0;					
					switch(ch){
						case 1:
                            printf("Enter value to insert: ");
					        scanf("%d", &value);
							list = insertAtStart(list, &size, value);
							printf("list after insertion at the beginning: ");
							traverselist(list, size);
                            c = 1;
							break;
						case 2:
                            printf("Enter value to insert: ");
					        scanf("%d", &value);
							list = insertAtEnd(list, &size, value);
							printf("list after insertion at the end: ");
							traverselist(list, size);
                            c = 1;
							break;
						case 3:
                            printf("Enter value to insert: ");
					        scanf("%d", &value);
							printf("Enter index to insert at: ");
							scanf("%d", &index);
							if (index < 0 || index > size) printf("Invalid index.\n");
							else{
								insertAtIndex(list, &size, index, value);
								printf("list after insertion at index %d: ", index);
								traverselist(list, size);
							}
                            c = 1;
							break;
						case 4:
                            printf("Enter value to insert: ");
					        scanf("%d", &value);
							printf("Enter position to insert at: ");
							scanf("%d", &pos);
							index = pos - 1;
							if (index < 0 || index > size) printf("Invalid position.\n");
							else{
								insertAtIndex(list, &size, index, value);
								printf("list after insertion at position %d: ", pos);
								traverselist(list, size);
							}
                            c = 1;
							break;
						case 5:
                            printf("Enter value to insert: ");
					        scanf("%d", &value);
							printf("Enter value to insert after: ");
							scanf("%d", &after);
							v = 1;
							insertAfterValue(list, &size, after, value, &v);
							if (v){
								printf("list after insertion after %d: ", after);
								traverselist(list, size);
							}
							else printf("%d not found in list.\n",after);
                            c = 1;
							break;
						
                        default:
                            printf("Invalid choice! Please try again.\n");
					}
					if (c) break;
                    getchar();
                    
                }
                break;				
            case 2:
                if (size != 0) {
				    while (1) {
						printf("\n");
						printf("1. Delete from start\n");
                        printf("2. Delete from end\n");
                        printf("3. Delete from index\n");
                        printf("4. Delete from position\n");
                        printf("5. Delete by value\n");
                        printf("Enter your choice: ");
                        scanf("%d", &ch);	
                        c = 0;						
						switch(ch){
							case 1:							
								list = deleteAtStart(list, &size);
								printf("list after deletion from the beginning: ");
								traverselist(list, size);	
                                c = 1;						
								break;							
							case 2:
								list = deleteAtEnd(list, &size);
								printf("list after insertion from the end: ");
								traverselist(list, size);
                                c = 1;
								break;
							case 3:
								printf("Enter index to delete from: ");
								scanf("%d", &index);
								if (index < 0 || index > size) printf("Invalid index.\n");
								else{
									list = deleteAtIndex(list, &size, index);
									printf("list after deletion from index %d: ", index);
									traverselist(list, size);
								}
                                c = 1;
								break;
							case 4:
								printf("Enter position to delete from: ");
								scanf("%d", &pos);
								index = pos - 1;
								if (index < 0 || index > size) printf("Invalid position.\n");
								else{
									list = deleteAtIndex(list, &size, index);
									printf("list after deletion from position %d: ", pos);
									traverselist(list, size);
								}
                                c = 1;
								break;
							case 5:
								printf("Enter value to delete: ");
								scanf("%d", &value);
								v = 1;
                                u = 0;
                                n = 0;
                                while (1) {
						            printf("\n");
						            printf("1. Delete Particular Occurrence\n");
                                    printf("2. Delete All Occurrence\n");
                                    printf("Enter your choice: ");
                                    scanf("%d", &ch);
                                    switch(ch){
							            case 1:							
								            printf("Which occurrence: ");
								            scanf("%d", &n);
                                            list = deleteNthValueOccurrence(list, &size, value, n, &v, &u);
                                            c = 1;				
								            break;							
							            case 2:
								            list = deleteByValue(list, &size, value, &v);
                                            c = 1;																		
								            break;
                                        default:
                                            printf("Invalid choice! Please try again.\n");
						            }
						            if (c) break;
                                    getchar();                        
                                }
                                								
								if (v){
									printf("list after deletion of %d: ", value);
									traverselist(list, size);
								}
                                else{
                                    if (u==0){
                                        printf("%d not found in list.\n", value);
                                    }
                                    else {
										if (n==1) printf("%dst ", n);
										else if (n==2) printf("%dnd ", n);
										else if (n==3) printf("%drd ", n);
										else printf("%dth ", n);
										printf("occurrence of %d not found in list.\n", value);
									}
                                }
                                
                                c = 1;
								break;
                            default:
                                printf("Invalid choice! Please try again.\n");
						}
						if (c) break;
                        getchar();
                        
                    }
				}
				else printf("list is already empty.\n");
                break;                
            case 3:
				printf("list = ");
				traverselist(list, size);						
                break;
            case 4:
				if (size != 0) {
					while (1) {
						printf("\n");
						printf("1. Search by value\n");
                        printf("2. Search by index\n");
                        printf("Enter your choice: ");
                        scanf("%d", &ch);
                        c = 0;
                        switch(ch){
							case 1:							
								printf("Enter value to search for: ");
								scanf("%d", &value);	
								searchByValue(list, size, value); 	
                                c = 1;				
								break;							
							case 2:
								printf("Enter index to search: ");
								scanf("%d", &index);
								searchByIndex(list, size, index);	
                                c = 1;																		
								break;
                            default:
                                printf("Invalid choice! Please try again.\n");
						}
						if (c) break;
                        getchar();                        
                    }
				}
				else printf("list is empty.\n");					
                break;
            case 5:
				free(list);
				printf("Exiting.....!");
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
        getchar();     
        
        
    }

    return 0;
}
