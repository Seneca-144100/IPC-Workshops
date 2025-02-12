/*
*****************************************************************************
                          Workshop - #4 (P2)
Full Name  : Zerak Mahmood
Student ID#: 107719213
Email      : zmahmood12@senecapolytechnic.ca
Section    : NBB

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void getShoppingList(int items[]);
void pickItems(int items[]);

int main() {
    int items[MAX_ITEMS];
    int shopping = 1;
    
    while (shopping) {
        getShoppingList(items);
        pickItems(items);
        
        printf("\nDo you want to shop again? (1 for Yes, 0 for No): ");
        scanf("%d", &shopping);
    } printf("\nShopping session ended.\n");
    return 0;
}

void getShoppingList(int items[]) {
    const char *itemNames[MAX_ITEMS] = {"Apples", "Oranges", "Pears", "Tomatoes", "Cabbages"};
    
    printf("\nEnter the quantity for each item (0 if not needed):\n");
    for (int i = 0; i < MAX_ITEMS; i++) {
        do {
            printf("%s: ", itemNames[i]);
            scanf("%d", &items[i]);
            
            if (items[i] < 0) {
                printf("Error: Quantity cannot be negative. Please enter again.\n");
            }
        } while (items[i] < 0);
    }
}

void pickItems(int items[]) {
    const char *itemNames[MAX_ITEMS] = {"Apples", "Oranges", "Pears", "Tomatoes", "Cabbages"};
    int quantity;
    
    printf("\nStart picking items:\n");
    for (int i = 0; i < MAX_ITEMS; i++) {
        while (items[i] > 0) {
            printf("Pick %s (Remaining: %d): ", itemNames[i], items[i]);
            scanf("%d", &quantity);
            
            if (quantity <= 0) {
                printf("Error: You must pick at least 1 item.\n");
            } else if (quantity > items[i]) {
                printf("Error: You cannot pick more than the remaining %d.\n", items[i]);
            } else {
                items[i] -= quantity;
                printf("%s picked successfully! Remaining: %d\n", itemNames[i], items[i]);
            }
        }
    }
    printf("\nAll items picked successfully!\n");
}
