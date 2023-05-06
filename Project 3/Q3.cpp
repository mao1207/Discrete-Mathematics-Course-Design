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
	void reflexive();					//���Է��հ�
	void symmetric();					//��ԳƱհ�
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
	relation = new int*[row];
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

//���ϵ������Է��հ�
void Relation::reflexive() {
	//��ʼ���Է��հ�����
	int** reflexive = new int* [row];
	for (int i = 0; i < row; i++) {
		reflexive[i] = new int[cal];
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < cal; j++) {
			reflexive[i][j] = relation[i][j];
		}
	}

	//���Է��հ�
	for (int i = 0; i < row; i++) {
		reflexive[i][i] = 1;
	}

	//��ӡ�Է��հ�
	printMatrix(reflexive);
}

//���ϵ����ĶԳƱհ�
void Relation::symmetric() {
	//��ʼ���ԳƱհ�����
	int** symmetric = new int* [row];
	for (int i = 0; i < row; i++) {
		symmetric[i] = new int[cal];
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < cal; j++) {
			symmetric[i][j] = relation[i][j];
		}
	}

	//��ԳƱհ�
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < cal; j++) {
			if (j < row && symmetric[i][j] == 1)
				symmetric[j][i] = 1;
		}
	}

	//��ӡ�ԳƱհ�
	printMatrix(symmetric);
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

	//�󴫵ݱհ�(��ͳ�㷨)
	for (int m = 0; m < row - 1; m++) {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < cal; j++) {
				if (transitive[i][j] == 1) {
					for (int k = 0; k < cal; k++) {
						if (transitive[j][k] == 1)
							transitive[i][k] = 1;
					}
				}
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
	while (1) {
		Relation matrix;
		cout << "�������Ӧ���ѡ���㷨" << endl;
		cout << "1:�Է��հ�" << endl;
		cout << "2:���ݱհ�" << endl;
		cout << "3:�ԳƱհ�" << endl;
		cout << "4:�˳�" << endl;
		int mode;
		while (1) {
			cin >> mode;
			if (cin.fail() || mode < 0 || mode > 4) {
				cout << "�����������������:" << endl;
				cin.clear();
				char t;
				while ((t = cin.get()) != '\n');
			}
			else
				break;
		}
		switch (mode) {
		case 1:
			matrix.reflexive();
			break;
		case 2:
			matrix.transitive();
			break;
		case 3:
			matrix.symmetric();
			break;
		case 4:
			exit(0);
		default:
			break;
		}
	}

}