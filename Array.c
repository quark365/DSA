#include <stdio.h>
#include <stdlib.h>

int* createArray(int size) {
    int* array = malloc(size * sizeof(int));
    if(size>0) printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
    return array;
}

int* insertAtStart(int* array, int* size, int value) {
    *size += 1;
    array = realloc(array, *size * sizeof(int));    
    for (int i = *size - 1; i > 0; i--) {
        array[i] = array[i - 1];
    }
    array[0] = value;    
    return array;
}

int* insertAtEnd(int* array, int* size, int value) {
    *size += 1;
    array = realloc(array, *size * sizeof(int));    
    array[*size - 1] = value;
    return array;
}

int* insertAtIndex(int* array, int* size, int index, int value) {   
	*size += 1;
	array = realloc(array, *size * sizeof(int)); 
	if (index != *size - 1){   
		for (int i = *size - 1; i > index; i--) {
			array[i] = array[i - 1];
		}		
	}
	array[index] = value;
    return array;
}

int* insertAfterValue(int* array, int* size, int after, int value, int* v) {
    int index = -1;
    for (int i = 0; i < *size; i++) {
        if (array[i] == after) {
            index = i + 1;
            break;
        }
    }
    if (index == -1) *v = 0;
    else{
		array = insertAtIndex(array, &*size, index, value);
	}
    return array;

}

int* deleteAtStart(int* array, int* size) {  
	for (int i = 0; i < *size - 1; i++) {
        array[i] = array[i + 1];
    }
    *size -= 1;
    array = realloc(array, *size * sizeof(int)); 
    return array;
}

int* deleteAtEnd(int* array, int* size) {
    *size -= 1;
    array = realloc(array, *size * sizeof(int)); 
    return array;
}

int* deleteAtIndex(int* array, int* size, int index) {
	if (index != *size - 1){
		for (int i = index; i < *size - 1; i++) {
			array[i] = array[i + 1];
		}
	}
    *size -= 1;
    array = realloc(array, *size * sizeof(int)); 
    return array;
}


int* deleteByValue(int* array, int* size, int value, int* v) {
    int y = 0;
    for (int i = 0; i < *size; i++) {
        if (array[i] == value) {
            y += 1;
            if (i != *size - 1) array[i] = array[i + 1];
        }
    }
    if (y == 0) *v = 0;
    else{
		*size -= y;
		array = realloc(array, *size * sizeof(int)); 
	}
    return array;
}

int* deleteNthValueOccurrence(int* array, int* size, int value, int n, int* v, int* u) {
    int index = -1;
    for (int i = 0; i < *size; i++) {
        if (array[i] == value) {
            *u += 1;
            if (*u == n) {
                index = i;
                break;
            }
        }
    }
    if (index == -1) *v = 0;
    else{
		array = deleteAtIndex(array, &*size, index);
	}
    return array;
}


void traverseArray(int* array, int size) {
    printf("["); 
    for (int i = 0; i < size; i++) {
        printf("%d", array[i]);
        if (i!=size-1) printf(", "); 
    }
    printf("]\n"); 
}

void searchByValue(int* array, int size, int value) {
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] == value) {
            found = 1;
            printf("%d found at index %d\n", value, i);
            break;
        }
    }
    if (!found) {
        printf("%d not found in array.\n", value);
    }
}

void searchByIndex(int* array, int size, int index) {
    if (index >= 0 && index < size) {
        printf("Element at index %d is %d\n", index, array[index]);
    } else {
        printf("Invalid index.\n");
    }
}

int main() {
	int* array = NULL;
    int size = 0, choice, value, after, index, pos, ch, v, c, n, u;  
    printf("Enter size of array: ");
	scanf("%d", &size);
	array = createArray(size);
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
							array = insertAtStart(array, &size, value);
							printf("Array after insertion at the beginning: ");
							traverseArray(array, size);
                            c = 1;
							break;
						case 2:
                            printf("Enter value to insert: ");
					        scanf("%d", &value);
							array = insertAtEnd(array, &size, value);
							printf("Array after insertion at the end: ");
							traverseArray(array, size);
                            c = 1;
							break;
						case 3:
                            printf("Enter value to insert: ");
					        scanf("%d", &value);
							printf("Enter index to insert at: ");
							scanf("%d", &index);
							if (index < 0 || index > size) printf("Invalid index.\n");
							else{
								insertAtIndex(array, &size, index, value);
								printf("Array after insertion at index %d: ", index);
								traverseArray(array, size);
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
								insertAtIndex(array, &size, index, value);
								printf("Array after insertion at position %d: ", pos);
								traverseArray(array, size);
							}
                            c = 1;
							break;
						case 5:
                            printf("Enter value to insert: ");
					        scanf("%d", &value);
							printf("Enter value to insert after: ");
							scanf("%d", &after);
							v = 1;
							insertAfterValue(array, &size, after, value, &v);
							if (v){
								printf("Array after insertion after %d: ", after);
								traverseArray(array, size);
							}
							else printf("%d not found in array.\n",after);
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
								array = deleteAtStart(array, &size);
								printf("Array after deletion from the beginning: ");
								traverseArray(array, size);	
                                c = 1;						
								break;							
							case 2:
								array = deleteAtEnd(array, &size);
								printf("Array after insertion from the end: ");
								traverseArray(array, size);
                                c = 1;
								break;
							case 3:
								printf("Enter index to delete from: ");
								scanf("%d", &index);
								if (index < 0 || index > size) printf("Invalid index.\n");
								else{
									array = deleteAtIndex(array, &size, index);
									printf("Array after deletion from index %d: ", index);
									traverseArray(array, size);
								}
                                c = 1;
								break;
							case 4:
								printf("Enter position to delete from: ");
								scanf("%d", &pos);
								index = pos - 1;
								if (index < 0 || index > size) printf("Invalid position.\n");
								else{
									array = deleteAtIndex(array, &size, index);
									printf("Array after deletion from position %d: ", pos);
									traverseArray(array, size);
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
                                            array = deleteNthValueOccurrence(array, &size, value, n, &v, &u);
                                            c = 1;				
								            break;							
							            case 2:
								            array = deleteByValue(array, &size, value, &v);
                                            c = 1;																		
								            break;
                                        default:
                                            printf("Invalid choice! Please try again.\n");
						            }
						            if (c) break;
                                    getchar();                        
                                }
                                								
								if (v){
									printf("Array after deletion of %d: ", value);
									traverseArray(array, size);
								}
                                else{
                                    if (u==0){
                                        printf("%d not found in array.\n", value);
                                    }
                                    else {
										if (n==1) printf("%dst ", n);
										else if (n==2) printf("%dnd ", n);
										else if (n==3) printf("%drd ", n);
										else printf("%dth ", n);
										printf("occurrence of %d not found in array.\n", value);
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
				else printf("Array is already empty.\n");
                break;                
            case 3:
				printf("Array = ");
				traverseArray(array, size);						
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
								searchByValue(array, size, value); 	
                                c = 1;				
								break;							
							case 2:
								printf("Enter index to search: ");
								scanf("%d", &index);
								searchByIndex(array, size, index);	
                                c = 1;																		
								break;
                            default:
                                printf("Invalid choice! Please try again.\n");
						}
						if (c) break;
                        getchar();                        
                    }
				}
				else printf("Array is empty.\n");					
                break;
            case 5:
				free(array);
				printf("Exiting.....!");
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
        getchar();      
        
        
    }

    return 0;
}
