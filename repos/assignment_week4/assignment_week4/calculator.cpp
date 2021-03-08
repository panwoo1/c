#include<iostream>
using namespace std;

class Calculator {
private:
	int value;
	int memoryValue;
public:
	Calculator() 
	{
		value = 0;
		memoryValue = 0;
	}
	void setValue(int x); //���� ���� x�� ����
	int getValue(); //���� ���� ��ȯ
	int add(int x); //���� ���� x�� ���� �� ��ȯ
	int sub(int x); //���� ���� x�� �� �� ��ȯ
	int multiply(int x); //���� ���� x�� ���� �� ��ȯ
	int divide(int x); //���� ���� x�� ���� ���� ��ȯ
	int mod(int x); //���� ���� x�� ���� �������� ��ȯ
	void changeSign(); //��ȣ ����ȭ
	void clear(); //���� ���� 0���� �ʱ�ȭ
	void memorySave(); //���� ���� �޸𸮿� ����
	void memoryRead(); //�޸� ���� ���� ������ ����
	void memoryClear(); // �޸� ���� 0���� �ʱ�ȭ
	void memoryAdd(); //�޸� ���� ���� ���� ����
	void memorySub(); //�޸� ������ ���� ���� ��
};
void command(Calculator c);

int main()
{
	Calculator c;
	command(c);

	return 0;
}


void Calculator:: setValue(int x)
{
	value = x;
}
int Calculator ::  getValue()
{
	return value;
}
int Calculator :: add(int x)
{
	value += x;
	return value;
}
int Calculator :: sub(int x)
{
	value -= x;
	return value;
}
int Calculator :: multiply(int x)
{
	value *= x;
	return value;
}
int Calculator::divide(int x)
{
	value /= x;
	return value;
}
int Calculator::mod(int x)
{
	value %= x;
	return value;
}
void Calculator::changeSign()
{
	value = -value;
}
void Calculator::clear()
{
	value = 0;
}
void Calculator::memorySave()
{
	memoryValue = value;
}
void Calculator::memoryRead()
{
	value = memoryValue;
}
void Calculator::memoryClear()
{
	memoryValue = 0;
}
void Calculator::memoryAdd()
{
	memoryValue += value;
}
void Calculator::memorySub()
{
	memoryValue -= value;
}
void command(Calculator c)
{
	string command;
	
	while (1) {
		
		cin >> command;

		if (command == "setValue") {
			int num;
			cin >> num;
			c.setValue(num);
		}
		else if (command == "add") {
			int num;
			cin >> num;
			c.add(num);
		}
		else if (command == "sub") {
			int num;
			cin >> num;
			c.sub(num);
		}
		else if (command == "mul") {
			int num;
			cin >> num;
			c.multiply(num);
		}
		else if (command == "div") {
			int num;
			cin >> num;
			c.divide(num);
		}
		else if (command == "mod") {
			int num;
			cin >> num;
			c.mod(num);
		}
		else if (command == "change") {
			c.changeSign();
		}
		else if (command == "clear") {
			c.clear();
		}
		else if (command == "MS") {
			c.memorySave();
		}
		else if (command == "MR") {
			c.memoryRead();
		}
		else if (command == "MPlus") {
			c.memoryAdd();
		}
		else if (command == "MMinus") {
			c.memorySub();
		}
		else if (command == "MC") {
			c.memoryClear();
		}
		else if (command == "result") {
			int num;
			num = c.getValue();
			cout << num << endl;
		}
		else if (command == "quit") {
			break;
		}
	}
}