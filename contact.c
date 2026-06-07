#include <stdio.h>
#include<strings.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include <ctype.h>

void listContacts(AddressBook *addressBook)                                  //Display contacts to the screen 
{
	printf("%-25s%-20s%-23s\n", "NAME", "PHONE", "EMAIL");
	printf("---------------------------------------------------\n");
	for(int i=0; i<addressBook->contactcount; i++)
	{
		for(int j=i+1; j<addressBook->contactcount; j++)
		{
		      if((strcasecmp(addressBook->contacts[i].name,addressBook->contacts[j].name)>0))
		      {	      
			Contact temp = addressBook->contacts[i];
			addressBook->contacts[i]=addressBook->contacts[j];
			addressBook->contacts[j]=temp;
		      }
		}
	}
	for(int i=0; i<addressBook->contactcount; i++)
	{
		printf("%-20s",addressBook->contacts[i].name);
	    	printf("%-15s",addressBook->contacts[i].phone);
	    	printf("%-20s",addressBook->contacts[i].email);
	    	printf("\n");
    	}
    	printf("-----------------------------------------------------\n");
	printf("\n");
    	}

void saveAndExit(AddressBook *addressBook) 
{
}


void createContact(AddressBook *addressBook)                                //Add one contact at a time
{
        int i=0;
        addressBook->contacts=realloc(addressBook->contacts, (addressBook->contactcount+1)*sizeof(Contact));
	printf("Enter name: ");
   	scanf(" %[^\n]",addressBook->contacts[addressBook->contactcount].name);
	printf("Enter phone number: "); 
   	scanf(" %[^\n]",addressBook->contacts[addressBook->contactcount].phone);
        for(i=0; addressBook->contacts[addressBook->contactcount].phone[i]!='\0'; i++)
        {
                if(addressBook->contacts[addressBook->contactcount].phone[i]<'0' || addressBook->contacts[addressBook->contactcount].phone[i]>'9')
                {
                        goto end;
                }
                if(strlen(addressBook->contacts[addressBook->contactcount].phone)!=10)
                {
                        printf("Enter correct phone number\n");
                        goto end;
                }
        }
   	printf("Enter email: ");   
   	scanf(" %[^\n]",addressBook->contacts[addressBook->contactcount].email);
        char *res=strstr(addressBook->contacts[addressBook->contactcount].email, "@gmail.com");
        if(res==NULL)
        {
                goto end;
        }
        for(i=0; i<addressBook->contactcount; i++)
        {
                if(strcmp(addressBook->contacts[addressBook->contactcount].name , addressBook->contacts[i].name)==0)
                {
                        if(strcmp(addressBook->contacts[addressBook->contactcount].phone, addressBook->contacts[i].phone)==0)
                        {
                              if(strcmp(addressBook->contacts[addressBook->contactcount].email, addressBook->contacts[i].email)==0)
                              {
                                printf("this contact already present\n");
                                printf("\n");
                                return;
                              }  
                        }
                }
        }
     	        printf("contact successfully updated  \n");
	        (addressBook->contactcount)++;
	        printf("\n");
                return;
        end:
                printf("invalid contact details try again\n");
                printf("\n");
}

void searchContact(AddressBook *addressBook)                                //Search contacts from file 
{
	int ch, flag=0, i=0;
	char temp[20];
	printf("1.search by name\n");
	printf("2.search by number\n");
	printf("3.search by email\n");
        scanf("%d", &ch);
        getchar();
	switch(ch)
	{
		case 1:
			printf("Enter name :");
			scanf("%[^\n]",temp);
			for(i=0; i<addressBook->contactcount; i++)
			{
				if(strcasecmp(temp,addressBook->contacts[i].name)==0)     //comparing name to file
				{
					flag=1;
					break;
				}
			}
			break;

		case 2:
                        printf("Enter phone number: ");
                        scanf("%[^\n]",temp);
                        for(i=0; i<addressBook->contactcount; i++)
                        {
                                if(strcasecmp(temp,addressBook->contacts[i].phone)==0)
                                {
					flag=1;
					break;
                                }
			}
			break;
		case 3:
                        printf("Enter email :");
                        scanf("%[^\n]",temp);
                        for(i=0; i<addressBook->contactcount; i++)
                        {
                                if(strcasecmp(temp,addressBook->contacts[i].email)==0)
                                {
                                        flag=1;
					break;
			        }
			}
			break;
		default:
			printf("invalid\n");

	}
	if(flag==1)
	{
		printf("Contact details found : \n"); 
		printf("Name  : %s\n", addressBook->contacts[i].name);
                printf("Phone : %s\n", addressBook->contacts[i].phone);
                printf("Email : %s\n", addressBook->contacts[i].email);
		printf("\n");
	}
	else
	{
		printf("No details Found\n");
		printf("\n");
	}
 }

void editContact(AddressBook *addressBook)                        //edit existing contact
{
	/* Define the logic for Editcontact */
	int ch, flag=0;
        char temp[20],rename[20];
        printf("1.Edit name\n");
        printf("2.Edit number\n");
        printf("3.Edit email\n");
        scanf("%d", &ch);
        getchar();
        switch(ch)
	{
        	case 1:
                	printf("Enter name :");
                        scanf("%[^\n]",temp);
                        for(int i=0; i<addressBook->contactcount; i++)
                        {
                                if(strcasecmp(temp,addressBook->contacts[i].name)==0)
                                {
                                        printf("name was found\n");
					printf("rename: ");
					scanf(" %[^\n]", rename);
                                        strcpy(addressBook->contacts[i].name,rename);
                                        flag=1;
                                        printf("\n updated successfully\n");
                                }
                        }
                        if(flag==0)
                        	printf("Name was not found\n");
                        break;
                case 2:
                        printf("Enter phone number: ");
                        scanf("%[^\n]",temp);
                        for(int i=0; i<addressBook->contactcount; i++)
                        {
                                if(strcasecmp(temp,addressBook->contacts[i].phone)==0)
                                {
                                     printf("phone number was found\n");
				     printf("enter new number : ");
				     scanf(" %[^\n]", rename);
                                     strcpy(addressBook->contacts[i].phone, rename);
                                     flag=1;
                                     printf("\n updated successfully\n");
                                }
                        }
                        if(flag==0)
                        	printf("phone num  was not found\n");
                        break;
                case 3:
                        printf("Enter email :");
                        scanf("%[^\n]",temp);
                        for(int i=0; i<addressBook->contactcount; i++)
                        {
                                if(strcasecmp(temp,addressBook->contacts[i].email)==0)
                               {
                                        printf("email was found\n");
					printf("enter new email : ");
					scanf(" %[^\n]", rename);
                                        strcpy(addressBook->contacts[i].email,rename);
                                        flag=1;
                                        printf("\n updated successfully\n");
                               }
                        }
                        if(flag==0)
                        	printf("email was not found\n");
                        break;
                default:
                        printf("invalid\n");

        }
	printf("\n");
}

void deleteContact(AddressBook *addressBook)
{
	/* Define the logic for deletecontact */
	int ch, flag=0, i=0;
        char temp[20];
        printf("1.delete by  name\n");
        printf("2.delete by number\n");
        printf("3.delete by  email\n");
        scanf("%d", &ch);
        getchar();
        switch(ch){
                case 1:
                        printf("Enter name :");
                        scanf("%[^\n]",temp);
                        for(i=0; i<addressBook->contactcount; i++)
                        {
                                if(strcasecmp(temp,addressBook->contacts[i].name)==0)
                                {
                                        flag=1;
					break;
                                }
                        }
                        break;
                case 2:
                        printf("Enter phone number: ");
                        scanf("%[^\n]",temp);
                        for(i=0; i<addressBook->contactcount; i++)
                        {
                                if(strcasecmp(temp,addressBook->contacts[i].phone)==0)
                                {
                                     flag=1;
				     break;
                                }
                        }
                        break;
                case 3:
                        printf("Enter email :");
                        scanf("%[^\n]",temp);
                        for(i=0; i<addressBook->contactcount; i++)
                        {
                                if(strcasecmp(temp,addressBook->contacts[i].email)==0)
                               {
                                     flag=1;
				     break;
                               }
                        }
                        break;
                default:
                        printf("invalid\n");

        }
	if(flag==1)
	{
		 for(int j=i; j<addressBook->contactcount-1; j++)
		 {
		       addressBook->contacts[j]=addressBook->contacts[j+1];
		 }
		addressBook->contactcount--;
	printf("\n");	
	}
	else
	{
		printf("Contact details not found\n");
		printf("\n");
	}
} 
