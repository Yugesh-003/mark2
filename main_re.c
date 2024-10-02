#include<stdio.h>
#include<stdlib.h>
#include"sub_selection.h"

#define MAX_STUDENTS 39
#define last_roll_no 242239

typedef struct details
{
    char name[50];

    unsigned long roll_num;

    int aper[8], viva[6], exam[8], theory[8], assignmentmark[8];

    float amark[8], internal[8], internal1[8], internal2[8],stotal[8],total;
}details;

char subjects[8][16] = {"English","Tamil","Maths","DPCO","Value Education","P.E","C-Lab","Excel"};
char divisions[6][18] = {"Viva mark","Exam mark","Attendance mark","Assignment mark","I internal","II internal"};

int choice;

void teacher_choice() {
    printf("\nWhat you want to do...\n\n1. Edit student data.\n2. View student data");
}

void add_data()//in progross
{
    FILE *fp;
    fp = fopen("student.txt","a+");

    struct details detail[MAX_STUDENTS];
    int t_roll,temp_roll;

    int sub_choice = sub_selection(); 
    if (sub_choice == 0)
        return;
    
    r_select:printf("\nEnter the student's roll number : ");
    scanf("%d",&temp_roll);

    if (temp_roll > last_roll_no || temp_roll < 242201){
        printf("\nRoll number does not exist.\n");
        goto r_select;
    }

    mark_select:printf("\nEnter what mark details you want to add for the student %d\n",temp_roll);
    if (sub_choice > 5){
        printf("\n1. Exam mark\n2. Attendance mark\n3. Assignment mark\n4. I internal\n5. II internal\n\nEnter your choice : ");    
        scanf("%d",&choice);
        choice ++;
    }
    else{
        printf("\n1. Viva mark\n2. Exam mark\n3. Attendance mark\n4. Assignment mark\n5. I internal\n6. II internal\n\n0. Exit\nEnter your choice : ");
        scanf("%d",&choice);
    }

    t_roll = temp_roll % 100;
    switch (choice)
    {
        case 0:
            return;
            break;
        case 1:
            if(sub_choice > 5){
                a:printf("\nEnter your viva mark : ");
                scanf("%d",&detail[t_roll].viva[sub_choice]);

                if (detail[t_roll].viva[sub_choice] > 20 || detail[t_roll].viva[sub_choice] < 1){

                    printf("\nViva mark should be under 20");
                    goto a;
                }
                else
                    printf("\nMark stored.\n");
                break;
            }

        case 2:
            b:printf("\nExam mark : ");
            scanf("%d", &detail[t_roll].exam[sub_choice]);

            if(detail[t_roll].exam[sub_choice] > 80){
                printf("\nExam mark should be under 80");
                goto b;
            }
            else 
                printf("\nMark stored.\n");
            break;
        case 3:
            printf("\nAttendance percentage : ");
            scanf("%d", &detail[t_roll].aper[sub_choice]);

            if(detail[t_roll].aper[sub_choice] > 100){
                printf("\nAttendance mark should be under 100");
                goto b;
            }
            else 
                printf("\nMark stored.\n");
            break;
        case 4:
            c:printf("\nAssignment mark : ");
            scanf("%d", &detail[t_roll].assignmentmark[sub_choice]);

            if(detail[t_roll].assignmentmark[sub_choice] > 10){
                printf("\nAssignment mark should be under 10");
                goto c;
            }
            else 
                printf("\nMark stored.\n");
            break;
        case 5:
            d:printf("\nI internal mark : ");
            scanf("%f", &detail[t_roll].internal1[sub_choice]);

            if(detail[t_roll].internal1[sub_choice] > 50){
                printf("\nI internal mark should be under 50");
                goto d;
            }
            else 
                printf("\nMark stored.\n");
            break;
        case 6:
            e:printf("\nII internal : ");
            scanf("%f", &detail[t_roll].internal2[sub_choice]);  

            if(detail[t_roll].internal2[sub_choice] > 50){
                printf("\nII internal mark should be under 50");
                goto e;
            }
            else 
                printf("\nMark stored.\n");
            break;
        default:
            printf("\nInvalid choice please try again.\n");
            break;
    }
    goto mark_select;
    fwrite(&detail[t_roll],sizeof(details),1,fp);

    fclose(fp);
}

int main()
{
    for(;;)
    {
        printf("\n\nAre you a...\n1. Teacher\n2. Student\n\n0. Exit\n");
        printf("\nEnter your choice :");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            add_data();
            break;
        case 0:
            exit(0);
            break;    
        default:
            printf("\nInvalid choice, please try again.\n");
        }
        
    }
}