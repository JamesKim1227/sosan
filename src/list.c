#include "common.h"

typedef struct sosan_sll_node_t sosan_sll_node_t;

struct sosan_sll_node_t {
	//void *data;
	int data;
	sosan_sll_node_t *next;
};

typedef struct sosan_sll_list_t {
	sosan_sll_node_t *head;
} sosan_sll_list_t;

int sll_create(sosan_sll_list_t **list);
int sll_destroy();
int sll_insert(sosan_sll_list_t *list, int data);
int sll_delete(sosan_sll_list_t *list);
int sll_printall(sosan_sll_list_t *list);

int sll_create(sosan_sll_list_t **list) {
	int ret = 0;

	*list = (sosan_sll_list_t *)malloc(sizeof(sosan_sll_list_t));
	if (!*list) { return -1; }

	(*list)->head = NULL;

	return 0;
}

int sll_insert(sosan_sll_list_t *list, int data) {
	sosan_sll_node_t *node = (sosan_sll_node_t*)malloc(sizeof(sosan_sll_node_t));
	node->data = data;
	node->next = NULL;

	if (list->head == NULL) {
		list->head = node;
		return 0;
	}

	sosan_sll_node_t *tmp = list->head;
	while (tmp->next != NULL) {
		tmp = tmp->next;
	}
	tmp->next = node;
}

int sll_delete(sosan_sll_list_t *list) {
	sosan_sll_node_t *node = list->head;

	if (node->next == NULL) {
		free(node);
		list->head = NULL;
		return 0;
	}

	sosan_sll_node_t *priv;
	while (node->next != NULL) {
		priv = node;
		node = node->next;
	}

	priv->next = NULL;
	free(node);
}

int sll_printall(sosan_sll_list_t *list) {
	sosan_sll_node_t *node = list->head;

	while (node) {
		printf("%d ", node->data);
		node = node->next;
	}
	printf("\n");
}

int sll_destroy(sosan_sll_list_t *list) {
	sosan_sll_node_t *node = list->head;

	while (node) {
		free(node);
		node = node->next;
	}
	free(list);
}

int main() {
	sosan_sll_list_t *list;

	sll_create(&list);

	sll_insert(list, 1);
	sll_insert(list, 2);
	sll_insert(list, 3);
	sll_printall(list);

	sll_delete(list);
	sll_printall(list);

	sll_insert(list, 5);
	sll_printall(list);

	sll_destroy(list);
	return 0;
}
