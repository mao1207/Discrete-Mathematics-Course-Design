#include <iostream>
using namespace std;

//关系类
class Relation {
private:
	int row, cal;						//行列数
	int** relation;						//关系矩阵
public:
	Relation();							//构造函数
	~Relation();						//析构函数
	void reflexive();					//求自反闭包
	void symmetric();					//求对称闭包
	void transitive();					//求传递闭包
	void printMatrix(int** matrix);		//打印矩阵
};

/*关系类函数的类外实现*/

//构造函数
Relation::Relation() {
	//输入行数
	cout << "请输入矩阵的行数:";
	while (1) {
		cin >> row;
		if (cin.fail()) {
			cout << "输入错误，请重新输入:" << endl;
			cin.clear();
			char t;
			while ((t = cin.get()) != '\n');
		}
		else if (row < 0 || row>100) {
			cout << "函数应该在0-100之间，请重新输入:" << endl;
			char t;
			while ((t = cin.get()) != '\n');
		}
		else
			break;
	}

	//输入列数
	cout << "请输入矩阵的列数:";
	while (1) {
		cin >> cal;
		if (cin.fail()) {
			cout << "输入错误，请重新输入:" << endl;
			cin.clear();
			char t;
			while ((t = cin.get()) != '\n');
		}
		else if (cal < 0 || cal>100) {
			cout << "函数应该在0-100之间，请重新输入:" << endl;
			char t;
			while ((t = cin.get()) != '\n');
		}
		else if (cal != row) {
			cout << "输入的行数不等于列数:" << endl;
			char t;
			while ((t = cin.get()) != '\n');
		}
		else
			break;
	}

	//输入关系矩阵
	relation = new int*[row];
	for (int i = 0; i < row; i++) {
		relation[i] = new int[cal];
	}
	cout << "请输入关系矩阵" << endl;
	for (int i = 0; i < row; i++) {
		cout << "请输入矩阵的第" << i + 1 << "行元素(元素以空格分隔):";
		for (int j = 0; j < cal; j++) {
			cin >> relation[i][j];
			if (cin.fail() || (relation[i][j] != 0 && relation[i][j] != 1)) {
				cin.clear();
				cout << "输入错误，请重新输入第" << i + 1 << "行元素:";
				char t;
				while ((t = cin.get()) != '\n');
				j = -1;
			}
		}
	}
}

//析构函数
Relation::~Relation() {
	delete[] relation;
}

//求关系矩阵的自反闭包
void Relation::reflexive() {
	//初始化自反闭包矩阵
	int** reflexive = new int* [row];
	for (int i = 0; i < row; i++) {
		reflexive[i] = new int[cal];
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < cal; j++) {
			reflexive[i][j] = relation[i][j];
		}
	}

	//求自反闭包
	for (int i = 0; i < row; i++) {
		reflexive[i][i] = 1;
	}

	//打印自反闭包
	printMatrix(reflexive);
}

//求关系矩阵的对称闭包
void Relation::symmetric() {
	//初始化对称闭包矩阵
	int** symmetric = new int* [row];
	for (int i = 0; i < row; i++) {
		symmetric[i] = new int[cal];
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < cal; j++) {
			symmetric[i][j] = relation[i][j];
		}
	}

	//求对称闭包
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < cal; j++) {
			if (j < row && symmetric[i][j] == 1)
				symmetric[j][i] = 1;
		}
	}

	//打印对称闭包
	printMatrix(symmetric);
}

//求关系矩阵的传递闭包
void Relation::transitive() {
	//初始化传递闭包矩阵
	int** transitive = new int* [row];
	for (int i = 0; i < row; i++) {
		transitive[i] = new int[cal];
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < cal; j++) {
			transitive[i][j] = relation[i][j];
		}
	}

	//求传递闭包(传统算法)
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

	//打印传递闭包
	printMatrix(transitive);
}

//打印矩阵
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
		cout << "请输入对应序号选择算法" << endl;
		cout << "1:自反闭包" << endl;
		cout << "2:传递闭包" << endl;
		cout << "3:对称闭包" << endl;
		cout << "4:退出" << endl;
		int mode;
		while (1) {
			cin >> mode;
			if (cin.fail() || mode < 0 || mode > 4) {
				cout << "输入错误，请重新输入:" << endl;
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