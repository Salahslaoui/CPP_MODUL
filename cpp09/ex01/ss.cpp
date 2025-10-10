#include <iostream>
#include <vector>

using namespace std;

int lengthOfLongestSubstring(string s)
{
    int tmp = 0;
    int save = 0;
    int flag = 0;
    string a = "";

    if (s[0])
        a += s[0];
    for (int i = 1; i < s.size(); ++i)
    {
        // if (s[i + 1] && s[i] == s[i + 1])
        // {
        //     if (tmp > save)
        //         save = tmp;
        //     tmp = 1;
        //     continue;
        // }
        // tmp++;
        for (int j = 0; j < a.size(); ++j)
        {
            if (s[i] == a[j])
            {
                if (tmp > save)
                    save = tmp;
                tmp = 1;
                break;
            }
            else if (j + 1 == a.size() && a[j] != s[i])
                a += s[i];
            else
                tmp++;
        }
        // if (flag == 1)
        // {
        //     if (s[i] == s[i - 1])

        // }
        // flag = 0;
    }
    // for (int i = 0; i < s.size(); ++i)
    // {
    //     for (int j = 0; j < a.size(); ++i)
    //     {
    //         if (s[i] == a[i])
    //     }
    // }
    return save;
}

int main()
{
    string a = "ckilbkd";
    string a = "abcdabcd";
    string b = "dvdf";
    string c = "pwwkew";
    std::cout << lengthOfLongestSubstring(b) << std::endl;
}
