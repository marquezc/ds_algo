#include <stdio.h>
#include <stdlib.h>

static int  stack_empty(void);
static void push(int key);
static void pop(void);
static void print_stack(void);

struct node {
        int key;
        struct node *next;
};

static struct node *head_;
static struct node *tail_;

int main()
{
        head_ = NULL;
        tail_ = NULL;
        int i;
        
        for (i = 1; i <= 10; i++)
                push(i);
        
        for (i = 0; i < 3; i++)
                pop();
        
        print_stack();
        return 0;
}

static int stack_empty(void)
{
        if (head_ == NULL)
                return 1;
        return 0;
}

static void push(int key)
{
        struct node *tmp = (struct node *) malloc(sizeof(tmp));
        tmp->key = key;
        tmp->next = NULL;
        
        if (stack_empty()) {
                head_ = tmp;
                tail_ = head_;
                return;
        }
    
        tail_->next = tmp;
        tail_ = tail_->next; 
}

static void pop(void)
{
        if (head_ == NULL)
                return;
    
        struct node *tmp;
        for (tmp = head_; tmp->next != tail_; tmp = tmp->next)
                ;;
        
        tail_ = tmp;
}

static void print_stack(void)
{
        struct node *tmp;
        for (tmp = head_; tmp != tail_->next; tmp = tmp->next)
                printf("ADDR: %p; KEY: %d; NEXT: %p\n", 
                        (void *) tmp, tmp->key, (void *) tmp->next);
}
