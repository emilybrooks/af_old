#ifndef M_COMMON_DATA_H
#define M_COMMON_DATA_H

#include "ultra64.h"

typedef struct {
    /* 0x00000 */ char unk0;
} Save; // size = 

typedef struct {
    /* 0x00000 */ char pad[0x10000];
    /* 0x10001 */ u8 unk10001;
} CommonData; // size = 10AB8



// void common_data_reinit();
// void common_data_init();
// void common_data_clear();

#endif
