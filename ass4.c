
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
19 0 Dinner_at_Subway_with_friends
14 30 Lab_in_Erie_Hall
8 5 Early_class
21 30 Read_my_lecture_notes_before_bed
12 30 Lunch_date_in_the_CAW
8 5 Early_class
12 30 Review_my_midterm
*/  
// Structure Deffintion of an event aggregate data type 
typedef struct event
{
    int hour; // between 0 and 23 inclusive
    int minute; // between 0 and 59 inclusive 
    char description[41]; // string descripng event 
   
    struct event* ptrNext; // self-referential pointer 
}Event ;
 
 
Event* ptrFirst = NULL; // pointer to beggining of the list 
Event* ptrLast = NULL; // pointer to the end of list 
 
// Function Prototypes 
void addEvent(int,int,char[41]);    // call to addEvent 
void viewEvents();          // call to view Events 
void loadEvents(char *);     // Loads events from specific file name 
int saveEvents(char *);     // Saves events to specific file name 
int checkRepeated(int,int,char[41]); 


int main(){// Beggining of program main 
 
   loadEvents("mylist.txt");
    viewEvents();
    printf("Saved [%d] Events back into the List File\n",saveEvents("mylist.txt")); 
    return 0;
   
} // end of main 

/* Name: addEvent 
   The function takes the created new node then adds the new node to the linked list 
   */ 
void addEvent(int h, int m, char des[41])
{
 
   Event *newnode=(Event *) malloc(sizeof(Event)); 
   newnode->hour = h; 
   newnode->minute = m; 
   strcpy(newnode->description,des); 
   
   
   if(ptrFirst == NULL)
   {
       ptrFirst = newnode;
       return; 
   }
   
   Event * p = ptrFirst, *L = p; 
   
   
   while((p!= NULL && p->hour<h) || (p!= NULL && p->hour==h && p->minute < m)){
       L=p; 
       p=p->ptrNext; 
   }
   
   if(p == ptrFirst )
   {
       newnode->ptrNext = ptrFirst; 
       ptrFirst = newnode; 
   }
  else{
      newnode->ptrNext = L->ptrNext; 
      L->ptrNext = newnode; 
  }
   
   
   
   
}
 
 
// Name: viewEvents
// iterates through the linked list 
// till node next is NULL
void viewEvents()  
{
    Event* ptrCurrent = NULL;
   
    ptrCurrent = ptrFirst;
    while( ptrCurrent != NULL) // while ptrCurrent isnt pointing to the end of the list print 
    {
        printf("%02d:%02d %s\n\n", ptrCurrent->hour,ptrCurrent->minute,ptrCurrent->description);
        ptrCurrent = ptrCurrent->ptrNext;
    }
}
 
// Name: saveEvents 
// Saves the linked list to file 
int saveEvents(char *filename)
{
	FILE *fn;
	int n = 0;	
	Event* ptrCurrent = NULL;

	fn = fopen(filename, "w");

	if (fn != NULL)
	{
	
		ptrCurrent = ptrFirst;
		while( ptrCurrent != NULL) // continues to save till ptrCurrent is null 
		{
				fprintf(fn, "%d %d %s\n", ptrCurrent->hour, ptrCurrent->minute, ptrCurrent->description);
			    ptrCurrent = ptrCurrent->ptrNext;
			    n++; // increments the amount of events saved 
		}
				
		fclose(fn);
	}

	return n;
}

// Name: loadEvents
// loads the file contents into a linked list 
void loadEvents(char *filename)
{
    FILE *f;
 
    f = fopen(filename, "r");
   int h,m; 
   char des[41]; 
    if (f != NULL)
    {
        while(!feof(f)) // iterates through each file till end of file 
        {
            fscanf(f, "%d%d%s", &h,&m,des); 
            if(checkRepeated(h,m,des) == 0 ){
                
                addEvent(h,m,des);
            }
            
        }  
    }
   
 
}

int checkRepeated(int h, int m, char des[41])
{
    Event *p = ptrFirst; 
    
    while (p != NULL)
    {
        if(p->hour == h && p->minute == m && strcmp(p->description,des) == 0)
        {
            return 1; 
        }
        p = p->ptrNext; 
    }
    return 0; 
}