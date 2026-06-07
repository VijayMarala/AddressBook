#include <stdio.h>
#include "file.h"
#include<string.h>
#include<stdlib.h>

void saveContactsToFile(AddressBook *addressBook)           //save contacts to file 
{
 
	FILE *fptr=fopen("contactslist.txt", "w");
        if(fptr==NULL)
        {
                printf("there was a error to create file\n");
                return;
        }
	                                                       //wrinting contacts to file
        for(int i=0; i<addressBook->contactcount; i++)
        {
           fprintf(fptr, "%s\n%s\n%s\n", addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
           //  fgets(addressBook->contacts[i].name, 20, stdin);
	    // fgets(addressBook->contacts[i].phone, 11, stdin);
	     //fgets(addressBook->contacts[i].email, 20, stdin);
	}
        fclose(fptr);
 
}

void loadContactsFromFile(AddressBook *addressBook)            //load contacts from file in intial state
{
       //printf("file is loading\n");
	FILE *fptr=fopen("contactslist.txt", "r");
        if(fptr==NULL)
	{
		printf("File was not opened successfully\n");
		return;
	}
	while(1)
    {
         addressBook->contacts=realloc(addressBook->contacts, (addressBook->contactcount+1)*sizeof(Contact));
         if(addressBook->contacts==NULL)
         {
            printf("memory not allocated\n");
            return;
         }
        if(
        fgets(addressBook->contacts[addressBook->contactcount].name, 50, fptr) &&
        fgets(addressBook->contacts[addressBook->contactcount].phone, 20, fptr) &&
        fgets(addressBook->contacts[addressBook->contactcount].email, 50, fptr)
        )
        {
        // remove newline from each
        addressBook->contacts[addressBook->contactcount].name[
            strcspn(addressBook->contacts[addressBook->contactcount].name, "\n")] = 0;

        addressBook->contacts[addressBook->contactcount].phone[
            strcspn(addressBook->contacts[addressBook->contactcount].phone, "\n")] = 0;

        addressBook->contacts[addressBook->contactcount].email[
            strcspn(addressBook->contacts[addressBook->contactcount].email, "\n")] = 0;

        addressBook->contactcount++;
        }
        else
        break;
    }
			     
fclose(fptr);
}
