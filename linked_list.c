#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

static struct node *create_node(int data);
static void append_node(int data);
static void remove_node(int data);

static void print_list();
static int list_size(); 

static struct node *head_;
static struct node *tail_;

int main(void)
{
	head_ = NULL;
	tail_ = NULL;

	head_ = create_node(29);
	tail_ = head_;

	int i; 
	for (i = 40; i < 50; i++)
		append_node(i);

	remove_node(43);
	remove_node(45);
	remove_node(48);

	print_list();
	printf("list_size = %d\n", list_size());

	return 0;	
} 

static struct node *create_node(int data)
{
	struct node *node = (struct node *) malloc(sizeof(*node));
	node->data = data;
	node->next = NULL;
	return node;
}

static void append_node(int data)
{
	struct node *tmp = create_node(data);
	tail_->next = tmp;
	tail_ = tmp;
}

// Remove first node in the list that has value 'data'
static void remove_node(int data)
{
	struct node *prev = head_;
	struct node *curr = prev->next;

	if (prev == NULL)
		return;

	while (curr != NULL && curr->data != data) {
		prev = prev->next;
		curr = prev->next;
	}

	if (curr == NULL)
		return;

	prev->next = curr->next;
	free(curr);
}

static void print_list()
{
	struct node *tmp = head_;
	while (tmp != NULL){
		printf("ADDR: %p; DATA: %d; NEXT: %p\n", 
			tmp, tmp->data, tmp->next);
		tmp = tmp->next;
	}
}

static int list_size()
{
	int i = 0;
	struct node *tmp = head_;
	while (tmp != NULL){
		i++;
		tmp = tmp->next;	
	}
	return i;
} 
