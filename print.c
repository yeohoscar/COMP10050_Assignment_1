//
// Created by yeoho on 23/02/2021.
// Contains print-related functions
//

#include "print.h"
#include "shuffle.h"
#include <stdio.h>
#include <string.h>

void printSorted(Artist artist[50], int numArtist) {
    int i, j;

    printf("Sorted list of artistes and songs");

    for (i = 0; i < numArtist; i++) {
        printf("\n%s\n", artist[i].artistName);

        for (j = 0; j < artist[i].songCount; j++) {
            printf("  o %s\n", artist[i].songs[j]);
        }
    }
}

//Prints song without the ***, as well as allowing the duration to be be added to the total playlist duration
void printSong(char artistName[50], char songName[100], int *totalTime) {
    char copy[100];
    char *token;

    printf("%s: ", artistName);

    //Gets and prints the song title
    strcpy(copy, songName);
    token = strtok(copy, "***");
    printf("\"%s\" ", token);

    //Gets and prints the song duration
    token = strtok(NULL, "***");
    printf("(%s)\n", token);

    //Takes the duration string and adds it to the playlist duration
    sumTime(token, totalTime);
}