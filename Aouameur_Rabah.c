#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
void Color(int ForgC)
{
    WORD wColor;

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    //We use csbi for the wAttributes word.
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        //Mask out all but the background attribute, and add in the forgournd     color
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}
typedef struct
{
    char name[20];
    int dep;
    int numstu[5];
    int section;
} faculte;
int main ()
{
    faculte f[20];
    int ch,counterf =0,j;
menu :
    /* ************ Main menu ***********************  */
    do
    {
        system("CLS");
        system("COLOR F0");
        char welcome[50]= "**** Welcome to my Management System \"Faculte\" ****";
        printf("\n\t\t\t\t     ");
        for(j=0; j<50; j++)
        {
            Sleep(48);
            printf("%c",welcome[j]);
        }
        system("COLOR F0");
        Color(4);
        Sleep(10);
        printf("\n\n\n\t\t\t\t\t\t      MAIN MENU\n\n\t\t\t\t\t\t=====================");
        Color(0);
        Sleep(10);
        printf("\n\t\t\t\t\t\t[1] Add a new faculte\n\t\t\t\t\t\t[2] List all faculte\n\t\t\t\t\t\t[3] Edit a faculte\n\t\t\t\t\t\t[4] Delete a faculte\n\t\t\t\t\t\t[0] Exit");
        Color(4);
        Sleep(10);
        printf("\n\t\t\t\t\t\t=====================\n\n\t\t\t\t");
        Color(2);
        Sleep(60);
        printf("Enter the choice : ");
        Color(0);
        scanf("%d",&ch);

    }
    while(ch>4 || ch<0 );
    FILE *fp;
    switch(ch)
    {
    case 0 :
        Color(2);
        puts("\n\t\t\tAre you sure???");
        break;
    case 1 :
        system("CLS");
        Color(4);
        puts("\t *-ADD Faculte-* ");
        fp = fopen("faculte.txt","w");
        Color(45);
        fflush(stdin);
        printf("\n   + Give me a name of faculte : ");
        Color(0);
        scanf("%s",&f[counterf].name);
        Color(45);
        printf("\n   + Give me number of departement : ");
        Color(0);
        scanf(" %i",&f[counterf].dep); 
        Color(45);
        printf("\n   + Give me number of section : ");
        Color(0);
        scanf("%i",&f[counterf].section);
        for(j = 0 ; j<f[counterf].section ; j++)
        {
            Color(45);
            printf("\n   + Give me a number of students in %i section : ",j+1);
            Color(0);
            scanf(" %i",&f[counterf].numstu[j]);
        }
        fseek(fp,0,SEEK_END);
        fwrite(f,sizeof(char),strlen(f[counterf]),fp);
        Color(2);
        puts("\n  The faculte is sucessfully added");
        counterf++;
        Color(28);
        fclose(fp);


        break;
    case 2:
        system("cls");
        Color(4);
        printf("\n\n\t\t\t\t\   ================================\n       \t\t\t\t\tLIST OF Faculte In UNIV\n\t\t\t\t   ================================");
        Color(0);
        Color(4);
        puts("\n\nNOTICE : ");
        Color(0);
        puts("\n  please give me a Shortcuts (for exemple : informatique => give me info ...*-*)   ");
        Color(2);
        printf("\n\n\n\t     Name_faculte      \tnumber_departement\tnumber_section\t\tnumber_students \n\t  ===================================================================================================\n\n");
        Color(0);
        fp=fopen("faculte.txt","w");
        fflush(stdin);
        int numfaculte;
        for(numfaculte=0; numfaculte<counterf; numfaculte++)
        {
            printf("\n\t\t%d-%s || \t\t || \t%d\t\t   ||  %i \t|| \t\t",numfaculte,f[numfaculte].name,f[numfaculte].dep,f[numfaculte].section);
            for(j=0; j<f[numfaculte].section; j++)
            {
                printf("%c- %i,  ",j+65,f[numfaculte].numstu[j]);
                if (j == f[numfaculte].section - 1) printf("\n");
            }
        }
        Color(2);
        printf("\n\t  ===================================================================================================");
        Color(0);
        fclose(fp);
        break;
    case 3 :
        /********************delete contacts**********************/
        system("cls");
        Color(2);
        printf("\n\n\t\t\t\t\   ================================\n       \t\t\t\t\tEdit a  Faculte In UNIV\n\t\t\t\t   ================================");
        Color(45);
        printf("\nGive me a number of faculte (number in list of faculte) : ");
        Color(0);
        scanf(" %i",&j);

        fp=fopen("faculte.txt","a");
        printf("\nGive me a new name : ");
        scanf("%s",&f[j].name);
        printf("\nGive me a new number departement : ");
        scanf(" %i",&f[j].dep);
        printf("\nGive me a new number section : ");
        scanf(" %i",&f[j].section);
        int i;
        for( i= 0; i<f[j].section; i++)
        {
            printf("\n   + Give me a number of students in %i section : ",i+1);
            scanf(" %i",&f[j].numstu[i]);
        }
        Color(2);
        puts("\n  The faculte is sucessfully EDITED *-*");
        break;
    case 4 :
        system("CLS");
        Color(4);
        puts("\t *-DELETE Faculte-* ");
        fp=fopen("faculte.txt","w");
        fflush(stdin);
        Color(45);
        printf("    Give me a number the faculte that you will be delete (number in list of faculte) : ");
        Color(0);
        scanf(" %i",&j);
        for(i=j; i<=counterf-1; i++)
        {
            f[i] = f[i+1];
        }
        counterf-=1;
        Color(2);
        puts("\n  The faculte is sucessfully DELETED *-*");

    }
    do {
    Color(45);
    printf("\n\n\t ** Enter the Choice : \n\n\t[1] Main Menu\t\t[0] Exit\n\t");
    scanf(" %d",&ch);
    }while(ch > 1 || ch < 0);
    switch(ch)
    {
    case 1:
        goto menu;
    case 0:
        break;
    default:
        printf("Invalid choice");
        break;
    }
}

