//
// Created by yeoho on 20/02/2021.
// Contains functions for input from file and user input
//

#include "fileIO.h"
#include <stdio.h>
#include <string.h>

//Allows user to enter their own file, else default to specified file
FILE *fileRead(char fileName[]) {
    char filePath[50];
    FILE *fp;

    //Checks for default file entry
    if (strcmp(fileName, "\0") == 0) {
        printf("No file provided. Default file will be used.\n");
        fp = fopen("./inputFiles/artistes+songs.txt", "r");
    }

    //Builds file path using user entry and opens the file
    else {
        fileName[strcspn(fileName, "\n")] = '\0';
        snprintf(filePath, sizeof(filePath), "./inputFiles/%s", fileName);
        fp = fopen(filePath, "r");
    }

    if (fp == NULL) {
        printf("No file found. Manual input is required.\n");
        return NULL;
    }

    return fp;
}

//Reads file contents into struct
int readIntoStruct(Artist artist[50], FILE **fp) {
    int i = -1;
    int j = -1;
    char buf[100];

    while ((fgets(buf, 100, *fp)) != NULL) {
        //Assuming input file is formatted correctly, checks if a new artist is being read in. If it is, then reads artist name into new struct and assign appropriate values to struct variables.
        if (artist[i].songs[j][0] == '\n' || i < 0) {
            strcpy(artist[++i].artistName, buf);
            artist[i].artistName[strcspn(artist[i].artistName, "\n")] = '\0'; //removes trailing newline

            artist[i].songCount = 0;
            artist[i].inPlaylist = 0;
            j = -1;
        }

        else {
            strcpy(artist[i].songs[++j], buf);

            //removes trailing newline from song titles and increments song count
            if (artist[i].songs[j][0] != '\n') {
                artist[i].songs[j][strcspn(artist[i].songs[j], "\n")] = '\0';
                artist[i].songCount++;
            }
        }
    }

    fclose(*fp);

    return i + 1; //returns total number of artists
}

//Allows user to manually input the artists and songs
int manualInput(Artist artist[50]) {
    int i, j;
    int numArtist;

    printf("Please manually input the artists and songs.\nPlease enter the number of artists you wish to input: ");
    scanf("%d", &numArtist);
    fflush(stdin);

    //Gets user input until the number of artists is reached
    for (i = 0; i < numArtist; i++) {
        printf("\nEnter the name of the artist: ");
        fgets(artist[i].artistName, 50, stdin);
        artist[i].artistName[strcspn(artist[i].artistName, "\n")] = '\0'; //removes trailing newline

        artist[i].songCount = 0;
        artist[i].inPlaylist = 0;
        j = -1;

        printf("\nPlease enter the song names and durations in the following format:\n"
               "  Song title***Song duration\n"
               "When you are done, press enter.\n");

        do {
            fgets(artist[i].songs[++j], 100, stdin);

            //Removes trailing newline and increments song count, as long as it is not just a newline character by itself
            if (artist[i].songs[j][strlen(artist[i].songs[j]) - 1] == '\n' && artist[i].songs[j][0] != '\n') {
                artist[i].songs[j][strlen(artist[i].songs[j]) - 1] = '\0';
                artist[i].songCount++;
            }

        } while (artist[i].songs[j][0] != '\n');
    }

    return i;
}