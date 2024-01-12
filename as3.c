#include <stdio.h>
#define MAX 5

typedef struct event{
    int hour;               
    int minute;         
    char description[41]; 

} Event;


int InputRange(int min, int max);
Event* InputEvent(Event *newEvent);
int AddEventAtIndex(Event list[], Event e, int i);
int InsertionSortEvent(Event list[], int *p_size, Event e);
void DisplayEvent(Event e);
void DisplayEventList(Event list[], int size);
int DeleteEvent(Event list[], int i, int *p_size);


int InputRange(int min, int max){
    int input;
    do{
        printf("Please Enter an integer between %d and %d: ", min, max);
        scanf("%d", &input);
        printf("\n");

        if(input < min || input > max)
            printf("Input is invalid\n");

    } while(input < min || input > max);

    return input;
}

Event* InputEvent(Event *newEvent){
    if(newEvent != NULL)
    {
        printf("Please enter desired event time:\n");
        newEvent->hour = InputRange(0, 23);
        newEvent->minute = InputRange(0, 59);
        printf("Please describe your event: ");
        scanf(" %[^\n]s", newEvent->description);
    }
    else{
        return newEvent;
    }
    return newEvent;
}


int AddEventAtIndex(Event list[], Event e, int i){
    list[i] = e;
    return i;

}

int InsertionSortEvent(Event list[], int *p_size, Event e){
    int index = *p_size;

    if(*p_size == 0){
        list[0] = e;
        ++(*p_size);
        return 0;
    }
    else if (*p_size > 0){
        for(int x = 0; x < *p_size; x++){
            if(((list[x]).hour > e.hour) || (((list[x]).hour == e.hour) && ((list[x]).minute > e.minute))){
                index = x;
                break;
            }
        }

        for(int x = *p_size; x >= index + 1; x--){
            list[x] = list[x-1];
        }

        AddEventAtIndex(list, e, index);
        ++(*p_size);
    
        return index;

    }
    else {
        return *p_size;
    }

}

void DisplayEvent(Event e){
    printf("%02d:%02d %s\n", e.hour, e.minute, e.description);
}


void DisplayEventList(Event list[], int size){
    for(int x = 0; x < size; x++){
        printf("[%d] ", x);
        DisplayEvent(list[x]);
    }
}

int DeleteEvent(Event list[], int i, int *p_size){
    for(int x = i; x < *p_size - 1; x++){
        list[i] = list[i+1];
        }
    --(*p_size);
    return 1;
}

void PrintMenu(void){
    puts("__= Scheduler v1.0 =__");
    puts("   1. Schedule an event.");
    puts("   2. Delete an event.");
    puts("   3. Display schedule.");
    puts("   4. Exit");
    printf("==> ");
}

int main(){
    Event EventList[MAX];
    Event tempEvent;
    int eventListSize = 0;


    int result;
    int opt = 1;
    int id; 
    char temp[41];

    PrintMenu();
    opt = InputRange(1, 6);

    while(opt != 6){
        switch(opt){
            case 1:
                if(eventListSize < MAX){
                    InsertionSortEvent(EventList, &eventListSize, *InputEvent(&tempEvent));
                }
                else {
                    printf("You've reached the maximum number of events you can add to the schedule!\n");
                }
                break;

            case 2:
                if(eventListSize == 0){
                    printf("You need to have an event to delete one\n");
                }
                else {
                    printf("Which event would you like to delete (-1 to cancel)?\n");;
                    scanf("%d", &id);
                    if(id == -1){
                        printf("Canceling...\n");
                    }
                    else if(DeleteEvent(EventList, id, &eventListSize) == -1){
                        printf("Deleting the event has failed.\n");
                        printf("Possible reasons event could not delete:\n1: I is not in a valid range of events in the array\n2: The list is already empty");
                    }
                    else {
                        printf("Event deleted successfully!\n");
                    }
                }

                break;

            case 3:
                if(eventListSize == 0){
                    printf("You need to have an event to display first...\n");
                }
                else{
                    printf("____=Schedule=____\n");
                    DisplayEventList(EventList, eventListSize);
                }

                break;

        }
        PrintMenu();
        opt = InputRange(1, 6);
    }

    return 0;
}