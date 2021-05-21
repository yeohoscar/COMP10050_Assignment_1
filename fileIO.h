//
// Created by yeoho on 20/02/2021.
//

#ifndef ASSIGNMENT_1_FILEIO_H
#define ASSIGNMENT_1_FILEIO_H

#include <stdio.h>
#include "struct.h"

FILE *fileRead(char fileName[]);
int readIntoStruct(Artist artist[50], FILE **fp);
int manualInput(Artist artist[50]);

#endif //ASSIGNMENT_1_FILEIO_H
