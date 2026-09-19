class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter,
                      int x1, int y1, int x2, int y2) {

        // Circle center ko rectangle ke andar clamp karo
        int closestX = max(x1, min(xCenter, x2));
        int closestY = max(y1, min(yCenter, y2));

        // Circle center se closest point ka distance
        int dx = xCenter - closestX;
        int dy = yCenter - closestY;

        // Distance^2 <= Radius^2
        return dx * dx + dy * dy <= radius * radius;
    }
};