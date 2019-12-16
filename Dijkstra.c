//Implementation of dijkstras algorithm on a weighted graph visualised as a 2D array

#include <stdio.h>

void dijkstra(int size, int graph[size][size], int curr, int max);
int sum(int size, int A[size]);


int main(void) {
  //Adjacency matrix with nodes in alphabetical order, column is departure, row is arrival
  const int NODES = 7;
  int graph[7][7] = {
  //       A, B, C, D, E, F, G
  /* A */{-1, 1, 3, 0, 0, 10, 0},
  /* B */{1, -1, 1, 7, 5, 0, 2},
  /* C */{3, 1, -1, 9, 3, 0, 0},
  /* D */{0, 7, 9, -1, 2, 1, 12},
  /* E */{0, 5, 3, 2, -1, 2, 0},
  /* F */{10, 0, 0, 1, 2, -1, 0},
  /* G */{0, 2, 0, 12, 0, 0, -1}
  };

  dijkstra(NODES, graph, 0, 12);

  return 0;
}

void dijkstra(int size, int graph[size][size], int start, int max){
  printf("\nPermanance Order: ");
//   label each node
// • tentative (white circles)
// • distance infinity
int permanent[size];
int curr = start;
int smallest = max * size;
int next;
int distance[size];
for(int i = 0; i < size; i++){
  distance[i] = smallest;
  permanent[i] = 0;
}
distance[start] = 0;
// mark start node as
// • permanent (grey circles)
// • make it the current node (arrow)
char node = (char)curr + 65;
printf("%c", node);
permanent[curr] = 1;
// calculate the distance from source via current node to each of its
// adjacent neighbours, if smaller than current distance to that
// neighbour, update it
while(sum(size, permanent) != size)
{

for(int i = 0; i < size; i++){
    if (graph[curr][i] > 0 && distance[i] > (graph[curr][i] + distance[curr])){
      distance[i] = graph[curr][i] + distance[curr];

  }
}
// from all tentative vertices - mark the one with shortest distance as
// • permanent
// • make it the current vertex
smallest = max * size;
for(int i = 0; i < size; i++){
  if(permanent[i] != 1 && distance[i] < smallest){
    smallest = distance[i];
    next = i;
  }
}
permanent[next] = 1;
curr = next;
node = (char)curr + 65;
printf("%c", node);
// repeat from 3 until all vertices are marked permanent or
// destination node is permanent
}
for(int i = 0; i < size; i++){
  if(i != start){
    printf("\nThe shortest distance from %c to %c is %d", (char)start + 65, (char)i + 65, distance[i]);
  }
}
return;
}

int sum(int size, int A[size]){
  int x = 0;
  for(int i = 0; i < size; i++){
    x += A[i];
  }
  return x;
}