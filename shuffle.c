//
// Created by yeoho on 22/02/2021.
// Contains functions related to the shuffling and creation of the playlist
//

#include "shuffle.h"
#include "print.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_TIME 3600
#define MAX_SONGS_PER_ARTIST 3

//Gets total number of songs
int sumSongTotal(Artist artist[50], int numArtist) {
    int i;
    int sum = 0;

    for (i = 0; i < numArtist; i++) {
        sum += artist[i].songCount;
    }

    return sum;
}

//Shuffles songs into a playlist using a form of the Fisher-Yates Shuffle algorithm modified to fit structs
void shuffleSongs(Artist artist[50], int *numOfSong, int *numArtist) {
    int i;
    int randSong;
    int songIndex;
    int totalTime = 0;

    printf("\nRandomised playlist:\n");

    while (totalTime < MAX_TIME && *numOfSong != 0) { //loop while playlist duration is less than 60 mins (3600 seconds) and there are songs left
        i = -1;
        randSong = rand() % *numOfSong; //generates a random number between 0 and total number of songs

        //Finds which artist struct the random song is in by subtracting each artist's song count until the value becomes zero or negative
        //Example: ArtistSongCount1 = 2, ArtistSongCount2 = 5, ArtistSongCount3 = 4
        //         randSong = 6 -> randSong - Artist1 = 4 - Artist2 = -1
        //Therefore, the random song must be in Artist2
        do {
            randSong -= artist[++i].songCount;
        } while (randSong >= 0);

        songIndex = artist[i].songCount + randSong;

        if (triplePlayCheck(artist[i].artistName)) {
            printSong(artist[i].artistName, artist[i].songs[songIndex], &totalTime);

            //Moves song to the end of the song array and decrement the song count, so that song can't be chosen anymore. (Fisher-Yates Shuffle)
            swapString(artist[i].songs[songIndex], artist[i].songs[artist[i].songCount - 1]);
            artist[i].songCount--;

            artist[i].inPlaylist++;
            *numOfSong -= 1;

            //If an artist's song appeared three times, then that artist's struct is moved so no songs can be chosen from it anymore
            if (artist[i].inPlaylist == MAX_SONGS_PER_ARTIST) {
                *numOfSong -= artist[i].songCount; //removes artist's songs from the selection pool
                swapStruct(&artist[i], &artist[*numArtist - 1]);
                *numArtist -= 1;
            }
        }
    }

    printf("\nTotal duration: %d:%d\n", totalTime / 60, totalTime % 60);
}

//Function to ensure an artist doesn't appear three times in a row
bool triplePlayCheck(char artistName[]) {
    //Strings to hold the artist name of the previous two songs
    char backOne[50];
    char backTwo[50];

    //If strcmp returns 0, then the current song and the string match
    if (strcmp(artistName, backOne) == 0) {
        if (strcmp(artistName, backTwo) == 0) { //If previous two songs match
            return false;
        }

        else { //If only previous song matches
            strcpy(backTwo, artistName);
            return true;
        }
    }

    else { //If previous song doesnt match
        strcpy(backOne, artistName);
        return true;
    }
}

//Adds song duration to the total playlist duration
void sumTime(char *duration, int *totalTime) {
    int minutes, seconds;
    char middle;
    sscanf(duration, "%d %c %d", &minutes, &middle, &seconds);

    *totalTime += ((minutes * 60) + seconds); //converts the minutes to seconds and adds it to the total playlist duration
}

//Utility function to swap strings
void swapString(char string1[], char string2[]) {
    char temp[100];
    strcpy(temp, string1);
    strcpy(string1, string2);
    strcpy(string2, temp);
}

//Utility function to swap structs
void swapStruct(Artist *struct1, Artist *struct2) {
    tempStruct = *struct1;
    *struct1 = *struct2;
    *struct2 = tempStruct;
}