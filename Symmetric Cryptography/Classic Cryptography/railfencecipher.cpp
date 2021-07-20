#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

void remove_LC_spaces(string& text)
{
    string formatted_text;

    for(auto text_single_char:text)
    {
        if (text_single_char!=' ')
            {
                    {formatted_text += tolower(text_single_char);}
            }
    }

    text = formatted_text;
}


string encrypt_using_rail_fence(string plain_text,int key)
{
    remove_LC_spaces(plain_text);

    int msgLen = plain_text.size();

    char matrix[key][msgLen];

    for(int row=0; row<key; row++)
        for(int col=0; col<msgLen; col++)
            matrix[row][col]='\n';

    int row=0; bool dir=0;
    for(int col=0; col<msgLen; col++)
    {
        matrix[row][col]=plain_text[col];

        if(row==0||row==key-1)
            dir=!dir;

        dir?row++:row--;
    }

    string cipher_text;
    for(int row=0; row<key; row++)
        for(int col=0; col<msgLen; col++)
            if(matrix[row][col]!='\n') cipher_text+=matrix[row][col];

    return cipher_text;
}

string decrypt_using_rail_fence(string text,int key)
{
    remove_LC_spaces(text);

    int msgLen = text.size();

    char matrix[key][msgLen];

    for(int row=0; row<key; row++)
        for(int col=0; col<msgLen; col++)
            matrix[row][col]='\n';

    int row=0; bool dir=0;
    for(int col=0; col<msgLen; col++)
    {
        matrix[row][col]='*';

        if(row==0||row==key-1)
            dir=!dir;

        dir?row++:row--;
    }

    int i=0;
    for(int row=0; row<key; row++)
        for(int col=0; col<msgLen; col++)
            {
                if(matrix[row][col]=='*') matrix[row][col]=text[i++];
            }

    string cipher_text;
    for(int row=0; row<key; row++)
        for(int col=0; col<msgLen; col++)
            if(matrix[row][col]!='\n') cipher_text+=matrix[row][col];

    return cipher_text;
}

int main()
{
    string plain_text, cipher_text, decipher_text;
    int key =3;

    cout<<"Enter plain text: ";
    getline(cin,plain_text);

    cout<<"\nEnter Key: ";
    cin>>key;

    cipher_text = encrypt_using_rail_fence(plain_text,key);

    cout<<"\nCipher text is: "<<cipher_text<<endl;

    decipher_text = decrypt_using_rail_fence(plain_text,key);

    cout<<"\nCipher text is: "<<decipher_text<<endl;
}

