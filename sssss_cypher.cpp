#include <bits/stdc++.h>
#include <vector>
using namespace std;
class modulo_inverse
{
protected:
    int x, y;
    void gcdex(int a, int b)
    {
        if (b == 0)
        {
            x = 1;
            y = 0;
        }
        else
        {
            gcdex(b, a % b);
            int t = x;
            x = y;
            y = t - (a / b) * y;
        }
    }
};
class multiplicative_cipher : protected modulo_inverse
{
private:
    string s;
    int key = 7;
    void encrypt()
    {
        for (int h = 0; h < s.size(); h++)
        {
            int a = s[h] - 'a';
            a = (a * key) % 26;
            s[h] = a + 'a';
        }
    }
    void decrypt()
    {
        gcdex(key, 26);
        x = (x + 26) % 26;
        for (int h = 0; h < s.size(); h++)
        {
            int a = s[h] - 'a';
            a = (a * x) % 26;
            s[h] = a + 'a';
        }
    }

public:
    void execute()
    {
        cout << "enter the plain text" << endl;
        cin >> s;
        encrypt();
        cout << "the encrypted text:- " << s << endl;
        decrypt();
        cout << "the decrypted text:- " << s << endl;
    }
};
class affine_cipher : protected modulo_inverse
{
private:
    string s;
    int a = 7, b = 1;
    void encrypt()
    {
        for (int h = 0; h < s.size(); h++)
        {
            int z = s[h] - 'a';
            z = (a * z + b) % 26;
            s[h] = z + 'a';
        }
    }
    void decrypt()
    {
        gcdex(a, 26);
        x = (x + 26) % 26;
        for (int h = 0; h < s.size(); h++)
        {
            int z = s[h] - 'a';
            z = (x * (z - b)) % 26;
            z = (z + 26) % 26;
            s[h] = z + 'a';
        }
    }

public:
    void execute()
    {
        cout << "enter the plain text for affine encryption" << endl;
        cin >> s;
        encrypt();
        cout << "the encrypted text:- " << s << endl;
        decrypt();
        cout << "the decrypted text:- " << s << endl;
    }
};
class autokey_cipher
{
private:
    string s;
    string k;
    void encrypt()
    {
        for (int h = 0; h < s.size(); h++)
        {
            int a = s[h] - 'a';
            int b = k[h] - 'a';
            a = (a + b) % 26;
            s[h] = a + 'a';
        }
    }
    void decrypt()
    {
        for (int h = 0; h < s.size(); h++)
        {
            int a = s[h] - 'a';
            int b = k[h] - 'a';
            a = (a - b + 26) % 26;
            s[h] = a + 'a';
        }
    }

public:
    void execute()
    {
        cout << "enter the plain text for autokey cipher" << endl;
        cin >> s;
        cout << "enter the key " << endl;
        cin >> k;
        if (k.size() < s.size())
        {
            k += s.substr(0, s.size() - k.size());
        }
        encrypt();
        cout << "the encrypted text:- " << s << endl;
        decrypt();
        cout << "the decrypted text:- " << s << endl;
    }
};
class playfair_cipher
{
    string s;
    string k;
    char v[5][5];
    void constructmatrix()
    {
        int z = 0;
        unordered_set<char> mp;
        mp.insert('j');
        bool fl = false;
        for (int h = 0; h < 5; h++)
        {
            for (int j = 0; j < 5; j++)
            {
                while (z < k.size() and mp.find(k[z]) != mp.end())
                {
                    z++;
                }
                if (z < k.size())
                {
                    v[h][j] = k[z];
                    mp.insert(k[z]);
                }
                else
                {
                    fl = true;
                    break;
                }
            }
            if (fl)
            {
                break;
            }
        }
        char ch = 'a';
        for (int h = 0; h < 5; h++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (v[h][j] != '#')
                    continue;
                while (mp.find(ch) != mp.end())
                {
                    ch++;
                }
                v[h][j] = ch;
                mp.insert(ch);
            }
        }
    }
    void init_mat()
    {
        for (int h = 0; h < 5; h++)
        {
            for (int j = 0; j < 5; j++)
            {
                v[h][j] = '#';
            }
        }
    }
    void print_mat()
    {
        for (int h = 0; h < 5; h++)
        {
            for (int j = 0; j < 5; j++)
            {
                cout << v[h][j] << " ";
            }
            cout << endl;
        }
    }
    void find(char a, char b, int pos[])
    {
        if (a == 'j')
        {
            a = 'i';
        }
        if (b == 'j')
        {
            b = 'i';
        }
        for (int h = 0; h < 5; h++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (v[h][j] == a)
                {
                    pos[0] = h;
                    pos[1] = j;
                }
                else if (v[h][j] == b)
                {
                    pos[2] = h;
                    pos[3] = j;
                }
            }
        }
    }
    void encrypt()
    {
        string res;
        int i = 0;
        int pos[4];
        while (i < s.size())
        {
            if (i + 1 < s.size() and s[i + 1] != s[i])
            {
                find(s[i], s[i + 1], pos);
                i += 2;
            }
            else
            {
                find(s[i], 'x', pos);
                i++;
            }
            if (pos[0] == pos[2])
            {
                res.push_back(v[pos[0]][(pos[1] + 1) % 5]);
                res.push_back(v[pos[0]][(pos[3] + 1) % 5]);
            }
            else if (pos[1] == pos[3])
            {
                res.push_back(v[(pos[0] + 1) % 5][pos[1]]);
                res.push_back(v[(pos[2] + 1) % 5][pos[1]]);
            }
            else
            {
                res.push_back(v[pos[0]][pos[3]]);
                res.push_back(v[pos[2]][pos[1]]);
            }
        }
        s = res;
    }
    void decrypt()
    {
        string res;
        int i = 0;
        int pos[4];
        while (i < s.size())
        {
            if (i + 1 < s.size() and s[i + 1] != s[i])
            {
                find(s[i], s[i + 1], pos);
                i += 2;
            }
            else
            {
                find(s[i], 'x', pos);
                i++;
            }
            if (pos[0] == pos[2])
            {
                res.push_back(v[pos[0]][(pos[1] - 1 + 5) % 5]);
                res.push_back(v[pos[0]][(pos[3] - 1 + 5) % 5]);
            }
            else if (pos[1] == pos[3])
            {
                res.push_back(v[(pos[0] - 1 + 5) % 5][pos[1]]);
                res.push_back(v[(pos[2] - 1 + 5) % 5][pos[1]]);
            }
            else
            {
                res.push_back(v[pos[0]][pos[3]]);
                res.push_back(v[pos[2]][pos[1]]);
            }
        }
        s = res;
    }

public:
    void execute()
    {
        cin >> k;
        cin >> s;
        init_mat();
        constructmatrix();
        print_mat();
        encrypt();
        cout << s << endl;
        decrypt();
        cout << s << endl;
    }
};
int main()
{
    playfair_cipher pl;
    pl.execute();
}