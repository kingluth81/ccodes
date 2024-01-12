#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <time.h>

const int page_size = 256;
const int virtualMemory_size = 256;
const int physicalMemory_size = 256;

int main(int argc, char *argv[]){

    int physical_memory[physicalMemory_size];
    int virtual_memory[virtualMemory_size][2];

    
    for(int i = 0; i < virtualMemory_size; i++){
        virtual_memory[i][0] = (i > physicalMemory_size - 1)? -1 : i;
        virtual_memory[i][1] = (i > physicalMemory_size - 1)? -1 : physicalMemory_size - i;
    }
    for(int i = 0; i < physicalMemory_size; i++){
        physical_memory[i] = i;
    }

    //Making sure the user has the files needed
    if(argc != 2){
        printf("\nFiles incomplete...\n");
        return 1;
    }

    FILE *pFile;
    pFile = fopen(argv[1], "r");

    //Checking if the text file can be opened, if not exit
    if(pFile == NULL){
        printf("\nYour file %s could not be opened: %s\n", argv[1], strerror(errno));
        exit(EXIT_FAILURE);
    }


    printf("\nWelcome to the Virtual Memory Manager!\n" );
        
        char *line = NULL;
        size_t length = 0;
        ssize_t read;

        int page_number = 0;
        int physicalAddress = 0;
        int pageFault_count = 0;
        double pageFault_rate = 0.0;

        while((read = getline(&line, &length, pFile)) != -1){
            int offset = atoi(line) & 255;
            int page = atoi(line) & 65280;
            int page_table_number = page >> 8;

            if(virtual_memory[page_table_number][0] < 0){
                        pageFault_count++;
                }

                    //printing formatting for Virtual Address
                    if (page < 100) {
                        printf("\nVirtual Address: %d\t", page);
                    }
                    else if (page < 1000) {
                        printf("\nVirtual Address: %d\t", page);
                    }
                    else {
                        printf("\nVirtual Address: %d\t", page);
                    }

                    //Calculating the physical address
                    physicalAddress = (physical_memory[virtual_memory[page_table_number][0]] * page_size) + offset;
                    printf("\tPhysical Address: %d\t", physicalAddress);
                
                    //Calculating the corresponding value
                    signed char values = ( physicalAddress * page_size ) + offset;
                    printf("\tValues: %d \t", values);

                    page_number++;

                    for(int i = 0; i < virtualMemory_size; i++){
                        virtual_memory[i][1]++;
                    }
                }
                pageFault_rate = (double) pageFault_count / 1000 * 100;
                printf("\n\nThe Page Fault Rate is: %.2f%%\n", pageFault_rate);

                free(line);
                fclose(pFile);
                exit(EXIT_SUCCESS);
                
            }