#include <stdio.h>
#include <stdlib.h>
typedef struct list
{
    int val;
    struct list *next;
} lt;
void insert_begin(int x, lt **h)
{
    lt *new;
    new = (lt *)malloc(sizeof(lt));
    new->val = x;
    new->next = *h;
    *h = new;
}
void display(lt *head)
{
    lt *p;
    if (head == NULL)
    {
        printf("the list is empty\n");
    }
    else
    {
        p = head;
        while (p != NULL)
        {
            printf("%d\n", p->val);
            p = p->next;
        }
    }
}
void Delet_element(int x, lt *h)
{
    lt *p, *q;
    p = h;
    q = NULL;
        while (p != NULL && p->val != x)
        {
            q = p;
            p = p->next;
        }
        if (p == NULL)
        {
            printf("x is not exist");
        }
        else
        {

             if (p == h)
                 {
                    h = p->next;
                    free(p);
                 }
                 else
                 {
                    if (p->next == NULL)
                    {
                       while (p->next != NULL)
                       {
                       q = p;
                       p =p->next;
                       }
                       q->next = NULL;
                       free(p);
                       
                    }
                    else
                    {
                         q->next = p->next;
                         free(p);
                    }
                    
                 }
        }

        
    }
    int Is_prime(int num)
    {
        if (num < 2)
        {
            return 0;
        }
        else
        {
            for (int i = 2; i <= num; i++)
            {
                if (num % i == 0)
                {
                    return 0;
                }
            }
        }
        return 1;
    }
    void prime_list(lt * head)
    {
        lt *p, *q;
        p = head;
        while (p != NULL)
        {
            q = p->next;
            while (q != NULL)
            {
                if ((Is_prime(q->val)) != 0)
                {
                    Delet_element(q->val, head);
                }
                q = q->next;
            }
            p = p->next;
        }
    }

    int main()
    {
        lt *head = NULL;
        insert_begin(1, &head);
        insert_begin(2, &head);
        insert_begin(3, &head);
        insert_begin(4, &head);
        insert_begin(5, &head);
        insert_begin(6, &head);
        insert_begin(7, &head);
        printf("the content of the list :\n");
        display(head);

        prime_list(head);

        printf("the content of the list :\n");
        display(head);
    }