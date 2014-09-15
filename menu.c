/******************************************************************************/
/*  Copyright (C)sse.ustc.edu.cn, 2014-2015                                   */
/*                                                                            */
/*  FILE NAME               :       menu.c                                    */
/*  PRINCIPAL AUTHOR        :       Xutong                                    */
/*  SUBSYSTEM NAME          :       menu                                      */
/*  MODULE NAME             :       menu                                      */
/*  LANGUAGE                :       C                                         */
/*  TARGET ENVIROMENT       :       ANY                                       */
/*  DATE OF FIRST RELEASE   :       2014/09/15                                */
/*  DESCRIPTION             :       This is a menu program                    */
/******************************************************************************/

/*
*   Revision log；
*
*   Create by Xutong,2014/09/15                                                 *
*/

#include<stio.h>
#include<stdlib.h>

int Help();

#define CMD_MAX_LEN     128
#define DESC_LEN        1024
#define CMD_NUM         10

/*  data struct and its operations*/

typedef struct DataNode
{
    char*   cmd;
    char*   desc;
    int     (*handler)();
    struct  DataNode *next;
}tDataNode;

tDataNode* FindCmd(tDataNode* head, char * cmd)
{
    if(!head || !cmd)
    {
        return NULL;
    }
    tDataNode *p = head;
    while(p)
    {
        if(!strcmp(p->cmd,cmd))
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}
int ShowAllCmd(tDataNode *head)
{
    printf("Menu List:\n");
    tDataNode *p = head;
    while(p)
    {
        printf("%s - %s\n",p->cmd,p->desc);
        p = p->next;
    }
    return 0;
}

/*  menu program*/
static tDataNode head[] =
{
    {"help","this is help cmd!",help,&head[1]},
    {"version","menu program v1.0",Help,NULL}
};

int Help()
{
    ShowAllCmd(head);
    return 0;
}

main()
{
    /"cmd line begins"/
    Help();
    while(1)
    {
        char cmd[CMD_MAX_LEN];
        printf("please input a cmd number :");
        scanf（"%s ,cmd");
        if(!p)
        {
            printf("this is a wrong cmd!\n");
            continue;
        }
        printf("%s - %s\n",p->cmd,p-desc);
        if(p->handler)
        {
            p->handler();
        }
    }
}
