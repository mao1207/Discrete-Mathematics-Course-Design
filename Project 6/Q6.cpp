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
	relation = new int* [row];
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

	//求传递闭包
	for (int i = 0; i < cal; i++) {
		for (int j = 0; j < row; j++) {
			for (int k = 0; k < cal; k++) {
				if (transitive[i][k] && transitive[j][i] == 1)
					transitive[j][k] = 1;
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
	Relation matrix;
	cout << "关系矩阵的传递闭包(Warshall算法实现)：" << endl;
	matrix.transitive();
}