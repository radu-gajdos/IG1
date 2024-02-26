#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <utility>
#include <vector>
#include <string>
using namespace std;

class GraphK {

private:
    vector<pair<int, int>> kanten;

public:

    GraphK();
    void showGraphK();
    bool havelHakimi(string fisier){

        ifstream in(fisier);
        vector<int> grade;
        int x;
        int s=0;

        while(in>>x){
            grade.push_back(x);
            s+=x;
        }
        if(s%2!=0){
            return false;
        }


        while(!grade.empty()){
            for(int i=0;i<grade.size();i++){
                cout<<grade[i]<<" ";
            }
            cout<<"  ||  ";
            mergeSort(grade, 0, grade.size());

            for(int i=0;i<grade.size();i++){
                cout<<grade[i]<<" ";
            }
            cout<<endl;


            int temp=grade[*grade.begin()];
            grade.erase(grade.begin());
            for(int i=0; i < temp; i++){
                grade[i]-=1;
            }

            if(grade[*min_element(grade.begin(), grade.end())]<0){
                return false;
            }
            if(grade[*max_element(grade.begin(), grade.end())]==0){
                return true;
            }
            if(grade[*max_element(grade.begin(), grade.end())]>grade.size()-1){
                return false;
            }




        }
    };

    void merge(vector<int>& v, int st, int dr, int mij)
    {
        int i, j, k;
        int temp[dr - st + 1];
        i = st;
        k = 0;
        j = mij + 1;
        while (i <= mij && j <= dr)
        {
            if (v[i] > v[j])
            {
                temp[k] = v[i];
                k++;
                i++;
            }
            else
            {
                temp[k] = v[j];
                k++;
                j++;
            }
        }
        while (i <= mij)
        {
            temp[k] = v[i];
            k++;
            i++;
        }
        while (j <= dr)
        {
            temp[k] = v[j];
            k++;
            j++;
        }
        for (i = st; i <= dr; i++)
        {
            v[i] = temp[i - st];
        }
    };

    void mergeSort(vector<int>& v, int low, int high)
    {
        int mid;
        if (low < high)
        {


            mid=(low+high)/2;
            mergeSort(v, low, mid);
            mergeSort(v, mid + 1, high);

            merge(v, low, high, mid);
        }
    };

};