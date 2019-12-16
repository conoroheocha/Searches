//Implementation of breadth first search and depth first search on an unweighted graph visualised as a 2D array

#include <stdio.h>

void dfs(int x, int graph[x][x], int start, int visited[x]);
void bfs(int x, int graph[x][x], int start, int visited[x]);
void addToQueue(int x, int queue[x], int node);
void removeFromQueue(int x, int queue[x]);

int main(void) {
  //Adjacency matrix with nodes in alphabetical order, column is departure, row is arrival
  const int NODES = 6;
  int graph[6][6] = {
  //       A, B, C, D, E, F
  /* A */{-1, 1, 0, 1, 1, 0},//1 is path, 0 is no path
  /* B */{0, -1, 1, 1, 0, 0},
  /* C */{0, 1, -1, 1, 0, 0},
  /* D */{0, 0, 0, -1, 0, 1},
  /* E */{0, 0, 0, 1, -1, 0},
  /* F */{0, 0, 1, 0, 0, -1},
  };

  //DFS
  int visitedDFS[6] = {0, 0, 0, 0, 0, 0};
  printf("DFS: ");
  dfs(NODES, graph, 0, visitedDFS);

  //BFS
  int visitedBFS[6] = {0, 0, 0, 0, 0, 0};
  printf("\nBFS: ");
  bfs(NODES, graph, 0, visitedBFS);

  return 0;
}

void dfs(int x, int graph[x][x], int curr, int visited[x]){
  char node = (char)curr + 65;
  printf("%c", node); //prints current
  visited[curr] = 1;  //marks as visited
  for(int i = 0; i < x; i++){
    if(graph[curr][i] == 1 && visited[i] != 1){
      dfs(x, graph, i, visited);  //for each non-visted with link, performs dfs
    }
  }
  return;
}

void bfs(int x, int graph[x][x], int curr, int visited[x]){
  visited[curr] = 1;
  char node = (char)curr + 65;
  printf("%c", node);
  int queue[x];
  for(int i = 0; i < x; i++){ //sets queue to empty
    queue[i] = -1;
  }
  addToQueue(x, queue, curr); //adds root to queue
  while(queue[0] != -1){  //while queue not empty
    curr = queue[0];  //curr node = next in queue
    removeFromQueue(x, queue);  //queue progresses
    for(int i = 0; i < x; i++){
      if(graph[curr][i] == 1 && visited[i] != 1){
        visited[i] = 1;
        node = (char)i + 65;
        printf("%c", node);
        addToQueue(x, queue, i);  //prints all newly visited nodes and adds them to queue
      }
    }
  }
}

void addToQueue(int x, int queue[x], int node){ //adds node to end of queue
  for(int i = 0; i < x; i++){
    if(queue[i] == -1){
      queue[i] = node;
      return;
    }
  }
}

void removeFromQueue(int x, int queue[x]){  //removes first from queue and moves others up one position
  for(int i = 1; i < x; i++){
    queue[i - 1] = queue[i];
    queue[i] = -1;
  }
}