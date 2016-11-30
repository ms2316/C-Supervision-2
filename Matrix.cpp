#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class Matrix {

private:
	vector< vector<T> > m;
	int ys, xs;
public:

	Matrix(vector< vector<T> >& m) : m(m), ys(m.size()), xs(m[0].size()) {}

	friend Matrix operator+(const Matrix& m1, const Matrix& m2) {
		vector< vector<T> > tmp (m1.ys,vector<T>(m1.xs,0));
		Matrix<T> ans( tmp );

		if (m1.ys != m2.ys || m1.xs != m2.xs)
			return ans;

		for (int i = 0; i < ans.ys; i++) {
			for (int j = 0; j < ans.xs; j++) {
				ans.m[i][j] = m1.m[i][j] + m2.m[i][j];
			}
		}

		return ans;
	}

	friend Matrix operator+(const Matrix& m1, const T& scalar) {
		vector< vector<T> > tmp (m1.ys,vector<T>(m1.xs,0));
		Matrix<T> ans( tmp );

		for (int i = 0; i < ans.ys; i++) {
			for (int j = 0; j < ans.xs; j++) {
				ans.m[i][j] = m1.m[i][j] + scalar;
			}
		}

		return ans;
	}

	friend Matrix operator+(const T& scalar, const Matrix& m1) {
		return operator+(m1, scalar);
	}


	friend Matrix operator-(const Matrix& m1, const Matrix& m2) {
		vector< vector<T> > tmp (m1.ys,vector<T>(m1.xs,0));
		Matrix<T> ans( tmp );

		if (m1.ys != m2.ys || m1.xs != m2.xs)
			return ans;

		for (int i = 0; i < ans.ys; i++) {
			for (int j = 0; j < ans.xs; j++) {
				ans.m[i][j] = m1.m[i][j] - m2.m[i][j];
			}
		}

		return ans;
	}

	friend Matrix operator-(const Matrix& m1, const T& scalar) {
		vector< vector<T> > tmp (m1.ys,vector<T>(m1.xs,0));
		Matrix<T> ans( tmp );

		for (int i = 0; i < ans.ys; i++) {
			for (int j = 0; j < ans.xs; j++) {
				ans.m[i][j] = m1.m[i][j] - scalar;
			}
		}

		return ans;
	}

	friend Matrix operator*(const Matrix& m1, const Matrix& m2) {
		vector< vector<T> > tmp (m1.ys,vector<T>(m2.xs,0));
		Matrix<T> ans( tmp );

		if (m1.xs != m2.ys)
			return ans;

		for (int i = 0; i < ans.ys; i++) {
			for (int j = 0; j < ans.xs; j++) {
				for (int k = 0; k < m1.xs; k++)
					ans.m[i][j] += m1.m[i][k]*m2.m[k][j];
			}
		}

		return ans;
	}

	friend Matrix operator*(const Matrix& m1, const T& scalar) {
		vector< vector<T> > tmp (m1.ys,vector<T>(m1.xs,0));
		Matrix<T> ans( tmp );

		for (int i = 0; i < ans.ys; i++) {
			for (int j = 0; j < ans.xs; j++) {
				ans.m[i][j] = m1.m[i][j] * scalar;
			}
		}

		return ans;
	}

	friend Matrix operator*(const T& scalar, const Matrix& m1) {
		return operator*(m1, scalar);
	}



	friend std::ostream& operator<<(std::ostream& out, const Matrix& matrix) {
		for (int i = 0; i < matrix.ys; i++) {
			for (int j = 0; j < matrix.xs; j++)
				out << matrix.m[i][j] << ' '; 		
			out << '\n';
		}
		return out;
	}
};



int main() {
	vector< vector<int> > a {{1,2,3}, {4,5,6}};
	vector< vector<int> > b {{0,1,2}, {3,4,5}};
	vector< vector<int> > c {{0}, {1}, {2}};
	vector< vector<int> > d {{1,2}};

	Matrix<int> m1(a);
	Matrix<int> m2(b);
	Matrix<int> v(c);
	Matrix<int> v2(d);

	cout << m1;
	cout << m2;
	cout << v;

	cout << m1+m2;
	cout << m2-m1;
	cout << m1*v;
	cout << v2*m1;
	cout << m1 + 100;
	cout << 100 + m1;
	cout << m1 - 100;
	cout << m1 * 100;
	cout << 100 * m1;
}

