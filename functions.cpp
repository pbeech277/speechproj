#include <string>
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;


string getFileLine(ifstream f)
{
    string line;
    f.getline(&line);
    return line;
}

int sentenceType(string in)
{
    int length = in.length();
    if(in[length] == '.')
        return 1; //declarative statement
    else if (in[length] == '?')
        return 2; //question
    else if (in[length] == '!')
        return 3; //exclamation
    else if((in[length] > 65 && in[length] < 90) || (in[length] > 97 && in[length] < 122))
        return 0; //no punctuation
    else
        return -1; //non-letter or punctuation symbol
}

int getNoun(string in)
{
    int nounLength = 0;
    string noun;
    int l = in.length();
    for (int i = 0; i < l; i++)
    {
        if(in[i] != ' ')
        {
                noun = noun + in[i];
        }
        else
        {
            if (noun == "The" || noun == "A")
            {
                cout << "Article: " << noun << endl;
                nounLength = noun.length() + 1;
                noun.clear();
            }
            else
            {
                cout << "Noun Phrase: " << noun << endl;
                break;
            }
        }
    }
    nounLength = nounLength + noun.length() + 1;
    return nounLength;
}

void getAction(string in, int del)
{
    string action;
    in.erase(0, del);
    int l = in.length();
    for (int i = 0; i < l; i++)
    {
        if(in[i] != ' ')
        {
            action = action + in[i];
        }
        else
            break;
    }
    cout << "Action: " << action<< endl;
}
string theWord(string &in)
{
    int length = in.length();
    string w;
    for (int i = 0; i < length; i++)
    {
        if(in[i] == ' ')
        {
            break;
        }
        else
        {
            w = w + in[i];
        }
    }
    return w;
}

bool Search(fstream in, string word) 
{
    string fileWord = in.getline(&word);
    while (in.eof()) 
    {
        if (word == fileWord) 
        {
            return true;
        }
    }
    return false;
}

string TypeDictionary(string currentWord) {
    fstream e, f, g, h;
    e.open("prepositions.txt");
    f.open("nouns.txt");
    g.open("adjectives.txt");
    h.open("verbs.txt");
    if (Search(e, currentWord)) {
        return "preposition";
    }
    else if (Search(f, currentWord)) {
        return "noun";
    }
    else if (Search(g, currentWord)) {
        return "adjective";
    }
    else if (Search(h, currentWord)) {
        return "verb";
    }
    else {
        return "not found";
    }
}

char first_vowel(string in)
{
    int length = in.length();
    for (int i = 0; i < length; i++)
    {
        if (in[i] == 'a' || in[i] == 'e' || in[i] == 'i' || in[i] == 'o' || in[i] == 'u')
        {
            return in[i];
        }
    }
}

string verb_tense(string in)
{
    int l = in.length();
    string end1 = in[l-1] + in[l];
    string end2 = in[l];
    string end3 = in[l-2] + in[l-1] + in[l]; 
    
    if(end1 == "ed" || (end2 != "s" && first_vowel(in) == 'a'))
    {
        return "past";
    }
    else if (end2 == "s" || end3 == "ing")
    {
        return "present";
    }
    else
        return "tense not found";
}

void evalSentence(string in)
{
    if(sentenceType(in) != 1)
    {
        cout << "Not a valid input"
    }
    else
    {
        int length = in.length();
        string article, noun, action, verbTense, word, type;
        noun = getNoun(in);
        action = getAction(in);
        verbTense = verb_tense(action);
        for (int i = 0; i < length; i++)
        {
            word = theWord(in);
            cout << word << ": " << TypeDictionary(word) << endl;
        }

    }
}
