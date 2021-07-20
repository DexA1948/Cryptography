#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<utility>
#include <algorithm>

using namespace std;

string remove_LC_spaces_j(const string& text)
{
    string return_text;

    for(auto text_single_char:text)
    {
        if (text_single_char!=' ')
            {
                if (text_single_char=='j' || text_single_char=='J')
                    {return_text += 'i';}
                else
                    {return_text += tolower(text_single_char);}
            }
    }

    return return_text;
}

void display_playfair_matrix(char playfair_matrix[5][5])
{
    for(int row=0;row<5;row++)
    {
        for(int column=0;column<5;column++)
        {
            cout<<playfair_matrix[row][column]<<" ";
        }
        cout<<endl;
    }
}

void generate_playfair_matrix(char playfair_matrix[5][5], string key)
{
    int row=0, column=0;
    map<char, int> mp;

    mp['j']=1;

    for(auto key_single_char:key)
    {
        if(mp[key_single_char]==0)
        {
             playfair_matrix[row][column]=key_single_char;
             mp[key_single_char]=1;
             column = (column+1)%5;
             if (column==0)
                row = (row+1)%5;
        }
    }

    for(char alphabet='a';alphabet<='z';alphabet++)
    {
        if(mp[alphabet]==0)
        {
             playfair_matrix[row][column]=alphabet;
             mp[alphabet]=1;
             column = (column+1)%5;
             if (column==0)
                row = (row+1)%5;
        }
    }
}

map<char, pair<int, int>> map_char_pos(const char playfair_matrix[5][5])
{
    map<char, pair<int, int>> char_row_column_map;char element;

    for(int row=0;row<5;row++)
    {
        for(int column=0;column<5;column++)
        {
            element = playfair_matrix[row][column];
            char_row_column_map[element]=make_pair(row,column);
        }
    }

    return char_row_column_map;
}

vector<pair<char,char>> divide_string_to_pairs(string plain_text)
{
    vector<pair<char,char>> plain_text_pair_vector;
    for(int i=0;i<plain_text.size();i++)
    {
        if(i!=plain_text.size()-1)
        {
            if(plain_text[i]!=plain_text[i+1])
            {
                plain_text_pair_vector.push_back(make_pair(plain_text[i],plain_text[i+1]));
                //plain_text_pair_vector[i].first=plain_text[i];
                //plain_text_pair_vector[i+1].first=plain_text[i];
                i++;
            }
            else if(plain_text[i]==plain_text[i+1])
            {
                plain_text_pair_vector.push_back(make_pair(plain_text[i],'x'));
            }
        }
        else
        {
            plain_text_pair_vector.push_back(make_pair(plain_text[i],'x'));
        }
    }

    return plain_text_pair_vector;
}

string encrypt_using_play_fair(string plain_text, string key)
{
    char playfair_matrix[5][5];

    plain_text=remove_LC_spaces_j(plain_text);
    key=remove_LC_spaces_j(key);

    generate_playfair_matrix(playfair_matrix, key);

    cout<<"\nThe 5*5 Play Fair Matrix or Key Table is:\n";
    display_playfair_matrix(playfair_matrix);

    map<char, pair<int,int>> char_row_column_map = map_char_pos(playfair_matrix);

    cout<<"\nThe row and column for each char in the 5*5 table is: \n";
    for(auto iter:char_row_column_map)
    {
        cout<<iter.first<<":<"<<iter.second.first<<","<<iter.second.second<<">"<<endl;
    }

    vector<pair<char,char>> plain_text_pair_vector = divide_string_to_pairs(plain_text);

    cout<<"\nThe Plain Text divided into Pairs: \n";
    for(auto single_pair_item:plain_text_pair_vector)
    {
        cout<<single_pair_item.first<<","<<single_pair_item.second<<endl;
    }

    //The main work
    //Generating Cipher Text
    //using the pairs which are inserted in vector
    string ciphertext;
    char first_letter, second_letter;
    int flr,flc,slr,slc;

    for(auto single_pair_item:plain_text_pair_vector)
    {
        first_letter=single_pair_item.first;
        second_letter=single_pair_item.second;

        flr=char_row_column_map[first_letter].first;
        flc=char_row_column_map[first_letter].second;
        slr=char_row_column_map[second_letter].first;
        slc=char_row_column_map[second_letter].second;

        if(flr==slr)
        {
            ciphertext+=playfair_matrix[flr][(flc+1)%5];
            ciphertext+=playfair_matrix[slr][(slc+1)%5];
        }
        else if(flc==slc)
        {
            ciphertext+=playfair_matrix[(flr+1)%5][flc];
            ciphertext+=playfair_matrix[(slr+1)%5][slc];
        }
        else
        {
            ciphertext+=playfair_matrix[flr][slc];
            ciphertext+=playfair_matrix[slr][flc];
        }
    }

    return ciphertext;
}

string decrypt_using_play_fair(string plain_text, string key)
{
    cout<<"\nThis is Decryption Process:\n";

    char playfair_matrix[5][5]{NULL};

    plain_text=remove_LC_spaces_j(plain_text);
    key=remove_LC_spaces_j(key);

    generate_playfair_matrix(playfair_matrix, key);

    cout<<"\nThe 5*5 Play Fair Matrix or Key Table is:\n";
    display_playfair_matrix(playfair_matrix);

    map<char, pair<int,int>> char_row_column_map = map_char_pos(playfair_matrix);

    cout<<"\nThe row and column for each char in the 5*5 table is: \n";
    for(auto iter:char_row_column_map)
    {
        cout<<iter.first<<":<"<<iter.second.first<<","<<iter.second.second<<">"<<endl;
    }

    vector<pair<char,char>> plain_text_pair_vector = divide_string_to_pairs(plain_text);

    cout<<"\nThe Cipher Text divided into Pairs: \n";
    for(auto single_pair_item:plain_text_pair_vector)
    {
        cout<<single_pair_item.first<<","<<single_pair_item.second<<endl;
    }

    //The main work
    //Generating Cipher Text
    //using the pairs which are inserted in vector
    string ciphertext;
    char first_letter, second_letter;
    int flr,flc,slr,slc;

    for(auto single_pair_item:plain_text_pair_vector)
    {
        first_letter=single_pair_item.first;
        second_letter=single_pair_item.second;

        flr=char_row_column_map[first_letter].first;
        flc=char_row_column_map[first_letter].second;
        slr=char_row_column_map[second_letter].first;
        slc=char_row_column_map[second_letter].second;

        if(flr==slr)
        {
            ciphertext+=playfair_matrix[flr][(flc-1+5)%5];
            ciphertext+=playfair_matrix[slr][(slc-1+5)%5];
        }
        else if(flc==slc)
        {
            ciphertext+=playfair_matrix[(flr-1+5)%5][flc];
            ciphertext+=playfair_matrix[(slr-1+5)%5][slc];
        }
        else
        {
            ciphertext+=playfair_matrix[flr][slc];
            ciphertext+=playfair_matrix[slr][flc];
        }
    }

    return ciphertext;
}

int main()
{
    string plain_text, key, cipher_text, decipher_text;

    cout<<"Enter plain text: ";
    getline(cin,plain_text);

    cout<<"\nEnter Key: ";
    getline(cin,key);

    cipher_text = encrypt_using_play_fair(plain_text,key);

    cout<<"\nCipher text is: "<<cipher_text<<endl;

    decipher_text = decrypt_using_play_fair(cipher_text,key);

    cout<<"\nDecipher text is: "<<decipher_text<<endl;
}
