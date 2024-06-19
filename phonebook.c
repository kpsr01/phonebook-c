#include <stdio.h>
#include <string.h>
#include <ctype.h>
typedef struct
{
  char name[100];
  int phno;
}contact; 

void get_details(int n,contact contact1[n])
{
  char s[255];
  int found1=0;
  FILE *pff=fopen("phonebook.txt","r");
   for (int i=0;i<n;i++)
  {
    printf("Enter details of person%d\n", i+1);
    printf("Name: ");
    scanf("%s", contact1[i].name);
    for (int j = 0; contact1[i].name[j]; j++) 
        {
          contact1[i].name[j] = toupper(contact1[i].name[j]);
        }
        while (fgets(s, 255, pff) != NULL) 
         {
                int leng = strlen(s);
                if (leng>0&&s[leng-1]=='\n') 
                {
                    s[leng-1]='\0';
                }
        if(strcmp(s,contact1[i].name)==0)
        {
          printf("\nContact already exists\nEnter new contact\n");
          get_details;
          found1=1;
          break;
        }
        if(found1==1)
        {
          continue;
        }
    printf("Number: ");
    scanf("%d", &contact1[i].phno);
     
         }
}
}

int main()
{
  int n;
  printf("Enter number of contacts: ");
  scanf("%d", &n);
  contact contact1[n];
  printf("Type \"1\" to add new contact\nType \"2\" to search for existing contact\n");
  int input;
  scanf("%d", &input);
  if (input==1)
  {
    get_details(n, contact1);
    FILE *pF=fopen("phonebook.txt", "a");
    for (int i=0;i<n;i++)
    {
      fprintf(pF,"%s\n%d\n",contact1[i].name,contact1[i].phno);
    }
  }
else if(input==2)
{
  char scan[100];
  printf("Enter name of the contact: ");
  scanf("%s", scan);
  FILE *pf=fopen("phonebook.txt","r");
  char string[255];
  int found=0;
  while (fgets(string, 255, pf) != NULL)
        {
            int len = strlen(string);
            if (len>0&&string[len-1]=='\n')
             {
                string[len-1] ='\0';
             }

            if (strcmp(string, scan) == 0)
             {
                printf("%s\n", string);
                if (fgets(string, 255, pf) != NULL) 
                {
                  printf("%s", string);
                }
                found=1;
                break;
             }
        }
        if (!found)
        {
          printf("Contact not found\n");
        }
  fclose(pf);
}
}
