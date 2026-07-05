// Atm machine
#include<stdio.h>
#include<string.h>
void showmenu();
void balence();
void depo();
void credit();
int bal=0;

int main () {
    int pin=1234, pass, count=0;
    while(count<3)
    {
        printf("\nEnter 4 digit pin: ");
        scanf("%d", &pass);
        if(pass==pin)
        {
            showmenu();
        }
        else{
            printf("Incorrect Pin!\n");
            count++;
        }
    }
    printf("**** Account is Locked ****");
}

void showmenu () {
    int choice;
    do{
        printf("\n\n********************************\n");
        printf("         ATM MACHINE.           \n");
        printf("********************************\n");
        printf("\n");
        printf("1. Check Balence\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        
        printf("Enter Choice :  ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: balence();
            break;

            case 2: depo();
            break;

            case 3: credit();
            break;

            case 4: printf("====Thanking You====");
            break;

            default: printf("Invalid Choise");


        } 




    } while(choice != 4);
}

void balence () {
    printf("\n===Balence Fatched Successfully===\n");
    printf("Availble Balence: %d", bal);
}

void depo () {
    int dep;
    printf("\nEnter ammount : ");
    scanf("%d", &dep);
    bal = bal + dep;
    printf("===Balence Updated===");
    printf("\nAvailable Balence : %d", bal);
    return;

}

void credit () {
    int cre;
    printf("\n Enter ammount : ");
    scanf("%d", &cre);
    bal = bal - cre;
    printf("===Balence Updated===");
    printf("\nAvailable Balence : %d", bal);
}
