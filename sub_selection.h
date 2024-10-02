#include<stdio.h>
int sub_selection()
{   
    int sub_choice;
        a:printf("\nEnter what subject you want to choose...\n\n1. English\n2. Tamil\n3. Maths\n4. DPCO\n5. Value Education\n6. P.E\n7. C-Lab\n8. Excel\n\n0. Exit\nEnter your choice : ");
        scanf("%d",&sub_choice);
        if (sub_choice == 0){
            printf("Exiting...");
            return 0;
        }
        else if (sub_choice < 0 || sub_choice > 9){
            printf("\nEnter a valid input.\n");
            goto a;
        }
        else
            return sub_choice - 1;  
}