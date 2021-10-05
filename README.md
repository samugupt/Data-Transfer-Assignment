# Data-Transfer-Assignment
## This project is an implementation of an approach to transfer data to-and-fro between two devices where a third device monitors the transmission and reception between them.

### Approach Used

#### Steps for Transmission of data

1. First I calculate the input string length.
2. Then I calculate the number of data blocks each with a size of 20 bytes
3. The string with a size of 20 bytes is sent to the transmit function along with total number of data blocks.
4. The loop runs till all the blocks are sent.

#### Steps for Reception of data

1. The complete binary string is sent as input to the receive function.
2. Then I use string delimiter functions from standard C library files to breakdown the binary string into 8-bit/ 1 character long strings.
3. Then I convert each character from its binary format to character format.
4. Using a pointer to a character array, I store all these characters to form a complete string (20 byte long).

### Results

![result_1](Images/result_1.png)
