#include<iostream>
#include<map>
#include<string>
#include<algorithm>

using namespace std;

void remove_UC_spaces(string& text)
{
    string formatted_text;

    for(auto text_single_char:text)
    {
        if (text_single_char!=' ')
            {
                formatted_text += tolower(text_single_char);
            }
    }

    text = formatted_text;
}

int main()
{
    string plain_text, cipher_text, decipher_text;
    char letter;

    map<char,char> key_map;
    cout<<"Enter key map to map alphabets: \n";
    for(char i='a'; i<='z'; i++)
    {
        cout<<i<<" => ";
        cin>>letter;
        key_map[i]=toupper(letter);
    }

    fflush(stdin);

    cout<<"\nEnter plain text: ";
    getline(cin,plain_text);

    remove_UC_spaces(plain_text);

    for(auto letter:plain_text)
    {
        cipher_text += key_map[letter];
    }

    cout<<"\nCipher text is: "<<cipher_text<<endl;

    //Reverse mapping
    for(auto letter:cipher_text)
    {
        for(auto iter:key_map)
        {
            if(iter.second==letter)
                decipher_text+=iter.first;
        }
    }

    cout<<"\nDecipher text is: "<<decipher_text<<endl;
}

