//
//  L1_020.cpp
//  algorithm
//
//  Created by Evan on 2019/2/6.
//  Copyright © 2019 Evan. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <set>
using namespace std;

int main()
{
    set<int> iSet;
    int count;
    cin >> count;
    for (int i = 0; i < count; i++)
    {
        int pCount;
        cin >> pCount;
        if (pCount >= 2)
        {
            for (int j = 0; j < pCount; j++)
            {
                int input;
                cin >> input;
                iSet.insert(input);
            }
        } else {
          cin >> pCount;
        }
    }

    int qCount;
    cin >> qCount;
    set<int> qSet;
    bool flag = false;
    for (int i = 0; i < qCount; i++)
    {
        int query;
        cin >> query;
        if (qSet.find(query) == qSet.end() && iSet.find(query) == iSet.end())
        {
            qSet.insert(query);
            if (flag)
                cout << " ";
            printf("%05d", query);
            flag = true;
        }
    }

    if (!flag)
        cout << "No one is handsome" << endl;
    return 0;
}
