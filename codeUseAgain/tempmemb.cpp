//成员模版：将另一个模版类和模版函数作为其成员
#include<iostream>
using std::cout;
using std::endl;
template<typename T>
class beta
{
private:
	//嵌套模版类声明：
	template<typename V>
	class hold
	{
	private:
		V val;
	public:
		//构造函数
		hold(V v =0):val(v){}
		void show()const { cout << val << endl; }
		//模版函数：
		V Value() const { return val; }
	};
	//模版类实例化：
	hold<T> q;
	hold<int> n;
public:
	beta(T t,int i):q(t),n(i){}
	template<typename U>//模版方法：
	U blab(U u, T t) { return (n.Value() + q.Value()) * u / t; }
	void Show()const { q.show(); n.show(); }
};

int main()
{
	beta<double> guy(3.5, 3);
	cout << "T被实例化为double\n";
	guy.Show();
	cout << "V先被实例化为T(double)，然后被实例化为int\n";
	cout << guy.blab(10, 2.3) << endl;
	cout << "U被实例化为int\n";
	cout << guy.blab(10.0, 2.3) << endl;
	cout << "U被实例化为double\n";
	cout << "Done\n";
	return 0;
}