class Solution {
public:
    bool isRobotBounded(string instructions) {
        int dir = 0;              // Keep track of directions: [0, 1, 2, 3] = [n, e, s, w]
        int pos[] = {0, 0};       // Keep track of position of robot.
        for (int i = 0; i < instructions.size(); i++) {
            if (instructions[i] == 'G') {
                if (dir == 0)       // When moves facing north, increment x-coordinate.
                    pos[1]++;
                else if (dir == 1)  // When moves facing east, increment y-coordinate.
                    pos[0]++;
                else if (dir == 3)  // When moves facing west, decrement y-coordinate.
                    pos[0]--;
                else                // When moves facing south, decrement x-coordinate.
                    pos[1]--;
            }
            
            else if (instructions[i] == 'L') {
                dir -= 1;                   // Change direction to one left.
                dir = (dir < 0) ? 3 : dir;  // If direction becomes negative.
            }
            
            else {
                dir += 1;                   // Change direction to one right.
                dir = (dir > 3) ? 0 : dir;  // If direction becomes greater than 3.
            }
        }
        
        // The robot stays in a circle only if either the robot returns to (0, 0) (no matter facing which direction) or 
	// when it ends up NOT facing north (no matter its position).
        if ((pos[0] == 0 && pos[1] == 0) || dir != 0)
            return true;
        
        return false;
    }
};