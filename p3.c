#include<stdio.h>
#include<stdlib.h>
#define MAX 8

int stack[MAX], top = -1;

// Push operation
void push(int item) {
    if (top == (MAX - 1))
        printf("\n\nStack Overflow");
    else
        stack[++top] = item;
}

// Display operation
void display() {
    int i;
    if (top == -1) {
        printf("\nStack is empty.");
        return;
    }
    printf("\nThe stack contents are:");
    for (i = top; i >= 0; i--)
        printf("\n ------\n| %d |", stack[i]);
    printf("\n ------\n");
}

// Pop operation
int pop() {
    if (top == -1)
        return -1;
    else
        return stack[top--];
}

// Palindrome checking
void palindrome(int num) {
    int i, rem, a[10], len = 0, count = 0;

    // Extract digits of the number
    while (num > 0) {
        rem = num % 10;
        push(rem);       // Push each digit onto the stack
        a[len++] = rem;  // Store digit in the array
        num = num / 10;
    }

    // Compare digits
    for (i = 0; i < len; i++) {
        if (a[i] == pop())
            count++;
    }

    if (count == len)
        printf("\nNumber is a Palindrome");
    else
        printf("\nNumber is not a Palindrome");
}

int main() {
    int choice, item, n;

    while (1) {
        printf("\n--------STACK IMPLEMENTATION----------");
        printf("\n1. PUSH\n2. POP\n3. PALINDROME CHECKING\n4. DISPLAY\n5. EXIT");
        printf("\n-----------------------------------------");
        printf("\nEnter your choice:\t");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Push
                if (top == (MAX - 1))
                    printf("\nStack is full, cannot push more items.");
                else {
                    printf("\nEnter an element to be pushed: ");
                    scanf("%d", &item);
                    push(item);
                    display();
                }
                break;

            case 2: // Pop
                item = pop();
                if (item != -1)
                    printf("\nPopped element is %d", item);
                else
                    printf("\nStack is empty");
                display();
                break;

            case 3: // Palindrome Checking
                printf("\nEnter a number to check for Palindrome: ");
                scanf("%d", &n);
                palindrome(n);
                break;

            case 4: // Display Stack
                display();
                break;

            case 5: // Exit
                printf("\nExiting program. Goodbye!");
                exit(0);

            default:
                printf("\nInvalid choice! Please try again.");
        }
    }
    return 0;
}
	