/*Arthur Hernandez
C291 hw 6 question 3
  Tuesday May 5th
*/

#include<stdio.h>
#include<string.h>

char *clean_quotes(char *string, char *unquotedWord);

int main(void) {
  char john[10] = "John";
  char john1[10] = "'John'";
  printf("%s  ",john);
  printf("%s\n",john1);
  char quotedStr[30];
  //dynamic array alloc
  char *string = (char *) malloc (30);
  printf("Please enter a string with quotes");
  scanf("%s",string);
  string = clean_quotes(string,quotedStr);
  printf("your string without quotes is: %s\n",string);
  return 0;
}

char *clean_quotes(char *stringArr, char *unquotedWord) {
    //set memory of unquotedWord
  memset(unquotedWord, '\0', sizeof(unquotedWord));
  strcpy(unquotedWord, stringArr);
  int i, j= 0; 
  for(i = 0; stringArr[i]!='\0'; i++) {
    if(stringArr[i]!='"' && stringArr[i]!='\'')
      unquotedWord[j++] = stringArr[i];
  }
  unquotedWord[j] = '\0';
  return unquotedWord;
}


