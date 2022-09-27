class Solution:
    def pushDominoes(self, dominoes: str) -> str:
        n, force = len(dominoes), 0
        # Initialise a list to store the forces acting on the dominoes.
        forces = [0] * n
        # Traverse the string and calculate the force acting towards right side.
        for i in range(n):
            # Check if the force is acting towards right side.
            if dominoes[i] == 'R':
                force = n
            # Check if the force is acting towards left side.
            elif dominoes[i] == 'L':
                force = 0
            # Check if no force is acting.
            else:
                force = max(force - 1, 0)
            # Update 'forces'.
            forces[i] += force
        # Traverse the string and calculate the force acting towards left side.
        force = 0
        for i in range(n - 1, -1, -1):
            # Check if the force is acting towards left side.
            if dominoes[i] == 'L':
                force = n
            # Check if the force is acting towards right side.
            elif dominoes[i] == 'R':
                force = 0
            # Check if no force is acting.
            else:
                force = max(force - 1, 0)
            # Update 'forces'.
            forces[i] -= force
        return "".join('.' if force == 0 else 'R' if force > 0 else 'L' for force in forces)