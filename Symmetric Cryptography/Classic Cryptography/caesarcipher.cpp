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

string encrypt_using_caesar(string text)
{
    remove_LC_spaces(text);
    for(auto& single_text_char:text)
    {
        single_text_char = (((single_text_char+3-97)%26)+97);
    }
    return text;
}

string decrypt_using_caesar(string text)
{
    remove_LC_spaces(text);
    for(auto& single_text_char:text)
    {
        single_text_char = (((single_text_char-3-97+26)%26)+97);
    }
    return text;
}


int main()
{
    string plain_text, cipher_text, decipher_text;

    cout<<"Enter plain text: ";
    getline(cin,plain_text);

    cipher_text = encrypt_using_caesar(plain_text);

    cout<<"\nCipher text is: "<<cipher_text<<endl;

    decipher_text = decrypt_using_caesar(cipher_text);

    cout<<"\nDecipher text is: "<<decipher_text<<endl;
}

