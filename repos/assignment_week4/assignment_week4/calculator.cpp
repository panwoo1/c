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
	void setValue(int x); //현재 값을 x로 설정
	int getValue(); //현재 값을 반환
	int add(int x); //현재 값에 x를 더한 후 반환
	int sub(int x); //현재 값에 x를 뺀 후 반환
	int multiply(int x); //현재 값에 x를 곱한 후 반환
	int divide(int x); //현재 값을 x로 나눈 몫을 반환
	int mod(int x); //현재 값을 x로 나눈 나머지를 반환
	void changeSign(); //부호 변경화
	void clear(); //현재 값을 0으로 초기화
	void memorySave(); //현재 값을 메모리에 저장
	void memoryRead(); //메모리 값을 현재 값으로 설정
	void memoryClear(); // 메모리 값을 0으로 초기화
	void memoryAdd(); //메모리 값에 현재 값을 더함
	void memorySub(); //메모리 값에서 현재 값을 뺌
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