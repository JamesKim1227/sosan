#include "list.h"


int sllInit(SosanSllList **list) {
	*list = (SosanSllList *)malloc(sizeof(SosanSllList));
	if (!*list) { return -1; }

	(*list)->head = NULL;

	return 0;
}

int sllAppendNode(SosanSllList *list, int data) {
	SosanSllNode *node = (SosanSllNode*)malloc(sizeof(SosanSllNode));
	node->data = data;
	node->next = NULL;

	if (list->head == NULL) {
		list->head = node;
		return 0;
	}

	SosanSllNode *tmp = list->head;
	while (tmp->next != NULL) {
		tmp = tmp->next;
	}
	tmp->next = node;
}

int sllDeleteLastNode(SosanSllList *list) {
	SosanSllNode *node = list->head;

	if (node->next == NULL) {
		free(node);
		list->head = NULL;
		return 0;
	}

	SosanSllNode *priv;
	while (node->next != NULL) {
		priv = node;
		node = node->next;
	}

	priv->next = NULL;
	free(node);
}

void sllPrintAllNodes(SosanSllList *list) {
	SosanSllNode *node = list->head;

	while (node) {
		printf("%d ", node->data);
		node = node->next;
	}
	printf("\n");
}

void sllDestroy(SosanSllList *list) {
	SosanSllNode *node = list->head;

	while (node) {
		free(node);
		node = node->next;
	}
	free(list);
}

SosanSllNode* sllAt(SosanSllList *list, int index) {
	SosanSllNode *node = list->head;

	while (node != NULL && --index >= 0) {
		node = node->next;
	}

	return node;
}

int sllDeleteNode(SosanSllList *list, SosanSllNode *node) {
	SosanSllNode *cur = list->head;

	if (!list || !node) return 0;

	if (cur == node) {
		if (cur->next == NULL ) {
			free(cur);
			list->head = NULL;
		} else {
			list->head = cur->next;
		}
		return 0;
	}

	SosanSllNode *priv;
	while (cur->next != NULL) {
		priv = cur;
		cur = cur->next;

		if (cur == node) {
			priv->next = cur->next;
			free(cur);
		}
	}
	
}

int main() {
	SosanSllList *list;

	sllInit(&list);

	sllAppendNode(list, 1);
	sllAppendNode(list, 2);
	sllAppendNode(list, 3);
	sllPrintAllNodes(list);

	sllDeleteLastNode(list);
	sllPrintAllNodes(list);

	sllAppendNode(list, 5);
	sllPrintAllNodes(list);

	SosanSllNode *node = sllAt(list, 1);
	sllDeleteNode(list, node);
	sllPrintAllNodes(list);

	node = sllAt(list, 0);
	sllDeleteNode(list, node);
	sllPrintAllNodes(list);


	sllDestroy(list);
	return 0;
}
