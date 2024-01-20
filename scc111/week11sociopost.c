#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct Post
{
    char *content;
    char *timedate;
}Post;

typedef struct element{
    Post data;
    struct element *next;
    struct element *prev;
}element;

typedef struct list{
    element head;
}list;

char* getCurrentTime();
void menu();
int feed(list, element*);
int nextPost();
int prevPost();
int likePost();
int postPost(list);
void welcome();
list createList();

int main()
{
    list list = createList();
    welcome();
    menu(list);

    return 0;
}

char* getCurrentTime() 
{
    static char buffer[32];

    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeinfo);

    return buffer;
}

void menu(list list)
{
    int action;
    printf("\n[1] New Post    [2] Feed    [0] Exit\n\n> ");
    scanf("%d", &action);
    
    switch (action)
    {
    case 1:
        postPost(list);
        break;
    case 2:
        feed(list, &list.head);
        break;
    case 0:
        exit(0);
        break;
    default:
        break;
    }
}

int feed(list list, element *current)
{
    printf("Current posts:\n");
    if (!strcmp(current->data.content, "/t")){
        printf("\nNo posts exist in feed. Post something!\n");
    } else {
        printf("\nPost: %s, %s\n", current->data.content, current->data.timedate);
    }

    element e = list.head;
    while (1){
        printf("%s\n", e.data.content);
        e = *e.next;
    }

    int action;
    printf("\n[1] Next Post    [2] Previous Post    [3] Like    [0] Main Menu\n\n> ");
    scanf("%d", &action);
    
    switch (action)
    {
    case 1:
        nextPost();
        break;
    case 2:
        prevPost();
        break;
    case 3:
        likePost();
    case 0:
        menu(list);
        break;
    default:
        break;
    }
}

list createList(){
    list list;
    list.head.data.content = "/t";
    return list;
}

void add(list list, element e){
    e.next = &list.head;

    if (!strcmp(list.head.data.content, "/t")){
        list.head.prev = &e;
    }
    list.head = e;
    e.prev = NULL;
}

int postPost(list list)
{
    char *messageContent;
    printf("\nMessage Content: ");
    scanf("%s", &messageContent);
    printf("sending it1\n");

    element e;
    Post p;
    printf("sending it2\n");
    p.content = messageContent;
    printf("sending it3\n");
    p.timedate = getCurrentTime();
    printf("sending it4\n");
    e.data = p;
    printf("sending it5\n");
    add(list, e);

    printf("Successfully Posted Message!\n");
    menu(list);
}

int likePost()
{
}

int nextPost()
{
}

int prevPost()
{
}

void welcome()
{
    printf("------------------- Welcome To SocioPost --------------------\n");
}