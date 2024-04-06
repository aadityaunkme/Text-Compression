#include<bits/stdc++.h>
using namespace std;
long long int sz(if stream fp)
{
    if (fp == NULL) {
        cout<< "file doesnt exist \n";
        return 0;
    }
    fseek(fp, 0L, SEEK_END);
    long int ans= ftell(fp);
    return ans;
}
bool isthere(string s,string c)
{
    if(s.find(c)>=0 && s.find(c)<s.size())
    return true;
    return false;
}
string compress(string &s,map<string,string> map)
{
for(auto &it:map)
{
    while(isthere(s,it.first))
    {
        s.replace(s.find(it.first),(it.first).size(),it.second);
    }
}
return s;
}
string decompress(string &s,map<string,string> map)
{
    for(auto &it:map)
   {
    while(isthere(s,it.second))
    {
        s.replace(s.find(it.second),1,it.first);
    }
   }
return s;
}
int main(int argc, char const *argv[])
{
    /* code */
    string s,line;
    ifstream fin;
    ofstream fout;
 vector <string> vec={"ity","able","ion","ive","ence","ness","al","ed","ist","der",
                      "ing","ary","the","er ","ment","ian","try","ify","ly","old",
                      "in","the","an","ies","ic","on","for","ere","eir","es","ogy",
                      "ture","or"};
map<string,string> map;
for(int i=0;i<vec.size();i++)
{
    if(i==26)
    map["for"]="|";
    else if(i==32)
    map[vec[i]]=char(128);
    else{
string str="";
    str+=char(i);
    map[vec[i]]=str;
    } 
    
}
map["ous"]="~";
map["     "]="{";
map["ea"]=char(127);
while(1)
{
	cout<<"Press 1 to Compress the file.\nPress 2 to Decompress.\nPress any other key to Exit.\nEnter your Choice:-";
 int ch;
 cin>>ch;
 switch(ch)
 {
 	case 1:{cout<<"Enter the Name of the file you want to compress:- ";
    cin>>s;
string compres="compressed_"+s;

    //by default open mode = ios::in mode
    fin.open(s);
    fout.open(compres);
    // Execute a loop until EOF (End of File)
    while (getline(fin, line)) 
    {
       
        // Print line (read from file) in Console
        compress(line,map);
        fout << line << endl;
    }
    // Close the file
    long long int in=sz(s),out=sz(compres);
    double per=(in-out)/in*100;
    fin.close();
    fout.close();
    cout<<"\n\n\nFile Compressed file by "<<per<<"% Succesfully!!\n"<<compres<<" file is created in the same location.\n\n\n";
    break;}
    case 2:{ cout<<"\nEnter the file name to decompress:-";
    string s1;
    cin>>s1;
    string s2="decompressed_"+s1;
    fout.open(s2);
    fin.open(s1);
    while (getline(fin, line))
    {
        decompress(line,map);
        fout << line << endl;
    }
    fin.close();
    fout.close();
    cout<<"\n\n\nFile decompressed successfully!!!!!!\n\n\n\n";	
    break;}
    default: {exit(0);}
 }
}

    return 0;
}
