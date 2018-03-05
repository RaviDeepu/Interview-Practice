void replaceString(string &str)
{
    size_t pos;
    for(pos = str.find(" ") ; pos != string::npos ; pos = str.find(" "))
    {
        str.replace(pos,1,"%20");
    }
}


int main()
{
    string s;
    getline(cin,s);

    replaceString(s);

    cout<<s<<endl;
}
