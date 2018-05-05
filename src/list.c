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

int sllPrintAllNodes(SosanSllList *list) {
	SosanSllNode *node = list->head;

	while (node) {
		printf("%d ", node->data);
		node = node->next;
	}
	printf("\n");
}

int sllDestroy(SosanSllList *list) {
	SosanSllNode *node = list->head;

	while (node) {
		free(node);
		node = node->next;
	}
	free(list);
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

	sllDestroy(list);
	return 0;
}
