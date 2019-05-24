#include <iostream>
#include<string>
#include<vector>

class IShape
{
public:

	virtual double getPerimiter() = 0;
	virtual double getArea() = 0;
	virtual std::string getName() = 0;
	virtual void setValue() = 0;
	virtual void printShapeInfo() = 0;
	
};

class Triangle : public IShape
{
public:
	float a = 0.f, b = 0.f, c = 0.f;
	


	void setValue()
	{
		bool check = true;
		while (check)
		{
			
			std::cout << "Enter first side: ";
			std::cin >> a;
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			std::cout << std::endl;

			std::cout << "Enter second side: ";
			std::cin >> b;
			std::cin.clear();
			std::cin.ignore(10000, '\n');

			std::cout << std::endl; std::cout << "Enter third side: ";
			std::cin >> c;
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			std::cout << std::endl;
			if ((a + b) > c && (a + c) > b && (b + c) > a)
			{
				check = false;
				break;
			}
			else
				std::cout << "ERROR. Two sides together must be bigger then third side for triangle!" << std::endl;
		}
	}



	double getPerimiter()
	{
		return a + b + c;
	}

	double getArea()
	{
		double s = getPerimiter() / 2;
		return sqrt(s*(s - a)*(s - b)*(s - c));
	}

	std::string getName()
	{
		return "Triangle";
	}

 void printShapeInfo() 
	{
		std::cout << "Shape name " << getName() << std::endl;
		std::cout << getName() << " perimiter is  " << getPerimiter() << std::endl;
		std::cout << getName() << " area is " << getArea() << std::endl;
		std::cout << "========================================================================" << std::endl;
	}

};

class Circle : public IShape
{
public:
	float radius;

	void setValue()
	{
		std::cout << "Enter circle radius : ";
		std::cin >> radius;
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cout << std::endl;
	}

	double getPerimiter()
	{
		return 2 * radius * _Pi;
	}
	double getArea()
	{
		
		return radius * radius * _Pi / 2;
	}

	std::string getName()
	{
		return "Circle";
	}
	void printShapeInfo()
	{
		std::cout << "Shape name " << getName() << std::endl;
		std::cout << getName() << " perimiter is  " << getPerimiter() << std::endl;
		std::cout << getName() << " area is " << getArea() << std::endl;
		std::cout << "========================================================================" << std::endl;
	}

private:
	float _Pi = 3.14;

};

class Rectangle : public IShape
{
public:
	float a, b;

	void setValue()
	{
		std::cout << "Enter first side: ";
		std::cin >> a;
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cout << std::endl;

		std::cout << "Enter second side: ";
		std::cin >> b;
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cout << std::endl;
	}

	double getPerimiter()
	{
		return 2 * a + 2 * b;
	}
	double getArea()
	{

		return a * b;
	}

	std::string getName()
	{
		return "Rectangle";
	}

	void printShapeInfo()
	{
		std::cout << "Shape name " << getName() << std::endl;
		std::cout << getName() << " perimiter is  " << getPerimiter() << std::endl;
		std::cout << getName() << " area is " << getArea() << std::endl;
		std::cout << "===============================================" << std::endl;
	}

};




 void inputData(std::string message, int& data)
{
	 std::cout << message;
	 std::cout << std::endl;
	 std::cin >> data;
	 std::cin.clear();
	 std::cin.ignore(10000, '\n');
	 std::cout << std::endl;
}









int main()
{
	int choseShape = 0;
	int numOfShapes = 0;

	Rectangle* rect = new Rectangle();

	Circle* circle = new Circle();

	Triangle* triangle = new Triangle();

	

	std::vector<IShape*> shapes;
	shapes.push_back(rect);

	shapes.push_back(circle);

	shapes.push_back(triangle);

	/*for (size_t i = 0; i < shapes.size(); i++)
	{
		shapes[i]->setValue();
	}

	for (size_t i = 0; i < shapes.size(); i++)
	{
		shapes[i]->printShapeInfo();
	}*/

	
	inputData("Enter which shape you want(1.Rectangle / 2. Circle / 3.Triangle) ", choseShape);
	switch (choseShape)
	{
	case 1:
	{

		inputData("How much shapes do you want ", numOfShapes);
		for (size_t i = 0; i < numOfShapes; i++)
		{
			shapes.at(0)->setValue();
			shapes.at(0)->printShapeInfo();
		}

		break;

	}
	case 2:
	{
		inputData("How much shapes do you want", numOfShapes);
		for (size_t i = 0; i < numOfShapes; i++)
		{
			shapes.at(1)->setValue();
			shapes.at(1)->printShapeInfo();
		}
		break;
	}
	case 3:
	{
		inputData("How much shapes do you want", numOfShapes);
		for (size_t i = 0; i < numOfShapes; i++)
		{
			shapes.at(2)->setValue();
			shapes.at(2)->printShapeInfo();
		}
		break;
	}
	default:
	{
		std::cout << "Wrong input!";
		break;
	}
	
	}

	system("pause");

}