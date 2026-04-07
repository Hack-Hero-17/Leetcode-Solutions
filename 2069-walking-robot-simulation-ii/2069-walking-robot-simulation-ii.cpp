class Robot {
public:
    int w, h, face = 1, perimeter, x = 0, y = 0;
    string dir[4] = {"North", "East", "South", "West"};
    Robot(int width, int height)
        : w(width), h(height), face(1), perimeter(2 * (h + w - 2)) {}

    void move(int num) {
        if (num >= perimeter) {
            num %= perimeter;
            if (x == 0 && y == 0 && face == 1) // edge case
                face = 2;     // change the starting direction
        }
        if (num == 0) return;
        int d = 0;
        switch (face) {
        case 0: // North
            d = min(num, h - 1 - y);
            y += d;
            num -= d;
            if (y == h - 1 && num > 0)
                face = 3;
            break;
        case 1: // East
            d = min(num, w - 1 - x);
            x += d;
            num -= d;
            if (x == w - 1 && num > 0)
                face = 0;
            break;
        case 2: // South
            d = min(num, y);
            y -= d;
            num -= d;
            if (y == 0 && num > 0)
                face = 1;
            break;
        case 3: // West
            d = min(num, x);
            x -= d;
            num -= d;
            if (x == 0 && num > 0)
                face = 2;
            break;
        }
        move(num);
    }

    void step(int num) { move(num); }

    vector<int> getPos() { return {x, y}; }

    string getDir() { return dir[face]; }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */