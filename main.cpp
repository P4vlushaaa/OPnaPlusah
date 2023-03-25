#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Shape {
public:
    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
};

class Object {
public:
    virtual int getId() const = 0;
    virtual bool equals(const Object& other) const = 0;
};

class GeometricObject : public Shape, public Object {
public:
    static size_t totalMemory; // статическая переменная для хранения общего количества памяти
    virtual std::string getName() const = 0;
    virtual ~GeometricObject() {} // виртуальный деструктор

    static size_t getTotalMemory() { // метод для доступа к общей памяти
        return totalMemory;
    }
};

// инициализация статической переменной
size_t GeometricObject::totalMemory = 0;

class Rectangle : public GeometricObject {
private:
    int id;
    double width;
    double height;

public:
    Rectangle(int id, double width, double height)
            : id(id), width(width), height(height) {
        GeometricObject::totalMemory += sizeof(*this); // увеличение общей памяти на размер объекта
    }

    ~Rectangle() {
        GeometricObject::totalMemory -= sizeof(*this); // уменьшение общей памяти на размер объекта
    }

    double getArea() const override {
        return width * height;
    }

    double getPerimeter() const override {
        return 2 * (width + height);
    }

    int getId() const override {
        return id;
    }

    bool equals(const Object& other) const override {
        if (const Rectangle* otherRect = dynamic_cast<const Rectangle*>(&other)) {
            return (id == otherRect->id) && (width == otherRect->width) && (height == otherRect->height);
        }
        return false;
    }

    std::string getName() const override {
        return "Rectangle";
    }
};

class IsoscelesTrapezoid : public GeometricObject {
private:
    int id;
    double upperBase;
    double lowerBase;
    double height;

public:
    IsoscelesTrapezoid(int id, double upperBase, double lowerBase, double height)
            : id(id), upperBase(upperBase), lowerBase(lowerBase), height(height) {
        GeometricObject::totalMemory += sizeof(*this); // увеличение общей памяти на размер объекта
    }

    ~IsoscelesTrapezoid() {
        GeometricObject::totalMemory -= sizeof(*this); // уменьшение общей памяти на размер объекта
    }

    double getArea() const override {
        return (upperBase + lowerBase) * height / 2;
    }

    double getPerimeter() const override {
        double leg = (lowerBase - upperBase) / 2;
        double hypotenuse = sqrt(pow(leg, 2) + pow(height, 2));
        return 2 * hypotenuse + upperBase + lowerBase;
    }

    int getId() const override {
        return id;
    }

    bool equals(const Object &other) const override {
        if (const IsoscelesTrapezoid *otherTrap = dynamic_cast<const IsoscelesTrapezoid *>(&other)) {
            return (id == otherTrap->id) && (upperBase == otherTrap->upperBase) && (lowerBase == otherTrap->lowerBase)
                   && (height == otherTrap->height);
        }
        return false;
    }

    std::string getName() const override {
        return "Isosceles Trapezoid";
    }
};


    int main() {
    std::vector<GeometricObject*> shapes;

    Rectangle r1(1, 2, 3);
    Rectangle r2(2, 4, 5);

    shapes.push_back(&r1);
    shapes.push_back(&r2);

    for (GeometricObject* shape : shapes) {
        std::cout << shape->getName() << ": Area = " << shape->getArea()
                  << ", Perimeter = " << shape->getPerimeter() << std::endl;
    }

    while (true) {
        char per;
        cin >> per;
        if (per == 'r') {
            // Запрашиваем идентификатор, ширину и высоту для создания прямоугольника
            int id;
            double width, height;
            std::cout << "id, width and height cherez space: ";
            std::cin >> id;

            // Выход из цикла, если введен -1
            if (id == -1) {
                break;
            }

            std::cin >> width >> height;

            // Проверяем, есть ли уже фигура с таким идентификатором
            bool idExists = false;
            for (const auto &shape: shapes) {
                if (shape->getId() == id) {
                    std::cout << "sushestvuet!" << std::endl;
                    idExists = true;
                    break;
                }
            }

            if (idExists) {
                continue;
            }

            // Создаем прямоугольник и добавляем его в контейнер фигур
            Rectangle *rect = new Rectangle(id, width, height);
            shapes.push_back(rect);
        }
        else if(per == 't'){
            int id;
            double upperBase, lowerBase, height;
            std::cout << "id, upper base, lower base and height cherez space: ";
            std::cin >> id;

            if (id == -1) {
                break;
            }

            cin >> upperBase >> lowerBase >> height;

// Проверяем, есть ли уже фигура с таким идентификатором
            bool idExists = false;
            for (const auto& shape : shapes) {
                if (shape->getId() == id) {
                    std::cout << "sushestvuet!" << std::endl;
                    idExists = true;
                    break;
                }
            }

            if (idExists) {
                continue;
            }

// Создаем равнобедренную трапецию и добавляем ее в контейнер фигур
            IsoscelesTrapezoid* trapezoid = new IsoscelesTrapezoid(id, upperBase, lowerBase, height);
            shapes.push_back(trapezoid);
        }
    }

    // Выводим информацию о всех фигурах в контейнере
    for (const auto& shape : shapes) {
        std::cout << shape->getName() << " (id=" << shape->getId() << ", area=" << shape->getArea() << ", perimeter=" << shape->getPerimeter() << ")" << std::endl;
        cout << shape->getTotalMemory() << endl;
    }

    double totalArea = 0.0;
    for (GeometricObject* shape : shapes) {
        totalArea += shape->getArea();
    }
    std::cout << "Total Area = " << totalArea << std::endl;

    double totalPerimeter = 0;
    for (const auto& shape : shapes) {
        totalPerimeter += shape->getPerimeter();
    }
    std::cout << "Total perimeter = " << totalPerimeter << std::endl;

    // Очищаем контейнер и освобождаем память
    for (const auto& shape : shapes) {
        delete shape;
    }

    return 0;
}