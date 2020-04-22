#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
using namespace std;

class ShannonFano
{
public:
    ShannonFano()// можно изменить что бы принимал на вход количесво элементов
    {

    }

    void build()
    {
        // запускает алгоритм (после того как были добавлены все элементы)
        Fano(' ', "", 0, number);
    }
    void addChance (int chance)
    {
        // добавляет элемент в список (дерево, все зависит от реализации)
        Tree.push_back(chance);
        result.push_back("");
        number++;
    }
    string get (int i)
    {
        // выдает битовый код i символа
        return result[i];
    }
private:
    void Fano(char branch, string fullStr, int begin, int end)
    {
        string tmp = fullStr;
        if (branch != ' ')
            tmp += branch;
        if ((begin + 1) == end)
            result[begin] = tmp;
        else
        {
            int medium = Med(begin, end);
            Fano('0', tmp, begin, medium);
            Fano('1', tmp, medium, end);
        }
    }

    int Med(int begin, int end)
    {
        int leftSum = 0, rightSum = 0, i = begin, j = end - 1;
        while(i <= j)
        {
            if (leftSum < rightSum)
            {
                leftSum += Tree[i];
                i++;
            }
            else
            {
                rightSum += Tree[j];
                j--;
            }
        }
        return i;
    }

    int number = 0;
    vector<int> Tree;
    vector<string> result;
};


int main() {

    int n;
    ShannonFano * shf = new ShannonFano();

    fstream fin;
    fin.open("input.txt",ios::in);
    if(fin.is_open()) {
        fin >> n;
        for (int i = 0; i < n; i++) {
            int x;
            fin >> x;
            shf->addChance (x);
        }

        fin.close();

        shf->build();
        fstream fout;
        fout.open("output.txt",ios::out);
        for (int i = 0; i < n; i++){
            fout <<shf->get(i) << (i==n-1?"":" ");
        }
        fout.close();
        delete shf;

    }
    return 0;
}