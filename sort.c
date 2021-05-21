//
// Created by yeoho on 22/02/2021.
// Contains functions needed for sorting
//

#include "sort.h"
#include <string.h>

//Insertion sorts to sort artists and songs. Two functions written as they can't be combined into one due to the nature of struct.

void insertionSortArtist(Artist artist[50], int num) {
    int i, j;

    for (i = 1; i < num; i++)
    {
        tempStruct = artist[i];
        j = i;

        while (j > 0 && strcmp(artist[j - 1].artistName, tempStruct.artistName) > 0)
        {
            artist[j] = artist[j - 1];
            j--;
        }

        artist[j] = tempStruct;
    }
}

void insertionSortSong(char arr[][100], int num) {
    int i, j;
    char keyString[50];

    for (i = 1; i < num; i++)
    {
        strcpy(keyString, arr[i]);
        j = i;

        while (j > 0 && strcmp(arr[j - 1], keyString) > 0)
        {
            strcpy(arr[j], arr[j - 1]);
            j--;
        }

        strcpy(arr[j], keyString);
    }
}