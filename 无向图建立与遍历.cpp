#include "Change.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
using namespace std;
int main() {
	system("color f2");
	int choose;
	MTGraph G,G4,* g2, *g3;
	ADJGraph G2,*g,*g4,G5;
	AMLGraph G3,*g5,*g6,G6;
	cout << "**===================================================================**" << endl;
	cout << "                欢迎来到无向图存储结构的建立与遍历（搜索）程序" << endl;
	cout << "**===================================================================**" << endl;
	cout << "-------------------------------------------------------------------------" << endl;
	cout << "该程序的无向图的建立程序可实现如下功能：" << endl;
	cout << "                                   1--以邻接矩阵的方式建立无向图；" << endl;
	cout << "                                   2--以邻接表的方式建立无向图；" << endl;
	cout << "                                   3--以邻接多重表的方式建立无向图；" << endl;
	cout << "                                   4--以输入元素到文件再读取文件方式建图。" << endl;
	cout << "输入时的几点规范：" << endl;
	cout << "                                   1--只接受int型整数" << endl;
	cout << "                                   2--输入边时直接输入顶点名" << endl;
	cout << "-------------------------------------------------------------------------" << endl;
	bool flag = true;
	while (flag == true) {
		cout << "请选择建无向图程序：";
		cin >> choose;
		switch (choose) {
		case 1: {
			cout << "************************************************" << endl;
			cout << "        接下来将使用邻接矩阵来建无向图！" << endl;
			cout << "************************************************" << endl;
			CreateMTGraph(&G);
			cout << "邻接矩阵如下：" << endl;
			PrintGraph(&G);
			cout << "深度优先遍历序列结果为：";
			DFSTraverse(&G);
			cout << endl;
			cout << "深度优先非递归遍历序列结果为：";
			DFSTraverse2(&G);
			cout << endl;
			cout << "广度优先遍历序列结果为：";
			BFSTraverse(&G);
			cout << endl;
			cout << "********************************************" << endl;
			cout << "            欢迎来到转换程序！" <<endl;
			cout << "********************************************" << endl;
			cout << "--------------------------------------------------" << endl;
			cout << "该程序可以实现邻接矩阵向如下结构转换：" << endl;
			cout << "                             1--邻接表" << endl;
			cout << "                             2--邻接多重表" << endl;
			cout << "--------------------------------------------------" << endl;
			int i;
			cout << "请选择要转换的其他方式：";
			cin >> i;
			switch (i) {
			case 1: {
				cout << "将转换成邻接表：" << endl;
				g=MTtoADJ(&G);
				cout << "邻接表如下：" << endl;
				PrintADJGraph(g);
				break;
			}
			case 2: {
				cout << "将转换成邻接多重表：" << endl;
				g5=MTtoAML(&G);
				cout << "转换成的邻接多重表如下：" << endl;
				(*g5).Display();
				break;
			}
			default: {
				break;
			}
			}
			break;
		}case 2: {
			cout << "************************************************" << endl;
			cout << "       接下来将使用邻接表来建无向图！" << endl;
			cout << "************************************************" << endl;
			CreateADJGraph(&G2);
			cout << "邻接表如下：" << endl;
			PrintADJGraph(&G2);
			cout << "广度优先遍历序列结果为：";
			BFSTraverse(&G2);
		    cout << "深度优先遍历序列结果为：";
			DFSVisited(&G2);
			cout << endl;
			cout << "深度优先非递归遍历序列结果为：";
			DFSVisited2(&G2);
			cout << endl;
			cout << "********************************************" << endl;
			cout << "            欢迎来到转换程序！" << endl;
			cout << "********************************************" << endl;
			cout << "--------------------------------------------------" << endl;
			cout << "该程序可以实现邻接矩阵向如下结构转换：" << endl;
			cout << "                             1--邻接矩阵" << endl;
			cout << "                             2--邻接多重表" << endl;
			cout << "--------------------------------------------------" << endl;
			int t;
			cout << "请选择要转换的其他方式：";
			cin >> t;
			switch (t) {
			case 1: {
				cout << "将转换成邻接矩阵：" << endl;
				g2=ADJtoMT(&G2);
				cout << "邻接矩阵如下：" << endl;
				PrintGraph(g2);
				break;
			}
			case 2: {
				cout << "将转换成邻接多重表：" << endl;
				g6=ADJtoAML(&G2);
				cout << "邻接多重表如下：";
				(*g6).Display();
				break;
			}
			default: {
				break;
			}
			}
			break;
		}case 3: {
			cout << "************************************************" << endl;
			cout << "      接下来将使用邻接多重表来建无向图！" << endl;
			cout << "************************************************" << endl;
			G3.CreateAMLGraph();
			cout << "邻接多重表结构为：" << endl;
			G3.Display();
			cout << "深度优先遍历序列结果为：";
			G3.DFS_Traverse();
			cout << "深度优先非递归遍历序列结果为：";
			G3.DFS_Traverse2();
			cout << "广度优先遍历序列结果为：";
			G3.BFS_Traverse();
			cout << "********************************************" << endl;
			cout << "            欢迎来到转换程序！" << endl;
			cout << "********************************************" << endl;
			cout << "--------------------------------------------------" << endl;
			cout << "该程序可以实现邻接矩阵向如下结构转换：" << endl;
			cout << "                             1--邻接矩阵" << endl;
			cout << "                             2--邻接表" << endl;
			cout << "--------------------------------------------------" << endl;
			int k;
			cout << "请选择要转换的其他方式：";
			cin >> k;
			switch (k) {
			case 1: {
				cout << "将转换成邻接矩阵：" << endl;
				g3=AMLtoMT(&G3);
				cout << "邻接矩阵如下：" << endl;
				PrintGraph(g3);
				break;
			}
			case 2: {
				cout << "将转换成邻接表：" << endl;
				g4=AMLtoADJ(&G3);
				cout << "邻接表显示为：" << endl;
				PrintADJGraph(g4);
				break;
			}
			default: {
				break;
			}
			}
			break;
			break;
		}case 4: {
			cout << "************************************************" << endl;
			cout << "              接下来以文件形式来建无向图！" << endl;
			cout << "************************************************" << endl;
			cout << "该程序可以用如下方式建立无向图：" << endl;
			cout << "                             1--邻接矩阵" << endl;
			cout << "                             2--邻接表" << endl;
			cout << "                             2--邻接多重表" << endl;
			cout << "--------------------------------------------------" << endl;
			InFile();
			OutFile();
			cout << "请选择建图程序：";
			freopen("CON", "r", stdin);
			int File;
			cin >> File;
			switch (File) {
			case 1:
				cout << "以邻接矩阵建无向图：" << endl;
				CreateMTGraph2(&G4);
				cout << "无向图显示为：" << endl;
				PrintGraph(&G4);
				break;
			case 2:
				cout << "以邻接表建无向图：" << endl;
				CreateADJGraph2(&G5);
				cout << "无向图显示为："<<endl;
				PrintADJGraph(&G5);
				break;
			case 3:
				cout << "以邻接多重表建图：" << endl;
				G6.CreateAMLGraph2();
				cout << "无向图显示为："<<endl;
				G6.Display();
			default:
				break;
			}
			break;
		}default: {
			break;
		}
		}
		getchar();
		char ch;
		cout << "请选择（‘Y’ 或‘y’继续，‘N’或‘n’结束）：";
		cin >> ch;
		if (ch == 'y' || ch == 'Y' || ch == 'n' || ch == 'N') {
			if (ch == 'y' || ch == 'Y') flag = true;
			else flag = false;
		}
		else {
			cout << "只接受以上四个字母！请重新输入：";
			cin >> ch;
			if (ch == 'y' || ch == 'Y') flag = true;
			else flag = false;
		}
	}
	system("pause");
	return 0;
}