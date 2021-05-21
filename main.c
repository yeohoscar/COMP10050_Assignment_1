//COMP10050 Software Engineering Project 1: Randomised playlist: "DJ for an hour"
//Oscar Yeoh 20403662

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fileIO.h"
#include "print.h"
#include "sort.h"
#include "shuffle.h"

int main(int argc, char* argv[]) {
    int i;
    int numArtist;
    int songTotal;

    srand(time(0));
    Artist artist[30];
    FILE *fp = NULL;

    if (argc == 1) { //if no file is provided
        fp = fileRead("\0"); //calls function with null string to trigger default file usage
    }

    else if (argc == 2) { //if a file is provided
        fp = fileRead(argv[1]); //calls function with passed file name argument
    }

    else if (argc > 2) { //if too many arguments were passed
        printf("Too many arguments passed to program. Only one file argument or none is allowed.\n");
        return 1;
    }

    //Functions to fill structs with artist and songs
    if (fp == NULL) {
        numArtist = manualInput(artist); //if file can't be found, calls function for user manual input
    }

    else {
        numArtist = readIntoStruct(artist, &fp); //if file is found, calls function to read from file into struct
    }

    //Sort the structs into alphabetical order and print
    insertionSortArtist(artist, numArtist);

    for (i = 0; i < numArtist; i++) {
        insertionSortSong(artist[i].songs, artist[i].songCount);
    }

    printSorted(artist, numArtist);

    //Finds number of songs then shuffles them into a ~60 mins playlist
    songTotal = sumSongTotal(artist, numArtist);
    shuffleSongs(artist, &songTotal, &numArtist);

    return 0;
}