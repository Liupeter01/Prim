#include"prim.h"

void InitPrim(MGraph G, BOOL** flag, unsigned int** min_weight, int** adjvex,VertexType StartVertex)//��ʼ�����ָ�������
{
		  *flag = (BOOL*)calloc(G.vexnum,sizeof(BOOL));
		  assert(*flag != NULL);
		  *min_weight = (unsigned int*)calloc(G.vexnum, sizeof(unsigned int));
		  assert(*min_weight != NULL);
		  *adjvex = (int*)calloc(G.vexnum, sizeof(int));
		  assert(*adjvex != NULL);
		  for (int i = 0; i < G.vexnum; ++i)
		  {
					(*adjvex)[i] = -1;			  //��ʼ��ǰ����������
					  /*��ʼ�������StartVertex����������Ȩ������Ĭ������StartVertex����Ѿ�����*/
					(*min_weight)[i] = G.Edge[LocateVertex(G, StartVertex)][i];	//��ʼ����������
		  }
		  (*min_weight)[LocateVertex(G, StartVertex)] = 0;
		  (*flag)[LocateVertex(G, StartVertex)] = TRUE;	    //Ĭ������StartVertex����Ѿ�����
}

void DestroyPrim( BOOL* flag, int* min_weight, int* adjvex)			  //�ͷ�prim�㷨���õ���Դ
{
		  free(flag);
		  free(min_weight);
		  free(adjvex);
}

BOOL JudgeFlag(MGraph G, BOOL* flag)			  //�жϱ�������Ƿ��Ѿ���ȫ���ķ���
{
		  BOOL Judge = TRUE;
		  for (int i = 0; i < G.vexnum; ++i)
		  {
					if (!flag[i])
					{
							  Judge = FALSE;
							  break;					//û��ȫ���ķ��ʣ�V(G)�л���û���ʵ�Ԫ��
					}
		  }
		  return Judge;	//ȫ������
}

void Prim(MGraph G, VertexType StartVertex)	  //ȷ����Ҫ���ʵĶ��㲢����prim������
{
		  BOOL* flag = NULL;
		  unsigned int* min_weight = NULL;
		  int* adjvex = NULL;
		  InitPrim(G, &flag, &min_weight, &adjvex, StartVertex);	//��ʼ��

		  /*����ѭ���жϣ���Ҫprim��С�������ж��㼯��V(G)����ȫ��������*/
		  while (!JudgeFlag(G, flag))	//����������飬�����жϵ�ǰ�Ƿ���û�з��ʵĶ���
		  {
					unsigned int ShortestEdge = INFINITYSIZE;   //��¼�ߵ�Ȩ����ʼ��Ϊ����ͨ��״̬
					int EndPos = 0;		 //��¼�յ����꣬��������
					int StartPos = 0;				 //��¼�������
					for (int i = 0; i < G.vexnum; ++i) 
					{
							  if (flag[i])		  //�ö����Ѿ���������
							  {
										for (int endpos = 0; endpos < G.vexnum; ++endpos)
										{
												  //�ö���û�����ʣ����ڼ���V-V_T
												  //�Ҹö��㲻Ӧ��λ�ڶԽ�����(��Ϊ0)
												  if (!flag[endpos] && G.Edge[i][endpos])
												  {
															if (G.Edge[i][endpos] != -1 &&ShortestEdge >= G.Edge[i][endpos] )		//ѡ��������Ȩ��С��
															{	
																	  ShortestEdge = G.Edge[i][endpos];
																	  EndPos = endpos; //��¼V-V_T�еĶ���
																	  StartPos = i;				  ////��¼(��ʼV_T)ǰ�������±�
															}
												  }
										}
							  }
					}
					adjvex[EndPos] = StartPos;		//��V-V_T�еĶ���ָ��V_T
					printf("%c----->%c      Distance = %d\n", G.Vex[StartPos], G.Vex[EndPos], ShortestEdge);
					flag[EndPos] = TRUE;			//��Ǹö��㱻����
					min_weight[EndPos] = 0;		//��ճ���
					/*���Ѿ����ʹ��Ķ��㵽��������ľ����Ƿ�С�ڴӳ�ʼԴ��StartVertex������������ľ���*/
					for (int alreadyvisit = 0; alreadyvisit < G.vexnum; ++alreadyvisit)
					{
							  if (flag[alreadyvisit])					  //�ö����Ѿ���������
							  {
										for (int i = 0; i < G.vexnum; ++i)
										{
												  //������������ĳ��Ȳ�Ϊ0(�����ʹ���)
												   //�Ҹö��㲻Ӧ��λ�ڶԽ�����(��Ϊ0)
												  if (min_weight[i] && G.Edge[alreadyvisit][i]) 
												  {
															//Դ�㵽�����������С�ڶ����Ѿ����ʹ��ĵ���������ľ���
															if (min_weight[i] >= G.Edge[alreadyvisit][i])
															{
																	  min_weight[i] = G.Edge[alreadyvisit][i];
															}
												  }
										}
							  }
					}
		  }
		  DestroyPrim(flag, min_weight, adjvex);			//��������Ĵݻ�
}
