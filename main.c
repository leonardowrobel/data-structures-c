#include <stdio.h>
#include <stdlib.h>

typedef struct time
{
    int hours;
    int minutes;
    int seconds;
} t_time;

typedef struct timetable
{
    char* value;
    t_time key;
    struct timetable* next;
} t_timetable;


t_timetable* create(t_time key, char* value)
{
    t_timetable* newTime = (t_timetable*) malloc(sizeof(t_timetable));
    newTime->key = key;
    newTime->value = value;
    return newTime;
}


int time_cmp(t_time* h1, t_time* h2)
{
    int totalSecondsH1 = ((*h1).hours * 60 * 60) + ((*h1).minutes * 60) + (*h1).seconds;
    int totalSecondsH2 = ((*h2).hours * 60 * 60) + ((*h2).minutes * 60) + (*h2).seconds;
    if(totalSecondsH1 > totalSecondsH2)
    {
        return 1;
    }
    else if (totalSecondsH1 == totalSecondsH2)
    {
        return 0;
    }
    else
    {
        return -1;
    }
};


int is_empty(t_timetable* head)
{
    if(head == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
};


int size(t_timetable* head)
{
    if(is_empty(head))
    {
        return 0;
    }
    else
    {
        if(head->next == NULL)
        {
            return 1;
        }
        int size = 0;
        for(t_timetable* c = head ; c != NULL ; c = c->next)
        {
            size++;
        }
        return size;
    }
};


void print_list(t_timetable* head)
{
    if(is_empty(head))
    {
        printf("==============================\n");
        printf("List is empty!\n");
        printf("==============================\n");
    }
    else
    {
        t_timetable* c = head;
        printf("==============================\n");
        while(c->next != NULL)
        {
            printf("%02d:%02d:%02d  %s\n", c->key.hours, c->key.minutes, c->key.seconds, c->value, c->next != NULL);
            c = c->next;
        };
        printf("%02d:%02d:%02d  %s\n", c->key.hours, c->key.minutes, c->key.seconds, c->value, c->next != NULL);
        printf("================= Items:%d ===\n", size(head));
    }
};


void put(t_timetable** head, t_time key, char* value)
{
    if(is_empty(*head))
    {
        t_timetable* newTime = create(key, value);
        newTime->next = NULL;
        *head = newTime;
    }
    else
    {
        {
            t_timetable* c = *head;
            while(c->next != NULL)
            {
                if (time_cmp(&key, &c->key) == 0)
                {
                    c->value = value;
                    return;
                }
                c = c->next;
            };
            if (time_cmp(&key, &c->key) == 0)
            {
                c->value = value;
                return;
            }
            t_timetable* newTime = create(key, value);
            newTime->next = NULL;
            c->next = newTime;
        }
    }
}


char* get(t_timetable* head, t_time key)
{
    if(!is_empty(head))
    {
        t_timetable* c = head;
        while( c != NULL)
        {
            if(time_cmp(&c->key, &key) == 0)
            {
                return c->value;
            }
            c = c->next;
        }
        return 0;
    }
}

// TODO:
void del(t_timetable** head, t_time key)
{
    if(!is_empty(*head))
    {
        t_timetable *c = *head;
        t_timetable *prev = NULL;
        t_timetable *next = c->next;
        while(c != NULL)
        {
            if(time_cmp(&c->key, &key) == 0)
            {
                printf("> INSIDE IF (time_cmp)\n");
                if(size(*head) == 1){
                    printf("> INSIDE IF (size == 1)\n");
                    *head = NULL;
                }else {
                    if(prev == NULL){
                        // *head = next;
                    } else if (next == NULL){

                    }
                }
                printf("> BEFORE FREE (c->value)\n");
                printf("c != NULL: %d\n", c != NULL);
                printf("c->value != NULL: %d\n", c->value != NULL);
                free(c->value);
                if(c->next != NULL){
                    printf("> INSIDE IF (c->next != NULL)\n");
                    free(c->next);
                }
                printf("> BEFORE FREE (c)\n");
                free(c);
            }
            c = c->next;
        }
    }
}


int contains(t_timetable* head, t_time key)
{
    if(!is_empty(head))
    {
        t_timetable *c = head;
        while(c != NULL)
        {
            if(time_cmp(&c->key, &key) == 0)
            {
                return 1;
            }
            c = c->next;
        }
    }
    return 0;
}

int main()
{
    t_timetable* head = NULL;

    t_time a = {2, 2, 2};
    t_time b = {3, 3, 3};
    t_time c = {4, 4, 4};
    t_time d = {5, 5, 5};
    t_time e = {6, 6, 5};
    t_time f = {6, 6, 6};
    put(&head, a, "first");
    // put(&head, b, "second");
//    put(&head, c, "third");
//    put(&head, d, "fourth");
//    put(&head, e, "fith");

    print_list(head);
//    del(&head, a);
    free(head->value);
    print_list(head);
//    printf("a == %s\n", get(head, a));
//    printf("d == %s\n", get(head, d));
//    printf("d exists? %d\n", contains(head, d));
//    printf("f exists? %d\n", contains(head, f));

    printf("\nFIM\n");
    return 0;
}
