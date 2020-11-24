#include"prim.h"

void InitPrim(MGraph G, BOOL** flag, unsigned int** min_weight, int** adjvex,VertexType StartVertex)//初始化各种辅助数组
{
		  *flag = (BOOL*)calloc(G.vexnum,sizeof(BOOL));
		  assert(*flag != NULL);
		  *min_weight = (unsigned int*)calloc(G.vexnum, sizeof(unsigned int));
		  assert(*min_weight != NULL);
		  *adjvex = (int*)calloc(G.vexnum, sizeof(int));
		  assert(*adjvex != NULL);
		  for (int i = 0; i < G.vexnum; ++i)
		  {
					(*adjvex)[i] = -1;			  //初始化前驱顶点数组
					  /*初始化从起点StartVertex到其他结点的权，并且默认设置StartVertex起点已经访问*/
					(*min_weight)[i] = G.Edge[LocateVertex(G, StartVertex)][i];	//初始化顶点数组
		  }
		  (*min_weight)[LocateVertex(G, StartVertex)] = 0;
		  (*flag)[LocateVertex(G, StartVertex)] = TRUE;	    //默认设置StartVertex起点已经访问
}

void DestroyPrim( BOOL* flag, int* min_weight, int* adjvex)			  //释放prim算法所用的资源
{
		  free(flag);
		  free(min_weight);
		  free(adjvex);
}

BOOL JudgeFlag(MGraph G, BOOL* flag)			  //判断标记数组是否已经被全部的访问
{
		  BOOL Judge = TRUE;
		  for (int i = 0; i < G.vexnum; ++i)
		  {
					if (!flag[i])
					{
							  Judge = FALSE;
							  break;					//没有全部的访问，V(G)中还有没访问的元素
					}
		  }
		  return Judge;	//全部访问
}

void Prim(MGraph G, VertexType StartVertex)	  //确定需要访问的顶点并生成prim生成树
{
		  BOOL* flag = NULL;
		  unsigned int* min_weight = NULL;
		  int* adjvex = NULL;
		  InitPrim(G, &flag, &min_weight, &adjvex, StartVertex);	//初始化

		  /*进入循环判断，需要prim最小生成树中顶点集合V(G)必须全部被访问*/
		  while (!JudgeFlag(G, flag))	//辅助标记数组，用于判断当前是否还有没有访问的顶点
		  {
					unsigned int ShortestEdge = INFINITYSIZE;   //记录边的权，初始化为不连通的状态
					int EndPos = 0;		 //记录终点坐标，用于连接
					int StartPos = 0;				 //记录起点坐标
					for (int i = 0; i < G.vexnum; ++i) 
					{
							  if (flag[i])		  //该顶点已经被访问了
							  {
										for (int endpos = 0; endpos < G.vexnum; ++endpos)
										{
												  //该顶点没被访问，属于集合V-V_T
												  //且该顶点不应该位于对角线上(不为0)
												  if (!flag[endpos] && G.Edge[i][endpos])
												  {
															if (G.Edge[i][endpos] != -1 &&ShortestEdge >= G.Edge[i][endpos] )		//选择排序找权最小的
															{	
																	  ShortestEdge = G.Edge[i][endpos];
																	  EndPos = endpos; //记录V-V_T中的顶点
																	  StartPos = i;				  ////记录(起始V_T)前驱顶点下标
															}
												  }
										}
							  }
					}
					adjvex[EndPos] = StartPos;		//将V-V_T中的顶点指向V_T
					printf("%c----->%c      Distance = %d\n", G.Vex[StartPos], G.Vex[EndPos], ShortestEdge);
					flag[EndPos] = TRUE;			//标记该顶点被访问
					min_weight[EndPos] = 0;		//清空长度
					/*从已经访问过的顶点到其他顶点的距离是否小于从初始源点StartVertex出发到各顶点的距离*/
					for (int alreadyvisit = 0; alreadyvisit < G.vexnum; ++alreadyvisit)
					{
							  if (flag[alreadyvisit])					  //该顶点已经被访问了
							  {
										for (int i = 0; i < G.vexnum; ++i)
										{
												  //辅助距离数组的长度不为0(被访问过了)
												   //且该顶点不应该位于对角线上(不为0)
												  if (min_weight[i] && G.Edge[alreadyvisit][i]) 
												  {
															//源点到其他顶点距离小于顶点已经访问过的到其他顶点的距离
															if (min_weight[i] >= G.Edge[alreadyvisit][i])
															{
																	  min_weight[i] = G.Edge[alreadyvisit][i];
															}
												  }
										}
							  }
					}
		  }
		  DestroyPrim(flag, min_weight, adjvex);			//辅助数组的摧毁
}
