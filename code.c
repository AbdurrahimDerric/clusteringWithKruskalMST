#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct edge
{
    int u;
    int v;
    int value;
}edge;

struct edge edges[250];  //global edges array
int mat[100][100];
int columns, rows;
int edgeNum;
int count[100]; //global array used in MST
int label = 0; // used in count array to make clusters



void readMatrix()  //reading matrix
{
    int i,j;  // auxiliary variables
   FILE *reader;
   reader = fopen("data.txt","r");
   char *temp[100], *token;  // auxiliary variables
    i=0;

        while(fscanf(reader,"%s",temp)==1)
          {
           token = strtok(temp,",");
           j=0;
             while(token!=NULL)
               {
                mat[i][j]= atoi(token);
                token = strtok(NULL,",");
                j++;
                }
           i++;
         }
    rows = j;
    columns =i;
}


void printMatrix()  //printing matrix
 {
     int i,j;   // auxiliary variables
     for(i=0;i<rows;i++)
     {
         for(j=0;j<columns;j++)
         {
             printf("%d ",mat[i][j]);

         }
         printf("\n");
     }

 }



 void CreateEdges()   //convert matrix to edges
 { int i,j,k=0;   // auxiliary variables

     for(i=1;i<rows;i++)
     {
         for(j=0;j<i;j++)
         {
             if(mat[i][j]!=0)
             {
             edges[k].u=i;
             edges[k].v=j;
             edges[k].value=mat[i][j];
             k++;
             }
         }
     }
    /* for(i=0; i<k; i++)
     {
         printf("%d %d %d \n",edges[i].u,edges[i].v,edges[i].value);
     }*/
     edgeNum = k;
 }

 void sortEdges()  //sorting the edge array to implement MSt
 {
   int i,j,min,yer;   // auxiliary variables
   int utemp, vtemp,valuetemp;   //temp variables

   for(i=0;i<edgeNum;i++)
     {
         min = edges[i].value;
         yer = i;
         for(j=i+1 ;j<edgeNum;j++)
         {
            if(edges[j].value<min)
            {
                min = edges[j].value;
                yer = j;
             }
          }
        utemp = edges[yer].u;
        vtemp =edges[yer].v;
        valuetemp =edges[yer].value;

        edges[yer].u=edges[i].u;
        edges[yer].v =edges[i].v;
        edges[yer].value=edges[i].value;

        edges[i].u = utemp;
        edges[i].v = vtemp;
        edges[i].value = valuetemp;

 }
  printf("\n");
  for(i=0; i<edgeNum; i++)
     {
         printf("%d %d %d \n",edges[i].u,edges[i].v,edges[i].value);
     }
 }


void cluster()   //creating cluster out of edge array
   {
      int i,j=0,temp,u,v; // auxiliary variables

      int labelCount=0;
      int k ; // number of clusters
      int labeledEdgeNumber = 0; // used to check number of  empty nodes left
      printf("enter number of clusters \n");
      scanf("%d",&k);

      for(i=0; i<rows; i++)  //zeroing count array
       {
           count[i]=0;
       }

      while((labelCount<k )&& ((labelCount + (rows - labeledEdgeNumber))>k))
      {
        u = edges[j].u;
        v= edges[j].v;
        if(count[u]+count[v]==0)
        {
          label++;
          labelCount++;
          count[u]=count[v]=label;
          labeledEdgeNumber+=2;
        }
        else if (count[u]!=count[v])
        {
           if(count[u]==0)
           {
               count[u]=count[v];
               labeledEdgeNumber++;
           }
           else if(count[v]==0)
           {
              count[v]=count[u];
              labeledEdgeNumber++;
           }
           else
            {
             for (i=0;i<rows;i++)
             {
                 if(count[i]==count[u])
                    count[i]=count[u];
             }
             labelCount--;
            }
        }
        j++;
      }
      printf("first phase done \n");

      if(labelCount==k)
      {
         // labeledEdgeNumber++;
       while (columns-labeledEdgeNumber!=0)
       {
         u = edges[j].u;
         v = edges[j].v;
        if(count[u]+ count[v]==0)
        {
          //pass
        }
        else if (count[u]!=count[v])
        {
           if(count[u]==0)
           {
               count[u]=count[v];
               labeledEdgeNumber++;
           }
           else if(count[v]==0)
           {
              count[v]=count[u];
              labeledEdgeNumber++;
           }
        }
        j++;
       }


      }
      else
      {
          for (i=0;i<rows;i++)
          {
              if ((count[i]==0) &&(label <k))
              {
                label++;
                count[i]=label;
              }
              else if(count[i]==0)
              {
                  count[i]=label;
              }
          }
     printf("clustering done \n ");
      }
}




void printClusters()    // printing cluster
     {   int i,j;
          printf("\n the label array is \n");
         for (i=0;i<rows;i++)
         {
             printf("%d " ,count[i]);
         }
         printf("\n \n the clusters are \n ");

        for (i=1 ;i<label+1;i++)
        {
            printf("\n %d. kume ",i);
            for (j=0;j<rows;j++)
            {
                if (count[j]==i)
                {
                     printf("%d ",j);
                }
            }

        }
     }


int main()
{
    readMatrix();
    printf("%d  rows %d colmns  \n",rows,columns);
    printMatrix();
    printf("Hello world!\n");
    CreateEdges();
    sortEdges();
    printf("\n \n");
    cluster();
    printClusters();
    return 0;
}
