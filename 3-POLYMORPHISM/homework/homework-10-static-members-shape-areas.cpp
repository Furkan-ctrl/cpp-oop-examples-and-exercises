#include <iostream>

using namespace std;


/*
    Inheritance and Polymorphism with Static members
*/

/*
    Exercise: Implement static methods within the Circle and Rectangle classes 
    to calculate the areas of circles and rectangles, respectively. 
    Additionally, create a static method in the Shape class to compare the areas of two shapes.

    Tasks:

    1. Implement the CalculateArea static methods in the Circle and Rectangle classes to calculate the areas of circles and rectangles, respectively.
    2. Create a static method in the Shape class to compare the areas of two shapes. You'll need to access the CalculateArea static methods in the derived classes for this comparison.
    3. In the main function, prompt the user to enter the radius for a circle and the width and height for a rectangle.
    4. Calculate and display the areas of the circle and rectangle using the static methods.

    Implement comparisons of areas using the static method in the Shape class to determine if the areas are equal.
*/

class Shape {
    public:
        static void compareAreas(double area1, double area2) {
            if (area1 == area2) {
                cout << "The areas of the circle and the rectangle are equal." << endl;
            } else if (area1 > area2) {
                cout << "The area of the circle is larger than the rectangle." << endl;
            } else {
                cout << "The area of the rectangle is larger than the circle." << endl;
            }
        }
};

class Circle : public Shape {
    private:
        double radius;

    public:
        Circle(double radius) : radius(radius) {}

        static double calculateArea(double radius) {
            return 3.14159 * radius * radius;
        }
};

class Rectangle : public Shape {
    private:
        double width;
        double height;

    public:
        Rectangle(double width, double height) : width(width), height(height) {}

        static double calculateArea(double width, double height) {
            return width * height;
        }
};

int main() {
    double circleRadius, rectWidth, rectHeight;

    cout << "Enter the radius of a circle: ";
    cin >> circleRadius;

    cout << "Enter the width and height of a rectangle: ";
    cin >> rectWidth >> rectHeight;

    double circleArea = Circle::calculateArea(circleRadius);
    double rectArea = Rectangle::calculateArea(rectWidth, rectHeight);

    cout << "Area of the circle: " << circleArea << endl;
    cout << "Area of the rectangle: " << rectArea << endl;

    Shape::compareAreas(circleArea, rectArea);

    return 0;
}