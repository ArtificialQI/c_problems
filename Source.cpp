#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class MyClass
{
public:
	void print();

};

void MyClass::print()
{
	cout << "print" << endl;
}

class TEST;

class point
{

private:
	int x;
	int y;
	int size;
	int* data;
	int a[5]{ 1,2,3,4,5 };
public:

	point()
	{
		x = 0;
		y = 0;

		cout << " default constructor called" << endl;
	}

	point(int value_x, int value_y)
	{
		x = value_x;
		y = value_y;
	}


	/*point(int size)
	{
		this->size = size;
		this->data = new int[size];

		for (int i = 0; i < size; i++)
			data[i] = i;

		cout << "constructor called" << endl;
	}

	point(const point& other)
	{
		this->size = other.size;

		this->data = new int[other.size];

		for (int i = 0; i < size; i++)
			this->data[i] = other.data[i];

		cout << "copy constructor called" << endl;

	}

	point& operator = (const point& other)
	{
		this->size = other.size;

		if (this->data != nullptr)
			delete[] this->data;

		this->data = new int[other.size];

		for (int i = 0; i < size; i++)
			this->data[i] = other.data[i];

		return *this;
	}*/

	point operator+(const point& other) /*for non-dynamic memory*/
	{
		point tmp;


		tmp.x = this->x + other.x;
		tmp.y = this->y + other.y;

		return tmp;
	}


	bool operator ==(const point& other)
	{
		return (this->x == other.x && this->y == other.y);
	}

	~point()
	{
		cout << "destructor called" << endl;
		delete[] data;
	}


	void set_y(int y)
	{
		this->y = y;
	}

	int get_y()
	{
		return y;
	}

	void set_x(int x)
	{
		this->x = x;
	}

	int get_x()
	{
		return x;
	}



	void print()
	{
		cout << "X = " << x << "\tY = " << y << endl;
	}


	point& operator++()
	{
		this->x++;
		this->y++;

		return *this;
	}

	point& operator++(int value)
	{
		point tmp(*this);

		this->x++;
		this->y++;

		return tmp;
	}

	int& operator[](int index)
	{
		return a[index];
	}

	friend void friendly(point& value, TEST& t_value);
};



class TEST
{
private:
	int data = 0;

	friend void friendly(point& value, TEST& t_value);
};


void friendly(point& value, TEST& t_value)
{
	value.x = -1;
	t_value.data = -1;
}



class class_1;
class class_2;

class class_2
{

public:

	void foo(class_1& c1);
};

class class_1
{
	friend class_2; //--------->>>>>

private:
	int a;
	int b;

public:
	class_1(int a, int b)
	{
		this->a = a;
		this->b = b;
	}

	//friend void class_2::foo(class_1& c1); ������������� ����� ----->>>>>>>>>>
};


class ID
{
private:

	int id;
	static int count;
public:
	

	ID()
	{
		count++;
		id = count;
		
	}

	~ID()
	{


	}

	int get_id()
	{
		return id;
	}

	 static int get_count() // ���������� ������ ��� ���� �������� ������ 
	{
		return count;
	}

	

};

int ID::count = 0;



int main()
{
	

	/*point d(10);

	point c(5);

	point k(3);

	d = c = k;

	c.print();

	point a(1, 2);
	point b(3, 4);

	bool result = a == b;*/

	/*point a(1, 2);

	TEST test;

	point b = a++;

	b.print();
	a.print();

	friendly(a, test);
	a.print();*/


	//class_1 c1(3, 4);

	//class_2 c2;

	//c2.foo(c1);

	ID Arr[10];
	

	cout << ID::get_count() << endl;

	


	return 0;
}

void class_2::foo(class_1& c1)
{
	cout << "foo" << c1.a << c1.b << endl;
}
