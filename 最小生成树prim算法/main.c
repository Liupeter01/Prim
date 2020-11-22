#include"MGraph.h"
#include"DirectedEdge.h"                   //����ͼ
#include"UnDirectedEdge.h"              //����ͼ
#include"prim.h"              //prim�㷨

int main()
{
          MGraph Graph;
          InitGraph(&Graph);         //��ʼ��

          /*�����б��������*/
          VertexType arr[] = { "ABCDEFG" };
          CreateBatchVertex(&Graph, arr, GRAPHWITHVALUE);      //�����б��������

          VertexType arr1[] = "AAABBCGGFEE";
          VertexType arr2[] = "BGFCGDFDDFD";
          int distance[] = { 18,18,19,8,20,20,15,15,16,3,9 };                 //������������

          for (int i = 0; i < (int)strlen(arr1); ++i)
          {
                    InsertUnDirectEdgeValue(&Graph, *(arr1 + i), *(arr2 + i), distance[i]);
          }
          DisplayGraph(Graph);          //ͼ�����

          Prim(Graph, 'A');

          DestroyGraph(&Graph);         //ͼ������
          return 0;
}