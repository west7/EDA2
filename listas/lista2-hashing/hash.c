#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pessoa
{
    int cod;
    char fname[100];
    char lname[100];
    char bday[100];
    char tel[100];
} Pessoa    ;

#define MAX_LINE_LEN 100000

int main(void)
{
    Pessoa bd[100000];
    int bd_size = 0;
    char cmd[100];
    int cod;
    char fname[100];
    char lname[100];
    char bday[100];
    char tel[100];

    while (scanf("%s", cmd) != EOF)
    {
        if (strcmp(cmd, "add") == 0)
        {
            scanf("%d %s %s %s %s", &cod, fname, lname, bday, tel);
            int found = 0;
            for (int i = 0; i < bd_size; i++)
            {
                if (bd[i].cod == cod)
                {
                    found = 1;
                    break;
                }
            }
            if (found)
            {
                printf("ID %d ja cadastrado.\n", cod);
            }
            else
            {
                bd[bd_size].cod = cod;
                strcpy(bd[bd_size].fname, fname);
                strcpy(bd[bd_size].lname, lname);
                strcpy(bd[bd_size].bday, bday);
                strcpy(bd[bd_size].tel, tel);
                bd_size++;
            }
        }
        else if (strcmp(cmd, "del") == 0)
        {
            scanf("%d", &cod);
            int found = 0;
            for (int i = 0; i < bd_size; i++)
            {
                if (bd[i].cod == cod)
                {
                    found = 1;
                    for (int j = i; j < bd_size - 1; j++)
                    {
                        bd[j] = bd[j + 1];
                    }
                    bd_size--;
                    break;
                }
            }
            if (!found)
            {
                printf("ID %d nao existente.\n", cod);
            }
        }
        else if (strcmp(cmd, "info") == 0)
        {
            scanf("%d", &cod);
            int found = 0;
            for (int i = 0; i < bd_size; i++)
            {
                if (bd[i].cod == cod)
                {
                    found = 1;
                    printf("%d\n", bd[i].cod);
                    printf("%s %s %s %s\n", bd[i].fname, bd[i].lname, bd[i].bday, bd[i].tel);
                    break;
                }
            }
            if (!found)
            {
                printf("ID %d nao existente.\n", cod);
            }
        }
        else if (strcmp(cmd, "query") == 0)
        {
            char line[MAX_LINE_LEN + 1];
            fgets(line, MAX_LINE_LEN, stdin);
        }
    }

    return 0;
}