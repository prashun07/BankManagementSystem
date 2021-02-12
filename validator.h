using namespace std;
//username should be in uppercase and lower case letter
//username should not contains integers or any symbol
//validate_username() take username and verify the given constraint
bool validate_username(string x)
{ //for loop runs from i=0 to size of string
    for (int i = 0; i < x.size(); i++)
    {                   //x[i] represent a char from string at ith position
        char ch = x[i]; //store char in variable ch
        //if you go through ascii table 'A' starts from 65 and 'Z' ends at 90
        //so if we subtract 65 from uppercase letter we get num in range of [0,25]
        //lowercase start from 97 and ends at 122 hence ewe get num in range of [32,57]
        int num = ch - 65;
        if ((num > 57 || num < 0) && (num <= 32 && num >= 25))
        { //if num <0 || num>57 it does not come in both of range [0,25] or [32,57]
            //again num between the range [0,25] and [32,57]
            //is neither lower or upper case
            return false; //hence char is not upper or lower case
        }

    } //if we do not found any int aur symbol then username satisfy all rules
    return true;
}
