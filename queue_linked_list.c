#include <stdio.h>
#include <stdlib.h>

struct node {
        int key;
        struct node *next;
};

static void enqueue(int key);
static void dequeue(void);

static int queue_empty(void); 
static void print_list(void);

struct node *head_;
struct node *tail_;

int main(void)
{
        tail_ = NULL;
        head_ = NULL;
        int i;
        
        for (i = 1; i <= 5; i++)
                enqueue(i);
                
        print_list();
                
        for (i = 6; i <= 8; i++) {
                enqueue(i);
                dequeue();
                print_list();
        }
        
        return 0;
}

static void enqueue(int key)
{
        struct node *tmp = (struct node *) malloc(sizeof(*tmp));
        tmp->key = key;
        tmp->next = NULL;
        
        if (tail_ == NULL) {
               tail_ = tmp;
               head_ = tail_;
               return;
        }
        
        tmp->next = tail_;
        tail_ = tmp;
}

static void dequeue()
{
        if (queue_empty())
                return;
        
        struct node *tmp = (struct node *) malloc(sizeof(*tmp));
        for (tmp = tail_; tmp->next != head_; tmp = tmp->next)
                ;;
        
        head_ = tmp;
}

static int queue_empty(void)
{
        if (tail_ == NULL)
                return 1;
        return 0;
}

static void print_list(void)
{
        struct node *tmp = (struct node *) malloc(sizeof(*tmp));
        for (tmp = tail_; tmp!= head_->next; tmp = tmp->next)
                printf("ADDR: %p; KEY: %d; NEXT: %p\n",
                        (void *) tmp, tmp->key, (void *) tmp->next);
                        
        printf("----------\n");
}
