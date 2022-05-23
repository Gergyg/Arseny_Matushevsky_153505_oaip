#include "receipt.h"


Receipt::Receipt(string s1, string s2, string s3, string s4) : group(s1), mark(s2), date(s3), ready(s4)
{

}

Receipt::Receipt()
{

}

string Receipt::toSort()
{
    string s="0123.56.89"; //01.34.6789
    s[0]=date[6];
    s[1]=date[7];
    s[2]=date[8];
    s[3]=date[9];
    s[5]=date[3];
    s[6]=date[4];
    s[8]=date[0];
    s[9]=date[1];
    return s;
}
