 // A C Program to store and get the cheapest price of walnut.        
#include<stdio.h>
#include<stdlib.> Including libraray files for the predefined functions used in this program.
struct info
{
char name[];
int price;
struct info *next;
};
struct info *temp,*disp,*head;
// Creating a user defined data type using structure to satisfy the memory storage of this program.
void addrecord();
void display();
void displaymin();
void displaymax();
void deleterecord();
// Declaring user defined functions for this program.

int main()
{
  int ch, ch1;
  while (1) 
   Using loop so that our function doesn't get close after a specific function, untill we enter the assigned input for exiting.
    {
      printf("\n~Akhrot tracker~\n");
      printf("\n 1. To add records.");
      printf("\n 2. To delete records.");
      printf("\n 3. To view the records.");
      printf("\n 4. To exit.");
      printf("\n Enter your choice: ");
// Print functions used for creating a user inteface.
      scanf("%d",&ch);
// Scan function is used to get the user input.       
      fflush(stdin);
      switch(ch)
            {
              case 1:
                  addrecord();
                      break;

              case 2:
                  deleterecord();
                    break;
              
              case 3:
                  printf("\n1. Display whole list.");
                  printf("\n2. Display minimum price.");
                  printf("\n3. Display maximum price.");
                  printf("\n Enter desired display option: ");
                  scanf("%d", &ch1);
                  switch(ch1)
                  {
                    case 1:
                      display();
                        break;

                    case 2:
                      displaymin();
                        break;

                    case 3:
                      displaymax();
                        break;

                    default:
                      printf("\n Invalid choice! :/");
                        break;
                  }
                      break;

              case 4:
                  exit(0);
                      break;

              default:
                  printf("Invalid choice! :/");
                    break;
            }
// Switch case is used to determine the function to be performed as per user input.

    }
return 0;
}

//Here onwards: The body of our declared functions.
void addrecord()
{
  struct info *add;
  // Using our user defined data structure a pointer variable is created.
  
  add=(struct info*)malloc(sizeof(struct info));
  //Line Memory is allocated to our variable using malloc.
  
  printf("\n Enter the name of dealer: ");
  gets(add->name);
  //As a name is generally considered as string so, gets is used to read that string & assign to the variable.
  fflush(stdin);
  printf("\n Enter the price of akhrot: ");
  scanf("%d",&add->price);
  // As a price is generally considered as number so, scanf is used to read that number & assign to the variable.
  fflush(stdin);

    if(head==NULL|| head->price>=add->price)
      {
        add->next=head;
        head=add;
      }
    else
      {
        temp=head;
          
          while(temp->next!=NULL && temp->next->price < add->price)
            {
              temp=temp->next;
            }
// A loop is used so that it can iterate through whole list and place the data entered in ascending order with respect to price.
        add->next=temp->next;
        temp->next=add;
      }

// if-else statements are used to insert/add the user input into the list.
  return;
 }

void display()
{
  int count=0;
// A integer value is declare…
