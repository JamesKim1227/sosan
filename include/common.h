#ifndef __SOSAN_COMMON_H
#define __SOSAN_COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define sosanDebug(fmt, ...) \
    printf("DEBUG %s:%d > " fmt "\n", __FUNCTION__, __LINE__, __VA_ARGS__)

#endif
