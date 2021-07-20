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

void fit_key_to_text(string& key, int ts, int ks)
{
    if(ts>ks)
    {
        for(int i=0;i<ts-ks;i++)
        {
            key.push_back(key[i%ks]);
        }
    }
}

string encrypt_using_vignere(string text, string key)
{
    string cipher_text;

    remove_LC_spaces(text);
    remove_LC_spaces(key);

    fit_key_to_text(key,text.size(),key.size());
    cout<<"\nNew key: "<<key<<endl;

    for(int i=0;i<text.size();i++)
    {
        cipher_text+=((((text[i]-'a')+(key[i]-'a'))%26)+97);
    }

    return cipher_text;
}

string decrypt_using_vignere(string text, string key)
{

}

int main()
{
    string plain_text, key, cipher_text, decipher_text;

    cout<<"Enter plain text: ";
    getline(cin,plain_text);

    cout<<"\nEnter key: ";
    getline(cin,key);

    cipher_text = encrypt_using_vignere(plain_text,key);

    cout<<"\nCipher text is: "<<cipher_text<<endl;

    //decipher_text = decrypt_using_vigenere(cipher_text,key);

    //cout<<"\nDecipher text is: "<<decipher_text<<endl;
}
