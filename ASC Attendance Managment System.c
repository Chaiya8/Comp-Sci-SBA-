//Attendance Management System
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct student
{
    char name[20];
    int idno;
    char dep[15];
    float attd, pres, tcls;
  /*int nattd;
     int pres;
     int tcls; */
} s[100];


int
   main ()
{

  char dep;
  FILE *f;
  FILE *u;
  FILE *fp;
  FILE *p;
  int found = 0;
  int i, n, m, mm,nm;
  //int idno;
  char name2;
  char c;
    //design code
     
    printf("\n\n\n\n*******************************************************************************************************************\n");
    printf("*******************************************************************************************************************\n");
    printf("\t\t\t\tANTIGUA STATE COLLEGE ATTENDANCE MANAGEMENT SYSTEM\n");
    printf("*******************************************************************************************************************");
    printf("\n*******************************************************************************************************************\n\n");
    printf("                                       ========================\n");
    printf("                                       |     LOGIN PORTAL     | \n");
    printf("                                       ========================\n\n\n");
    printf("\n\t           PRESS 1 ==> Teacher \n");
    printf("\t           PRESS 2 ==> Student\n");
    printf ("   \n\n\t\t   :  ");
    scanf ("%d", &mm);
    
    jump: //jump2, jump, and jj are labels with the function goto that helos the program go back to the main menu. i.e login portal
    if (mm==1) { //if the user chooses to login as a teacher, the program will allow admin options for student records
        printf("\n\n\n\n*******************************************************************************************************************\n");
        printf("*******************************************************************************************************************\n");
        printf("\t\t\t\tANTIGUA STATE COLLEGE ATTENDANCE MANAGEMENT SYSTEM\n");
        printf("*******************************************************************************************************************");
        printf("\n*******************************************************************************************************************\n\n");
        printf("\n\t           PRESS 1 ==> Input Record \n");
        printf("\t           PRESS 2 ==> View Attendance\n");
        printf("\t           PRESS 3 ==> View Records\n");
        printf("\t           PRESS 4 ==> EXIT\n");
        printf ("   \n\n\n\n\t\t\t\t   :  ");
        scanf ("%d", &m);


//            1    TAKING INPUT


        if (m == 1) {
            printf ("\n\t\t\t\t________ADD RECORD________\n\n");
      //system("cls");
            printf ("\n\nEnter the class size :\t");
            scanf ("%d", &n);
      //class size is now saved to n 

      //                      INPUT RECORD

        for (i = 1; i <= n; i++) {
	        printf ("Enter student %d name :\t", i);
	        scanf ("\n%[^\n]s", s[i].name);
	  
	        printf ("Enter student ID number :\t");
	        scanf ("\n%d", &s[i].idno);
	  
	        printf ("Enter student department : \t");
	        scanf ("\n%[^\n]s", s[i].dep);
	        printf ("Enter total number of classes held :\t");
	        scanf ("\n%2f", &s[i].tcls);
	        printf ("Enter number of classes student attended :\t");
	        scanf ("\n%2f", &s[i].pres);
	        //Attendance calculation 
	        s[i].attd = s[i].pres/s[i].tcls*100;
	        printf ("Attendance : \n%2f\n\n",s[i].attd);      
        }
	  
      //writing and saving the records to the file, to record text. only teachers will see
            f = fopen ("record.txt", "a+");
            for (i = 1; i <= n; i++)
	        {
	            fprintf (f, "Name: %s\n ID no: %d\n Department: %s\n Attendance: %2f\n\n\n",s[i].name, s[i].idno, s[i].dep, s[i].attd);
	        }
            fclose (f);
      

     //saving the students' name, department and attendance details to attdetails.text. this file show student who did and did not meet the criteria
            u = fopen ("attddetails.txt", "a+");
            for (i = 1; i <= n; i++)
	        {  
	            fprintf(u,"Name: %s\n ID no: %d\n Department: %s\n Attendance: %2f",s[i].name, s[i].idno, s[i].dep, s[i].attd);
	            if (s[i].attd >=80) {
	                fprintf(u,"\nThis student is eligible to sit the exam.");
	                fprintf(u,"\n=======================================================\n\n\n");
	      
	            } else {
	                fprintf(u,"\nThis student is not eligible to sit the exam.");
	                fprintf(u,"\n=======================================================\n\n\n");
	               }
	   
	        }
            fclose (u); //close file
      
      // code for file which will be displayed when students login. they will see if the are eligible to sit their exam or not
            p = fopen ("check.txt", "a+");
            for (i = 1; i <= n; i++)
	        {  
	            fprintf(p,"Name: %s\n Department: %s\n Attendance: %2f",s[i].name, s[i].dep, s[i].attd);
	            if (s[i].attd >=80) {
	                fprintf(p,"\nCONGRATULATIONS! YOU ARE ELIGIBLE :)");
	                fprintf(p,"\n=====================================================\n\n\n");
	      
	            } else {
	                fprintf(p,"\nUNFORTUNATELY YOU ARE NOT ELIGIBLE :(");
	                fprintf(p,"\n=====================================================\n\n\n");
	              }
	   
	        }   
            fclose(p);

        goto jump;		//returns to the teacher's menu
        }

  //                           2 FINAL ATTENDANCE
        else if (m == 2)
        {
            printf ("\n\t\t\t\t________SEE FINAL ATTENDANCE________\n\n");
    //code that allows program to output what was stored in the file
        char ch;
	    FILE *fp;
	    fp = fopen ("attddetails.txt", "r+");
	    ch = fgetc (fp);
	    while (ch != EOF)
	    {
	        printf ("%c", ch);
	        ch = fgetc (fp);

	    }
	    fclose (fp);
	    goto jump;//this jump goes back the second main menu for teachers

      } 


    //              3 View the records in record txt.
    else if (m == 3)
    {
	    char ch;
	    FILE *fp;

	    printf ("\n\t\t\t\t________VIEW RECORD________\n\n");

	    fp = fopen ("record.txt", "r+");
	    ch = fgetc (fp);
	    while (ch != EOF)
	    {
	    printf ("%c", ch);
	    ch = fgetc (fp);

	    }
	    fclose (fp);
	    goto jump;
      }


      //code that allow users to exit program
    else if (m == 4)
    {
	//system("cls");
	    printf ("\n*** Thank you for using the program! Goodbye. ***");
    }

    else
    {
	//if the user enters a wrong option
	    printf ("INVALID SELECTION!!!");
	    return main ();//returns to the main menu which asks for the user to login
        }
    //The portal for teachers end.
    }
    //this is the portal for students
    else if (mm==2) {
    // Design code
        printf("\n\n\n\t\t\t\t_________WELCOME STUDENT________\n\n");
        printf("\t\t    Please check if you're elegible to sit the exam.....\n\n");
        printf("\t           PRESS 1 ==> Check\n");
        printf ("   \n\n\t\t   :  ");
        scanf ("%d", &nm);
    
        if(nm = 1) {
            printf("\n\n\n\t\t\t\t\t_________STUDENTS ELIGIBILITY________\n\n");
   //code for students to view the file
            char  ch;
            FILE *fp;
	        fp = fopen("check.txt", "r+");
	        ch = fgetc (fp);
    	    while (ch != EOF)
	        {
	            printf ("%c", ch);
	            ch = fgetc (fp);
	        }
	        fclose (fp);
	    goto jj;
        }
     
         jj: //ends the studentb portal
         	printf("\n                            *** Thank you for using the program! Goodbye. ***");
         	printf("\n                                       ========================\n");
            printf("                                       |      !!GOODBYE!!     | \n");
            printf("                                       ========================\n\n\n");
     
     }


  return 0;
}