f = open("input.txt", "w")

s = """/*C-style comments can contain
multiple lines*/ /*or just one*/
// C++-style comment lines
int main() {
// The below code wont be run
//return 1;
return 0; //this will be run
}
// vot takaya vot hyinya sobachka
abc/\n/\n/*/\n/***\n/*//"""

f.write(s)

# print(365 * 24 * 3600)
