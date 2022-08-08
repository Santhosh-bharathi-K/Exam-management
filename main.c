
#include <stdio.h>
#include<string.h>
struct students
{
    char name[20],fees[10];
    int rollno,present;
    
};



int main()
{  int n;
   
    printf("enter the number of students:");
    scanf("%d",&n);
    struct students stud[n];
    int i;
    
    for(i=0;i<n;i++){
        printf("Enter the name of the student%d:",i+1);
        scanf("%s",stud[i].name);
        printf("Enter the roll number:");
        scanf("%d",&stud[i].rollno);
        printf("Enter number of days present(out of 250):");
        scanf("%d",&stud[i].present);
        printf("Your attendence percentage is:%d\n",stud[i].present*100/250);
        printf("Enter 'p' if fees paid or 'n' for not paid\n");
        scanf("%s",stud[i].fees);
        if(stud[i].present*100/250<70||stud[i].fees[0]=='n')
        printf("You are not eligible\n");
        else
        printf("You are eligible\n\n");
    }
    int fno=i;
    int display(struct students[],int n );
    int delete1 (struct students[],int);
    int update1(struct students[],int n);
    int choice;
     do
    {

        printf("\n---list of operations---\n");
        printf("Press 1 to display.\n");
        printf("Press 2 to update the data.\n");
        printf("Press 3 to delete\n");

        printf("Press 0 to exit\n");
        printf("\nEnter choice(0-3) : ");
        scanf("%d", &choice);
        switch (choice)
        {
            
            case 1:
            	display(stud,n);
                break;
            case 2:
            	update1(stud,n);
            	break;
            case 3:
                n-=delete1(stud,n);
                break;
                
        }
    }
    while (choice != 0);
	return 0;
}
int display(struct students stu[],int n){
	
    printf("#Details of the students#:\n");
    int i;
    for(i=0;i<n;i++){
        
        printf("name of the student:%s\n",stu[i].name);
        printf("roll number:%d\n",stu[i].rollno);
        printf("number of days precent:%d\n",stu[i].present*100/250);
         if(stu[i].present*100/250<70||stu[i].fees[0]=='n')
        printf("You are not eligible.\n");
        else
        printf("You are eligible.\n\n");
      
}
return 0;}

int delete1 (struct students s[],int n)
{
    int i,j,nd;
	int a = 0;
    printf("Enter the roll number of the student to be deleted:\t");
    scanf("%d", &a);
    for (i = 0; i <= n; i++) {
        if (s[i].rollno == (a)) {
        	
            for (j = i; j < n; j++) {
                strcpy(s[j].name,s[j + 1].name);
                strcpy(s[j].fees,s[j + 1].fees);
                s[j].rollno = s[j + 1].rollno;
                s[j].present= s[j + 1].present;
            }
        printf("Student Record Has been deleted."); 
        return 1;}
        else
        	nd+=1;
        }
        if(i==nd)
        {
        	return 0;
		}
 
}
int update1 (struct students stud[],int n)
{
    int i,j;
	int a,rollt,feest,pres;
	char pay[10];
	char nametemp[20];
    printf("Enter the roll number of the student to update: \t");
    scanf("%d", &a);
    for (i = 0; i <= n; i++) {
        if (stud[i].rollno == (a)) {
        printf("Enter the name of the student%d:",i+1);
        scanf("%s",nametemp);
        strcpy(stud[i].name,nametemp);
        printf("Enter the roll number:");
        scanf("%d",&rollt);
        stud[i].rollno=rollt;
        printf("Enter the present days:");
        scanf("%d",&pres);
        stud[i].present=pres;
        printf("Your attendence percentage is:%d\n",stud[i].present*100/250);
        printf("Enter 'p' if fees paid or 'n' for not paid\n");
        scanf("%s", pay);
        strcpy(stud[i].fees,pay);
            
            printf("Student Record updated!");
            return 0;
        } 
    }
}

