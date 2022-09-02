/*Arthur Hernandez
  C291 hw6 q1
  Tuesday May 5th 
  */
#include<stdio.h>
#include<string.h>
//structure of student
struct student {
  char lastName[ 15 ];
  char firstName[ 15 ]; 
  char location[ 10 ];
  int age;
};
//will search through records 
void records(FILE *filePtr);

int main(void){
     char lastN[15];
     char firstN[15]; 
     char loc[1];
     int agee;
    FILE *filePtr;
    int count = 0;
   //opens read and write file nameage.dat
    if((filePtr = fopen("nameage.dat","w+")) == NULL) {
         puts("File could not be opened");
    }else{  
        //if it works it will assign astudent that is unassigned or if even it will ask for inputs for each
        for(count = 1; count <= 20; ++count){
            struct student aStudent = {"unassigned", "","n\\a",0};
            if(count % 2 == 0){
              printf("Enter information for student number %d:\n",count);

              printf("Input Last Name: \n");
              scanf("%s",lastN);
              printf("Input First Name: \n");
              scanf("%s",firstN);
              printf("Input Location: \n");
              scanf("%s",loc);
              printf("Input age: \n");
              scanf("%d",&agee);
              
              struct student newStudent = {lastN,firstN,loc,agee};
              fwrite(&newStudent,sizeof(struct student),1,filePtr);
          }else{
           //initializes empty aStudent if not even 
           fwrite(&aStudent,sizeof(struct student),1,filePtr);
          }
     }
    //asks for search 
    printf("would you like to search through the records enter y or n?");
    char yOrN;
    scanf(" %c", &yOrN);
    if(yOrN == 'y' || yOrN == 'Y' ){
        records(filePtr);
    }
}   
fclose(filePtr);
return 0;
}
//searches records using last names 
void records(FILE *filePtr){
    char last[15];
    printf("please enter a last name you would like to search for through the records: \n");
    scanf("%s",last);
    //starts at the begining of the file
    fseek( filePtr, 0, SEEK_SET );
    struct student in;
    struct student temp; 
    reads all students students
    while(fread(&in, sizeof(struct student), 1, filePtr))
      //if last names match then the name is shown
      if(strcmp(in.lastName ,last) == 0){
          printf("Found: %s\nLast name: %s\nFirst name: %s\n Location: %s\nAge: %d\n",last,in.lastName,in.firstName,in.location,in.age);
          fseek( filePtr, 0, SEEK_CUR );//sets the poitner to the current so it doesnt repeat over what has already been searched
          while(fread(&temp, sizeof(struct student), 1, filePtr)){
              // if temp is the same as the first (in)
              if(strcmp(temp.lastName,in.lastName) == 0 && strcmp(temp.firstName, in.firstName) == 0 && strcmp(temp.location,in.location) == 0 && in.age == temp.age){
                  struct student temp = {"unassigned", "","n\\a",0};  //temp is reinitiallized and set in place
                  fwrite(&temp,sizeof(struct student),1,filePtr); //this set it in the same spot as temp
              }
          }
      }
}



