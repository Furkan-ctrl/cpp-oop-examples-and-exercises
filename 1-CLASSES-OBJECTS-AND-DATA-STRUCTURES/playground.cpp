#include <iostream>
#include <string>
using namespace std;

const double PI = 3.14159265358979323846264338327950288;

class Cylinder {
    public:
        double radius = 1;
        double height = 1;

    public: 
        double volume() {
            return PI * radius * radius * height;
        }
};



int main() {


    Cylinder cylender1;   

    cout << "volume: " << cylender1.volume() << endl;

    cylender1.height = 10;
    cylender1.radius = 4;

    cout << "volume: " << cylender1.volume() << endl;


}