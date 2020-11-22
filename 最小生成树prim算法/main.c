#include"MGraph.h"
#include"DirectedEdge.h"                   //����ͼ
#include"UnDirectedEdge.h"              //����ͼ
#include"prim.h"              //prim�㷨

int main()
{
          MGraph Graph;
          InitGraph(&Graph);         //��ʼ��

          /*�����б��������*/
          VertexType arr[] = { "ABCDE" };
          CreateBatchVertex(&Graph, arr, GRAPHWITHVALUE);      //�����б��������

          VertexType arr1[] = "AAABCC";
          VertexType arr2[] = "BCECDE";
          int distance[] = { 3,1,4,2,5,6 };                 //������������

          for (int i = 0; i < (int)strlen(arr1); ++i)
          {
                    InsertUnDirectEdgeValue(&Graph, *(arr1 + i), *(arr2 + i), distance[i]);
          }
          DisplayGraph(Graph);          //ͼ�����

          Prim(Graph, 'A');

          DestroyGraph(&Graph);         //ͼ������
          return 0;
}