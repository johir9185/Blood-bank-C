#include <stdio.h>
#include <conio.h>
#include <string.h>

struct person{
    char name[20];
     char address[20];
     char blood_group [50];
     long unsigned int mobile_num;

};

void appendData(){
      FILE *fp1,*fp2;
      struct person obj;
      fp1=fopen("text.in","a");
      fp1=fopen("text.in","r");
      fp2=fopen("text.out","r+");
      system ("color 5a");
      printf("\n\n\t\t*****Add Record****\n");
      printf ("\t\tEnter your blood_group :");
      scanf ("%s",obj.blood_group);
      printf("\t\tEnter Name : ");
      scanf("%s",obj.name);
      printf("\t\tEnter your address : ");
      scanf("%s",&obj.address);
      printf ("\t\tEnter your Mobile number :");
      scanf ("%lu",&obj.mobile_num);
      fprintf(fp1,"%s\t%s\t%s\t%lu",obj.blood_group,obj.name,obj.address,&obj.mobile_num);
      fprintf(fp2,"%s\t%s\t%s\t%lu",obj.blood_group,obj.name,obj.address,&obj.mobile_num);
      fclose(fp1);fclose(fp2);
}

void showAllData(){
      FILE *fp1,*fp2;
      struct person obj;
      fp1=fopen("text.in","r");
      fp2=fopen("text.out","r");
      printf("\n\n\t\t*****Display All Records*****\n");
      printf("\n\nblood group\tName\t\taddress\t\tmobile num\n");
      //printf("\n\n\t\t=====\t\t=========\n\n");
      while(!feof(fp1))
      {
      fscanf(fp1,"%s %s %s %lu",obj.blood_group,obj.name,obj.address,&obj.mobile_num);
      printf("%s\t\t%s\t\t%s\t\t%lu\n",obj.blood_group,obj.name,obj.address,&obj.mobile_num);
      fprintf (fp2,"blood group :%s\nName :%s\naddress :%s\nmobile num :%lu",obj.blood_group,obj.name,obj.address,obj.mobile_num);
      }
      fclose(fp1);fclose(fp2);
}

void findData(){
      FILE *fp1,*fp2;
      struct person obj;
      char blood_group[50];
      char name [20];
      char address[20];
      unsigned long int mobile_num;
      int totrec=0;
      fp1=fopen("text.in","r+");
      fp2=fopen("text.out","w");
      printf("\n\n*****Display Specific Records*****\n");
      printf ("Enter blood_group:");
      scanf ("%s",&blood_group);
      //printf("\nEnter address : ");
      //scanf("%s",&address);
      while(!feof(fp1))
      {
      fscanf(fp1,"%s%s%s%lu",obj.blood_group,obj.name,obj.address,&obj.mobile_num);
      fscanf (fp2,"%s%s%s%lu",obj.blood_group,obj.name,obj.address,&obj.mobile_num);
         if(strcmp(obj.blood_group,blood_group)==0){
        printf("\n\nName:%s\taddress:%s \tmobile num:%lu\n",obj.name,obj.address,&obj.mobile_num);
        //fprintf (fp2,"%s%s%lu",obj.name,obj.address,&obj.mobile_num);
        totrec++;
         }
      }
      if(totrec==0)
         printf("\n\n\nNo Data Found");
      else
         printf("\n\n===Total %d Record found===",totrec);
      fclose(fp1);
}



void main(){
      char choice;
      while(1){
          system ("color 5a");
    printf("\t\t*****BLOOD BANK*****\n\n");
    printf("\t\t+++++++++++++++++++++\n");
    printf("\t\t|1. Insert Record   |\n");
    printf("\t\t|2. Find Record     |\n");
    printf("\t\t|3. Read all record |\n");
    printf("\t\t|4. exit            |\n");
    printf("\t\t+++++++++++++++++++++");
    printf("\n");
    printf("\n");
    printf("\t\tEnter your choice : ");
    fflush(stdin);
    choice = getche();
    switch(choice){
         case'1' : //call append record
            appendData();
            break;
         case'2' : //call find record
             findData();
            break;
         case'3' : //Read all record
            showAllData();
            break;
         case'4' :
         case 27  : exit(1);
    }
      }
}
