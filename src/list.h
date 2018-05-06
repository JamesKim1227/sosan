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
void sllDestroy(SosanSllList *list);
int sllAppendNode(SosanSllList *list, int data);
int sllDeleteLastNode(SosanSllList *list);
void sllPrintAllNodes(SosanSllList *list);
SosanSllNode *sllAt(SosanSllList *list, int index);
int sllDeleteNode(SosanSllList *list, SosanSllNode *node);

#endif
