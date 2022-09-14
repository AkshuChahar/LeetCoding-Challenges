class Solution:
    def validUtf8(self, data: List[int]) -> bool:
        byte = 0
        # Traverse the array.
        for num in data:
            # Convert the number into binary and get the 8 least significant digits.
            binary = format(num, '#010b')[-8:]
            # Get the number of bytes.
            if byte == 0:
                for bit in binary:
                    if bit == '0':
                        break
                    byte += 1
                # Check if we a 1-byte character.
                if byte == 0:
                    continue
                # Check if the bytes are between 1 and 4.
                if byte == 1 or byte > 4:
                    return False
            else:
                # Check if the subsequent numbers adhere to the rules.
                if not (binary[0] == '1' and binary[1] == '0'):
                    return False
            byte -= 1
        return byte == 0