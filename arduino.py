def read_file_to_string(fname):
    """
    Reads file to a string
    :param fname: string
    :returns: string
    """
    with open(fname, "r") as file1:
        read_content = file1.read()
    return read_content

def write_string_to_file(fname,string):    
    with open(fname, "w") as file1:
        file1.write(string)

def dict_from_columns(ind1,ind2,table):
    fnames = {}
    for i in table:
        var=i[ind1]
        value=i[ind2]
        fnames[var]=value
    return fnames

def quote_lisp_library_text(mystring):
    lines = mystring.splitlines()
    fline2 = ""
    for line in lines:
        if line=="": continue
        fline1 = line.replace('"','\\"')
        fline = '\"' + fline1 + '\"'
        fline2 = fline2 + fline + "\n"
    return fline2[0:-1] + ";\n"
