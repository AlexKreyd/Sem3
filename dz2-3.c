#include<stdio.h>
#include<stdlib.h>

int main(void){
  int arr1[100];
  int arr2[100];
  printf("Enter the graph, write -1 - -1 to end\n");
  int a = 0,b = 0;
  int max_node = -1;;
  do{
    int c,d;
    scanf("%d - %d",&c, &d);
    if(c == -1 && d == -1) break;
    if(c > max_node) max_node = c;
    if(d > max_node) max_node = d;
    arr1[a] = c;
    arr2[b] = d;
    a++;
    b++;
  }while(1);

  int matrix[100][100];
  for(int i =0; i < 100; ++i){
    for(int j = 0; j < 100; ++j)
      matrix[i][j] = 0;
  }


  for(int i = 0; i < a; ++i){
    if(arr1[i] == arr2[i]){
      matrix[arr1[i]-1][arr2[i]-1] += 1;
      continue;
    }
    matrix[arr1[i]-1][arr2[i]-1] += 1;
    matrix[arr2[i]-1][arr1[i]-1] += 1;
  }


    int simple = 1;
    for(int i =0; i < max_node; ++i){
      if(simple == 0 ) break;
      for(int j = 0; j < max_node; ++j){
        if((i == j) && matrix[i][j] > 0){
          simple = 0;
          break;
        }
        if(matrix[i][j] > 1){
          simple = 0;
          break;
        }
      }
    }

    if(simple == 0) {
      printf("\nGraph isn't simple");
      printf("\nConnectivity can't be calculated\n\n");
    }
    else {
      printf("\nGraph is simple");
      int nodes = 0;
        for(int i =0; i < max_node; ++i){
          for(int j = 0; j< max_node; ++j){
            if(matrix[i][j] == 1){
              nodes +=1;
              break;
            }
          }
        }
      int edges = 0;
      for(int i =0; i < max_node; ++i){
        for(int j = 0; j < max_node; ++j){
          if(matrix[i][j] == 1) edges += 1;
        }
    }
    edges /= 2;
    printf("\nThe number of nodes = %d", nodes);
    printf("\nThe number of edges = %d", edges);
    if(edges > (nodes-1)*(nodes-2)/2) printf("\nGraph is connected\n\n");
    else printf("\nGraph isn't connected\n\n");
  }

  FILE *file;
  file = fopen("graph.dot", "w");
  fprintf(file,"graph gr{\n");
  for(int i = 0; i < a; ++i)
    fprintf(file, "\t%d -- %d;\n", arr1[i], arr2[i]);
  fprintf(file, "}");
  fclose(file);

  system("dot -v -Tpng -o graph_image.png graph.dot");
  system("graph_image.png");

  return 0;
}
