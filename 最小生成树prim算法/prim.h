#pragma once
#include"MGraph.h"

#pragma warning(disable:4018)

void InitPrim(MGraph G, BOOL** flag, unsigned int** min_weight, int** adjvex, VertexType StartVertex);//��ʼ�����ָ�������
void DestroyPrim(BOOL* flag, int* min_weight, int* adjvex);		  //�ͷ�prim�㷨���õ���Դ
BOOL JudgeFlag(MGraph G, BOOL* flag);			  //�жϱ�������Ƿ��Ѿ���ȫ���ķ���
void Prim(MGraph G, VertexType StartVertex);	  //ȷ����Ҫ���ʵĶ��㲢����prim������