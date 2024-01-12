#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define DEBUG 0

/*Globals*/
char WordList[101][21];        // stores a list of 100 words
int AnagramGroup[101];          // for each word, store
                                // corresponding group id

int wordcount=0;                // how many words in the list
int anagram_group_count=0;      // how many groups we have
int AnagramGroupSizes[100];     // each group id (by index) we
                                // store its size

int PrintTop = 5;               // how many of the top groups
                                // do we want print out

// reads a word from input then stores it at a given address
void ReadWord(char *buffer){
    scanf("%s", buffer);
    return;
}

// alphabetically sorts the letters of a word
// *word is the address of the word
// size is the amount of letters in the word
void SortWord(char *word, int size){
    char temp;
    for(int i = 0; i < size - 1; i++){
        for(int j = i + 1; j < size; j++){
            if((int)*(word+i) > (int)*(word+j)){
                temp = *(word+i);
                *(word+i) = *(word+j);
                *(word+j) = temp;
            }
        }
    }
    return;
}

// determines if 2 words are anagrams of one another
// *word1 and *word2 is the addresses of the words
// wanting to be checked
bool isAnagram(char *word1, char *word2){
    char temp1[21];
    char temp2[21];

    strcpy(temp1, word1);
    strcpy(temp2, word2);

    SortWord(temp1, strlen(temp1));
    SortWord(temp2, strlen(temp2));

    if(strcmp(temp1, temp2) == 0)
        return true;
    else
        return false;
}

// assigns a group id to a word words that are anagrams
// of one another will be assigned to the same group
// if no word is an angram of anyother word, a new group
// will be created
void AssignAnagramGroup(int wordIndex){
    for(int x = 0; x <= wordIndex; ++x){
        if(x==wordIndex){
            ++anagram_group_count;
            AnagramGroup[wordIndex] = anagram_group_count;
            ++AnagramGroupSizes[anagram_group_count-1];
            break;
        }
        else if(isAnagram(WordList[wordIndex],WordList[x])){
            AnagramGroup[wordIndex]=AnagramGroup[x];
            ++AnagramGroupSizes[AnagramGroup[x]-1];
            break;
        }
    }
    return;
}

//sorts every word in wordlist alphabetically
void SortWordList(void){
    char ctemp[21]; // temporary char array, used when swapping 2 words
    int itemp;      // temporary int variable, used when swapping 2 numbers

    for(int i = 0; i < wordcount - 1; i++){
        for(int j = i + 1; j < wordcount; j++){
            if(strcmp(WordList[i], WordList[j]) > 0){
                //swap
                strcpy(ctemp, WordList[i]);
                strcpy(WordList[i], WordList[j]);
                strcpy(WordList[j], ctemp);

                itemp = AnagramGroup[i];
                AnagramGroup[i] = AnagramGroup[j];
                AnagramGroup[j] = itemp;

            }
        }
    }
    return;
}

// determins the top x groups, where x is the number of top groups
void CalculateTopGroups(void){
    int atemp[anagram_group_count]; // temporary int array, used to remember the Gids
                                    // of AnagramGroupSizes after sorting
    int itemp;                      // temporary variable, used when swapping 2 integers
    int c1, c2;                     //
    int t1, t2;                     // used to know when to increment c1 and c2

    //creating an array of indexs, will be used in pair with AnagramGroupSizes
    for(int x = 0; x < anagram_group_count; x++){
        atemp[x] = x;
    }

    //sorting AnagramGroupSizes in ascending order to determine top x group sizes
    for(int x = 0; x < anagram_group_count - 1; x++){
        for(int y = x + 1; y < anagram_group_count; y++){
            if(AnagramGroupSizes[x] < AnagramGroupSizes[y]){

                itemp = AnagramGroupSizes[x];
                AnagramGroupSizes[x] = AnagramGroupSizes[y];
                AnagramGroupSizes[y] = itemp;

                // this must be done to remember which id has which size
                itemp = atemp[x];
                atemp[x] = atemp[y];
                atemp[y] = itemp;
            }
        }
    }

    // doing another sort to deal with anagram sizes ties
    // if tie then sort using lexicograhpic order
    for(int x = 0; x < anagram_group_count-1; x++){
        for(int y = x+1; y < anagram_group_count; y++){
            t1 = 1, t2 = 1;
            if(AnagramGroupSizes[x]==AnagramGroupSizes[y]){ // if there is a tie in group sizes
                c1 = 0, c2 = 0;
                while(t1 || t2){
                    // find the index of the first word in each group that tied
                    if(AnagramGroup[c1] == atemp[x]+1){
                        t1 = 0;
                        break;
                    } else if (t1){
                        ++c1;
                    }
                    if(AnagramGroup[c2] == atemp[y]+1){
                        t2 = 0;
                        break;
                    } else if (t2){
                        ++c2;
                    }
                }

                //swap if the order of the words are backwards
                if(strcmp(WordList[c1], WordList[c2]) > 0){
                    itemp = atemp[x];
                    atemp[x] = atemp[y];
                    atemp[y] = itemp;
                }
            }
        }
    }

    // print top groups
    for(int x = 0; x < PrintTop; x++){
        c1 = 0;
        if(x+1 <= anagram_group_count){
            printf("Group of size %d:[GID:%d] ", AnagramGroupSizes[x], atemp[x]+1);
        } else {
            printf("Group of size 0:");
        }
        for(int id = 0; id < AnagramGroupSizes[x];c1++){
            if(AnagramGroup[c1] == atemp[x]+1){
                printf("%s ", WordList[c1]);
                ++id;
            }
        }
        printf("\n");
    }
    return;
}


int main(){
    char word[21];
    int done = 0;
    do{
        ReadWord(word);

        if(strcmp(word, "STOP")==0 || wordcount > 99){
            break;
        }

        strcpy(WordList[wordcount], word);
        AssignAnagramGroup(wordcount++);

        if(DEBUG){
            printf("ReadWord: WordList[%d]=\"%s\" AnagramGroup=%d\n", wordcount, word, AnagramGroup[wordcount-1]);
        }

    } while(!done);


    if(DEBUG){
        printf("WordList size = %d words\n", wordcount);
        for(int x = 0; x < anagram_group_count; x++){
            printf("Anagram Group %d of size %d\n", x+1, AnagramGroupSizes[x]);
        }
    }

    SortWordList();
    if(DEBUG){
        for(int x = 0; x < wordcount; x++){
            printf("WordList[%d]=\"%s\"   Gid=%d Gsize=%d\n", x, WordList[x], AnagramGroup[x], AnagramGroupSizes[AnagramGroup[x]-1]);
        }
    }

    CalculateTopGroups();
    return 0;
}