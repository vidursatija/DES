//initial permutation
int IP[] = 
{
	  58, 50, 42, 34, 26, 18, 10, 2,
	  60, 52, 44, 36, 28, 20, 12, 4,
	  62, 54, 46, 38, 30, 22, 14, 6,
	  64, 56, 48, 40, 32, 24, 16, 8,
	  57, 49, 41, 33, 25, 17,  9, 1,
	  59, 51, 43, 35, 27, 19, 11, 3,
	  61, 53, 45, 37, 29, 21, 13, 5,
	  63, 55, 47, 39, 31, 23, 15, 7
};
// Expanstion D box
int ED[] = 
{
	  32,  1,  2,  3,  4,  5,
	   4,  5,  6,  7,  8,  9,
	   8,  9, 10, 11, 12, 13,
	  12, 13, 14, 15, 16, 17,
	  16, 17, 18, 19, 20, 21,
	  20, 21, 22, 23, 24, 25,
	  24, 25, 26, 27, 28, 29,
	  28, 29, 30, 31, 32,  1
};
// P-box
int P[] = 
{
	  16,  7, 20, 21,
	  29, 12, 28, 17,
	   1, 15, 23, 26,
	   5, 18, 31, 10,
	   2,  8, 24, 14,
	  32, 27,  3,  9,
	  19, 13, 30,  6,
	  22, 11,  4, 25
};
// Final permutation
int FP[] = 
{
	  40, 8, 48, 16, 56, 24, 64, 32,
	  39, 7, 47, 15, 55, 23, 63, 31,
	  38, 6, 46, 14, 54, 22, 62, 30,
	  37, 5, 45, 13, 53, 21, 61, 29,
	  36, 4, 44, 12, 52, 20, 60, 28,
	  35, 3, 43, 11, 51, 19, 59, 27,
	  34, 2, 42, 10, 50, 18, 58, 26,
	  33, 1, 41,  9, 49, 17, 57, 25
};
// S-boxes
int s[8][4][16] = 
{
{
		14,  4, 13,  1,  2, 15, 11,  8,  3, 10,  6, 12,  5,  9,  0,  7,
		0, 15,  7,  4, 14,  2, 13,  1, 10,  6, 12, 11,  9,  5,  3,  8,
		4,  1, 14,  8, 13,  6,  2, 11, 15, 12,  9,  7,  3, 10,  5,  0,
		15, 12,  8,  2,  4,  9,  1,  7,  5, 11,  3, 14, 10,  0,  6, 13
},
{
	15,  1,  8, 14,  6, 11,  3,  4,  9,  7,  2, 13, 12,  0,  5, 10,
	 3, 13,  4,  7, 15,  2,  8, 14, 12,  0,  1, 10,  6,  9, 11,  5,
	 0, 14,  7, 11, 10,  4, 13,  1,  5,  8, 12,  6,  9,  3,  2, 15,
	13,  8, 10,  1,  3, 15,  4,  2, 11,  6,  7, 12,  0,  5, 14,  9
},
{
	10,  0,  9, 14,  6,  3, 15,  5,  1, 13, 12,  7, 11,  4,  2,  8,
	13,  7,  0,  9,  3,  4,  6, 10,  2,  8,  5, 14, 12, 11, 15,  1,
	13,  6,  4,  9,  8, 15,  3,  0, 11,  1,  2, 12,  5, 10, 14,  7,
	 1, 10, 13,  0,  6,  9,  8,  7,  4, 15, 14,  3, 11,  5,  2, 12
},
{
	 7, 13, 14,  3,  0,  6,  9, 10,  1,  2,  8,  5, 11, 12,  4, 15,
	13,  8, 11,  5,  6, 15,  0,  3,  4,  7,  2, 12,  1, 10, 14,  9,
	10,  6,  9,  0, 12, 11,  7, 13, 15,  1,  3, 14,  5,  2,  8,  4,
	 3, 15,  0,  6, 10,  1, 13,  8,  9,  4,  5, 11, 12,  7,  2, 14
},
{
	 2, 12,  4,  1,  7, 10, 11,  6,  8,  5,  3, 15, 13,  0, 14,  9,
	14, 11,  2, 12,  4,  7, 13,  1,  5,  0, 15, 10,  3,  9,  8,  6,
	 4,  2,  1, 11, 10, 13,  7,  8, 15,  9, 12,  5,  6,  3,  0, 14,
	11,  8, 12,  7,  1, 14,  2, 13,  6, 15,  0,  9, 10,  4,  5,  3
},
{
	12,  1, 10, 15,  9,  2,  6,  8,  0, 13,  3,  4, 14,  7,  5, 11,
	10, 15,  4,  2,  7, 12,  9,  5,  6,  1, 13, 14,  0, 11,  3,  8,
	 9, 14, 15,  5,  2,  8, 12,  3,  7,  0,  4, 10,  1, 13, 11,  6,
	 4,  3,  2, 12,  9,  5, 15, 10, 11, 14,  1,  7,  6,  0,  8, 13
},
{
	 4, 11,  2, 14, 15,  0,  8, 13,  3, 12,  9,  7,  5, 10,  6,  1,
	13,  0, 11,  7,  4,  9,  1, 10, 14,  3,  5, 12,  2, 15,  8,  6,
	 1,  4, 11, 13, 12,  3,  7, 14, 10, 15,  6,  8,  0,  5,  9,  2,
	 6, 11, 13,  8,  1,  4, 10,  7,  9,  5,  0, 15, 14,  2,  3, 12
},
{
	13,  2,  8,  4,  6, 15, 11,  1, 10,  9,  3, 14,  5,  0, 12,  7,
	 1, 15, 13,  8, 10,  3,  7,  4, 12,  5,  6, 11,  0, 14,  9,  2,
	 7, 11,  4,  1,  9, 12, 14,  2,  0,  6, 10, 13, 15,  3,  5,  8,
	 2,  1, 14,  7,  4, 10,  8, 13, 15, 12,  9,  0,  3,  5,  6, 11
}
};
// Compression P box
int CP[56]=  
    {    57,49,41,33,25,17,9, 
        1,58,50,42,34,26,18, 
        10,2,59,51,43,35,27, 
        19,11,3,60,52,44,36,           
        63,55,47,39,31,23,15, 
        7,62,54,46,38,30,22, 
        14,6,61,53,45,37,29, 
        21,13,5,28,20,12,4 
    };
// No. of bit shifts  
    int BITSHIFTS[16]= 
    {    1, 1, 2, 2, 
        2, 2, 2, 2,  
        1, 2, 2, 2,  
        2, 2, 2, 1 
    };
//compression D-box
int CD[48]= 
	{ 14,17,11,24,1,5, 
		3,28,15,6,21,10, 
		23,19,12,4,26,8, 
		16,7,27,20,13,2, 
		41,52,31,37,47,55, 
		30,40,51,45,33,48, 
		44,49,39,56,34,53, 
		46,42,50,36,29,32 
	};

#include <iostream>
#include <unordered_map>
#include <vector>
#include <bitset>

using namespace std;

string ascii2hex(string s, int n)
{
    string res = "";
    unordered_map<int, char> mp;
    for(int i=0; i<10; i++)
    {
        mp[i] = i + '0';
    }
    for(int i=0; i<6; i++)
    {
        mp[10+i] = i + 'A';
    }
    for(int i=0; i<n; i++)
    {
        int x = s.at(i);
        int b1 = mp[x/16];
        int b2 = mp[x%16];
        res += string(1, b1) + string(1, b2);
    }
    for(int i=0; n%8 != 0 && i<8-n%8; i++)
    {
        res += "00";
    }
    return res;
}

string hex2ascii(string s, int n)
{
    string res = "";
    unordered_map<char, int> mp;
    for(int i=0; i<10; i++)
    {
        mp[i + '0'] = i;
    }
    for(int i=0; i<6; i++)
    {
        mp[i + 'A'] = i + 10;
    }
    for(int i=0; i<n/2; i++)
    {
        int b1 = mp[s[2*i]];
        int b2 = mp[s[2*i+1]];
        char x = b1*16 + b2;
        res += string(1, x);
    }
    return res;
}

bitset<64> hex2bin(string s){ 
        // hexadecimal to binary conversion 
    unordered_map<char, string> mp; 
    mp['0']= "0000"; 
    mp['1']= "0001"; 
    mp['2']= "0010"; 
    mp['3']= "0011"; 
    mp['4']= "0100"; 
    mp['5']= "0101"; 
    mp['6']= "0110"; 
    mp['7']= "0111"; 
    mp['8']= "1000"; 
    mp['9']= "1001"; 
    mp['A']= "1010"; 
    mp['B']= "1011"; 
    mp['C']= "1100"; 
    mp['D']= "1101"; 
    mp['E']= "1110"; 
    mp['F']= "1111"; 
    string binString = ""; 
    for(int i=0; i<s.size(); i++){ 
        binString += mp[s[i]]; 
    } 
    bitset<64> bin(binString);
    return bin; 
}

unordered_map<string, string> createB2H()
{
    unordered_map<string, string> bin2hex_mp; 
    bin2hex_mp["0000"]= "0"; 
    bin2hex_mp["0001"]= "1"; 
    bin2hex_mp["0010"]= "2"; 
    bin2hex_mp["0011"]= "3"; 
    bin2hex_mp["0100"]= "4"; 
    bin2hex_mp["0101"]= "5"; 
    bin2hex_mp["0110"]= "6"; 
    bin2hex_mp["0111"]= "7"; 
    bin2hex_mp["1000"]= "8"; 
    bin2hex_mp["1001"]= "9"; 
    bin2hex_mp["1010"]= "A"; 
    bin2hex_mp["1011"]= "B"; 
    bin2hex_mp["1100"]= "C"; 
    bin2hex_mp["1101"]= "D"; 
    bin2hex_mp["1110"]= "E"; 
    bin2hex_mp["1111"]= "F";
    return bin2hex_mp;
}

string bin2hex(bitset<64> bin){
    unordered_map<string, string> bin2hex_mp = createB2H();
    string s = bin.to_string();
    string hex=""; 
    for(int i=0; i<s.length(); i+=4){ 
        string ch=""; 
        ch+= s[i]; 
        ch+= s[i+1]; 
        ch+= s[i+2]; 
        ch+= s[i+3]; 
        hex+= bin2hex_mp[ch]; 
    } 
    return hex; 
} 

string bin2hex(bitset<32> bin){
    unordered_map<string, string> bin2hex_mp = createB2H(); 
    string s = bin.to_string();
    string hex=""; 
    for(int i=0; i<s.length(); i+=4){ 
        string ch=""; 
        ch+= s[i]; 
        ch+= s[i+1]; 
        ch+= s[i+2]; 
        ch+= s[i+3]; 
        hex+= bin2hex_mp[ch]; 
    } 
    return hex; 
} 

string bin2hex(bitset<28> bin){ 
    unordered_map<string, string> bin2hex_mp = createB2H();
    string s = bin.to_string();
    string hex=""; 
    for(int i=0; i<s.length(); i+=4){ 
        string ch=""; 
        ch+= s[i]; 
        ch+= s[i+1]; 
        ch+= s[i+2]; 
        ch+= s[i+3]; 
        hex+= bin2hex_mp[ch]; 
    } 
    return hex; 
} 

string bin2hex(bitset<48> bin){ 
    unordered_map<string, string> bin2hex_mp = createB2H(); 
    string s = bin.to_string();
    string hex=""; 
    for(int i=0; i<s.length(); i+=4){ 
        string ch=""; 
        ch+= s[i]; 
        ch+= s[i+1]; 
        ch+= s[i+2]; 
        ch+= s[i+3]; 
        hex+= bin2hex_mp[ch]; 
    } 
    return hex; 
} 
  
bitset<32> permute_32t32(bitset<32> k, int* arr){
    bitset<32> per; 
    for(int i=0; i<32 ; i++){ 
        per[32-1-i] = k[32-1-(arr[i]-1)]; 
    } 
    return per; 
}

bitset<48> permute_32t48(bitset<32> k, int* arr){
    bitset<48> per; 
    for(int i=0; i<48 ; i++){ 
        per[48-1-i] = k[32-1-(arr[i]-1)]; 
    } 
    return per; 
} 

bitset<56> permute_64t56(bitset<64> k, int* arr){
    bitset<56> per; 
    for(int i=0; i<56 ; i++){ 
        per[56-1-i] = k[64-1-(arr[i]-1)]; 
    } 
    return per; 
} 

bitset<64> permute_64t64(bitset<64> k, int* arr){
    bitset<64> per; 
    for(int i=0; i<64 ; i++){ 
        per[64-1-i] = k[64-1-(arr[i]-1)]; 
    }
    return per; 
} 

bitset<48> permute_56t48(bitset<56> k, int* arr){
    bitset<48> per; 
    for(int i=0; i<48 ; i++){ 
        per[48-1-i] = k[56-1-(arr[i]-1)]; 
    } 
    return per; 
} 

bitset<56> drop_parity(bitset<64> k)
{
    bitset<56> res;
    int count = 0;
    for(int i=0; i<56; i++)
    {
        res[i] = k[count];
        count++;
        if(count % 8 == 7)
        {
            count++;
        }
    }
    return res;
}
  
bitset<28> shift_left(bitset<28> k, int shifts){
    
    bitset<28> res = k;
    for(int i=0; i<shifts; i++)
    {
        int msb = res[27];
        res = res <<= 1;
        res[0] = msb;
    }
    return res; // k <<= shifts; 
} 
  
bitset<48> xor_(bitset<48> a, bitset<48> b){ 
    return a ^= b;
}

bitset<32> xor_(bitset<32> a, bitset<32> b){ 
    return a ^= b;
}

bitset<28> cut(bitset<56> x, int left=1)
{
    int start = (left == 1)?28:0;
    bitset<28> res;
    for(int i=0; i<28; i++)
    {
        res[i] = x[i+start];
    }
    return res;
}

bitset<32> cut(bitset<64> x, int left=1)
{
    int start = (left == 1)?32:0;
    bitset<32> res;
    for(int i=0; i<32; i++)
    {
        res[i] = x[i+start];
    }
    return res;
}

bitset<56> combine28(bitset<28> left, bitset<28> right)
{
    bitset<56> res;
    for(int i=0; i<28; i++)
    {
        res[i] = right[i];
        res[i+28] = left[i];
    }
    return res;
}

bitset<64> combine32(bitset<32> left, bitset<32> right)
{
    bitset<64> res;
    for(int i=0; i<32; i++)
    {
        res[i] = right[i];
        res[i+32] = left[i];
    }
    return res;
}

string encrypt(string pt_string, vector<bitset<48> > rkb, vector<string> rk){ 
    //Hexadecimal to binary 
    bitset<64> pt = hex2bin(pt_string); 

    //Initial Permutation 
    pt = permute_64t64(pt, IP); 
    // cout<<"After initial permutation: "<<bin2hex(pt)<<endl; 
      
    //Splitting  
    bitset<32> left = cut(pt, 1); 
    bitset<32> right = cut(pt, 0); 
    // cout<<"After splitting: L0="<<bin2hex(left) 
    //        <<" R0="<<bin2hex(right)<<endl; 

    for(int i=0; i<16; i++){ 
        //Expansion D-box 
        bitset<48> right_expanded= permute_32t48(right, ED); 
        // cout<<"Right expand: "<<bin2hex(right_expanded)<<endl;
          
        //XOR RoundKey[i] and right_expanded 
        bitset<48> x = xor_(rkb[i], right_expanded); 
          
        //S-boxes 
        bitset<32> op;
        int count = 31;
        for(int i=0;i<8; i++){ 
            int row= 2*int(x[47-i*6])+ int(x[47-(i*6 +5)]); 
            int col= 8*int(x[47-(i*6 +1) ])+ 4*int(x[47-(i*6 +2)])+  
                                 2*int(x[47-(i*6 +3)])+ int(x[47-(i*6 +4)]); 
            int val= s[i][row][col]; 
            op[count--] = val/8;
            val= val%8; 
            op[count--] = val/4; 
            val= val%4; 
            op[count--] = val/2; 
            val= val%2; 
            op[count--] = val; 
        } 
        //Straight P-box 
        op = permute_32t32(op, P); 
          
        //XOR left and op 
        bitset<32> x2 = xor_(op, left); 
          
        left = x2; 
          
        //Swapper 
        if(i!= 15){ 
            swap(left, right); 
        } 
        // cout<<"Round "<<i+1<<" "<<bin2hex(left)<<" "
        //                      <<bin2hex(right)<<" "<<rk[i]<<endl; 
    } 
      
    //Combination 
    bitset<64> combine = combine32(left, right); 
      
    //Final Permutation 
    string cipher = bin2hex(permute_64t64(combine, FP)); 
    return cipher; 
} 
int main(){ 

    string plaintext;
    cin>>plaintext;

    string key_string; // = "AABB09182736CCDD";
    cin>>key_string;
    int key_n = key_string.length();
    int cutoff = min(key_n, 8);
    key_string = ascii2hex(key_string, cutoff);

    //Key Generation 
        
    //Hex to binary 
    bitset<64> key_full = hex2bin(key_string); 

    bitset<56> key = permute_64t56(key_full, CP); 
    
    //Splitting 
    bitset<28> left = cut(key, 1); 
    bitset<28> right = cut(key, 0); 

    vector<bitset<48> > rkb;//rkb for RoundKeys in binary 
    vector<string> rk;//rk for RoundKeys in hexadecimal 
    for(int i=0; i<16; i++){ 
        //Shifting 
        left = shift_left(left, BITSHIFTS[i]); 
        right = shift_left(right, BITSHIFTS[i]); 
        // cout<<"Shifted keys: "<<bin2hex(left)<<" "<<bin2hex(right)<<endl;
        //Combining 
        bitset<56> combine = combine28(left, right); 
        
        //Key Compression 
        bitset<48> RoundKey = permute_56t48(combine, CD); 
        
        rkb.push_back(RoundKey); 
        rk.push_back(bin2hex(RoundKey)); 
    } 

    //pt_string = "123456ABCD132536"; 

    int n = plaintext.length();
    string totalDecr = "";
    string totalCipher = "";
    for(int part=0; part<(n+7)/8; part++)
    {
        int cutoff = min(n, (part+1)*8);
        string part_string = plaintext.substr(part*8, cutoff);
        string pt_string = ascii2hex(part_string, cutoff-part*8);
        // cout<<"Cut part: "<<part_string<<" Hex: "<<pt_string<<endl;
        
        // cout<<"\nEncryption:\n\n"; 
        string cipher= encrypt(pt_string, rkb, rk); 
        totalCipher += hex2bin(cipher).to_string();
        //cout<<cipher<<endl; 
        
        // cout<<"\nDecryption\n\n"; 
        reverse(rkb.begin(), rkb.end()); 
        reverse(rk.begin(), rk.end()); 
        string text= encrypt(cipher, rkb, rk); 
        totalDecr += hex2bin(text).to_string();
        //cout<<"\nPlain Text: "<<text<<" ASCII: "<<hex2ascii(text, 16)<<endl;
    }
    cout<<totalCipher<<endl;
    cout<<totalDecr<<endl;
} 