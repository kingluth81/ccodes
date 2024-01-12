#include <stdio.h>
#define MAX 5

typedef struct event{
    int hour;               
    int minute;         
    char description[41];   // to describe event

} Event;

// Function prototypes
int InputRange(int min, int max);
Event* InputEvent(Event *newEvent);
int AddEventAtIndex(Event list[], Event e, int i);
int InsertionSortEvent(Event list[], int *p_size, Event e);
void DisplayEvent(Event e);
void DisplayEventList(Event list[], int size);
int DeleteEvent(Event list[], int i, int *p_size);

// bonus
int SaveEventList(char *filename,Event list[],int size);
int LoadEventList(char *filename,Event list[],int *p_size);
void encode(char*s);
void decode(char*s);


int InputRange(int min, int max){
    int input;
    do{
        printf("Enter an integer between %d and %d: ", min, max);
        scanf("%d", &input);
        printf("\n");

        if(input < min || input > max)
            printf("Input is invalid\n");

    } while(input < min || input > max);

    return input;
}

Event* InputEvent(Event *newEvent){
    if(newEvent != NULL) // condition to check if the pointer is valid or invalid
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

// function to add an event
int AddEventAtIndex(Event list[], Event e, int i){
    list[i] = e;
    return i;

}

// function to sort an event in ascending order
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

        // to move wrongly placed index down
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

// function to display an event in hh:mm format
void DisplayEvent(Event e){
    printf("%02d:%02d %s\n", e.hour, e.minute, e.description);
}

// function to display all events
void DisplayEventList(Event list[], int size){
    for(int x = 0; x < size; x++){
        printf("[%d] ", x);
        DisplayEvent(list[x]);
    }
}

// function to delete an event
int DeleteEvent(Event list[], int i, int *p_size){
    for(int x = i; x < *p_size - 1; x++){
        list[i] = list[i+1];
        }
    --(*p_size);
    return 1;
}

// funcion that takes a string and replaces the space characters with a _
void encode(char*s){
    int x = 0;
    while(s[x] != '\0'){
        if(s[x] == ' '){
            s[x] = '_';
        }
        ++x;
    }
}

// function that takes a string and replaces the _ characters with a space
void decode(char*s){
    int x = 0;
    while(s[x] != '\0'){
        if(s[x] == '_'){
            s[x] = ' ';
        }
        ++x;
    }
}

// function that saves a given Event list to a file
int SaveEventList(char *filename, Event list[], int size){
    FILE * file;
    file = fopen(filename, "w");
    for(int x = 0; x < size; ++x){
        encode((list[x]).description);
        fprintf(file, "%d %d %s", (list[x]).hour,(list[x]).minute,(list[x]).description);
        decode((list[x]).description);
        if((x+1) != size){
            fprintf(file, "\n");
        }
    }
    fclose(file);
    return size;
}

// function to load event from a file and saves it into a event list
int LoadEventList(char *filename, Event list[], int *p_size){
    FILE * file;
    file = fopen(filename, "r");
    *p_size = 0;

    // condition to load every line in the file until we reach the end of the file
    while(!feof(file)){
        fscanf(file, "%d %d %s", &(list[*p_size]).hour,&(list[*p_size]).minute,(list[*p_size]).description);
        ++(*p_size);
    }

    for(int x = 0; x < *p_size; x++){
        decode(list[x].description);
    }

    fclose(file);
    return *p_size;
}

void PrintMenu(void){
    puts("__= Scheduler v1.0 =__");
    puts("   1. Schedule an event.");
    puts("   2. Delete an event.");
    puts("   3. Display schedule.");
    puts("   4. Save schedule.");
    puts("   5. Load schedule.");
    puts("   6. Exit");
    printf("==> ");
}

int main(){
    Event EventList[MAX];
    Event tempEvent;
    int eventListSize = 0;


    int result;
    int opt = 1;
    int id; // to determine event to delete
    char temp[41];

    PrintMenu();
    opt = InputRange(1, 6);

// case switch condtion to switch between each cases
    while(opt != 6){
        switch(opt){
            case 1:
                if(eventListSize < MAX){
                    InsertionSortEvent(EventList, &eventListSize, *InputEvent(&tempEvent));
                }
                else {
                    printf("Sorry you've reached the maximum number of events you can add to the schedule!\n");
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

            case 4:
                if(eventListSize == 0){
                    printf("There are 0 files to save. Please add atleast 1 event to save.\n");
                } else {
                    printf("What is the name of the file you would like to save to?\n");
                    scanf(" %[^\n]s", temp);
                    result = SaveEventList(temp, EventList, eventListSize);
                    if(result == -1){
                        printf("Something went wrong :/\n");
                    } else {
                        printf("%d events were saved to %s\n", result, temp);
                    }
                }
                break;

            case 5:
                printf("What file will you like to load from?\n");
                scanf(" %[^\n]s", temp);
                result = LoadEventList(temp, EventList, &eventListSize);
                if(result == -1){
                    printf("Something went wrong :/\n");
                }
                else {
                    printf("%d events were loaded from %s\n", result, temp);
                }
                break;
            default:
                printf("Something went wrong :/\n");
        }
        PrintMenu();
        opt = InputRange(1, 6);
    }

    return 0;
}