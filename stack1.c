#include <stdio.h>
#include <string.h>

#define MAX 100


char stack[MAX][MAX];
int top = -1;

void push(char *text) {
    if (top < MAX - 1)
        strcpy(stack[++top], text);
}

void pop(char *text) {
    if (top >= 0)
        strcpy(text, stack[top--]);
    else
        strcpy(text, "");
}

int isEmpty() {
    return top == -1;
}

int main() {
    char document[MAX] = "";
    char undo[MAX][MAX], redo[MAX][MAX];
    int undoTop = -1, redoTop = -1;
    int choice;
    char temp[MAX];

    printf("===== TEXT EDITOR (UNDO / REDO) =====\n");

    while (1) {
        printf("\nCurrent Document: \"%s\"\n", document);
        printf("1. Make a Change\n2. Undo\n3. Redo\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 

        if (choice == 1) {
        
            if (undoTop < MAX - 1)
                strcpy(undo[++undoTop], document);

            printf("Enter new document text: ");
            fgets(document, MAX, stdin);
            document[strcspn(document, "\n")] = '\0';

            
            redoTop = -1;
        }
        else if (choice == 2) { 
            if (undoTop >= 0) {
                if (redoTop < MAX - 1)
                    strcpy(redo[++redoTop], document);

                strcpy(document, undo[undoTop--]);
                printf("Undo done.\n");
            } else {
                printf("Nothing to undo!\n");
            }
        }
        else if (choice == 3) {  
            if (redoTop >= 0) {
                if (undoTop < MAX - 1)
                    strcpy(undo[++undoTop], document);

                strcpy(document, redo[redoTop--]);
                printf("Redo done.\n");
            } else {
                printf("Nothing to redo!\n");
            }
        }
        else if (choice == 4) {
            printf("Exiting...\n");
            break;
        }
        else {
            printf("Invalid choice!\n");
        }
    }

    return 0;
}