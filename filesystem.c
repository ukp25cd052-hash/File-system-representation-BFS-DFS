
#include <stdio.h>
#include <string.h>

#define MAX 20

int graph[MAX][MAX];
int visited[MAX];
char name[MAX][50];
int n, found;

// Breadth First Search
void BFS(int start, char target[])
{
    int queue[MAX], front = 0, rear = 0;
    int i, current;

    for (i = 0; i < n; i++)
        visited[i] = 0;

    queue[rear++] = start;
    visited[start] = 1;

    printf("\nBFS Traversal: ");

    while (front < rear)
    {
        current = queue[front++];
        printf("%s ", name[current]);

        if (strcmp(name[current], target) == 0)
            found = 1;

        for (i = 0; i < n; i++)
        {
            if (graph[current][i] == 1 &&
                visited[i] == 0)
            {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }

    if (found)
        printf("\nFile found using BFS.\n");
    else
        printf("\nFile not found using BFS.\n");
}

// Depth First Search
void DFS(int current, char target[])
{
    int i;

    visited[current] = 1;
    printf("%s ", name[current]);

    if (strcmp(name[current], target) == 0)
        found = 1;

    for (i = 0; i < n; i++)
    {
        if (graph[current][i] == 1 &&
            visited[i] == 0)
        {
            DFS(i, target);
        }
    }
}

int main()
{
    int i, j, start;
    char target[50];

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("\nEnter node names:\n");
    for (i = 0; i < n; i++)
    {
        printf("Node %d: ", i);
        scanf("%49s", name[i]);
    }

    printf("\nEnter adjacency matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("\nEnter starting node number: ");
    scanf("%d", &start);

    printf("Enter file name to search: ");
    scanf("%49s", target);

    found = 0;
    BFS(start, target);

    for (i = 0; i < n; i++)
        visited[i] = 0;

    found = 0;
    printf("\nDFS Traversal: ");
    DFS(start, target);

    if (found)
        printf("\nFile found using DFS.\n");
    else
        printf("\nFile not found using DFS.\n");

    return 0;
}
