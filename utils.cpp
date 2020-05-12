#include "utils.h"

string elem_two_spaces(string str)
{
    while (str.find("  ") != string::npos)
    {
        str.erase(str.find("  "), 1);
    }
    return str;
}


vector<string> string_split(string str, char sep)
{
    vector<string> result;
    string component = "";

    for (int i = 0; i < str.size(); i++)
    {
        char ch = str.at(i);
        if (ch != sep)
        {
            component.append(1, ch);
        }
        else
        {
            component = elem_two_spaces(component);
            if (component.at(component.size() - 1) == ' ') component.pop_back();
            if (component.at(0) == ' ') component.erase(0, 1);
            result.push_back(component);
            component = "";
        }
        if (i == (str.size() - 1))
        {
            component = elem_two_spaces(component);
            if (component.at(component.size() - 1) == ' ') component.pop_back();
            if (component.at(0) == ' ') component.erase(0, 1);
            result.push_back(component);
        }
    }
    return result;
}
