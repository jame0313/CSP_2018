#define PI 3.14
class Rectangle{
    private:
        float top;
        float left;
        float bottom;
        float right;
    public:
       Rectangle(): top(0),left(0),bottom(0),right(0) {}
       void setpos(float left, float top, float right, float bottom);
       float getarea();
       float getperimeter();
};

class Circle{
    private:
        float x;
        float y;
        float radius;
    public:
       Circle(): x(0),y(0),radius(0) {}
       void setpos(float x, float y, float radius);
       float getarea();
       float getperimeter();
};
