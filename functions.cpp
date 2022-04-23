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
    int length = in.length()
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

string getNoun(string &in, string &article)
{
    string noun;
    int l = in.length();
    for (int i = 0; i < l; i++)
    {
        if(in[i] != ' ')
        {
            if(in[i] != '_')
            {
                noun = noun + in[i];
                in[i] = '_';
            }
        }
        else
            break;
    }
    if (noun == "The" || noun == "A")
    {
        article = noun;
        cout << "Article: " << noun << endl;
        noun = getNoun(in);
    }
    else
        cout << "Noun Phrase: " << noun << endl;
        return noun;
}

string getAction(string &in)
{
    string action;
    int l = in.length();
    for (int i = 0; i < l; i++)
    {
        if(in[i] != ' ')
        {
            if(in[i] != '_')
            {
                action = action + in[i];
                in[i] = '_';
            }
        }
        else
            break;
    }
    cout << "Action: " << action<< endl;
    return action;
}
string word(string &in)
{
    int length = in.length();
    string w;
    for (int i = 0; i < length; i++)
        {
            if (in[i] == '_')
            {

            }
            else if(in[i] == ' ')
            {
                break;
            }
            else
            {
                w = w + in[i];
                in[i] = '_';
                
            }
        }
    return w;
}

string theWord(string in)
{
    fstream e, f, g, h;
    e.open("prepositions.txt");
    f.open("nouns.txt");
    g.open("adjectives.txt");
    h.open("verbs.txt");
    string word;
    while(!e.eof())
    {
        word = e.getline(&word);
        if(word == in)
        {
            return "preposition";
        }
    }
    while(!f.eof())
    {
        word = f.getline(&word);
        if(word == in)
        {
            return "noun";
        }
    }
    while(!g.eof())
    {
        word = g.getline(&word);
        if(word == in)
        {
            return "adjective";
        }
    }
    while(!h.eof())
    {
        word = h.getline(&word);
        if(word == in)
        {
            return "verb";
        }
    }
    return "not found in list";
}

char first_vowel(string in)
{
    int length = in.length()
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
        noun = getNoun(in, article);
        action = getAction(in);
        verbTense = verb_tense(action);
        for (int i = 0; i < length; i++)
        {
            word = word(in);
            cout << word << ": " << theWord(word) << endl;
        }

    }
}
