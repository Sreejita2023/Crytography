
# Security Using Colors and Armstrong Numbers 

A **research-based** C++ Program that enables Double layer encryption and decryption of data using Armstrong Numbers and RGB color model for text file format.


## Tech Stack

**Language:** C++




## How encryption and decryption of file is done

1. The user provides a key using it a XOR value is generated and base value of 3 matrices is generated.

2. The matrix is 16 * 16 matrix which has 256 elements and is used to store 1 byte of data.
3. Now lets say the base values for 3 matrices is (24, 210, 231). Further the base values is incremented sequentially and in a cyclic manner to fill up the matrix elements, as follows:
```
Matrix-1 : 24, 25, 26, ..., 255, 0, 1, 2, 3, ... 23

Matrix-2 : 210, 211, 212, ..., 255, 0, 1, 2, 3, ... 209

Matrix-3 : 231, 232, 233, ..., 255, 0, 1, 2, 3, ... 230
```
4. During encryption, Data (byte) to be encrypted is splitted into 2 nibbles. The higher nibble acts as row and lower one as column. By using this row, col as co-ordinates we get encoded value from matrix.
5. During decryption, the encoded value which is unique is to be searched in the matrix and co-ordinates (row, col) of matching element are to be treated as the high nibble and lower nibble from which we get original data back.
6. Also instead of creating an actual matrix, we simply use mathematical formula to get values from the supposed matrix in constant time.
7. Before the encryption and decryption we also take xor of original data with XOR value that we generated earlier from user key.

## Screenshots

- Encryption

![encryption](https://github.com/user-attachments/assets/ced18607-0761-4657-8cc3-4acb644f4c4d)

- Decryption

![decryption](https://github.com/user-attachments/assets/ef38fbd2-1771-4547-9244-ff1bdb4b2ad2)

- FlowChart
![Screenshot 2024-07-30 010549](https://github.com/user-attachments/assets/3c91b882-34a8-49c0-9e42-41186b77fc5e)

- Color Encryption
![Screenshot 2024-07-30 182008](https://github.com/user-attachments/assets/8419f218-9554-4c8a-aa52-ccaa79e2dcd7)

- Armstrong Encryption
![Screenshot 2024-07-30 183447](https://github.com/user-attachments/assets/3a81ecbd-69ce-4450-9ce6-f2bb10b24748)


## Advantages: 

1. **Enhanced Security Through Complexity:** The technique uses a minimum key length of 8 bits for Armstrong numbers, which can be increased if needed, enhancing the complexity and security of the encryption. This complexity makes it difficult for unauthorized parties to decrypt the data without knowing the exact encoding process.

2. **Multi-Step Encryption Process:** The technique involves converting characters by adding them with digits of Armstrong numbers and then encoding using a matrix. This multi-step process, combined with the use of colors and Armstrong numbers, makes tracing and hacking extremely difficult.

3. **Triple Key System:** The technique employs three different keys (colors, key values added with colors, and Armstrong numbers), similar to the triple DES algorithm. This triple key system ensures that unless all keys and the entire encryption and decryption process are known, the data remains secure, providing an added layer of protection compared to simpler encryption methods.


## Acknowledgements

- S. Pavithra Deepa, S. Kannimuthu and V. Keerthika, "Security using colors and Armstrong numbers," 2011 National Conference on Innovations in Emerging Technology, Erode, India, 2011, pp. 157-160, doi: 10.1109/NCOIET.2011.5738822. keywords: {Image color analysis;Encryption;Receivers;Encoding;Classification algorithms;Armstrong numbers;data security;authentication;cryptography},


