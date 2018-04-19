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

class People											//기반 클래스
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

class Domino : public Pizza								//Pizza에 대한 파생 클래스
{
	string name = "도미노 피자";
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
		cout << "# 기본 토핑을 올리는 중..." << endl;
	}
	virtual void MakeCheeze() override
	{
		cout << "# 기본 치즈를 뿌리는 중..." << endl;
	}
	virtual void MakeDough() override
	{
		cout << "# 기본 도우를 반죽하는 중..." << endl;
	}
	virtual void Delete() override {}
};

class Mister : public Pizza								//Pizza에 대한 파생 클래스
{
	string name = "미스터 피자";
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
		cout << "# 기본 토핑을 올리는 중..." << endl;
	}
	virtual void MakeCheeze() override
	{
		cout << "# 기본 치즈를 뿌리는 중..." << endl;
	}
	virtual void MakeDough() override
	{
		cout << "# 기본 도우를 반죽하는 중..." << endl;
	}
	virtual void Delete() override {}
};

class school : public Pizza								//Pizza에 대한 파생 클래스	
{
	string name = "피자스쿨";
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
		cout << "# 기본 토핑을 올리는 중..." << endl;
	}
	virtual void MakeCheeze() override
	{
		cout << "# 기본 치즈를 뿌리는 중..." << endl;
	}
	virtual void MakeDough() override
	{
		cout << "# 기본 도우를 반죽하는 중..." << endl;
	}
	virtual void Delete() override {}
};

class Add : public Pizza								//추가된 클래스
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
		cout << "# 기본 토핑을 올리는 중..." << endl;
	}
	virtual void MakeCheeze() override
	{
		cout << "# 치즈를 뿌리는 중..." << endl;
	}
	virtual void MakeDough() override
	{
		cout << "# 도우를 반죽하는 중..." << endl;
	}
	virtual void Delete() override 
	{
		pz->Delete();
		delete pz;
	}
};

class Chicken : public Add								//Add 클래스의 파생 클래스
{
	string name = "닭가슴살";
public:
	Chicken(Pizza* pz) : Add(pz){}
	virtual void finish(int n) override
	{
		n--;
		if ( n != 0)
		{
			cout << name << "과(/와)";
			pz->finish(n);
		}
		else{
			cout << name << "을(/를) 올린 ";
			pz->finish(n);
		}
	}
	virtual void Delivery(int n) override
	{
		n--;
		if (n != 0)
		{
			cout << name << "과(/와)";
			pz->Delivery(n);
		}
		else{
			cout << name << "을(/를) 올린 ";
			pz->Delivery(n);
		}
	}
	virtual void BasicTopping() override
	{
		pz->BasicTopping();
		cout << "# 닭가슴살을 올리는 중..." << endl;
		
	}
	//virtual void MakeCheeze() override{}
	//virtual void MakeDough() override{}
	virtual void Delete() override
	{
		pz->Delete();
		delete pz; 
	}
};

class Beef : public Add									//Add 클래스의 파생 클래스
{
	string name = "불고기";
public:
	Beef(Pizza * pz) : Add(pz){}
	virtual void finish(int n) override
	{
		n--;
		if (n != 0)
		{
			cout << name << "과(/와)";
			pz->finish(n);
		}
		else{
			cout << name << "을(/를) 올린 ";
			pz->finish(n);
		}
	}
	virtual void Delivery(int n) override
	{
		n--;
		if (n != 0)
		{
			cout << name << "과(/와)";
			pz->Delivery(n);
		}
		else{
			cout << name << "을(/를) 올린 ";
			pz->Delivery(n);
		}
	}
	virtual void BasicTopping() override
	{
		pz->BasicTopping();
		cout << "# 불고기를 올리는 중..." << endl;	
	}
	virtual void Delete() override
	{
		pz->Delete(); 
		delete pz; 
	}
	//virtual void MakeCheeze() override{}
	//virtual void MakeDough() override{}
};

class Shrimp : public Add								//Add 클래스의 파생 클래스
{ 
	string name = "새우";
public:
	Shrimp(Pizza* pz) : Add(pz){}
	virtual void finish(int n) override
	{
		n--;
		if (n != 0)
		{
			cout << name << "과(/와)";
			pz->finish(n);
		}
		else{
			cout << name << "을(/를) 올린 ";
			pz->finish(n);
		}
	}
	virtual void Delivery(int n) override
	{
		n--;
		if (n != 0)
		{
			cout << name << "과(/와)";
			pz->Delivery(n);
		}
		else{
			cout << name << "을(/를) 올린 ";
			pz->Delivery(n);
		}
	}
	virtual void BasicTopping() override
	{
		pz->BasicTopping();
		cout << "# 새우를 올리는 중..." << endl;
	}
	virtual void Delete() override
	{
		pz->Delete(); 
		delete pz; 
	}
	//virtual void MakeCheeze() override{}
	//virtual void MakeDough() override{}
};

class Order												//입출력 클래스
{
	vector<Pizza*> pz;
	int pizzaBrand = 0, pizzaNumber = 0, toppingNumber = 0, toppingCount = 0;
	bool add_Topping = false;
	vector<int> checkNumber;
	vector<string> pizza_list_;
	vector<string> topping_list_;
	//c++11인데 vc에서 error...
	//vector<string> pizza_list_ = { "도미노피자", "미스터피자", "피자 스쿨" };
	//vector<string> topping_list_ = { "닭가슴살", "불고기", "새우"};
	
public:
	void orderPz() // 1
	{
		cout << "## 피자 주문 ##" << endl;
		pizza_list_.push_back("도미노피자");
		pizza_list_.push_back("미스터피자");
		pizza_list_.push_back("피자 스쿨");


		topping_list_.push_back("닭가슴살");
		topping_list_.push_back("불고기");
		topping_list_.push_back("새우");
		cout << endl;
	}
	void pickBrand() // 2
	{
		cout << "# [-]피자 선택/[ ]토핑 선택/[ ]추가 주문/[ ]만들기" << endl;
		cout << "# 원하시는 피자를 선택해주세요." << endl;
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
		cout << "(0) 추가하지 않음" << endl;
	}
	void ChooseTopping() // 4
	{
		cout << "# [x]피자 선택/[-]토핑 선택/[ ]추가 주문/[ ]만들기" << endl;
		if (!add_Topping)
		{
			cout << "# 추가하실 토핑을 선택해주세요." << endl;
		}
		else
		{
			cout << "# 토핑을 더 추가하시려면 선택해주세요." << endl;	
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
		cout << "# [x]피자 선택/[x]토핑 선택/[-]추가 주문/[ ]만들기" << endl;
		cout << "# 추가로 피자를 주문하실 건가요?" << endl;
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
		cout << "# [x]피자 선택/[x]토핑 선택/[x]추가 주문/[-]만들기" << endl;
		for (int i = 0; i <= pizzaNumber; i++)
		{
			p.Dough(pz[i]);
			cout << "# 토마토 소스를 바르는 중..." << endl;
			p.Cheeze(pz[i]);
			p.Topping(pz[i]);
			cout << "# 굽는 중..." << endl;
			p.Finish(pz[i], checkNumber[i]);
			cout << "의 피자가 완성되었습니다!" << endl;
		}
		cout << "# 배달 중..." << endl;
		for (int i = 0; i <= pizzaNumber; i++)
		{
			p.Delivery(pz[i], checkNumber[i]);
			cout << "의 피자가 배달되었습니다!" << endl;
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
