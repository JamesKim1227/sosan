#ifndef __SOSAN_LIST_H
#define __SOSAN_LIST_H

#include "common.h"

typedef struct SosanSllNode SosanSllNode;

struct SosanSllNode {
	//void *data;
	int data;
	SosanSllNode *next;
};

typedef struct SosanSllList {
	SosanSllNode *head;
} SosanSllList;


int sllInit(SosanSllList **list);
int sllDestroy();
int sllAppendNode(SosanSllList *list, int data);
int sllDeleteLastNode(SosanSllList *list);
int sllPrintAllNodes(SosanSllList *list);

#endif
