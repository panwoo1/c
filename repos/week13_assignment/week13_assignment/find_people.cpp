#include <iostream>
#include <vector>

using namespace std;

class Family {
	vector<int>setPerson_for_id; //id�� ������ ����� �迭
	vector <int> idArray;//��� id �迭
	vector<int>setPerson_for_parent; //�ڽ��� ������ �迭
	vector <int> parent; //�θ� ������ �迭
public:
	int relation(int p1, int p2); //���踦 ���ϴ� �Լ�
	int distance(int p1, int p2); //�̼��� ���ϴ� �Լ�
	int lca(int p1, int p2); //���������� ���ϴ� �Լ�
	void setId(int n); //id�� �Է¹ް� �����ϴ� �Լ�
	void setParent(int m); //�θ� ���踦 �Է¹ް� �����ϴ� �Լ�
	int getId(int p);//id�� �޴� �Լ�
	int getParent(int p);//�θ� �޴� �Լ�
};

int main()
{
	int n, m, id_1, id_2;
	Family f;

	cin >> n >> m;
	f.setId(n);
	f.setParent(m);
	cin >> id_1 >> id_2;
	//cout << f.relation(id_1, id_2) << endl;
	if (f.distance(id_1, id_2) != -1 and f.lca(id_1, id_2) != -1)
		cout << f.lca(id_1, id_2) << ' ' << f.distance(id_1, id_2) << endl;
	else if (f.distance(id_1, id_2) == -1 or f.lca(id_1, id_2) == -1)
		cout << -1 << endl;

	return 0;
}

int Family::relation(int p1, int p2)
{
	int person_1 = -1, person_2 = -1; //p1, p2 ���
	int person_1_parent = -1, person_2_parent = -1; //p1, p2�� �θ�
	int person_1_grandparent = -1, person_2_grandparent = -1; //���� p1�� p2�� ���θ�
	int person1_super_grandparent = -1, person2_super_grandparent = -1; //���� p1�� p2�� ����
	if (p1 == p2) {
		return 0;
	}
	for (int i = 0; i < idArray.size(); i++) {
		if (idArray[i] == p1)  person_1 = setPerson_for_id[i];
		else if (idArray[i] == p2) person_2 = setPerson_for_id[i];
	}
	person_1_parent = getParent(person_1);
	person_2_parent = getParent(person_2);
	person_1_grandparent = getParent(person_1_parent);
	person_2_grandparent = getParent(person_2_parent);
	person1_super_grandparent = getParent(person_1_grandparent);
	person2_super_grandparent = getParent(person_2_grandparent);

	if (person_1_parent != -1 and person_2_parent == -1) { //�� �� �� ���� �θ���� ���� ���
		int p = person_1;
		int flag = -1;
		while (getParent(p) != -1) {
			if (getParent(p) == person_2) {
				flag = 1;
				return flag;
			}
			p = getParent(p);
		}
		return flag;
	}
	else if (person_1_parent == -1 and person_2_parent != -1) {
		int p = person_2;
		int flag = -1;
		while (getParent(p) != -1) {
			if (getParent(p) == person_1) {
				flag = 2;
				return flag;
			}
			p = getParent(p);
		}
		return flag;
	}
	else if (person_1_parent != -1 and person_2_parent != -1) { //�� �� �θ���� �ִ� ���
		if (person_2 == person_1_parent) return 1; //p2�� p1�� �θ���� ���
		else if (person_1 == person_2_parent) return 2; //p1�� p2�� �θ���� ���
		else if (person_1_grandparent == person_2) return 1; //p1�� ���θ�� p2�� ���
		else if (person_2_grandparent == person_1) return 2;//p2�� ���θ� p1�� ���
		else if (person1_super_grandparent == person_2) return 1;//�����ΰ��
		else if (person2_super_grandparent == person_1) return 2;
		else if (getParent(person1_super_grandparent) == person_2)return 1;
		else if (getParent(person2_super_grandparent) == person_1) return 2;
		else  return -1;
	}
	else
		return -1;

}
int Family::distance(int p1, int p2)
{//-1�� �ʱ�ȭ �� ������ �θ� ���� ��츦 ���ؼ� -1�� �ʱ�ȭ �߽��ϴ�
	int person_1 = -1, person_2 = -1; //p1�� p2
	int person_1_parent = -1, person_2_parent = -1; //���� p1�� p2�� �θ�
	int person_1_grandparent = -1, person_2_grandparent = -1; //���� p1�� p2�� ���θ�
	int person1_super_grandparent = -1, person2_super_grandparent = -1; //���� p1�� p2�� ����
	int distance = 1;

	if (p1 == p2) return -1;
	for (int i = 0; i < idArray.size(); i++) {
		if (idArray[i] == p1)  person_1 = setPerson_for_id[i];
		else if (idArray[i] == p2) person_2 = setPerson_for_id[i];
	}
	person_1_parent = getParent(person_1);
	person_2_parent = getParent(person_2);
	person_1_grandparent = getParent(person_1_parent);
	person_2_grandparent = getParent(person_2_parent);
	person1_super_grandparent = getParent(person_1_grandparent);
	person2_super_grandparent = getParent(person_2_grandparent);

	if (relation(p1, p2) == 1) {//p1�� ������ p2�ΰ��
		int p = person_1;
		while (getParent(p) != person_2) {
			distance++;
			p = getParent(p);
		}
		return distance;
	}
	else if (relation(p1, p2) == 2) {//p1�� p2�� ������ ���
		int p = person_2;
		while (getParent(p) != person_1) {
			distance++;
			p = getParent(p);
		}
		return distance;
	}
	else if (relation(p1, p2) == -1) {//p1�� p2�� ���迡 ���� �Ÿ� ���
		if (relation(p1, getId(person_2_parent)) == 1) {
			int p = person_1;
			while (getParent(p) != person_2_parent) {
				distance++;
				p = getParent(p);
			}
			distance++;
			return distance;
		}
		else if (relation(p1, getId(person_2_grandparent)) == 1) {
			int p = person_1;
			while (getParent(p) != person_2_grandparent) {
				distance++;
				p = getParent(p);
			}
			distance += 2;
			return distance;
		}
		else if (relation(p1, getId(person2_super_grandparent)) == 1) {
			int p = person_1;
			while (getParent(p) != person2_super_grandparent) {
				distance++;
				p = getParent(p);
			}
			distance += 3;
			return distance;
		}
		else if (relation(p1, getId(getParent(person2_super_grandparent))) == 1) {
			int p = person_1;
			while (getParent(p) != getParent(person2_super_grandparent)) {
				distance++;
				p = getParent(p);
			}
			distance += 4;
			return distance;
		}
		else if (relation(getId(person_1_parent), p2) == 2) {
			int p = person_2;
			while (getParent(p) != person_1_parent) {
				distance++;
				p = getParent(p);
			}
			distance++;
			return distance;
		}
		else if (relation(getId(person_1_grandparent), p2) == 2) {
			int p = person_2;
			while (getParent(p) != person_1_grandparent) {
				distance++;
				p = getParent(p);
			}
			distance += 2;
			return distance;
		}
		else if (relation(getId(person1_super_grandparent), p2) == 2) {
			int p = person_2;
			while (getParent(p) != person1_super_grandparent) {
				distance++;
				p = getParent(p);
			}
			distance += 3;
			return distance;
		}
		else if (relation(getId(getParent(person1_super_grandparent)), p2) == 2) {
			int p = person_2;
			while (getParent(p) != getParent(person1_super_grandparent)) {
				distance++;
				p = getParent(p);
			}
			distance += 4;
			return distance;
		}
		else return -1;
	}
	else return -1;
}
int Family::lca(int p1, int p2)
{//-1�� �ʱ�ȭ �� ������ �θ� ���� ��츦 ���ؼ� -1�� �ʱ�ȭ �߽��ϴ�
	int person_1 = -1, person_2 = -1;
	int person_1_parent = -1, person_2_parent = -1;
	int person_1_grandparent = -1, person_2_grandparent = -1;
	int person1_super_grandparent = -1, person2_super_grandparent = -1;

	for (int i = 0; i < idArray.size(); i++) {
		if (idArray[i] == p1)  person_1 = setPerson_for_id[i];
		else if (idArray[i] == p2) person_2 = setPerson_for_id[i];
	}
	person_1_parent = getParent(person_1);
	person_2_parent = getParent(person_2);
	person_1_grandparent = getParent(person_1_parent);
	person_2_grandparent = getParent(person_2_parent);
	person1_super_grandparent = getParent(person_1_grandparent);
	person2_super_grandparent = getParent(person_2_grandparent);

	if (person_1_parent != -1 and person_2_parent != -1)//Ư�̻���-����
		if (person_2_grandparent == person_1) return getId(person_1);
	if (relation(p1, p2) == 1) {//p1�� ������ p2�� ���
		if (person_2_parent == -1) return getId(person_2);
		else if (person_2_parent != -1) return getId(person_2_parent);
		else return -1;
	}
	else if (relation(p1, p2) == 2) {//p1�� p2�� ������ ���
		if (person_1_parent == -1) return getId(person_1);
		else if (person_1_parent != -1) return getId(person_1_parent);
		else return -1;
	}
	else if (relation(p1, p2) == -1) {//����/�ڽ� ���谡 �ƴ� ���
		if (relation(p1, getId(person_2_parent)) == 1)  return getId(person_2_parent);
		else if (relation(p1, getId(person_2_grandparent)) == 1) return getId(person_2_grandparent);
		else if (relation(p1, getId(person2_super_grandparent)) == 1) return getId(person2_super_grandparent);
		else if (relation(p1, getId(getParent(person2_super_grandparent))) == 1) return getId(getParent(person2_super_grandparent));

		else if (relation(getId(person_1_parent), p2) == 2) return getId(person_1_parent);
		else if (relation(getId(person_1_grandparent), p2) == 2)return getId(person_1_grandparent);
		else if (relation(getId(person1_super_grandparent), p2) == 2)return getId(person1_super_grandparent);
		else if (relation(getId(getParent(person1_super_grandparent)), p2) == 2) return getId(getParent(person1_super_grandparent));
		else return -1;
	}
	else return -1;
}
int Family::getId(int p)
{
	int id = 0;

	for (int i = 0; i < idArray.size(); i++) {
		if (setPerson_for_id[i] == p) {
			int id = idArray[i];
			return id;
		}
	}
	return id = -1;
}
int Family::getParent(int p)
{
	int p_parent = 0;

	for (int i = 0; i < parent.size(); i++) {
		if (setPerson_for_parent[i] == p) {
			int p_parent = parent[i];
			return p_parent;
		}
	}
	return -1;
}
void Family::setId(int n)
{
	for (int i = 0; i < n; i++) {
		int id, num;
		cin >> num >> id;
		setPerson_for_id.push_back(num);
		idArray.push_back(id);
	}
}
void Family::setParent(int m)
{
	for (int i = 0; i < m; i++) {
		int id, num;
		cin >> num >> id;
		setPerson_for_parent.push_back(num);
		parent.push_back(id);
	}
}
