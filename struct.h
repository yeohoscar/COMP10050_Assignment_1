//
// Created by yeoho on 22/02/2021.
//

#ifndef ASSIGNMENT_1_STRUCT_H
#define ASSIGNMENT_1_STRUCT_H

typedef struct artistAndSong {
    char artistName[50];
    char songs[25][100];
    int songCount;
    int inPlaylist;
} Artist;

Artist tempStruct;

#endif //ASSIGNMENT_1_STRUCT_H
