#include"MGraph.h"
#include"DirectedEdge.h"                   //有向图
#include"UnDirectedEdge.h"              //无向图
#include"prim.h"              //prim算法

int main()
{
          MGraph Graph;
          InitGraph(&Graph);         //初始化

          /*顶点列表批量添加*/
          VertexType arr[] = { "ABCDE" };
          CreateBatchVertex(&Graph, arr, GRAPHWITHVALUE);      //顶点列表批量添加

          VertexType arr1[] = "AAABCC";
          VertexType arr2[] = "BCECDE";
          int distance[] = { 3,1,4,2,5,6 };                 //距离设置数组

          for (int i = 0; i < (int)strlen(arr1); ++i)
          {
                    InsertUnDirectEdgeValue(&Graph, *(arr1 + i), *(arr2 + i), distance[i]);
          }
          DisplayGraph(Graph);          //图的输出

          Prim(Graph, 'A');

          DestroyGraph(&Graph);         //图的销毁
          return 0;
}