// Atm machine
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct atm{
    int ac;
    int pin;
    char name[20];
    float bal;
};

struct atm s[20];
int n=0;
int current = -1;

void list();
void logout();
void display();
void pin();
void open();
void showmenu();
void balence();
void depo();
void credit();

int main () {
    int pass, count=0, a, i, no;

    printf("\n\n********************************\n");
    printf("        Welcome, Grahak         \n");
    printf("********************************\n\n");
    printf("1. Create New Account\n");
    printf("2. Already have an Account\n");
    printf("3. EXIT! \n");
    printf("Enter Choice: ");
    scanf("%d", &a);

    if(a==1)
    {
        open();
    }
    else if(a==2)
    {
        current = -1;
        printf("Enter your account No.: ");
        scanf("%d", &no);
        for(i=0;i<n;i++)
        {
            if(no==s[i].ac)
            {
                current = i;
                printf("Verify it's You! ");
                pin();
                break;
            }
            if(current == -1) 
            {
                printf("Account Not Found!");
                main();
            }
        }
    }
    else if(a==3)
    {
        printf("===THANKING YOU===");
        goto end;
        }
    else
    {
        printf("Invalid Choice\n");
    }
    end:

    return 0;
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
        printf("4. Costumer Details\n");
        printf("5. Add New Account\n");
        printf("6. Log Out!\n");
        printf("7. Exit\n");
        
        printf("Enter Choice :  ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: balence();
            break;

            case 2: depo();
            break;

            case 3: credit();
            break;

            case 7: printf("====Thanking You====\n");
            exit(0);
            return;

            case 4: display();
            break;

            case 5: open();
            break;

            case 6: logout();
            break;

            case 8: list();
            break;

            default: printf("Invalid Choise");


        } 




    } while(choice != 7);
}

void balence () {
    printf("\n===Balence Fatched Successfully===\n");
    printf("Availble Balence: %.2f", s[current].bal);
}

void depo () {
    int dep;
    printf("\nEnter ammount : ");
    scanf("%d", &dep);
    s[current].bal = s[current].bal + dep;
    printf("===Balence Updated===");
    printf("\nAvailable Balence : %.2f", s[current].bal);
    return;

}

void credit () {
    int cre;
    printf("\n Enter ammount : ");
    scanf("%d", &cre);
    if(cre<=s[current].bal)
    {
        s[current].bal -= cre;
        printf("===Balence Updated===");
        printf("\nAvailable Balence : %.2f", s[current].bal);
    }
    else{
        printf("Hmm. Hmm. Hmm. RAJAJI (>|<)");
    }
}

void open() {
    int t1, t2;
    s[n].bal = 0.00;
    printf("Enter your Details\n");
    printf("Account No.: ");
    scanf("%6d",&s[n].ac);
    printf("Generate 4-Digit PIN: ");
    scanf("%d",&t1);
    printf("Confirm PIN: ");
    scanf("%d", &t2);
    if(t1==t2)
    {
        s[n].pin = t1;
    }
    else{
        printf("PIN Doesn't Matched!");
        exit(0);
    }

    printf("Name: ");
    getchar();
    gets(s[n].name);
    current = n;
    n++;
    printf("===Account Successfully Created===\n\n");
    
    showmenu();

}


void pin () {
    int pass, count=0;
    while(count<3)
    {
        printf("\nEnter 4 digit pin: ");
        scanf("%d", &pass);
        if(pass==s[current].pin)
        {
            printf("\n=== Costumer Details===");
            printf("Account: %d\nName: %s\nAvailable Balance: %.2f", s[current].ac, s[current].name, s[current].bal);
            showmenu();
        }
        else{
            printf("Incorrect Pin!\n");
            count++;
        }
    }
    printf("**** Account is Locked ****");
    exit(0);
}

void display () {
    printf("\nAccount no.: %d\nName: %s\n", s[current].ac, s[current].name);
    return;
}

void logout () {
    current = -1;
    exit(0);
}

void list() {
    int i;
    if(n==0){
        printf("\nNO Data Found!");
        return;
    }
    for(i=0;i<n;i++)
    {
        printf("\n\n===Costumer Info===\n");
        printf("Account No: %d\nName :%s\nAvailable Balance: %.2f", s[i].ac, s[i].name, s[i].bal);
    }
}
