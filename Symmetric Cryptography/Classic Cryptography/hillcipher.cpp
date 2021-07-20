//Code to implement Hill Cipher in C++ to encrypt a message
#include<iostream>
#include<string>
#include<math.h>
using namespace std;

void remove_LC_spaces(string& text)
{
    string formatted_text;

    for(auto text_single_char:text)
        if (text_single_char!=' ')
            formatted_text += tolower(text_single_char);

    text = formatted_text;
}

void create_key_matrix(char* key_matrix, string key, int block_size)
{
    int ks=key.size();

    //fitting key size to no of matrix elements
    if(block_size*block_size>ks)
        for(int i=0; i<block_size*block_size-ks;i++)
            key+='x';

    for(int row=0;row<block_size;row++)
        for(int col=0;col<block_size;col++)
            key_matrix[row*block_size+col]=key[row*block_size+col];
}

string encrypt_using_hill_cipher(string text, string key, int block_size)
{
    string return_text;
    char product=0;
    int ts=text.size();

    char key_matrix[block_size][block_size];

    remove_LC_spaces(text);
    ts=text.size();
    remove_LC_spaces(key);

    //key_matrix is a pointer which points to 1D array of integers (i.e first element of 2D array)
    //key_matrix[0] is a pointer which points to first element of 1D array of integers
    //same as *key_matrix
    create_key_matrix(key_matrix[0], key, block_size);

    //displaying key_matrix formed
    cout<<"\nThe key matrix created is: "<<endl;
    for(int i = 0; i < block_size; i++)
    {
          for(int j = 0; j < block_size; j++)
              printf("%c ", key_matrix[i][j]);
          printf("\n");
    }

    //padding text with extra letters to make multiple of block_size
    while(ts%block_size!=0)
    {
        text.push_back('x');
        ts=text.size();
    }

    int m,t,p=0;
    //multiplying key_matrix with text
    for(int i=0;((i+1)*block_size)<=ts;i++)
    {
        for(int row=0; row<block_size; row++)
        {
            for(int col=0; col<block_size; col++)
            {
                m=key_matrix[row][col]-97;
                t=text[i*block_size+col]-97;
                p+=m*t;
            }
            p=(p%26)+97;
            product = p;
            return_text+=product;
            p=0;
        }
    }

    return return_text;
}

int main()
{

    string plain_text, key, cipher_text, decipher_text;
    int block_size;

    cout<<"Enter plain text: ";
    getline(cin,plain_text);

    cout<<"\nEnter Key: ";
    getline(cin,key);

    cout<<"\nEnter Block Size: ";
    cin>>block_size;

    cipher_text = encrypt_using_hill_cipher(plain_text,key,block_size);

    cout<<"\nCipher text is: "<<cipher_text<<endl;

}
