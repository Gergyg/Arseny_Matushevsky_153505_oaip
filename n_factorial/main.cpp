#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int k;
    cin>>k;

    int del[10001]={};
    int cop = k;
    int i=2;
    //��������� � ������ del ���������� ��������� ��� ������� i
    while(cop>1 && i<10001){

        int ci = i;
        bool prost = true;
        for(int j = 2; j<i; j++){
            if(i%j==0)
                prost = false;
        }

        if(prost){
            if(cop%i == 0){
                del[i]++;
                cop/=i;
            } else {
                i++;
            }
        } else {
            i++;
        }

    }
    //�� ���� ��������� ���� �����, ��� ���� ��� �������� � ������� ��� ��������� � ����� ������� ���������, ��� ������� ����� �����������
    int a=0;
    for(int i=2; i<10001; i++){
        if(del[i]>0){
            if(pow(i,del[i])>pow(a,del[a])){
                a=i;
            }
        }

    }
    long long s=0;
    long long m=a;
    //������� ���������� ��������� ����������� ��������
    while (n>=m){
        s=s+(n/m);
        m=m*a;
    }
    //����� ���������� ����� ����� �������� �� ��� ������� ���������
    s/=del[a];
    cout<<s;
    return 0;
}
