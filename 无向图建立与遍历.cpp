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
	cout << "                ��ӭ��������ͼ�洢�ṹ�Ľ��������������������" << endl;
	cout << "**===================================================================**" << endl;
	cout << "-------------------------------------------------------------------------" << endl;
	cout << "�ó��������ͼ�Ľ��������ʵ�����¹��ܣ�" << endl;
	cout << "                                   1--���ڽӾ���ķ�ʽ��������ͼ��" << endl;
	cout << "                                   2--���ڽӱ�ķ�ʽ��������ͼ��" << endl;
	cout << "                                   3--���ڽӶ��ر�ķ�ʽ��������ͼ��" << endl;
	cout << "                                   4--������Ԫ�ص��ļ��ٶ�ȡ�ļ���ʽ��ͼ��" << endl;
	cout << "����ʱ�ļ���淶��" << endl;
	cout << "                                   1--ֻ����int������" << endl;
	cout << "                                   2--�����ʱֱ�����붥����" << endl;
	cout << "-------------------------------------------------------------------------" << endl;
	bool flag = true;
	while (flag == true) {
		cout << "��ѡ������ͼ����";
		cin >> choose;
		switch (choose) {
		case 1: {
			cout << "************************************************" << endl;
			cout << "        ��������ʹ���ڽӾ�����������ͼ��" << endl;
			cout << "************************************************" << endl;
			CreateMTGraph(&G);
			cout << "�ڽӾ������£�" << endl;
			PrintGraph(&G);
			cout << "������ȱ������н��Ϊ��";
			DFSTraverse(&G);
			cout << endl;
			cout << "������ȷǵݹ�������н��Ϊ��";
			DFSTraverse2(&G);
			cout << endl;
			cout << "������ȱ������н��Ϊ��";
			BFSTraverse(&G);
			cout << endl;
			cout << "********************************************" << endl;
			cout << "            ��ӭ����ת������" <<endl;
			cout << "********************************************" << endl;
			cout << "--------------------------------------------------" << endl;
			cout << "�ó������ʵ���ڽӾ��������½ṹת����" << endl;
			cout << "                             1--�ڽӱ�" << endl;
			cout << "                             2--�ڽӶ��ر�" << endl;
			cout << "--------------------------------------------------" << endl;
			int i;
			cout << "��ѡ��Ҫת����������ʽ��";
			cin >> i;
			switch (i) {
			case 1: {
				cout << "��ת�����ڽӱ�" << endl;
				g=MTtoADJ(&G);
				cout << "�ڽӱ����£�" << endl;
				PrintADJGraph(g);
				break;
			}
			case 2: {
				cout << "��ת�����ڽӶ��ر�" << endl;
				g5=MTtoAML(&G);
				cout << "ת���ɵ��ڽӶ��ر����£�" << endl;
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
			cout << "       ��������ʹ���ڽӱ���������ͼ��" << endl;
			cout << "************************************************" << endl;
			CreateADJGraph(&G2);
			cout << "�ڽӱ����£�" << endl;
			PrintADJGraph(&G2);
			cout << "������ȱ������н��Ϊ��";
			BFSTraverse(&G2);
		    cout << "������ȱ������н��Ϊ��";
			DFSVisited(&G2);
			cout << endl;
			cout << "������ȷǵݹ�������н��Ϊ��";
			DFSVisited2(&G2);
			cout << endl;
			cout << "********************************************" << endl;
			cout << "            ��ӭ����ת������" << endl;
			cout << "********************************************" << endl;
			cout << "--------------------------------------------------" << endl;
			cout << "�ó������ʵ���ڽӾ��������½ṹת����" << endl;
			cout << "                             1--�ڽӾ���" << endl;
			cout << "                             2--�ڽӶ��ر�" << endl;
			cout << "--------------------------------------------------" << endl;
			int t;
			cout << "��ѡ��Ҫת����������ʽ��";
			cin >> t;
			switch (t) {
			case 1: {
				cout << "��ת�����ڽӾ���" << endl;
				g2=ADJtoMT(&G2);
				cout << "�ڽӾ������£�" << endl;
				PrintGraph(g2);
				break;
			}
			case 2: {
				cout << "��ת�����ڽӶ��ر�" << endl;
				g6=ADJtoAML(&G2);
				cout << "�ڽӶ��ر����£�";
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
			cout << "      ��������ʹ���ڽӶ��ر���������ͼ��" << endl;
			cout << "************************************************" << endl;
			G3.CreateAMLGraph();
			cout << "�ڽӶ��ر�ṹΪ��" << endl;
			G3.Display();
			cout << "������ȱ������н��Ϊ��";
			G3.DFS_Traverse();
			cout << "������ȷǵݹ�������н��Ϊ��";
			G3.DFS_Traverse2();
			cout << "������ȱ������н��Ϊ��";
			G3.BFS_Traverse();
			cout << "********************************************" << endl;
			cout << "            ��ӭ����ת������" << endl;
			cout << "********************************************" << endl;
			cout << "--------------------------------------------------" << endl;
			cout << "�ó������ʵ���ڽӾ��������½ṹת����" << endl;
			cout << "                             1--�ڽӾ���" << endl;
			cout << "                             2--�ڽӱ�" << endl;
			cout << "--------------------------------------------------" << endl;
			int k;
			cout << "��ѡ��Ҫת����������ʽ��";
			cin >> k;
			switch (k) {
			case 1: {
				cout << "��ת�����ڽӾ���" << endl;
				g3=AMLtoMT(&G3);
				cout << "�ڽӾ������£�" << endl;
				PrintGraph(g3);
				break;
			}
			case 2: {
				cout << "��ת�����ڽӱ�" << endl;
				g4=AMLtoADJ(&G3);
				cout << "�ڽӱ���ʾΪ��" << endl;
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
			cout << "              ���������ļ���ʽ��������ͼ��" << endl;
			cout << "************************************************" << endl;
			cout << "�ó�����������·�ʽ��������ͼ��" << endl;
			cout << "                             1--�ڽӾ���" << endl;
			cout << "                             2--�ڽӱ�" << endl;
			cout << "                             2--�ڽӶ��ر�" << endl;
			cout << "--------------------------------------------------" << endl;
			InFile();
			OutFile();
			cout << "��ѡ��ͼ����";
			freopen("CON", "r", stdin);
			int File;
			cin >> File;
			switch (File) {
			case 1:
				cout << "���ڽӾ�������ͼ��" << endl;
				CreateMTGraph2(&G4);
				cout << "����ͼ��ʾΪ��" << endl;
				PrintGraph(&G4);
				break;
			case 2:
				cout << "���ڽӱ�����ͼ��" << endl;
				CreateADJGraph2(&G5);
				cout << "����ͼ��ʾΪ��"<<endl;
				PrintADJGraph(&G5);
				break;
			case 3:
				cout << "���ڽӶ��ر�ͼ��" << endl;
				G6.CreateAMLGraph2();
				cout << "����ͼ��ʾΪ��"<<endl;
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
		cout << "��ѡ�񣨡�Y�� ��y����������N����n����������";
		cin >> ch;
		if (ch == 'y' || ch == 'Y' || ch == 'n' || ch == 'N') {
			if (ch == 'y' || ch == 'Y') flag = true;
			else flag = false;
		}
		else {
			cout << "ֻ���������ĸ���ĸ�����������룺";
			cin >> ch;
			if (ch == 'y' || ch == 'Y') flag = true;
			else flag = false;
		}
	}
	system("pause");
	return 0;
}