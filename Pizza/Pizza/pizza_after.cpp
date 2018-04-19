#include <iostream>
#include <vector>
#include <string>
using namespace std;

#ifndef _DEBUG	// vc

#define new new(_CLIENT_BLOCK,__FILE__,__LINE)

#endif

class Pizza												//Abstract class
{
public:
	virtual ~Pizza() = default;
	virtual void BasicTopping() = 0;					
	virtual void MakeCheeze() = 0;						
	virtual void MakeDough() = 0;						
	virtual void finish(int n) = 0;
	virtual void Delivery(int n) = 0;
	virtual void Delete() = 0;
};

class People											//��� Ŭ����
{
public:
	void Topping(Pizza* p)
	{ 
		p->BasicTopping();
	}
	void Cheeze(Pizza* p)
	{
		p->MakeCheeze(); 
	}
	void Dough(Pizza* p)
	{
		p->MakeDough(); 
	}
	void Finish(Pizza* p, int n)
	{
		p->finish(n);
	}
	void Delivery(Pizza* p, int n)
	{
		p->Delivery(n);
	}
	void Delete(Pizza* p)
	{
		p->Delete();
	}
};

class Domino : public Pizza								//Pizza�� ���� �Ļ� Ŭ����
{
	string name = "���̳� ����";
public:
public:
	virtual void finish(int n) override
	{
		cout << name;
	}
	virtual void Delivery(int n) override
	{
		cout << name;
	}
	virtual void BasicTopping() override
	{
		cout << "# �⺻ ������ �ø��� ��..." << endl;
	}
	virtual void MakeCheeze() override
	{
		cout << "# �⺻ ġ� �Ѹ��� ��..." << endl;
	}
	virtual void MakeDough() override
	{
		cout << "# �⺻ ���츦 �����ϴ� ��..." << endl;
	}
	virtual void Delete() override {}
};

class Mister : public Pizza								//Pizza�� ���� �Ļ� Ŭ����
{
	string name = "�̽��� ����";
public:
	virtual void finish(int n) override
	{
		cout << name;
	}
	virtual void Delivery(int n) override
	{
		cout << name;
	}
	virtual void BasicTopping() override
	{
		cout << "# �⺻ ������ �ø��� ��..." << endl;
	}
	virtual void MakeCheeze() override
	{
		cout << "# �⺻ ġ� �Ѹ��� ��..." << endl;
	}
	virtual void MakeDough() override
	{
		cout << "# �⺻ ���츦 �����ϴ� ��..." << endl;
	}
	virtual void Delete() override {}
};

class school : public Pizza								//Pizza�� ���� �Ļ� Ŭ����	
{
	string name = "���ڽ���";
public:
	virtual void finish(int n) override
	{
		cout << name;
	}
	virtual void Delivery(int n) override
	{
		cout << name;
	}
	virtual void BasicTopping() override
	{
		cout << "# �⺻ ������ �ø��� ��..." << endl;
	}
	virtual void MakeCheeze() override
	{
		cout << "# �⺻ ġ� �Ѹ��� ��..." << endl;
	}
	virtual void MakeDough() override
	{
		cout << "# �⺻ ���츦 �����ϴ� ��..." << endl;
	}
	virtual void Delete() override {}
};

class Add : public Pizza								//�߰��� Ŭ����
{
protected:
	Pizza* pz;
public:
	Add(Pizza* pz)
	{
		this->pz = pz;
	}
	virtual void Delivery(int n) override {}
	virtual void finish(int n) override {}
	virtual void BasicTopping() override
	{
		cout << "# �⺻ ������ �ø��� ��..." << endl;
	}
	virtual void MakeCheeze() override
	{
		cout << "# ġ� �Ѹ��� ��..." << endl;
	}
	virtual void MakeDough() override
	{
		cout << "# ���츦 �����ϴ� ��..." << endl;
	}
	virtual void Delete() override 
	{
		pz->Delete();
		delete pz;
	}
};

class Chicken : public Add								//Add Ŭ������ �Ļ� Ŭ����
{
	string name = "�߰�����";
public:
	Chicken(Pizza* pz) : Add(pz){}
	virtual void finish(int n) override
	{
		n--;
		if ( n != 0)
		{
			cout << name << "��(/��)";
			pz->finish(n);
		}
		else{
			cout << name << "��(/��) �ø� ";
			pz->finish(n);
		}
	}
	virtual void Delivery(int n) override
	{
		n--;
		if (n != 0)
		{
			cout << name << "��(/��)";
			pz->Delivery(n);
		}
		else{
			cout << name << "��(/��) �ø� ";
			pz->Delivery(n);
		}
	}
	virtual void BasicTopping() override
	{
		pz->BasicTopping();
		cout << "# �߰������� �ø��� ��..." << endl;
		
	}
	//virtual void MakeCheeze() override{}
	//virtual void MakeDough() override{}
	virtual void Delete() override
	{
		pz->Delete();
		delete pz; 
	}
};

class Beef : public Add									//Add Ŭ������ �Ļ� Ŭ����
{
	string name = "�Ұ��";
public:
	Beef(Pizza * pz) : Add(pz){}
	virtual void finish(int n) override
	{
		n--;
		if (n != 0)
		{
			cout << name << "��(/��)";
			pz->finish(n);
		}
		else{
			cout << name << "��(/��) �ø� ";
			pz->finish(n);
		}
	}
	virtual void Delivery(int n) override
	{
		n--;
		if (n != 0)
		{
			cout << name << "��(/��)";
			pz->Delivery(n);
		}
		else{
			cout << name << "��(/��) �ø� ";
			pz->Delivery(n);
		}
	}
	virtual void BasicTopping() override
	{
		pz->BasicTopping();
		cout << "# �Ұ�⸦ �ø��� ��..." << endl;	
	}
	virtual void Delete() override
	{
		pz->Delete(); 
		delete pz; 
	}
	//virtual void MakeCheeze() override{}
	//virtual void MakeDough() override{}
};

class Shrimp : public Add								//Add Ŭ������ �Ļ� Ŭ����
{ 
	string name = "����";
public:
	Shrimp(Pizza* pz) : Add(pz){}
	virtual void finish(int n) override
	{
		n--;
		if (n != 0)
		{
			cout << name << "��(/��)";
			pz->finish(n);
		}
		else{
			cout << name << "��(/��) �ø� ";
			pz->finish(n);
		}
	}
	virtual void Delivery(int n) override
	{
		n--;
		if (n != 0)
		{
			cout << name << "��(/��)";
			pz->Delivery(n);
		}
		else{
			cout << name << "��(/��) �ø� ";
			pz->Delivery(n);
		}
	}
	virtual void BasicTopping() override
	{
		pz->BasicTopping();
		cout << "# ���츦 �ø��� ��..." << endl;
	}
	virtual void Delete() override
	{
		pz->Delete(); 
		delete pz; 
	}
	//virtual void MakeCheeze() override{}
	//virtual void MakeDough() override{}
};

class Order												//����� Ŭ����
{
	vector<Pizza*> pz;
	int pizzaBrand = 0, pizzaNumber = 0, toppingNumber = 0, toppingCount = 0;
	bool add_Topping = false;
	vector<int> checkNumber;
	vector<string> pizza_list_;
	vector<string> topping_list_;
	//c++11�ε� vc���� error...
	//vector<string> pizza_list_ = { "���̳�����", "�̽�������", "���� ����" };
	//vector<string> topping_list_ = { "�߰�����", "�Ұ��", "����"};
	
public:
	void orderPz() // 1
	{
		cout << "## ���� �ֹ� ##" << endl;
		pizza_list_.push_back("���̳�����");
		pizza_list_.push_back("�̽�������");
		pizza_list_.push_back("���� ����");


		topping_list_.push_back("�߰�����");
		topping_list_.push_back("�Ұ��");
		topping_list_.push_back("����");
		cout << endl;
	}
	void pickBrand() // 2
	{
		cout << "# [-]���� ����/[ ]���� ����/[ ]�߰� �ֹ�/[ ]�����" << endl;
		cout << "# ���Ͻô� ���ڸ� �������ּ���." << endl;
		for (int i = 0; i < pizza_list_.size(); i++)
		{
			cout << "(" << i+1 << ") " << pizza_list_[i] << endl;
		}
		cout << endl;
		cout << ">> ";
		cin >> pizzaBrand;
		CheckPizzaBrand();
	}
	void CheckPizzaBrand() // 3
	{
		enum class market : int { domino = 1, mister, school };
		switch (pizzaBrand)
		{
		case static_cast<int>(market::domino) :
			pz.push_back(new Domino);
			break;
		case static_cast<int>(market::mister) :
			pz.push_back(new Mister);
			break;
		case static_cast<int>(market::school) :
			pz.push_back(new school);
			break;
		default:
			break;
		}
		ChooseTopping();
	}
	void PrintNoAdd()
	{
		cout << "(0) �߰����� ����" << endl;
	}
	void ChooseTopping() // 4
	{
		cout << "# [x]���� ����/[-]���� ����/[ ]�߰� �ֹ�/[ ]�����" << endl;
		if (!add_Topping)
		{
			cout << "# �߰��Ͻ� ������ �������ּ���." << endl;
		}
		else
		{
			cout << "# ������ �� �߰��Ͻ÷��� �������ּ���." << endl;	
		}
		for (int i = 0; i < topping_list_.size(); i++)
		{
			cout << "(" << i + 1 << ") " << topping_list_[i] << endl;
		}
		PrintNoAdd();
		cout << endl;
		cout << ">> ";
		cin >> toppingNumber;
		addTopping();
	}
	void addTopping() // 5
	{
		enum class toppingType{ chicken = 1, beef, shrimp };
		if (toppingNumber != 0) 
		{
			add_Topping = true;
			toppingCount++;
			switch (toppingNumber)
			{
			case static_cast<int>(toppingType::chicken) :
				pz[pizzaNumber] = new Chicken(pz[pizzaNumber]);
				break;
			case static_cast<int>(toppingType::beef) :
				pz[pizzaNumber] = new Beef(pz[pizzaNumber]);
				break;
			case static_cast<int>(toppingType::shrimp) :
				pz[pizzaNumber] = new Shrimp(pz[pizzaNumber]);
				break;
			default:
				break;
			}
			ChooseTopping();
		}
		else
		{
			add_Topping = false;
			ChooseMorePizza();
		}
	}
	void ChooseMorePizza() //6
	{
		bool yes_Or_No_;
		cout << "# [x]���� ����/[x]���� ����/[-]�߰� �ֹ�/[ ]�����" << endl;
		cout << "# �߰��� ���ڸ� �ֹ��Ͻ� �ǰ���?" << endl;
		cout << "(1) Yes" << endl;
		cout << "(0) No" << endl;
		cout << endl;
		cout << ">> ";
		cin >> yes_Or_No_;
		checkNumber.push_back(toppingCount);
		toppingCount = 0;
		if (yes_Or_No_)
		{
			pizzaNumber++;
			pickBrand();
		}
	}	
	void bill() // 7
	{
		enum pizzaBrand { domino = 1, mister, school };
		People p;
		cout << "# [x]���� ����/[x]���� ����/[x]�߰� �ֹ�/[-]�����" << endl;
		for (int i = 0; i <= pizzaNumber; i++)
		{
			p.Dough(pz[i]);
			cout << "# �丶�� �ҽ��� �ٸ��� ��..." << endl;
			p.Cheeze(pz[i]);
			p.Topping(pz[i]);
			cout << "# ���� ��..." << endl;
			p.Finish(pz[i], checkNumber[i]);
			cout << "�� ���ڰ� �ϼ��Ǿ����ϴ�!" << endl;
		}
		cout << "# ��� ��..." << endl;
		for (int i = 0; i <= pizzaNumber; i++)
		{
			p.Delivery(pz[i], checkNumber[i]);
			cout << "�� ���ڰ� ��޵Ǿ����ϴ�!" << endl;
		}

		for (int i = 0; i <= pizzaNumber; i++)
		{
			p.Delete(pz[i]);
			delete[] pz[i];
		}
		//pz.clear();	
	}
};
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	Order o;
	o.orderPz();
	o.pickBrand();
	o.bill();
	return 0;
}
