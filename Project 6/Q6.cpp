#include <iostream>
using namespace std;

//��ϵ��
class Relation {
private:
	int row, cal;						//������
	int** relation;						//��ϵ����
public:
	Relation();							//���캯��
	~Relation();						//��������
	void transitive();					//�󴫵ݱհ�
	void printMatrix(int** matrix);		//��ӡ����
};

/*��ϵ�ຯ��������ʵ��*/

//���캯��
Relation::Relation() {
	//��������
	cout << "��������������:";
	while (1) {
		cin >> row;
		if (cin.fail()) {
			cout << "�����������������:" << endl;
			cin.clear();
			char t;
			while ((t = cin.get()) != '\n');
		}
		else if (row < 0 || row>100) {
			cout << "����Ӧ����0-100֮�䣬����������:" << endl;
			char t;
			while ((t = cin.get()) != '\n');
		}
		else
			break;
	}

	//��������
	cout << "��������������:";
	while (1) {
		cin >> cal;
		if (cin.fail()) {
			cout << "�����������������:" << endl;
			cin.clear();
			char t;
			while ((t = cin.get()) != '\n');
		}
		else if (cal < 0 || cal>100) {
			cout << "����Ӧ����0-100֮�䣬����������:" << endl;
			char t;
			while ((t = cin.get()) != '\n');
		}
		else if (cal != row) {
			cout << "�������������������:" << endl;
			char t;
			while ((t = cin.get()) != '\n');
		}
		else
			break;
	}

	//�����ϵ����
	relation = new int* [row];
	for (int i = 0; i < row; i++) {
		relation[i] = new int[cal];
	}
	cout << "�������ϵ����" << endl;
	for (int i = 0; i < row; i++) {
		cout << "���������ĵ�" << i + 1 << "��Ԫ��(Ԫ���Կո�ָ�):";
		for (int j = 0; j < cal; j++) {
			cin >> relation[i][j];
			if (cin.fail() || (relation[i][j] != 0 && relation[i][j] != 1)) {
				cin.clear();
				cout << "������������������" << i + 1 << "��Ԫ��:";
				char t;
				while ((t = cin.get()) != '\n');
				j = -1;
			}
		}
	}
}

//��������
Relation::~Relation() {
	delete[] relation;
}

//���ϵ����Ĵ��ݱհ�
void Relation::transitive() {
	//��ʼ�����ݱհ�����
	int** transitive = new int* [row];
	for (int i = 0; i < row; i++) {
		transitive[i] = new int[cal];
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < cal; j++) {
			transitive[i][j] = relation[i][j];
		}
	}

	//�󴫵ݱհ�
	for (int i = 0; i < cal; i++) {
		for (int j = 0; j < row; j++) {
			for (int k = 0; k < cal; k++) {
				if (transitive[i][k] && transitive[j][i] == 1)
					transitive[j][k] = 1;
			}
		}
	}

	//��ӡ���ݱհ�
	printMatrix(transitive);
}

//��ӡ����
void Relation::printMatrix(int** matrix) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < cal; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	delete[] matrix;
}

int main()
{
	Relation matrix;
	cout << "��ϵ����Ĵ��ݱհ�(Warshall�㷨ʵ��)��" << endl;
	matrix.transitive();
}