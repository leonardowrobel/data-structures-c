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
    char* key;
    t_time value;
    struct timetable* next;
} t_timetable;

t_timetable* create(t_time val, char *key)
{
    t_timetable* newTime = (t_timetable*) malloc(sizeof(t_timetable));
    newTime->key = key;
    newTime->value = val;
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
            printf("%d:%d:%d %s | next? %d\n", c->value.hours, c->value.minutes, c->value.seconds, c->key, c->next != NULL);
            c = c->next;
        };
        printf("%d:%d:%d %s | next? %d\n", c->value.hours, c->value.minutes, c->value.seconds, c->key, c->next != NULL);
        printf("==============================\n");
    }
};

void put(t_timetable* head, t_time val, char *key)
{
    if(is_empty(head))
    {
        t_timetable* newTime = create(val, key);
        newTime->next = NULL;
        head = newTime;
    }
    else
    {
        {
            t_timetable* c = head;
            while(c->next != NULL)
            {
                if (time_cmp(&val, &c->value) == 0)
                {
                    c->key = key;
                    return;
                }
                c = c->next;
            };
            if (time_cmp(&val, &c->value) == 0)
            {
                c->key = key;
                return;
            }
            t_timetable* newTime = create(val, key);
            newTime->next = NULL;
            c->next = newTime;
        }
    }
}

// TODO:
//char* get(t_time key){
//
//}

int main()
{
    t_timetable* head = NULL;

    t_time a = {2, 2, 2};
    t_time b = {3, 3, 3};
    t_time c = {3, 3, 3};
    t_time d = {5, 5, 5};
    put(head, a, "first");
    put(head, b, "second");
    put(head, c, "third");
    put(head, d, "fourth");

    printf("\nBEFORE PRINT\n");
    print_list(head);
    printf("\nAFTER PRINT\n");

    printf("\nFIM\n");
    return 0;
}
