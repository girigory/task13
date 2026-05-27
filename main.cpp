#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

template <typename T>
class Set {
    int capacity;
    int size;
    T* data;
public:
    Set(T data[], int size) {
        this->size = size;
        this->capacity = size * 2;
        this->data = new T[capacity];
        for (int i = 0; i < size; i++) {
            this -> data[i] = data[i];
        }
    }

    Set() : size(0), capacity(4), data(new T[4]) {}

    Set(const Set& other) {
        size = other.size;
        capacity = other.capacity;
        data = new T[capacity];
        for (int i = 0; i < size; i++)
            data[i] = other.data[i];
    }

    Set operator = (Set other) {
        if (this == &other) return *this;
        delete[] data;
        size = other.size;
        capacity = other.capacity;
        data = new T[capacity];
        for (int i = 0; i < size; i++)
            data[i] = other.data[i];
        return *this;
    }

    bool availability(T object) {
        for (int i = 0; i < this -> size; i++) {
            if (data[i] == object){
                return true;
            }
        }
        return false;
    }

    int getCapacity() {
        return this -> capacity;
    }

    int getSize() {
        return this -> size;
    }

    T getElem(int i) {
        return data[i];
    }

    Set operator + (T element) {
        Set res(*this);
        if (res.availability(element)) {
            return res;
        } else if (res.capacity > res.size) {
            res.data[res.size] = element;
            res.size++;
        } else {
            res.capacity *= 2;
            T* bufer = new T[res.capacity];
            for (int i = 0; i < res.size; i++) {
                bufer[i] = res.data[i];
            }
            delete[] res.data;
            res.data = bufer;
            res.data[res.size] = element;
            res.size++;
        }
        return res;
    }

    Set operator + (Set element) {
        Set res = Set(this -> data, this -> size);
        for (int i = 0; i < element.getSize(); i++) {
            res + element.getElem(i);
        }
        return res;
    }

    Set operator * (Set element) {
        Set res;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < element.getSize(); j++) {
                if (data[i] == element.getElem(j)) {
                    res = res + data[i];
                }
            }
        }
        if (res.getSize()) {
            return res;
            } else {
            cout << "У множеств нет пересечений" << "\n";
            return res;
        }
    }

    ~Set() {
        delete[] data;
    }

};

class Vehicle {
    string brand;
    int year;
    int hp;

protected:
    static int totalPower;

public:
    Vehicle(string brand, int year, int hp) : brand(brand), year(year), hp(hp) {}

    Vehicle(const Vehicle& other) : brand(other.brand), year(other.year), hp(other.hp) {}

    virtual ~Vehicle() {}

    virtual void describe() const {
        cout << "Vehicle: " << brand << ", " << year << ", " << hp << " hp" << endl;
    }

    virtual string getType() const {
        return "Vehicle";
    }

    static int getTotalPower() {
        return totalPower;
    }

    string getBrand() const { return brand; }
    int getHp() const { return hp; }

    bool operator==(const Vehicle& other) const {
        return brand == other.brand && hp == other.hp && year == other.year;
    }
    Vehicle() : brand(""), year(0), hp(0) {}
};

int Vehicle::totalPower = 0;

class Car : public Vehicle {
    int doors;
public:
    Car(string brand, int year, int hp, int doors) : Vehicle(brand, year, hp), doors(doors) {}

    Car(const Car& other) : Vehicle(other), doors(other.doors) {}

    void describe() const override {
        cout << "Car: " << getBrand() << ", " << getHp() << " hp, " << doors << " doors" << endl;
    }

    string getType() const override { return "Car"; }
    Car() : Vehicle("", 0, 0), doors(0) {}
};

class Motorcycle : public Vehicle {
    bool hasSidecar;
public:
    Motorcycle(string brand, int year, int hp, bool hasSidecar) : Vehicle(brand, year, hp), hasSidecar(hasSidecar) {}

    Motorcycle(const Motorcycle& other) : Vehicle(other), hasSidecar(other.hasSidecar) {}

    void describe() const override {
        cout << "Motorcycle: " << getBrand() << ", " << getHp() << " hp";
        cout << (hasSidecar ? ", with sidecar" : "") << endl;
    }

    string getType() const override { return "Motorcycle"; }
    Motorcycle() : Vehicle("", 0, 0), hasSidecar(false) {}
};

class Truck : public Vehicle {
    float payload;
public:
    Truck(string brand, int year, int hp, float payload) : Vehicle(brand, year, hp), payload(payload) {}

    Truck(const Truck& other) : Vehicle(other), payload(other.payload) {}

    void describe() const override {
        cout << "Truck: " << getBrand() << ", " << getHp() << " hp, payload: " << payload << "t" << endl;
    }

    string getType() const override { return "Truck"; }
    Truck() : Vehicle("", 0, 0), payload(0) {}
};

template <typename T>
int calcTotalPower(Set<T>& s) {
    int total = 0;
    for (int i = 0; i < s.getSize(); i++) {
        total += s.getElem(i).getHp();
    }
    return total;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "RU");

    Car car1("Toyota", 2020, 150, 4);
    Car car2("BMW", 2021, 200, 2);
    Car car3("Toyota", 2020, 150, 4);

    Car arr[] = { car1 };
    Set<Car> vehicles(arr, 1);

    vehicles = vehicles + car2;
    vehicles = vehicles + car3;

    for (int i = 0; i < vehicles.getSize(); i++) {
        vehicles.getElem(i).describe();
    }

    Truck truck1("Volvo", 2021, 400, 20.5);
    Truck arr2[] = { truck1 };
    Set<Truck> trucks(arr2, 1);
    trucks = trucks + Truck("MAN", 2022, 350, 15.0);

    cout << "Trucks size: " << trucks.getSize() << endl;

    int total = calcTotalPower(vehicles) + calcTotalPower(trucks);
    cout << "Total power: " << total << " hp" << endl;

    char chars[] = { 'a', 'b', 'c' };
    Set<char> s1(chars, 3);
    s1 = s1 + 'd';
    s1 = s1 + 'a';

    for (int i = 0; i < s1.getSize(); i++) cout << s1.getElem(i) << " ";
    cout << endl;

    int nums[] = { 1, 2, 3 };
    int nums2[] = { 3, 4, 5 };
    Set<int> n1(nums, 3);
    Set<int> n2(nums2, 3);

    Set<int> united = n1 + n2;
    for (int i = 0; i < united.getSize(); i++) cout << united.getElem(i) << " ";
    cout << endl;

    Set<int> crossed = n1 * n2;
    for (int i = 0; i < crossed.getSize(); i++) cout << crossed.getElem(i) << " ";
    cout << endl;
    return 0;
}
