#pragma once
#include"MGraph.h"

#pragma warning(disable:4018)

void InitPrim(MGraph G, BOOL** flag, unsigned int** min_weight, int** adjvex, VertexType StartVertex);//初始化各种辅助数组
void DestroyPrim(BOOL* flag, int* min_weight, int* adjvex);		  //释放prim算法所用的资源
BOOL JudgeFlag(MGraph G, BOOL* flag);			  //判断标记数组是否已经被全部的访问
void Prim(MGraph G, VertexType StartVertex);	  //确定需要访问的顶点并生成prim生成树