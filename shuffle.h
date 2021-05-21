//
// Created by yeoho on 22/02/2021.
//

#ifndef ASSIGNMENT_1_SHUFFLE_H
#define ASSIGNMENT_1_SHUFFLE_H

#include "struct.h"
#include <stdbool.h>

int sumSongTotal(Artist artist[50], int numArtist);
void shuffleSongs(struct artistAndSong artist[50], int *numOfSong, int *numArtist);
bool triplePlayCheck(char artistName[]);
void swapString(char arr1[], char arr2[]);
void swapStruct(Artist *struct1, Artist *struct2);
void sumTime(char *duration, int *totalTime);

#endif //ASSIGNMENT_1_SHUFFLE_H
