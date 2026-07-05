// Atm machine
#include<stdio.h>
#include<string.h>

void balence();
void depo();
void credit();
int bal = 0;

int main() {
    int choice;

    do {
        printf("\n\n************\n");
        printf("         ATM MACHINE            \n");
        printf("************\n\n");

        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                balence();
                break;

            case 2:
                depo();
                break;

            case 3:
                credit();
                break;

            case 4:
                printf("==== Thank You ====");
                break;

            default:
                printf("Invalid Choice");
        }

    } while (choice != 4);

    return 0;
}

void balence() {
    printf("\n=== Balance Fetched Successfully ===\n");
    printf("Available Balance: %d", bal);
}

void depo() {
    int dep;

    printf("\nEnter Amount: ");
    scanf("%d", &dep);

    bal = bal + dep;

    printf("=== Balance Updated ===");
    printf("\nAvailable Balance: %d", bal);
}

void credit() {
    int cre;

    printf("\nEnter Amount: ");
    scanf("%d", &cre);

    bal = bal - cre;

    printf("=== Balance Updated ===");
    printf("\nAvailable Balance: %d", bal);
}
