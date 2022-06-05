#ifndef BITSET_H
#define BITSET_H

#include <iostream>
#include <math.h>
#include <vector>
#define uint unsigned int
using namespace std;

template <size_t size>
class Bitset{
    public:
        Bitset(){
            size_t realSize = (size%8==0)? size/8 : (size/8)+1;
            for(uint i = 0; i < realSize; i++){
                numbers[i] = 0;
            }
        }
        uint count(){
            size_t n = this->realSize();
            uint result = 0;
            for (int i = 0; i < n; i++){
                result += __builtin_popcount(numbers[i]);
            }
            return result;
        }
        bool none(){
            if(count()>0)
                return false;
            else
                return true;
        }
        bool test(size_t x){
            uint8_t k = ( numbers[x/8] >> (7 - x % 8) ) & 1;
            return k == 1;
        }
        bool all(){
            size_t n = this->realSize();
            for(uint i = 0; i < n; i++ ){
                uint nshifts = (i < n-1)? 0 : 7 - (this->maxValue() % 8);
                if( numbers[i] != (uint8_t)(0b11111111 << nshifts) )
                    return false;
            }
            return true;
        }
        bool any(){
            if(!none())
                return true;
            else
                return false;
        }
        void set(size_t x){
            if(this->outOfIndex(x)) throw;
            size_t quotient = x / 8;
            size_t remainder = x % 8;
            numbers[quotient] = (numbers[quotient] | 0b10000000 >> remainder); //128
        }
        void flip(size_t x){
            if(this->outOfIndex(x)) throw;
            size_t quotient = x/8;
            size_t remainder = x % 8;
            if(this->test(x)){
                numbers[quotient] = numbers[quotient] ^ (0b10000000 >> remainder);
            } else {
                this->set(x);
            }
        }
        void reset(size_t x){
            if(this->outOfIndex(x)) throw;
            size_t quotient = x/8;
            size_t remainder = x % 8;
            if(this->test(x)){
                numbers[quotient] = numbers[quotient] ^ (0b10000000 >> remainder);
            }
        }
        string to_string(){
            vector<char> init(size, '0');
            string digits(begin(init), end(init));
            size_t n = this->realSize();
            for(uint i = 0; i < n; i++ ){
                uint ndigits = (i < n-1)? 8 : (this->maxValue() % 8)+1;
                byteAsString(digits, numbers[i], i*8, ndigits);
            }
            return digits;
        }
        void byteAsString(string &s, uint8_t k, size_t start, size_t ndigits){
            for(uint i = 0; i < ndigits; i++){
                if((k >> 7-i) & 1){
                    s[start+i] = '1';
                }
            }
        }
        unsigned long long to_ullong(){
            if(size>64) throw;
            string t = this->to_string();
            return stoull(t.c_str(), 0, 2);
        }
        unsigned long int to_ulong(){
            if(size>32) throw;
            string t = this->to_string();
            return stoul(t.c_str(), 0, 2);
        }
        bool outOfIndex(size_t x){
            return (x < 0 or x > this->maxValue())? true:false;
        }
        void XOR(Bitset &r){
            for (int i = 0; i < this->realSize(); i++){
                this->numbers[i] ^= r.numbers[i];
            }
        }
        void OR(Bitset &r){
            for (int i = 0; i < this->realSize(); i++){
                this->numbers[i] |= r.numbers[i];
            }
        }
        void AND(Bitset &r){
            for (int i = 0; i < this->realSize(); i++){
                this->numbers[i] &= r.numbers[i];
            }
        }
        bool operator[](size_t x) const{
            if(test(x))
                return true;
            else
                return false;
        }
        Bitset<size>& operator=(const Bitset<size>& src){
            this->numbers = src->numbers;
        }
        size_t Size() { return size; }
        size_t realSize() { return (size%8==0)? size/8 : (size/8)+1; }
        size_t byteIndex(size_t x) { return x/8; }
        size_t remainder(size_t x) { return x % 8; }
        size_t maxValue() { return max; }
    private:
        size_t max = size - 1;
        uint8_t* numbers = new uint8_t[(size%8==0)? size/8 : (size/8)+1];
};

#endif // BITSET_H
